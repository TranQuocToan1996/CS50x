while True:
    height = input('Height: ')
    # Check for height in range and is a numeric
    if (height.isnumeric() and (0 < int(height) < 9)):
        # Change back to interger
        height = int(height)
        break
for row in range(1, height + 1):
    # rjust and ljust is function add space into string
    print(('#'*row).rjust(height) + '  ' + ('#'*row))