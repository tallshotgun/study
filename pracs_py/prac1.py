import math

a = int(input("Enter coefficient of x^2(can not be 0): "))
b = int(input("Enter coefficient of x: "))
c = int(input("Enter constant: "))
if a !=0:    
    root1 = (-b + math.sqrt(b**2-4*a*c))/2*a
    root2 = (-b - math.sqrt(b**2-4*a*c))/2*a
    print(root1,",",root2,"are the two roots")
else:
    print("Coefficient of x^2 can not be 0")
