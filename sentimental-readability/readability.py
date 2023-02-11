from cs50 import get_string

# Gets input from the user
text = get_string("Text: ")

# Creates all variable for the letters, words and sentences
letters = 0
words = 1
sentences = 0

# Goes through the whole text
for i in text:
    # If the current character is a letter of the alphabet increment letters
    if i.isalpha():
        letters += 1
    # If the current character is a space increment words
    elif i.isspace():
        words += 1
    # If the current character is a ponctuation increment sentences
    elif i == "." or i == "!" or i == "?":
        sentences += 1
# Calculate grade index
index = round((0.0588 * letters / words * 100) - (0.296 * sentences / words * 100) - 15.8)

# Prints what grade the text is
if index < 1:
    print("Before Grade 1")

elif index >= 16:
    print("Grade 16+")
else:
    print(f"Grade {index}")