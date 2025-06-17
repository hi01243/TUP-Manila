#include <iostream>
using namespace std;

void swap1(int *a, int *b){//using pointers
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void swap2(int &a, int &b){//using reference
    int temp;
    temp = a;
    a = b;
    b = temp;
}

int main(){
    int x =15, y =23;
    swap1(&x,&y);
    cout<<"X = "<<x<<endl;
    cout<<"Y = "<<y<<endl;
    swap2(x,y);
    cout<<"X = "<<x<<endl;
    cout<<"Y = "<<y<<endl;


    return 0;
}
