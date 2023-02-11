import csv
import sys


def main():

    if len(sys.argv) != 3:
        sys.exit("Usage python dna.py CSVFILE DNASEQUENCE")

    # Read database file into a variable
    database = []
    STRlist = []

    STRcount = 0
    with open(sys.argv[1], "r") as file:
        reader = csv.reader(file)
        for row in reader:
            if STRcount == 0:
                firstRow = row
                STRcount += 1
                continue
            if STRcount < len(firstRow):
                STRlist.append(firstRow[STRcount])
                STRcount += 1
            database.append(row)
        STRcount -= 1

    # Read DNA sequence file into a variable
    file = open(sys.argv[2], "r")
    dnaSequence = file.read()

    # Find longest match of each STR in DNA sequence
    longest = {}
    for i in range(STRcount):
        longest[i] = longest_match(dnaSequence, STRlist[i])

    count = 0
    # Check database for matching profiles
    for person in database:
        isMatch = True
        for str in range(STRcount):
            if int(person[str + 1]) != longest[str]:
                isMatch = False
                break
        if isMatch == True:
            print(person[0])
            break

    if isMatch == False:
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
