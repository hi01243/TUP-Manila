#3 control structure : 1. Sequence 2. Decision 3. Iteratuib
#To implement these;
#Student Record program - Average, det. Passed or Failed

#Sequence

for i in range(1):
    name = input("Input name: ")
    q1 = int(input("Input Quiz 1: "))
    q2 = int(input("Input Quiz 2: "))
    q3 = int(input("Input Quiz 3: "))
    ave = (q1+q2+q3)/3

    print(f'Average = {ave:6.2f}')
    if ave>=75:
        print(f"{name} Passed")
        print("Bravo")
    else:
        print(f"{name} Failed")
        print("Malas")


students= []
record = {
    "name": "Gas Par",
    q1: 77,
    q2: 86,
    q3: 54
} 
students.append(record)
record = {
    "name": "Gas Par",
    q1: 77,
    q2: 86,
    q3: 54
} 
students.append(record)
