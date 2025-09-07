#include <iostream>
#include <string>
using namespace std;
#define MAX 6

struct List{
    int data[MAX];
    int last;
};

class ADTList{
private:
    List L;
    int locate(int x);
    bool isFull();
    bool isEmpty();
public:
    void add(int x);
    void del(int x);
    void display();
    void init();

};
int menu(){
    int op;
    cout<<"ADT LIst of structures"<<endl;
    cout<<"|\t1. Insert\t\t|\n|\t2. Delete\t\t|\n|\t3. Display\t\t|\n|\t4. Exit\t\t\t|\n";
    cout<<"Enter choice: ";
    cin>>op;
    return op;
}

int main()
{
    int x;
    ADTList ADT;
    ADT.init();
    while(true){
        switch(menu()){
            case 1:
                system("cls");
                cout<<"Input a number: ";
                cin>>x;
                ADT.add(x);
                break;
            case 2:
                system("cls");
                cout<<"Enter a number to delete: ";
                cin>>x;
                ADT.del(x);
                break;
            case 3:
                system("cls");
                ADT.display();
                break;
            case 4:
                cout<<"Exited Successfully"<<endl;
                return 0;
            default:
                cout<<"Enter 1-4 only!"<<endl;

        }
    }
    return 0;
}
void ADTList::init(){
    L.last=-1;
}
bool ADTList::isFull(){
    return (L.last==MAX-1);
}
bool ADTList::isEmpty(){
    return (L.last==-1);
}
int ADTList::locate(int x){
    for(int i =0;i<=L.last;i++){
        if(x == L.data[i])
            return i;
    }return -1;
}

void ADTList::add(int x){
    if(isFull()){
        cout<<"List is full"<<endl;
    }else{
        L.last++;
        L.data[L.last] = x;
        cout<<"Successfully added"<<endl;
        system("pause");
    }
}
void ADTList::del(int x){
    if(isEmpty()){
        cout<<"List is empty"<<endl;
    }else{
        int loc = locate(x);
        if(loc ==-1){
            cout<<"Not found"<<endl;
            system("pause");
        }else{
            for(int i = loc;i<=L.last;i++){
                L.data[i] = L.data[i+1];
            }
            cout<<"Integer deleted"<<endl;
            system("pause");
            L.last --;
        }
    }
}
void ADTList::display(){
    if(isEmpty()){
        cout<<"List is empty"<<endl;
    }else{
        for(int i = 0;i<= L.last;i++){
            cout<<"Name: " <<L.data[i]<<endl;
        }
    }
}
