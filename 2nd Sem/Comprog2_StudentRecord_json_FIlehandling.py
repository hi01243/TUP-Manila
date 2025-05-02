import os
import json
FILENAME = "Students_Record.json"
students = []

def Retrieve():
    try:
        with open(FILENAME,"r") as f:
            students = json.load(f)
            print(f"Records successfully retrieved from {FILENAME}")
            return students
    except FileNotFoundError:
        print(f"File {FILENAME} not found.")
        return []

def Save(students):
    try:
        with open(FILENAME,"w") as f:
            json.dump(students, f, indent = 4)
    except FileNotFoundError:
        print(f"File {FILENAME} not found")

def menu():
    print("MENU")
    print("   1. Add a Record")
    print("   2. Update Record")
    print("   3. Delete a Record")
    print("   4. Display a Record")
    print("   5. Display All")
    print("   6. Exit")
    x = int(input("Input choice: "))
    return x

def avg(a,b,c):
    return (a+b+c)/3

def addRec(name,a,b,c):
    record = {"name":name,"q1": a,"q2": b,"q3":c}
    students.append(record)
    print(f"Record of {name} is added successfully.")
    Save(students)
    os.system("pause")
    return

def updRec():
    rname = input("Input name of record to change: ")
    for rec in students:
            if rec["name"] == rname:
                rec["q1"] = int(input("Input quiz 1: "))
                rec["q2"] = int(input("Input quiz 2: "))
                rec["q3"] = int(input("Input quiz 3: "))
                print(f"Record of {rname} updated successfully.")
                os.system("pause")
    return


def delRec():
    os.system("cls")
    name = input("Input name to delete record: ")
    for rec in students:
        if rec["name"] == name:
            students.remove(rec)
            print(f"Record of {name} successfully deleted")
            os.system("pause")
            return

    print(f"Record of {name} not found.")
    os.system("pause")
    return

def display():
    os.system('cls')
    print("{:<10} {:<10} {:<10} {:<10} {:<10} {:<10}".format("NAME","QUIZ 1","QUIZ 2","QUIZ 3","AVERAGE","REMARKS"))
    for rec in students:
        ave = avg(rec["q1"],rec["q2"],rec["q3"])
        remarks = "PASSED" if ave>= 75 else "FAILED"
        print("{:<10} {:<10} {:<10} {:<10} {:<10.2f} {:<10}".format(
            rec["name"],rec["q1"],rec["q2"],rec["q3"],ave,remarks
        ))
    os.system("pause")
    return

def displayOne():
    os.system("cls")
    rname = input("Input name to display: ")
    for rec in students:
        if rec["name"]==rname:
            print("\n{:<10} {:<10} {:<10} {:<10} {:<10} {:<10}".format("NAME","QUIZ 1","QUIZ 2","QUIZ 3","AVERAGE","REMARKS"))
            ave = avg(rec["q1"],rec["q2"],rec["q3"])
            remarks = "PASSED" if ave>= 75 else "FAILED"
            print("{:<10} {:<10} {:<10} {:<10} {:<10.2f} {:<10}".format(
            rec["name"],rec["q1"],rec["q2"],rec["q3"],ave,remarks
            ))
    os.system("pause")
    return

if __name__=="__main__":
    students = Retrieve()
    while True:
        os.system("cls")
        match(menu()):
            case 1:
                os.system('cls')
                name=input("Input name: ").strip()
                q1= int(input("Input quiz 1: "))
                q2= int(input("Input quiz 2: "))
                q3= int(input("Input quiz 3: "))
                addRec(name,q1,q2,q3)
            case 2:
                os.system('cls')
                updRec()
            case 3:
                delRec()
            case 4:
                displayOne()
            case 5:
                display()
            case 6:
                Save(students)
                print("Recorded Successfully.")
                os.system("pause")
                break
            case _: print("Invalid choice.")