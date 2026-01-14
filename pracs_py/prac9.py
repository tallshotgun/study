file = open("/home/tsglmao/Documents/repos/study/pracs_py/textfile.txt",'a+')
file.seek(0)    # Set pointer to start of file
data1 = file.readlines()     # Read file content
file.seek(0)
data2 = file.read()

# a. Print total number of characters, words and lines.

chars = len(data2)
words = 0
lines = len(data1)
for line in data1:
    words += len(line.split())

print(f"Total character in the file are {chars}")
print(f"Total words in the file are {words}")
print(f"Total lines in the file are {lines}",end="\n\n")

# b. Calculate frequency of each character in the file and use dictionary type variable to maintain the count

countDict = {}
for char in data2:
    if char not in countDict:
        countDict[char] = 1
    else:
        x = countDict[char]
        countDict.update({char:x+1})
sortedDict = {key: countDict[key] for key in sorted(countDict)}
print(sortedDict,end="\n\n")

# c. Print the words in reverse order

data1.reverse()
for revrs in data1:
    l = revrs.split()
    l.reverse()
    for word in l:
        print(word,end= " ")
    print()

# d. Copy even lines of the file to a file named ‘File1’ and odd lines to another file named 'File2"

data1.reverse()
file1 = open("/home/tsglmao/Documents/repos/study/pracs_py/file1.txt","w+")
file2 = open("/home/tsglmao/Documents/repos/study/pracs_py/file2.txt","w+")
file1.writelines(data1[1::2])
file2.writelines(data1[0::2])

file.close()
file1.close()
file2.close()