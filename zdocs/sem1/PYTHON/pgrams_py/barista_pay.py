def empPay():
    hours = [0] * 6
    for i in range(6):
        hours[i] = float(input(f"Enter hours worked by employee {i+1}"))
    payrate = float(input("\nEnter the hourly pay rate: "))
    print()

    for i in range(6):
        grosspay = hours[i] * payrate
        print(f"Grosspay for employee {i+1}: ${grosspay:,.2f}")
if __name__ == '__empPay()__':
    empPay()