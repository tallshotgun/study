l = input("Enter a character: ")
if len(l) == 1:

    if l.isalpha():
        print("Character is a letter;",end=" ")
        if l.isupper():
            print("Letter is uppercase")
        elif l.islower():
            print("Letter is lowercase")


    elif l.isdigit():
        print("Character is a digit;",end=" ")
        words = ["Zero","One","Two","Three","Four","Five","Six","Seven","Eight","Nine"]
        print(words[int(l)])


    elif not l.isalnum():
        print("Character is a special character.")
else:
    print("Please enter only one character.")