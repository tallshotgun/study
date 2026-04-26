def func():
    global x
    global y
    sum = x + y
    return sum

x , y = 2 , 3
print(func())
x = 4
print(func())