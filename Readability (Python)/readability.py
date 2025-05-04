import re

def count_letters(text):
    letters = 0

    # Count only letterss of text
    for i in text:
        if i.isalpha():
            letters+=1
    return letters

def calc_level(w, l, s):

    # Calculate the average of letters and sentences
    L = (l / w) * 100
    S = (s / w) * 100

    # Return the level
    level = 0.0588 * L - 0.296 * S - 15.8
    return level

# Get text from user
text = input("Text: ")

# Count the letters
letters = count_letters(text)

# Count the words
words = len(text.split())

# Count the sentences
sentences = len(re.split(r'[.!?]+', text)) - 1


# Calculate the grade level
grade = calc_level(words, letters, sentences)


# Ouput the grade level
if grade < 1:
    print("Before Grade 1")

elif grade >= 16:
    print("Grade 16+")
else:
    print(f"Grade {round(grade)}")
