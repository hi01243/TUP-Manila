import os
"""
    Instructions
    Study sample program class44.py 
    (using List of Dictionaries) and 
    class4.py (using List of Objects) and 
    write the Student Record Program 
    in Python OOP using:
    List of Dictionaries
    List of Objects
    Turn in 2 files

        Menu
        Add a Record
        Delete a Record
        Display all
        Exit
"""""
MAX=50
class Student:
    def __init__(self,filename="records.txt"):
        self.records=[]
        self.filename
        self.load_accounts()
    def AddRec(self):

    def DelRec(self):

    def DispRec(self):

    def isFull(self):
        return len(self.accounts) >= MAX
    def locate(self,name):
        for i, student in enumerate(self.records):
            if student["name"]==name:
                return i
        return -1


def menu():
    print("Student Record Program using python")
    print("MENU")
    print("   1. Add a Record")
    print("   2. Delete a Record")
    print("   3. Display All")
    print("   4. Exit")
    op = int(input("Input choice (1-4): "))
    return op

if __name__=="__main__":
    while True:
        match(menu):
            case 1:
                AddRec()
            case 2:
                DelRec()
            case 3:
                DispRec()
            case 4:
                break
            case _:
                print("Invalid Choice!")
