""" Module which provides parsing functionality for problem inside the repository
"""
import os
import re
import requests

class Parser:
    """ This class is parse the project root directory
    """
    def __init__(self):
        self.table = []
        self.cquery_directory = '.cquery_cached_index'
        self.gnu_link = 'www.gnu.org'
        self.leetcode_table = Parser.__fill_leetcode_table()
        self.leetcode_diff_map = {1:'Easy', 2:'Medium', 3:'Hard'}

    def parse_root_directory(self, root_directory, verbose=False):
        """ Parse the root directory in order to build infos.
        """
        self.table = []
        root_directory = os.path.abspath(root_directory)
        header_files = self.__get_headers_from_root(root_directory)

        for header_file in header_files:
            if verbose:
                print("Parsing header file: {}".format(header_file))
            data = self.__parse_header_file(root_directory, header_file)

            if verbose:
                print("  URL Found: {}".format(bool(data[0])))
                print("  Function Name: {}".format(data[1]))
                print("  Impl. File: {}".format(data[2]))
                print("  Difficulty: {}".format(data[3]))

            self.table.append(data)

        self.table.sort(key=lambda x: x[1])

    def get_table(self):
        """ To use after `parse_root_directory` method which fills this table.
            The table is a list of tuple.
            Each tuple represent a potential algorithm implemented which the following info:
                  [0] -> string: url to the problem (can be emtpy)
                  [1] -> string: function name (parsed from header filename)
                  [2] -> string: implementation file (file path complete)
                  [3] -> string: difficulty (can be emtpy)
        """
        return self.table

    @staticmethod
    def __fill_leetcode_table():
        leet_code_api = 'https://leetcode.com/api/problems/algorithms/'
        response = requests.get(leet_code_api)
        if response.status_code != 200:
            raise Exception('Error parsing HTML website "{}"'.format(leet_code_api))
        return response.json()

    def __get_headers_from_root(self, root_directory):
        include_directory = root_directory + '/include'
        if not os.path.exists(include_directory):
            raise Exception('Not found the include directory of the project ({})'
                            .format(include_directory))

        files = []
        for items in os.walk(include_directory):
            if self.cquery_directory not in items[0]:
                for file in items[2]:
                    file_name = items[0] + '/' + file
                    files.append(file_name)
        return files

    @staticmethod
    def __get_pure_name_of_file(file_name):
        """ return the pure name of a file (without extension).
               E.g /root/another/filename.txt  --->  filename
        """
        return os.path.splitext(os.path.split(file_name)[1])[0]

    @staticmethod
    def __grep_urls_from_file(file_name):
        file = open(file_name)
        urls = []
        for line in file:
            matches = re.search("https?://.*", line)
            if matches:
                urls.append(matches.group(0))
        return urls

    @staticmethod
    def __purge_root_from_directory(root_directory, file_name):
        return file_name.replace(root_directory + '/', '')

    def __find_cpp_file(self, root_directory, header_file):
        src_directory = root_directory + '/src'
        if not os.path.exists(src_directory):
            raise Exception('Not found the src directory of the project ({})'
                            .format(src_directory))

        name_to_find = Parser.__get_pure_name_of_file(header_file)

        for items in os.walk(src_directory):
            if self.cquery_directory not in items[0]:
                for file in items[2]:
                    if os.path.splitext(file)[0] == name_to_find:
                        complete_filename = items[0] + '/' + file
                        return Parser.__purge_root_from_directory(root_directory,
                                                                  complete_filename)

        return Parser.__purge_root_from_directory(root_directory, header_file)

    def __parse_header_file(self, root_directory, header_file):
        urls = {url for url in Parser.__grep_urls_from_file(header_file)
                if self.gnu_link not in url}
        if len(urls) > 1:
            raise Exception('The header file "{}" contains multiple different URLs'
                            .format(header_file))
        url = urls.pop() if urls else ""

        meta = self.__get_meta(url)
        function_name = meta[1] if meta[1] else re.sub('([a-z])([A-Z])',
                                                       '\\g<1> \\g<2>',
                                                       Parser.__get_pure_name_of_file(header_file))
        cpp_file = self.__find_cpp_file(root_directory, header_file)
        difficulty = meta[0]

        return (url, function_name, cpp_file, difficulty)

    def __get_meta(self, url):
        """ return a tuple of two elements.
            Given a URL, returns:
               [0] -> string:  The Difficulty
               [1] -> string:  The problem name
        """
        leet_code_url = 'leetcode.com/'
        hacker_rank_url = 'hackerrank.com/'
        wiki_url = 'wikipedia.org'

        if leet_code_url in url:
            return self.__get_meta_leetcode(url)
        if hacker_rank_url in url:
            return self.__get_meta_hacker_rank(url)
        if wiki_url in url:
            return self.__get_meta_wikipedia(url)

        return ('', '')

    def __get_meta_leetcode(self, url):
        pattern = 'https?://leetcode.com/(problems|articles)/([\\w-]+)/.*$'
        matches = re.search(pattern, url)
        if not matches:
            raise Exception('Cannot parse metadata for url "{}"'.format(url))
        title_slug = matches.group(2)

        for item in self.leetcode_table['stat_status_pairs']:
            if item['stat']['question__title_slug'] == title_slug:
                return (self.leetcode_diff_map[item['difficulty']['level']],
                        item['stat']['question__title'])
        return ('', '')

    @staticmethod
    def __get_meta_hacker_rank(url):
        response = requests.get(url)
        if response.status_code != 200:
            raise Exception('Cannot parse metadata for url "{}" (Get Failed)'
                            .format(url))

        pattern_title = 'class="ui-icon-label page-label">([^<]+)</h1>'
        matches_title = re.search(pattern_title, response.text)
        if not matches_title:
            raise Exception('Cannot parse metadata for url "{}" (Title Not Found)'
                            .format(url))

        pattern_difficulty = 'class="pull-right difficulty-medium">(Easy|Medium|Hard)</p>'
        matches_difficulty = re.search(pattern_difficulty, response.text)
        if not matches_difficulty:
            raise Exception('Cannot parse metadata for url "{}" (Difficulty Not Found)'
                            .format(url))
        return (matches_difficulty.group(1), matches_title.group(1))

    @staticmethod
    def __get_meta_wikipedia(url):
        response = requests.get(url)
        if response.status_code != 200:
            raise Exception('Cannot parse metadata for url "{}" (Get Failed)'
                            .format(url))

        pattern_title = 'class="firstHeading" [^>]+>([^<]+)</'
        matches_title = re.search(pattern_title, response.text)
        if not matches_title:
            raise Exception('Cannot parse metadata for url "{}" (Title Not Found)'
                            .format(url))
        return ('', matches_title.group(1))

if __name__ == "__main__":
    PARSER = Parser()
    PARSER.parse_root_directory(".", True)
    print(PARSER.get_table())
