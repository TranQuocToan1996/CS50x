def main():
    # Input and declare variables
    text = input('Text: ')
    letters = float(0)
    words = float(0)
    sentences = float(0)
    spaces = float(0)

    # Count
    for i in range(len(text)):
        if text[i].isalpha():
            letters += 1.0
        if ord(text[i]) == 32:
            spaces += 1.0
        if (text[i] == '!') or (text[i] == '?') or (text[i] == '.'):
            sentences += 1.0
    words = float(spaces + 1.0)

    # Calculate index
    L = float(100 * letters / words)
    S = float(100 * sentences / words)
    index = float(round(0.0588 * L - 0.296 * S - 15.8))

    # Grade
    if index < 1:
        print("Before Grade 1")
        return 0
    elif index < 16:
        print("Grade {}".format(round(int(index))))
        return 0
    else:
        print('Grade 16+')
        return 0

if __name__ == '__main__':
    main()