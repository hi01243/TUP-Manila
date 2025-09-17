#include <iostream>
using namespace std;


// Define a node structure for the linked list
struct List{
    int data;       // Data stored in the node
    List *next;     // Pointer to the next node in the list
};

// Class for Abstract Data Type Linked List
class ADTLink{
private:
    List *head;     // Pointer to the first node of the list (head)
public:
    void makeNull();   // Initialize the list (make it empty)
    void add(int x);   // Add an element at the end
    void del(int x);   // Delete a specific element
    void display();    // Display all elements
};

int menu(); // Function prototype for menu

int main(){
    ADTLink lst;   // Create a linked list object
    int d;         // Variable to hold user input
    lst.makeNull(); // Initialize list as empty

    // Infinite loop to show menu repeatedly
    while (true){
        switch(menu()){  // Get user choice
            case 1:
                system("cls"); // Clear screen
                cout<<"input x: "; cin>>d;
                lst.add(d); // Add element
                break;
            case 2:
                system("cls");
                cout<<"input x: "; cin>>d;
                lst.del(d); // Delete element
                break;
            case 3:
                system("cls");
                lst.display(); // Display all elements
                break;
            case 4:
                exit(0); // Exit program
            default:
                cout<<"Invalid input"<<endl;
                system("pause"); // Pause before retry
        }
    }
    return 0;
}

// Function to display menu options and return user's choice
int menu(){
    int op;
    cout <<"Menu\n";
    cout<<"1. Add\n";
    cout<<"2. Delete\n";
    cout<<"3. Display\n4. Exit\nEnter choice [1-4]: ";
    cin >> op;
    return op;
}

// Initialize the list (empty list = head points to NULL)
void ADTLink::makeNull(){
    head = NULL;
}

void ADTLink::add(int x){
    List *p,*q, *newNode;  // Temporary pointers
    p=q=head;              // Start traversal from head
    newNode = new List();  // Create a new node
    newNode->data = x;     // Assign data
    //newNode->data = x;     // (duplicate line, but does same thing)

    // Traverse until end of list
    while (p!=NULL){
        q=p;
        p=p->next;
    }

    // If list was empty, new node becomes head
    if (p==head)
        head = newNode;
    else{
        q->next = newNode; // Otherwise, attach at the end
    }

    newNode->next = p; // Next of new node is NULL
    cout<<x<<" was added successfully"<<endl;
    system("pause");
}

void ADTLink::del(int x){
    List *p,*q;   // Temporary pointers
    p=q=head;     // Start traversal from head

    // Traverse until data found or end of list
    while(p != NULL && x!=p ->data){
        q=p;
        p=p->next;
    }

    // If element not found
    if(p==NULL){
        cout<<"Not found\n";
        system("pause");
    }else{
        // If node to delete is the head
        if(p == head)
            head = p->next;
        else
            q->next = p -> next; // Link previous node to next node

        delete(p); // Free memory
        cout<<x<<" was deleted successfully"<<endl;
        system("pause");
    }
}

void ADTLink::display(){
    List *p;
    int i = 1;    // Counter for numbering
    p = head;     // Start from head
    system("cls");
    cout<<"List elements: \n";

    // Traverse list and print all nodes
    while (p!=NULL){
        cout<<i++<<".)"<<p->data<<endl;
        p=p->next;
    }
    system("pause");
}
