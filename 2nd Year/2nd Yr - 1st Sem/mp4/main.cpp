#include <iostream>
#include <string>
using namespace std;

struct Person {
    string name;
    int age;
};

struct PersonNode {
    Person data;
    PersonNode *next;
};

class PersonList {
private:
    PersonNode *head;
public:
    void makeNull();
    void add(Person x);
    void del(string name);
    void display();
};

int menu();

int main(){
    PersonList lst;
    Person d;
    lst.makeNull();

    while (true){
        switch(menu()){
            case 1:
                system("cls");
                cin.ignore();
                cout<<"Enter name: "; getline(cin,d.name);
                cout<<"Enter age: "; cin>>d.age;
                lst.add(d);
                break;
            case 2:
                system("cls");
                cin.ignore();
                cout<<"Enter name to delete: "; getline(cin,d.name);
                lst.del(d.name);
                break;
            case 3:
                system("cls");
                lst.display();
                break;
            case 4:
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

void PersonList::add(Person x){
    PersonNode *newNode = new PersonNode{x, nullptr};
    if (!head){
        head = newNode;
    }else{
        PersonNode *p = head;
        while (p->next)
            p=p->next;
        p->next = newNode;
    }
}

void PersonList::del(string name){
    if(!head){
        cout<<"List is empty"<<endl;
        system("pause");
        return;
    }

    if(head->data.name == name){
        PersonNode *temp = head;
        head = head->next;
        delete temp;
        cout <<name<<" was deleted successfully"<<endl;
        system("pause");
        return;
    }

    PersonNode *p = head;
    while(p->next && p->next->data.name != name)
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
    if (!head){
        cout<<"List is empty"<<endl;
    } else {
        PersonNode *p = head;
        int i = 1;
        cout<<"List of persons: \n";
        while (p!=NULL){
            cout<<i++<<".) Name: "<<p->data.name<<", Age: "<<p->data.age<<endl;
            p=p->next;
        }
    }
    system("pause");
}
