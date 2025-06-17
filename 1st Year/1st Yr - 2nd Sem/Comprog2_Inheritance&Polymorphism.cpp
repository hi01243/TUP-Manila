#include <iostream>
using namespace std;

class Animal {
public:
    virtual void makeSound(){
        cout <<"Animal sound"<<endl;
    }
};

class Dog : public Animal{
public:
    void makeSound()

};

class Dog : public Animal{
public:
    void makeSound()override

};

void makeSound(Animal &a){
    a.makeSound();
}

int main(){
    Animal *a;
    Dog d;
    a = &d;
    a -> makeSound();
    Cat c;
    makeSound(c);

    return 0;
}

