table = int(input("Enter which digit table you want to show: "))
into = int(input("Enter upto how many multiples you want to show: "))
for i in range(1,into+1):
    print(f"{table} * {i} = {table*i}")