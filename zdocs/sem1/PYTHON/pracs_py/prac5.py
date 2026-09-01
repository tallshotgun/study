msg = input("Enter a string: ")

#   INPUT CHARACTER TO BE FOUND AND USE COUNT FUNCTION TO FIND ITS FREQUENCY

find_char = input("Enter character to find frequency: ")
print(f"The character '{find_char}' is present {msg.count(find_char)} times")

# INPUT CHARACTER TO BE REPLACED AND TO BE REPLACED WITH

repl = input("Enter character to be replaced: ")
val1 = msg.find(repl)
if val1 != -1:
    replwith = input(f"Enter character to replace {repl} with: ")
    new_msg1 = msg.replace(repl,replwith)
    msg = new_msg1
    print(msg)
else:
    print("Character does not exist")

# INPUT CHARACTER TO BE REMOVED AND FIND ITS OCCURENCE USING FIND FUNCTION
rem1 = input("Enter character whose first occurence is to be removed: ")
val2 = msg.find(rem1)
if val2 != -1:
    new_msg2 = msg[:val2]+msg[val2+1:]
    msg = new_msg2
    print(msg)
else:
    print("Character does not exist")

#   INPUT CHARACTER TO BE REMOVED AND REMOVE IT BY USING REPLACE

rem2 = input("Enter character whose all occurences are to be removed: ")
val3 = msg.find(rem2)
if val3 != -1:
    new_msg3 = msg.replace(rem2,"")
    msg = new_msg3
    print(msg)
else:
    print("Character does not exist")