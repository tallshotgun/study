num1 = int(input("Enter first number: ")) #inputting first number
num2 = int(input("Enter second number: ")) #inputting second number
#print choices for user
print("Enter 1 for addition: ")
print("Enter 2 for substraction: ")
print("Enter 3 for multiplication: ")
print("Enter 4 for division: ")
choice = int(input("Enter choice (1,2,3,4): ")) #input choice from user
if choice == 1: #perform sum if choice is 1
    print(num1+num2)
elif choice == 2: #perform substraction if choice is 2
    print(num1-num2)
elif choice == 3: #perform multiplication is choice is 3
    print(num1*num2)
elif choice == 4:
    if num2 != 0:
        print(num1/num2)
    else:
        print("Division by zero is not possible >.<")