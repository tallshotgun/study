def checkName(name):
    dig = False
    special = False
    for char in name:
        if char.isdigit() and char != " ":
            dig = True
        elif not char.isalnum() and char != " ":
            special = True
    if dig and special:
        raise ValueError("You cannot have digits and special characters in your name.")
    elif dig:
        raise ValueError("You cannot have digits in your name.")
    elif special:
        raise ValueError("You cannot have special characters in your name.")
    
name = input("Enter your name: ")
try:
    checkName(name)
except ValueError as err:
    print(err)