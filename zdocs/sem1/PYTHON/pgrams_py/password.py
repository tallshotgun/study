def pswd(password):
    u,l,d,s = False,False,False,False
    for char in password:
        if char.isupper():
            u = True
        elif char.islower():
            l = True
        elif char.isdigit():
            d = True
        else:
            s = True
    if len(password) >=8 and u and l and d and s:
        print("Password is acceptable.")

    else:
        if not u:
            print("Password requires atleast one upper case character.")
        if not l:
            print("Password requires atleast one lower case character.")
        if not d:
            print("Password requires atleast one digit.")
        if not s:
            print("Password requires atleast one special character")
        if len(password) < 8:
            print("Password requires atleast 8 characters.")
            
pasw = input("Enter your password: ")
pswd(pasw)