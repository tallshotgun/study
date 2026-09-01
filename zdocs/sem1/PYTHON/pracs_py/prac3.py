n = int(input("Enter nummber of lines of pyramid: "))
for i in range(1,n + 1):
    print(" " * (n - i) + "*" * (2 * i - 1))
for j in range(n):
    print(" " * (j) + "*" * (n * 2 - 1 - j * 2))