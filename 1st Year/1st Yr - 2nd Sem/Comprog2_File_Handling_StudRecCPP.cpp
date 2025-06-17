#include <iostream>
#include <iomanip>
#include <cstring>
#include <fstream>
#include <string>
using namespace std;
#define MAX 50
int last =-1;
struct Record{
    string Name;
    int Quiz1,Quiz2,Quiz3;
};

class Student{
protected:
    Record Student[MAX];
    bool isFul();
    int Locate(string n);
    float ComAve(int q1,int q2,int q3);
public:
    int init = -1;
    void AddRec(Record S);
    void DelRec(string n);
    void DisplayAll();
    void Save();
    void Retrieve();
    int isDup(string n);
    bool isEmp();
};

int Menu();

int main(){
    Record student;
    Student student1;
    student1.Retrieve();
    while (1){
        switch(Menu()){
        case 1:
            system("cls");
            cout <<"======================"<<endl;
            cout <<"|    ADD A RECORD    |"<<endl;
            cout <<"======================"<<endl;
            cin.ignore();
            cout<<"Enter name: ";getline(cin,student.Name);
            if(student1.isDup(student.Name)==0){
                cout<<student.Name<<" is already recorded."<<endl;
                system("pause");break;}
            cout<<"\nEnter quiz 1 score: ";cin>>student.Quiz1;
            cout<<"\nEnter quiz 2 score: ";cin>>student.Quiz2;
            cout<<"\nEnter quiz 3 score: ";cin>>student.Quiz3;
            student1.AddRec(student);system("cls");break;
        case 2:
            system("cls");
            cin.ignore();
            if(student1.isEmp()){
                cout<<"Record is empty."<<endl;
                system("pause");break;
            }
            cout<<"Enter name: ";getline(cin,student.Name);
            if(student1.isDup(student.Name)){
            cout<<"No record yet"<<endl;
            system("pause");break;
            }
            student1.DelRec(student.Name);system("pause");system("cls");break;
        case 3:
            system("cls");
            if(student1.isEmp()==true){
                cout<<"No record yet."<<endl;
                system("pause");break;
            }
            student1.DisplayAll();system("pause");break;
        case 4: cout <<"Exited Successfully"<<endl; student1.Save(); exit(0);
        default: cout<<"Enter (1-4) only!"<<endl; system("pause");
        }

    }
    return 0;
}

int Student::Locate(string n){
    int i;
    for(i = 0; i <= last; i++){
        if(n == Student[i].Name)
            return i;
    }return -1;
}
int Student::isDup(string n){
    return (Locate(n) == -1)? 1:0;
}
bool Student::isFul(){
    if(last == MAX -1)
    return true;
    return false;
}
bool Student::isEmp(){
    if(last == -1)
    return true;
    return false;
}
float Student::ComAve(int q1,int q2,int q3){
    return(q1+q2+q3)/3.0;
}

void Student::AddRec(Record s){
    if(isFul())
        cout<<"Student record is full"<<endl;
    else{
    last++;
    Student[last]=s;
    cout<<"-------------------------------------------"<<endl;
    cout<<"Record of "<<s.Name<<" was successfully inputted"<<endl;
    system("pause");
    }
}
void Student::DelRec(string n){
    int p = Locate(n),i;
    for(i = p;i<=last;i++){
    Student[i] = Student[i+1];
    }
    last --;
    cout<<"Record of "<<n<<" was successfully deleted."<<endl;
}
void Student::DisplayAll(){
    float ave;
    system("cls");
    cout <<"================================================================="<<endl;
    cout<<setw(10)<<left<<"NAME"<<setw(12)<<right<<"Quiz 1"<<setw(10)<<right<<"Quiz 2"<<setw(10)<<right<<"Quiz 3"<<setw(10)<<right<<"Average"<<setw(10)<<right<<"Remarks"<<endl;
    cout <<"================================================================="<<endl;
    for (int i = 0; i <=last; i++){
        ave = ComAve(Student[i].Quiz1,Student[i].Quiz2,Student[i].Quiz3);
        cout<<i+1<<".) "<<setw(13)<<left<<Student[i].Name<<setw(10)<<left<<Student[i].Quiz1<<setw(10)<<left<<Student[i].Quiz2<<setw(10)<<left<<Student[i].Quiz3<<setw(10)<<left<<fixed<<setprecision(2)<<ave<<setw(10)<<left<<(ave >= 75? "Passed":"Failed")<<endl;
    }
}

int Menu(){
    int op;
    cout<<"============"<<endl;
    cout<<"|---MENU---|"<<endl;
    cout<<"============"<<endl;
    cout<<"1. Add a Record\n2. Delete a Record\n3. Display All Records\n4. Save and Exit\nEnter (1-4): ";
    cin>>op;
    return op;
}
void Student::Save(){
    fstream rec;
    rec.open("Student_Record.txt",ios::out);
    if(rec.is_open()){
        for(int i = 0; i <=last;i++){
            rec << Student[i].Name<<"\n"
                << Student[i].Quiz1 <<" "
                << Student[i].Quiz2 <<" "
                << Student[i].Quiz3 << endl;
        }
    }rec.close();
}
void Student::Retrieve() {
    fstream rec("Student_Record.txt", ios::in);
    last = -1;

    while (true) {
        string name;
        int q1, q2, q3;
        if (!getline(rec, name)) break;
        if (!(rec >> q1 >> q2 >> q3)) break;
        rec.ignore();
        Student[++last] = {name, q1, q2, q3};
    }
    rec.close();
}
