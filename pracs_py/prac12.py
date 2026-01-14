class Employee:
    count = 0
    def __init__(self,empNum,empName,empDept,basicSal,DA,HRA):

        if basicSal < 0 or DA < 0 or HRA < 0: # Check if salary,da,hra are positive
            raise ValueError("Basic, DA and HRA must not be negative.")
        self.empNum = empNum
        self.empName = empName
        self.empDept = empDept
        self.basicSal = basicSal
        self.DA = DA
        self.HRA = HRA
        Employee.count += 1
        
    def salary(self):
        salary = self.basicSal+self.DA+self.HRA
        return salary
    
    def __del__(self):
        Employee.count -= 1
    
    def __str__(self):
        return (f"Employee No: {self.empNum}, Name: {self.empName}, Dept: {self.empDept}, Basic: {self.basicSal}, DA: {self.DA}, HRA: {self.HRA}, Salary: {self.salary()}")

# Example for using this class
if __name__ == "__main__":
    emp1 = Employee(101,"rahul","IT",20000,500,200)
    print(emp1)
    print("Employee count before deleting: ",Employee.count)
    del(emp1)
    print("Employee count after deleting: ",Employee.count)
