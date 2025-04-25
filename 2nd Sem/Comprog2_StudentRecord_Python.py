import os
students = []
last = -1
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

def locate(name):
    for i in range(len(students)):
        if students[i]["name"] == name:
            return i
    return False

def addRec(name,a,b,c):
    global last
    record = {"name":name,"q1": a,"q2": b,"q3":c}
    students.append(record)
    print(f"Record of {name} is added successfully.")
    last += 1
    os.system("pause")
    return

def updRec():
    rname = input("Input name of record to change: ")
    i = locate(rname)
    if i is False:
        print("No record of {name} found.")
        os.system("pause")
        return
    else:
        tq1 = int(input("Input quiz 1: "))
        tq2 = int(input("Input quiz 2: "))
        tq3 = int(input("Input quiz 3: "))
        students[i]["q1"] = tq1
        students[i]["q2"] = tq2
        students[i]["q3"] = tq3
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
    global last
    os.system('cls')
    if last == -1:
        print("No record yet.")
        os.system("pause")
        return
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
    name = input("Input name to display: ")
    i = locate(name)
    if i is False:
        print(f"No record of {name} yet.")
        os.system("pause")
        return
    else:
        print("\n{:<10} {:<10} {:<10} {:<10} {:<10} {:<10}".format("NAME","QUIZ 1","QUIZ 2","QUIZ 3","AVERAGE","REMARKS"))
        ave = avg(students[i]["q1"],students[i]["q2"],students[i]["q3"])
        remarks = "PASSED" if ave>= 75 else "FAILED"
        print("{:<10} {:<10} {:<10} {:<10} {:<10.2f} {:<10}".format(
        students[i]["name"],students[i]["q1"],students[i]["q2"],students[i]["q3"],ave,remarks
        ))
    os.system("pause")
    return

while True:
    os.system("cls")
    match(menu()):
        case 1:
            os.system('cls')
            name=input("Input name: ")
            q1= int(input("Input q1: "))
            q2= int(input("Input q2: "))
            q3= int(input("Input q3: "))
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
            break
        case _: print("Invalid choice.")