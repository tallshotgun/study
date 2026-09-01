#   A function that accepts two strings and returns the indices of all the occurences of the second string in the first string as a list.
#   If second string is not present then it should return -1d

s1 = input("Enter first string: ")
s2 = input("Enter second string: ")
def find(s1,s2):
    n = s1.find(s2)
    list = []
    while n != -1:
        list.append(n)
        n = s1.find(s2,n+len(s2))
    if list:
        return list
    else:
        return -1
    
print(find(s1,s2))