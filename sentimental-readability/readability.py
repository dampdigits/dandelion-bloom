# Readability calculates the approximate grade level needed to comprehend some text.
# It uses the Coleman-Liau index reading test.
import sys

text = ""
letters = words = sentences = 0


def main():
    # Input text
    global text
    text = input("Text: ")
    # Count number of letters, words and sentences in text
    analyzetext()
    # Calculate Coleman-Liau index
    index = round(findindex())
    # Display Grade
    display(index)
    sys.exit(0)


# Count the number of letters, words and sentences
def analyzetext():
    global text, letters, words, sentences

    for ch in text:
        # If character is a letter, one letter is counted
        if ch.isalpha():
            letters += 1
        # If character is a whitespace, one word is counted
        if ch == "\t" or ch == " ":
            words += 1
        # If character is a terminating punctuation, one sentence is counted
        if ch == "." or ch == "?" or ch == "!":
            sentences += 1
    # Count the last word
    words += 1


def findindex():
    global letters, sentences, words

    # Average number of letters per 100 words
    L = letters / words * 100
    # Average number of sentences per 100 words
    S = sentences / words * 100
    # Coleman-Liau index
    index = (0.0588 * L) - (0.296 * S) - 15.8
    return index


# Prints the grade
def display(index):
    if index < 1:
        print("Before Grade 1")
    elif index >= 16:
        print("Grade 16+")
    else:
        print(f"Grade {index}")


if __name__ == "__main__":
    main()
