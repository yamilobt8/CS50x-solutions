import csv
import sys


def main():

    # TODO: Check for command-line usage
    if len(sys.argv) != 3:
        print("Usage: python dna.py data.csv sequence.txt")
        sys.exit(1)
    # TODO: Read database file into a variable
    database = []
    dna = {}
    with open(sys.argv[1]) as csvfile:
        # we are gonna copy rows to our database but enumerated like index 0, 1, 2, 3 etc...
        for index, row in enumerate(csvfile):
            # the first row contain the name, and STRs
            if index == 0:
                # the name, STRs between them  there are ,
                database = [data for data in row.strip().split(",")[1:]]
            else:
                name = row.strip().split(",")
                dna[name[0]] = name[1:]
    # TODO: Read DNA sequence file into a variable
    with open(sys.argv[2], "r") as txtfile:
        # deleting the new ligne
        sequence = txtfile.read().replace('\n', '')
    # TODO: Find longest match of each STR in DNA sequence by counting subsequence for each sequence
    longestmatch = [longest_match(sequence, subsequence)  for subsequence in database]
    # TODO: Check database for matching profiles
    for person  in dna:
        match = 0
        for i in range(len(dna[person])):
            if longestmatch[i] == int(dna[person][i]):
                match += 1
        if match == len(database):
            print(person)
            return
    print("No match")
    return


def longest_match(sequence, subsequence):
    """Returns length of longest run of subsequence in sequence."""

    # Initialize variables
    longest_run = 0
    subsequence_length = len(subsequence)
    sequence_length = len(sequence)

    # Check each character in sequence for most consecutive runs of subsequence
    for i in range(sequence_length):

        # Initialize count of consecutive runs
        count = 0

        # Check for a subsequence match in a "substring" (a subset of characters) within sequence
        # If a match, move substring to next potential match in sequence
        # Continue moving substring and checking for matches until out of consecutive matches
        while True:

            # Adjust substring start and end
            start = i + count * subsequence_length
            end = start + subsequence_length

            # If there is a match in the substring
            if sequence[start:end] == subsequence:
                count += 1

            # If there is no match in the substring
            else:
                break

        # Update most consecutive matches found
        longest_run = max(longest_run, count)

    # After checking for runs at each character in seqeuence, return longest run found
    return longest_run


main()
