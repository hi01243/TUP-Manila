import os

MAX = 50
class Students:
    def __init__(self, name, q1,q2,q3):
        self.name = name
        self.q1 = q1
        self.q2 = q2
        self.q3 = q3

    def __str__(self):
        return f"{self.name} | {self.q1} | {self.q2} | {self.q3}"

    def to_csv(self):
        return f"{self.name},{self.q1}, {self.q2},{self.q3}"

    @staticmethod
    def from_csv(line):
        parts = line.strip().split(',')
        if len(parts)==4:
            name, q1, q2, q3 = parts
            return Students(name, int(q1), int(q2), int(q3))
        return None

class Records:
    def __init__(self, filename="records.txt"):
        self.records = []
        self.filename = filename
        self.retrieve()

    def get_Ave(self, q1, q2, q3):
        return (q1 + q2 + q3) / 3
    
    def locate(self, name):
        for i, rec in enumerate(self.records):
            if rec.name == name:
                return i
        return -1

    def is_full(self):
        return len(self.records) >= MAX

    def AddRec(self,name, q1,q2,q3):
        if self.is_full():
            print("Student record is full.")
            os.system("pause")
        elif self.locate(name) != -1:
            print("Student record already exists.")
            os.system("pause")
        else:
            self.records.append(Students(name,q1,q2,q3))
            print("Record added.")
            os.system("pause")
            self.save()

    def DelRec(self, name):
        i = self.locate(name)
        if i == -1:
            print("Record not found.")
            os.system("pause")
        else:
            del self.records[i]
            print("Record deleted.")
            os.system("pause")
            self.save()

    def DispRec(self):
        os.system("cls")
        print("     Student Records")
        print("-"*33)
        print("No | Name       | Q1 | Q2 | Q3 | Average | Remarks")
        print("-"*33)
        for i,rec in enumerate(self.records):
            ave = self.get_Ave(rec.q1,rec.q2,rec.q3)
            print(f"{i+1:2} | {rec.name:10} | {rec.q1:2} | {rec.q2:2} | {rec.q3:2} | {ave:5.2f}   | {'Passed' if ave>=75 else 'Failed'}")
        os.system("pause")


    def save(self):
        try:
            with open(self.filename, 'w') as file:
                for rec in self.records:
                    file.write(rec.to_csv() + '\n')
        except IOError:
            print("Error saving records to file.")

    def retrieve(self):
        try:
            with open(self.filename,"r") as f:
                for line in f:
                    student = Students.from_csv(line)
                    if student:
                        self.records.append(student)
                    
        except FileNotFoundError:
            print(f"File {self.filename} not found.")
            os.system("pause")
        except IOError:
            print("Error reading records from file.")
            os.system("pause")


def menu():
    print("Student Record Program using python")
    print("-"*35)
    print("        MENU")
    print("-"*35)
    print("   1. Add a Record")
    print("   2. Delete a Record")
    print("   3. Display All")
    print("   4. Exit")
    print("-"*35)
    op = int(input("Input choice (1-4): "))
    return op

if __name__=="__main__":
    rec = Records()
    while True:
        os.system("cls")
        match(menu()):
            case 1:
                os.system("cls")
                name = input("Enter name: ")
                q1 = int(input("Input quiz 1 score: "))
                q2 = int(input("Input quiz 2 score: "))
                q3 = int(input("Input quiz 3 score: "))
                rec.AddRec(name,q1,q2,q3)
            case 2:
                os.system("cls")
                name = input("Input name to delete record: ")
                rec.DelRec(name)
            case 3:
                rec.DispRec()
            case 4:
                break
            case _:
                print("Invalid Choice!")
