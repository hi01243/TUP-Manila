#include <iostream>
#include <iomanip>
#include <string.h>
using namespace std;

#define MAX 5
struct rec{
    string name;
    int q1,q2,q3;
};
rec student[MAX];
int last = -1;
int menu();
void display();
float comAve(int q1,int q2,int q3);
void add(rec s);
bool isFul();
bool isEmp();
int locate(string n);
int isDup(string n);
void del(string n);
void upd(string n);

int main(){
    rec temp;
    while(1){
        switch(menu()){
        system("cls");
        case 1:
            cin.ignore(); system("cls");
            cout <<"======================"<<endl;
            cout <<"|    ADD A RECORD    |"<<endl;
            cout <<"======================"<<endl;
            cout<<"Input name: "; getline(cin,temp.name);
            if(isDup(temp.name)==0){
                cout<<"Student Already Recorded!"<<endl;
                system("pause");
                break;
            }
            cout<<"Input Quiz 1 score: "; cin>> temp.q1;
            cout<<"Input Quiz 2 score: "; cin>> temp.q2;
            cout<<"Input Quiz 3 score: "; cin>> temp.q3;
            add(temp); break;
        case 2:
            cin.ignore(); system("cls");
            cout<<"Input name: "; getline(cin,temp.name);
            if(locate(temp.name)==-1){
                system("pause"); break; }
            upd(temp.name);
            break;
        case 3:
            system("cls");
            cin.ignore();
            cout<<"Input name: "; getline(cin,temp.name);
            if(locate(temp.name)==-1){
                cout <<"No record yet."<<endl;
                system("pause");
                break;
                }
            del(temp.name); break;
        case 4:
            system("cls");
            if(isEmp() == true){
                cout <<"No record yet"<<endl;
                system("pause");
                break;
            }
            display(); system("pause"); system("cls"); break;
        case 5:
            system("cls");
            cout<<"Exited Successfully"<<endl;
            exit(0);
        default:
            cout<<"Input 1-5 only!"<<endl;
            system("pause");
        }
    }

    return 0;
}

int menu(){
    int op;
    cout <<"=========================="<<endl;
    cout <<"|STUDENT RECORD using CPP|"<<endl;
    cout <<"=========================="<<endl;
    cout <<"1. Add a record"<<endl;
    cout <<"2. Update a record"<<endl;
    cout <<"3. Delete a record"<<endl;
    cout <<"4. Display All"<<endl;
    cout <<"5. Exit"<<endl;
    cout <<"--------------------------"<<endl;
    cout <<"Enter 1-5: ";
    cin >> op;
    return op;
}
void display(){
    float ave;
    system("cls");
    cout <<"================================================================="<<endl;
    cout<<setw(10)<<left<<"NAME"<<setw(12)<<right<<"Quiz 1"<<setw(10)<<right<<"Quiz 2"<<setw(10)<<right<<"Quiz 3"<<setw(10)<<right<<"Average"<<setw(10)<<right<<"Remarks"<<endl;
    cout <<"================================================================="<<endl;
    for (int i = 0; i <=last; i++){
        ave = comAve(student[i].q1,student[i].q2,student[i].q3);
        cout<<i+1<<".) "<<setw(13)<<left<<student[i].name<<setw(10)<<left<<student[i].q1<<setw(10)<<left<<student[i].q2<<setw(10)<<left<<student[i].q3<<setw(10)<<left<<setprecision(2)<<ave<<setw(10)<<left<<(ave >= 75? "Passed":"Failed")<<endl;
    }
}
float comAve(int q1,int q2,int q3){
    return (q1+q2+q3)/3.0;
}
bool isFul(){
    if(last == MAX-1)
        return true;
    return false;
}
bool isEmp(){
    if(last==-1)
        return true;
    return false;
}
int locate(string n){
    for (int i = 0; i <= last; i++){
        if(n == student[i].name)
            return i;
    }return -1;
}
int isDup(string n){
    if(locate(n) != -1)
        return 0;
    else return -1;
}
void add(rec s){
    if(isFul()){
        cout<<"Record is full"<<endl;
        system("pause");
    }else{
        last ++;
        student[last] = s;
        cout<<"-------------------------------------------"<<endl;
        cout<<"Record of "<<s.name<<" was successfully recorded"<<endl;
        system("pause");
        system("cls");
    }
}
void del(string n){
    int p = locate(n),i;
    for (i = p; i <=last; i++){
        student[i] = student[i+1];
    }
    last --;
    cout<<"Record of "<<n<<" was successfully deleted."<<endl;
    system("pause");
    system("cls");
}
void upd(string n){
    int p = locate(n),i, c;
    system("cls");
    cout << "========================================"<<endl;
    cout << "|             UPDATE A RECORD           |"<<endl;
    cout << "========================================"<<endl;
    cout << "----------------------------------------"<<endl;
    if(c == 1){
        cout << "Enter score: "; cin>> student[p].q1;
        cout << "----------------------------------------"<<endl;
        cout << "Updated Successfully" <<endl;
        cout << "----------------------------------------"<<endl;
    }else if(c==2){
        cout << "Enter score: "; cin>> student[p].q2;
        cout << "----------------------------------------"<<endl;
        cout << "Updated Successfully" <<endl;
        cout << "----------------------------------------"<<endl;
    }else if(c== 3){
        cout << "Enter score: "; cin>> student[p].q3;
        cout << "----------------------------------------"<<endl;
        cout << "Updated Successfully" <<endl;
        cout << "----------------------------------------"<<endl;
    }else{ cout<< "Invalid input."<<endl; system("pause");system("cls");}
}


