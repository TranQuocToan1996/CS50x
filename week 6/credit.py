def main():
    # In put cardnumber until it has proper format
    while True:
        cardnumber = input("Input: ")
        if (cardnumber.isnumeric() and (0 < int(cardnumber))):
            cardnumber = int(cardnumber)
            break

    # Check sum and card length

    digit = str(cardnumber) # make a copy of card number to process
    count = len(digit)

    if ((count != 13) and (count != 15) and (count != 16)):
        print("INVALID\n")
        return 0

    number = []
    for i in range(len(digit)):
        number.append(int(digit[i]))

    # [0 1 2 3 4]
    checksum = 0
    # index while loop secondtolast
    i = count - 2
    while (i >= 0):
        if number[i] * 2 >= 10:
            checksum += 1 + (2 * number[i]) % 10
        else:
            checksum += 2 * number[i]
        i -= 2
    # index while loop other number in cardnumber
    i = count - 1
    while (i >= 0):
        checksum += number[i]
        i -= 2

    if ((checksum % 10) != 0):
        print("INVALID\n")
        return 0
    # Print name of the card
    if (count == 15 and number[0] == 3 and (number[1] == 4 or number[1] == 7)):
        print("AMEX\n")
        return 0

    elif (count == 16 and number[0] == 5 and (number[1] == 1 or number[1] == 2 or number[1] == 3 or number[1] == 4 or number[1] == 5)):
        print("MASTERCARD\n")
        return 0

    elif ((count == 13 or count == 16) and number[0] == 4):
        print("VISA\n")
        return 0
    else:
        print("INVALID\n")
        return 0
if __name__ == '__main__':
    main()