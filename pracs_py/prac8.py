#   WAP to create a list of the cubes of only the even integers appearing in the input list(may have elements of other types also) using following methods.

list = []   # List to input values from user
cubeList1 = []  # Output list for method A: For loop
cubeList2 = []  # Output list for method B: List comprehension

num = int(input("Enter number of items you want to add in the list: "))
for i in range(num):
    item = input(f"Enter item {i+1}: ")
    if item.isdigit():
        list.append(int(item))
    else:
        list.append(item)

# Method A: Using For Loops

for x in list:
    if type(x) == int and x%2 == 0:
        cubeList1.append(x**3)
print(cubeList1)

# Method B: Using list comprehension

cubeList2 = [x**3 for x in list if type(x)==int and x%2 == 0]
print(cubeList2)































"""
def choice():
    ch = input("Enter y to continue or n to finish: ")
    if ch == "n":
        return -1        
    elif ch != "y" and ch != "n":
        print("Wrong choice entered. Please try again")
        choice()
    else:
        return 1

while True:
    n = input("Enter item: ")
    if n.isdigit():
        list.append(int(n))
    else:
        list.append(n)
    n = choice()
    if n == -1:
        break
    elif n == 1:
        continue
    else:
        break
"""