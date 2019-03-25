""" Module main
"""
import argparse
import parser

def gen_markdown_table(table_data):
    """ Generates the table with Markdown syntax
    """
    difficulty_badges = {
        '' : '![Not Defined](https://img.shields.io/badge/Difficulty-ND-lightgray.svg)',
        'Easy' : '![Easy](https://img.shields.io/badge/Difficulty-Easy-green.svg)',
        'Medium' : '![Medium](https://img.shields.io/badge/Difficulty-Medium-yellow.svg)',
        'Hard' : '![Hard](https://img.shields.io/badge/Difficulty-Hard-red.svg)'}
    table = []
    table.append('# Problems List')
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
    TABLE = gen_markdown_table(TABLE_DATA)

    if STDOUT:
        print("\n\n\n--- Output ---\n\n\n")
        print(TABLE)
    else:
        OUTPUT_FILE = open(ARGS.output_file, 'x')
        for row in TABLE:
            OUTPUT_FILE.write(row + '\n')
