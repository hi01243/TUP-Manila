import os

MAX=50
class Student:
    def __init__(self,filename="records.txt"):
        self.records=[]
        self.filename = filename
        self.retrieve()

    def isFull(self):
        return len(self.records) >= MAX
    def locate(self,name):
        for i, student in enumerate(self.records):
            if student["name"]==name:
                return i
        return -1
    def get_Ave(self,q1,q2,q3):
        return (q1+q2+q3)/3

    def AddRec(self,name,q1,q2,q3):
        if self.isFull():
            print("Student Record is maxed.")
            os.system("pause")
        elif self.locate(name) != -1:
            print("Student record already exists.")
            os.system("pause")
        else:
            self.records.append({
                "name":name,"q1":q1,"q2":q2,"q3":q3
            })
            print(f"Record of {name} added.")
            os.system("pause")
            self.save()

    def DelRec(self,name):
        i = self.locate(name)
        if i == -1:
            print(f"{name} has no record yet.")
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
            ave = self.get_Ave(rec['q1'],rec['q2'],rec['q3'])
            print(f"{i+1:2} | {rec['name']:10} | {rec['q1']:2} | {rec['q2']:2} | {rec['q3']:2} | {ave:5.2f}   | {"Passed" if ave>=75 else "Failed"}")
        os.system("pause")

    def save(self):
        try:
            with open(self.filename,"w") as f:
                for rec in self.records:
                    line = f"{rec['name']},{rec['q1']},{rec['q2']},{rec['q3']}\n"
                    f.write(line)
        except FileNotFoundError:
            print(f"File {self.filename} not found.")
            os.system("pause")

    def retrieve(self):
        records=[]
        try:
            with open(self.filename,"r") as f:
                for line in f:
                    name,q1,q2,q3 = line.strip().split(",")
                    self.records.append({
                        "name":name,"q1":int(q1),"q2":int(q2),"q3":int(q3)
                    })
        except FileNotFoundError:
            print(f"File {self.filename} not found.")
            os.system("pause")
        return records

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
    rec = Student()
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
