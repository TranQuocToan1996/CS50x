import csv
import sys
import math

def max_repeat_STR(sequences: str, STR: str) -> int:
    STR_count = sequences.count(STR)
    if STR_count > 0:
        for max_repeat_str in reversed(range(1, STR_count + 1)):
            if sequences.find(max_repeat_str * STR) != -1:
                return max_repeat_str
    else:
        return 0


def main():
    # Check the running
    if len(sys.argv) != 3:
        sys.exit("Usage: python dna.py file.csv file1.txt")

    # read the CSV file into memory
    database = []
    STRs = []
    with open(sys.argv[1], 'r') as csvfile:
        readercsv = csv.DictReader(csvfile)
        STRs = readercsv.fieldnames[1:]
        for row in readercsv:
            database.append(row)
    # read the TXT file into memory

    with open(sys.argv[2], 'r') as textfile:
        sequences = textfile.readline()

    # Compute maximum STR of sequence, and count max_repeat_str
    max_repeat_STRs_sequence = {}
    # match_repeat_STR = {}
    for STR in STRs:
        max_repeat_STRs_sequence[STR] = max_repeat_STR(sequences, STR)
    for person in database:
        # print(person['name'])
        match_repeat_STR = 0
        for STR in STRs:
            # print(STR)
            # print(type(max_repeat_STRs_sequence[STR]), type(person[STR]))
            if max_repeat_STRs_sequence[STR] == int(person[STR]):
                match_repeat_STR += 1
            if match_repeat_STR == len(STRs):
                print(person['name'])
                return person['name']
    print("No match")
    return "No match"

if __name__ == '__main__':
    main()