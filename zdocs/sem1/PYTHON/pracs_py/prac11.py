t1 = (1,2,5,7,9,2,4,6,8,10)

#   A.  Print half the values of the tuple in one line and the other half in the next line.
midP = int(len(t1)/2)
print(t1[:midP])
print(t1[midP:])

#   B.  Print another tuple whose values are even number in the given tuple.
evenTup = ()
for i in t1:
    if i % 2 == 0:
        evenTup += (i,)
print(tuple(evenTup),"is the tuple with even elements of t1.")

#   C.  Concatenate a tuple t2=(11,13,15) with t1.
t2 = (11,13,15)
t3 = t1 + t2
print(t3,"is the new concatenated tuple of t1 and t2.")

#   D.  Return maximum and minimum value from this tuple(t3?)
def min_max(tup):
    mini = min(tup)
    maxi = max(tup)
    return mini,maxi
values = min_max(t3)
print(values[0],"is the minimum value of the tuple")
print(values[1],"is the maximum value of the tuple")