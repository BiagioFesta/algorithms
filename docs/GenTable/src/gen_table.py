""" Module main
"""
import argparse
import parser

def gen_markdown_insights(table_data):
    """ Generate insigths as markdown.
        The output is a list of string to print.
    """
    map_difficulty = {'Easy': 0, 'Medium': 1, 'Hard': 2, '': 3}
    counter_difficulty = [['Easy', 0],
                          ['Medium', 0],
                          ['Hard', 0],
                          ['Undefined', 0]]
    difficulties_color = {'Easy' : 'green',
                          'Medium': 'yellow',
                          'Hard': 'red',
                          'Undefined': 'lightgray'}
    badge_url_templte = 'https://img.shields.io/badge/{}-{}-{}.svg?style=for-the-badge&logo=c%2b%2b'

    for problem in table_data:
        difficulty = problem[3]
        counter_difficulty[map_difficulty[difficulty]][1] += 1

    output = []
    for label, counter in counter_difficulty:
        markdown_str = '![{}_counter]({})'.format(label, badge_url_templte)
        output.append(markdown_str.format(label, counter, difficulties_color[label]))

    return output


def gen_markdown_table(table_data, gen_insights=False):
    """ Generates the table with Markdown syntax
    """
    difficulty_badges = {
        '' : '![Not Defined](https://img.shields.io/badge/Difficulty-ND-lightgray.svg)',
        'Easy' : '![Easy](https://img.shields.io/badge/Difficulty-Easy-green.svg)',
        'Medium' : '![Medium](https://img.shields.io/badge/Difficulty-Medium-yellow.svg)',
        'Hard' : '![Hard](https://img.shields.io/badge/Difficulty-Hard-red.svg)'}
    table = []
    table.append('# Problems List')
    if gen_insights:
        insigths_data = gen_markdown_insights(table_data)
        for row in insigths_data:
            table.append(row)
    table.append('')
    table.append('| Problem Name | Difficulty | Implementation |')
    table.append('| - | - | - |')
    for data in table_data:
        link_col = '[{}]({})'.format(data[1], data[0])
        diff_col = difficulty_badges[data[3]]
        source_col = '[Source](https://github.com/BiagioFesta/algorithms/blob/master/{})'.format(
            data[2])
        table.append('| {} | {} | {} |'.format(link_col, diff_col, source_col))
    return table

if __name__ == "__main__":
    ARGPARSER = argparse.ArgumentParser()
    ARGPARSER.add_argument("--project-directory", required=True)
    ARGPARSER.add_argument("--output-file", required=False)

    ARGS = ARGPARSER.parse_args()

    PROJECT_PARSER = parser.Parser()
    STDOUT = bool(not ARGS.output_file)
    PROJECT_PARSER.parse_root_directory(ARGS.project_directory, verbose=STDOUT)
    TABLE_DATA = PROJECT_PARSER.get_table()
    TABLE = gen_markdown_table(TABLE_DATA, True)

    if STDOUT:
        print("\n\n\n--- Output ---\n\n\n")
        print(TABLE)
    else:
        OUTPUT_FILE = open(ARGS.output_file, 'x')
        for row in TABLE:
            OUTPUT_FILE.write(row + '\n')
