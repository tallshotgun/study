s1 = input("Enter first String: ")
s2 = input("Enter second String: ")
num = int(input("Enter number of characters you want to swap: "))

s1new = s2[:num]+s1[num:]
s2new = s1[:num]+s2[num:]
print(s1new)
print(s2new)