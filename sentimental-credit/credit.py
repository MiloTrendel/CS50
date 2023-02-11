from cs50 import get_int

# Prompts the user until he gives a correct input
while True:
    card = get_int("Number: ")
    if card > 0:
        break

# Converts the card number to string so you can reverse it later on
card = str(card)
# Creates every variable needed through the code
multiplication = 0
addition = 0
result = 0
isMult = False
isValid = False

# Iterate through the card number but in reverse order
for i in reversed(card):
    i = int(i)
    # Alternate between multiplication and addition with isMult bool
    if isMult == False:
        addition += i
        isMult = True

    elif isMult == True:
        doubleNumber = i * 2
        # If the current number * 2 is higher than 10 then add both numbers
        if doubleNumber > 9:
            multiplication += doubleNumber % 10
            doubleNumber = int(doubleNumber / 10)
            multiplication += doubleNumber
        else:
            multiplication += doubleNumber
        isMult = False

result = multiplication + addition

# Checks if the card is valid 
if result % 10 == 0:
    isValid = True

if isValid == False:
    print("INVALID")
else:
    if len(card) == 15 and int(card[0]) == 3 and (int(card[1]) == 4 or int(card[1]) == 7):
        print("AMEX")

    elif len(card) == 13:
        print("VISA")

    elif len(card) == 16:
        if int(str(card[0])) == 4:
            print("VISA")

        elif int(card[0]) == 5 and (int(card[1]) == 1 or int(card[1]) == 2 or int(card[1]) == 3 or int(card[1]) == 4 or int(card[1]) == 5):
            print("MASTERCARD")

        else:
            print("INVALID")
    else:
        print("INVALID")
