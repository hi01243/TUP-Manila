#include <iostream>
#include <string>
#include <fstream>
using namespace std;


struct PersonNode {
    string name;
    int age;
    PersonNode *next;
};


struct Person {
    string name;
    int age;
};


class PersonList {
private:
    PersonNode *head;
public:
    void makeNull();
    void add(string name, int age);
    void del(string name);
    void display();
    void save();
    void retrieve();
};

int menu();

int main(){
    PersonList lst;
    Person d;
    lst.makeNull();
    lst.retrieve();

    while (true){
        switch(menu()){
            case 1:
                system("cls");
                cin.ignore();
                cout<<"Enter name: "; getline(cin,d.name);
                cout<<"Enter age: "; cin>>d.age;
                lst.add(d.name, d.age);
                lst.save();
                break;
            case 2:
                system("cls");
                cin.ignore();
                cout<<"Enter name to delete: "; getline(cin,d.name);
                lst.del(d.name);
                lst.save();
                break;
            case 3:
                system("cls");
                lst.display();
                break;
            case 4:
                lst.save();
                exit(0);
            default:
                cout<<"Invalid input"<<endl;
                system("pause");
        }
    }
    return 0;
}


int menu(){
    int op;
    cout <<"Menu\n";
    cout<<"1. Add Person\n";
    cout<<"2. Delete Person\n";
    cout<<"3. Display List\n";
    cout<<"4. Exit\nEnter choice [1-4]: ";
    cin >> op;
    return op;
}


void PersonList::makeNull(){
    head = NULL;
}


void PersonList::add(string name, int age){
    PersonNode *newNode = new PersonNode{name,age,nullptr};
    if (!head){
        head = newNode;
    }else{
        PersonNode *p = head;
        while (p->next)
            p=p->next;
        p -> next = newNode;
    }
}


void PersonList::del(string name){
    if(!head){
        cout<<"List is empty"<<endl;
        system("pause");
        return;
    }

    if(head->name == name){
        PersonNode *temp = head;
        head = head->next;
        delete temp;
        cout <<name<<" was deleted successfully"<<endl;
        system("pause");
        return;
    }
    PersonNode *p = head;
    while(p->next && p->next->name != name)
        p = p->next;
    if(!p->next){
        cout<<"Person not found"<<endl;
    }
    else{
        PersonNode *temp = p->next;
        p->next = temp->next;
        delete temp;
        cout<<name<<" was deleted successfully"<<endl;
    }
    system("pause");
}


void PersonList::display(){
    if(!head){
        cout<<"List is empty"<<endl;
    } else {
        PersonNode *p = head;
        int i = 1;
        cout<<"List of persons: \n";
        while (p!=NULL){
            cout<<i++<<".) Name: "<<p->name<<", Age: "<<p->age<<endl;
            p=p->next;
        }
    }
    system("pause");
}

void PersonList::save(){
    ofstream fout("persons.txt");
    if(!fout){
        cout<<"Error opening file for writing!"<<endl;
        return;
    }
    PersonNode *p = head;
    while(p){
        fout<<p->name<<"\n"<<p->age<<"\n";
        p=p->next;
    }
    fout.close();
}


void PersonList::retrieve(){
    ifstream fin("persons.txt");
    if(!fin) return;

    makeNull();
    string name;
    int age;
    while(getline(fin,name)){
        if(!(fin>>age)) break;
        fin.ignore();
        add(name,age);
    }
    fin.close();
}
