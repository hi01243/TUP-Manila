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
                cout<<"Enter name: "; cin>>d.name;
                cout<<"Enter age: "; cin>>d.age;
                lst.add(d.name, d.age);
                break;
            case 2: // Delete person
                system("cls");
                cout<<"Enter name to delete: "; cin>>d.name;
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
    PersonNode *p,*q, *newNode;
    p=q=head;

    // Create new node
    newNode = new PersonNode();
    newNode->name = name;
    newNode->age = age;

    // Traverse to the end
    while (p!=NULL){
        q=p;
        p=p->next;
    }

    // If list is empty, new node is head
    if (p==head)
        head = newNode;
    else
        q->next = newNode;

    newNode->next = p; // p is NULL here
    cout<<name<<" (age "<<age<<") was added successfully"<<endl;
    system("pause");
}

// Delete a person by name
void PersonList::del(string name){
    PersonNode *p,*q;
    p=q=head;

    // Traverse list until found
    while(p != NULL && name!=p->name){
        q=p;
        p=p->next;
    }

    if(p==NULL){ // Not found
        cout<<"Person not found\n";
        system("pause");
    }else{
        // If deleting head
        if(p == head)
            head = p->next;
        else
            q->next = p->next;

        delete(p); // Free memory
        cout<<name<<" was deleted successfully"<<endl;
        system("pause");
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
