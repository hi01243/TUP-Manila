#include <iostream>
#include <string>
#include <fstream>
#define MAX 6
using namespace std;

struct Record {
    string name;
    int age;
};

struct List {
    Record person[MAX];
    int last;
};

class ADTList {
private:
    List L;
    int locate(string x);
    bool isFull();
    bool isEmpty();
public:
    void add(Record x);
    void init();
    void del(string x);
    void display();
    void save();
    void retrieve();
};

int menu() {
    int op;
    cout << "ADT List of structures" << endl;
    cout << "|\t1. Insert\t\t|\n|\t2. Delete\t\t|\n|\t3. Display\t\t|\n|\t4. Exit\t\t\t|\n";
    cout << "Enter choice: ";
    cin >> op;
    return op;
}

int main() {
    ADTList ADT;
    ADT.init();
    ADT.retrieve();

    while (true) {
        switch (menu()) {
        case 1: {
            system("cls");
            Record r;
            cin.ignore();
            cout << "Enter name: ";
            getline(cin, r.name);
            cout << "Enter age: ";
            cin >> r.age;
            ADT.add(r);
            ADT.save();
            break;
        }
        case 2: {
            system("cls");
            cin.ignore();
            string name;
            cout << "Enter name to delete: ";
            getline(cin, name);
            ADT.del(name);
            ADT.save();
            break;
        }
        case 3: {
            system("cls");
            ADT.display();
            system("pause");
            break;
        }
        case 4: {
            cout << "Exited successfully" << endl;
            ADT.save();
            return 0;
        }
        default: {
            cout << "Input 1-4 only" << endl;
        }
        }
    }
    return 0;
}

bool ADTList::isFull() {
    return L.last == MAX - 1;
}
bool ADTList::isEmpty() {
    return L.last == -1;
}
int ADTList::locate(string x) {
    for (int i = 0; i <= L.last; i++) {
        if (x == L.person[i].name)
            return i;
    }
    return -1;
}
void ADTList::init() {
    L.last = -1;
}
void ADTList::add(Record x) {
    if (isFull()) {
        cout << "List is full" << endl;
        system("pause");
    }
    else {
        L.last++;
        L.person[L.last] = x;
        cout << "Record added" << endl;
        system("pause");
    }
}
void ADTList::del(string x) {
    if (isEmpty()) {
        cout << "List is empty" << endl;
        system("pause");
    }
    else {
        int temp = locate(x);
        if (temp == -1) {
            cout << "Not found" << endl;
            system("pause");
        }
        else {
            for (int i = temp; i < L.last; i++) {
                L.person[i] = L.person[i + 1];
            }
            cout << "Successfully deleted" << endl;
            system("pause");
            L.last--;
        }
    }
}

void ADTList::display() {
    if (isEmpty()) {
        cout << "List is empty" << endl;
    }
    else {
        for (int i = 0; i <= L.last; i++) {
            cout << "Name: " << L.person[i].name
                << "\tAge: " << L.person[i].age << endl;
        }
    }
}


void ADTList::save() {
    ofstream fout("records.txt");
    if (!fout) {
        cout << "Error opening file for writing!" << endl;
        return;
    }
    fout << L.last << endl;
    for (int i = 0; i <= L.last; i++) {
        fout << L.person[i].name << endl;
        fout << L.person[i].age << endl;
    }
    fout.close();
}


void ADTList::retrieve() {
    ifstream fin("records.txt");
    if (!fin) return;
    fin >> L.last;
    fin.ignore();
    for (int i = 0; i <= L.last; i++) {
        getline(fin, L.person[i].name);
        fin >> L.person[i].age;
        fin.ignore();
    }
    fin.close();
}
