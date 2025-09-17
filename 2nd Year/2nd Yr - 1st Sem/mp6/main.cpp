 #include <iostream>
#include <string>
#include <fstream>
using namespace std;

struct Person {
    string name;
    int age;
};

struct List {
    Person data;
    List *next;
};

class ADTLink {
private:
    List *head;
public:
    void makeNull();
    void add(Person x);
    void del(string name);
    void display();
    void save();
    void retrieve();
    void update(string x);
};

int menu();

int main() {
    ADTLink adt;
    Person d;
    adt.makeNull();
    adt.retrieve();

    while (true) {
        switch(menu()) {
            case 1:
                system("cls");
                cin.ignore();
                cout << "Enter name: "; getline(cin, d.name);
                cout << "Enter age: "; cin >> d.age;
                adt.add(d);
                adt.save();
                break;
            case 2:
                system("cls");
                cin.ignore();
                cout << "Enter name to delete: "; getline(cin, d.name);
                adt.del(d.name);
                adt.save();
                break;
            case 3:
                cin.ignore();system("cls");
                cout<<"Enter name to update their age: "; getline(cin,d.name);
                adt.update(d.name); adt.save(); break;

            case 4:
                system("cls");
                adt.display();
                break;
            case 5:
                adt.save();
                exit(0);
            default:
                cout << "Invalid input" << endl;
                system("pause");
        }
    }
    return 0;
}

int menu() {
    system("cls");
    int op;
    cout << "Menu\n";
    cout << "1. Add Person\n";
    cout << "2. Delete Person\n";
    cout << "3. Update Record\n4. Display List\n";
    cout << "5. Exit\nEnter choice [1-4]: ";
    cin >> op;
    return op;
}

void ADTLink::makeNull() {
    head = NULL;
}

void ADTLink::add(Person x) {
    List *newNode = new List;
    newNode->data = x;
    newNode ->next = NULL;
    if (!head) {
        head = newNode;
    } else {
        List *p = head;
        while (p->next)
            p = p->next;
        p->next = newNode;
    }
}

void ADTLink::del(string name) {
    if (!head) {
        cout << "List is empty" << endl;
        system("pause");
        return;
    }

    if (head->data.name == name) {
        List *temp = head;
        head = head->next;
        delete temp;
        cout << name << " was deleted successfully" << endl;
        system("pause");
        return;
    }

    List *p = head;
    while (p->next && p->next->data.name != name)
        p = p->next;

    if (!p->next) {
        cout << "Person not found" << endl;
    } else {
        List *temp = p->next;
        p->next = temp->next;
        delete temp;
        cout << name << " was deleted successfully" << endl;
    }
    system("pause");
}

void ADTLink::display() {
    if (!head) {
        cout << "List is empty" << endl;
    } else {
        List *p = head;
        int i = 1;
        cout << "List of persons: \n";
        while (p != NULL) {
            cout << i++ << ".) Name: " << p->data.name << ", Age: " << p->data.age << endl;
            p = p->next;
        }
    }
    system("pause");
}

void ADTLink::save() {
    ofstream fout("records.txt");
    if (!fout) {
        cout << "Error opening file for writing!" << endl;
        return;
     }
    List *p = head;
    while (p) {
        fout << p->data.name << "\n" << p->data.age << "\n";
        p = p->next;
    }
    fout.close();
}

void ADTLink::retrieve() {
    ifstream fin("records.txt");
    if (!fin) return;

    makeNull();
    string name;
    int age;
    while (getline(fin, name)) {
        if (!(fin >> age)) break;
        fin.ignore();
        Person d{name, age};
        add(d);
    }
    fin.close();
}

void ADTLink::update(string x){
    if (!head) {
        cout << "List is empty" << endl;
        system("pause");
        return;
    }

    List *p = head;
    while (p->next && p->next->data.name != x)
        p = p->next;

    if (!p->next) {
        cout << "Person not found" << endl;
    } else {
        char c;
        cout<<"Age: "<<p->next->data.age<<endl;
        cout<<"Do you want to continue (Y\\N)? "; cin>>c; system("cls");
        while(true){
            switch(c){
            case 'Y':
                    int age;
                    cout<<"Input new age: "; cin>>age;
                    p->next->data.age = age;
                    cout<<x<<" was successfully updated"<<endl;
                    system("pause"); return;
            case 'N':
                system("cls"); cout<<"Edi don't"<<endl;
                system("pause"); system("cls");return;
            default: cout<<"Invalid input"<<endl;
            }
        }
    }

}

