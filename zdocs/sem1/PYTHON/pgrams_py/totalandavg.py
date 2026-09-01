# write a program to input a list of integers from user and calculate the total of values in the list

# Create a variable to store the total
total = 0 

# Create an empty list to store the integers
ls = [] 

# Input the number of integers to be added
amount = int(input("Enter the amount of numbers you want to add: "))

# Run a loop for a range of the amount inputted by user
for i in range(amount):
    n = int(input(f"Enter integer {i+1}: "))    #   Input the integer
    ls.append(n)    #      Append the integer to the list
total = sum(ls)    #   Calculate the total of the list
average = total/len(ls)
print(f"Total is {total}")
print(f"Average is {average}")