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

class Student_Record:
    def __init__(self, filename="Record.txt"):
        self.records = []
        self.filename = filename
        self.load_records()
    def AddRec():
        
    def UpdRec():

    def DelRec():

    def DispRec():


    def menu():
        print("Student Record Program using python")
        print("MENU")
        print("   1. Add a Record")
        print("   2. Update Record")
        print("   3. Delete a Record")
        print("   4. Display All")
        print("   5. Exit")
        op = int(input("Input choice (1-5): "))
        return op

if __name__=="__main__":
    while True:
        match(menu):
            case 1:

                AddRec()
            case 2:
                UpdRec()
            case 3:
                DelRec()
            case 4:
                DispRec()
            case 5:
                break
            case _:
                print("Invalid Choice!")
