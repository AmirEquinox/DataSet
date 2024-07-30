#include <iostream>

 class Animal 
 {
    public:
    virtual void makesound()
    {
        std::cout << "General Sound" << std::endl;
    }
 };

 class Dog : public Animal
 {
    public:
    void makesound() override
    {
        std::cout<< "bark"<<std::endl;
    }
    
 };


 int main(){
    Animal* myAnim = new Dog();
    myAnim->makesound();

    return 0;
 }