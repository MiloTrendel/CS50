while True:
    try:
        height = int(input("Height: "))
        if height >= 1 and height <= 8:
            break
    except:
        print("Enter a number")

for i in range(height + 1):
    if i == 0:
        continue
    print(" " * (height - i), end="")
    print("#" * i)