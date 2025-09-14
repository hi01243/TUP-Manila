#include <iostream>
#include <string>
using namespace std;

// Node structure representing a person
struct PersonNode {
    string name;         // Person's name
    int age;             // Person's age
    PersonNode *next;    // Pointer to the next node
};

// A simple struct just for holding input data (like d.name, d.age)
struct Person {
    string name;
    int age;
};

// Class for linked list of persons
class PersonList {
private:
    PersonNode *head; // Pointer to the first person in the list
public:
    void makeNull();                         // Initialize the list as empty
    void add(string name, int age);          // Add a person at the end
    void del(string name);                   // Delete a person by name
    void display();                          // Display all persons
};

int menu();

int main(){
    PersonList lst;   // Create linked list object
    Person d;         // Temporary Person object for user input
    lst.makeNull();   // Initialize empty list

    while (true){
        switch(menu()){
            case 1: // Add person
                system("cls");
                cin.ignore();
                cout<<"Enter name: "; getline(cin,d.name);
                cout<<"Enter age: "; cin>>d.age;
                lst.add(d.name, d.age);
                break;
            case 2: // Delete person
                system("cls");
                cin.ignore();
                cout<<"Enter name to delete: "; getline(cin,d.name);
                lst.del(d.name);
                break;
            case 3: // Display all persons
                system("cls");
                lst.display();
                break;
            case 4: // Exit program
                exit(0);
            default:
                cout<<"Invalid input"<<endl;
                system("pause");
        }
    }
    return 0;
}

// Display the menu and return choice
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

// Initialize list (head points to NULL)
void PersonList::makeNull(){
    head = NULL;
}

// Add a new person to the end of the list
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

// Delete a person by name
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

}

// Display all persons
void PersonList::display(){
    PersonNode *p;
    int i = 1;
    p = head;
    cout<<"List of persons: \n";

    // Traverse list and print
    while (p!=NULL){
        cout<<i++<<".) Name: "<<p->name<<", Age: "<<p->age<<endl;
        p=p->next;
    }
    system("pause");
}
