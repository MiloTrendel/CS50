from cs50 import get_float
while True:
    cash = get_float("Change owed: ")
    if cash > 0:
        break

total = 0

temp = int(cash / 0.25)
total += temp
cash = round(cash - (temp * 0.25), 2)


temp = int(cash / 0.10)
total += temp
cash = round(cash - (temp * 0.10), 2)


temp = int(cash / 0.05)
total += temp
cash = round(cash - (temp * 0.05), 2)


temp = int(cash / 0.01)
total += temp

print(total)