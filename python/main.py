class Employee:
    increment = 2

    def __init__(self, firstName, lastName, salary):
        self.fName = firstName
        self.lName = lastName
        self.salary = salary

    def changeSalary(self):
        self.salary *= self.increment

    @classmethod
    def changeIncrement(cls, amount):
        cls.increment = amount

    @classmethod
    def alternateConstructor(cls, string):
        firstName, lastName, salary = string.split("-")
        return cls(firstName, lastName, salary)


class Programmer(Employee):
    def __init__(self, firstName, lastName, salary, language, experience):
        super().__init__(firstName, lastName, salary)
        self.language = language
        self.experience = experience

    def changeSalary(self):
        self.salary *= (self.increment + 0.2)


abhishek = Programmer("Abhishek", "Tanwar", 230000, "Python", 3)
print(abhishek.salary)
abhishek.changeSalary()
print(abhishek.salary)

# abhishek = Employee("Abhishek", "Tanwar", 25000)
# print(abhishek.salary)
# abhishek.changeSalary()
# print(abhishek.salary)
# Employee.changeIncrement(3)
# abhishek.changeSalary()
# print(abhishek.salary)
# shivam = Employee.alternateConstructor("Shivam-Tanwar-500000")
# print(shivam.fName)