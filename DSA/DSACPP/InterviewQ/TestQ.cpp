

#include <iostream>

// Base class
class Base {
public:
    void sayHello() const {
        std::cout << "Hello from Base" << std::endl;
    }
};

// First derived class
class Derived1 : public Base {
};

// Second derived class
class Derived2 : public Base {
};

// Class with multiple inheritance
class Derived3 : public Derived1, public Derived2 {
};

int main() {
    Derived3 obj;
    // obj.sayHello();  
    // Error: Ambiguity due to diamond problem

    obj.Derived1::sayHello();  // Output: Hello from Base
    obj.Derived2::sayHello();  // Output: Hello from Base

    return 0;
}

/*

Virtual Inheritance Solution:
C++ provides virtual inheritance to resolve the diamond problem
 by ensuring only one instance of the common base class is inherited.
*/

// #include <iostream>

// // Base class
// class Base {
// public:
//     void sayHello() const {
//         std::cout << "Hello from Base" << std::endl;
//     }
// };

// // First derived class
// class Derived1 : virtual public Base {
// };

// // Second derived class
// class Derived2 : virtual public Base {
// };

// // Class with multiple inheritance
// class Derived3 : public Derived1, public Derived2 {
// };

// int main() {
//     Derived3 obj;
//     obj.sayHello();  // Output: Hello from Base

//     return 0;
// }