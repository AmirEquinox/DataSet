#include <iostream>

// Base class
class Animal {
public:
    virtual void makeSound() const {
        std::cout << "Some generic animal sound" << std::endl;
    }
};

// Derived class
class Dog : public Animal {
public:
    void makeSound() const override {
        std::cout << "Bark" << std::endl;
    }
};

int main() {
    Animal* myAnimal = new Dog();
    myAnimal->makeSound();  // Output: Bark

    // Obj
    Animal Anim ;
    Anim.makeSound();

    delete myAnimal;
    return 0;
}

------------------------------------------------------------
#include <iostream>
template <typename T>
T add(T a, T b) {
    return a + b;
}

int main() {
    std::cout << add(5, 10) << std::endl;        // Output: 15
    std::cout << add(5.5, 10.3) << std::endl;    // Output: 15.8
    return 0;
}


 
------------------------------------------------------------

#include <iostream>
#include <stdexcept>

int divide(int a, int b) {
    if (b == 0) {
        throw std::invalid_argument("Division by zero");
    }
    return a / b;
}

int main() {
    try {
        std::cout << divide(10, 0) << std::endl;
    } catch (const std::invalid_argument& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    return 0;
}

------------------------------------------------------------

#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::vector<int> numbers = {3, 1, 4, 1, 5, 9, 2};
    std::sort(numbers.begin(), numbers.end());

    std::cout << "Sorted numbers: ";
    for (int num : numbers) {
        std::cout << num << " ";
    }
    std::cout << std::endl; // Output: 1 1 2 3 4 5 9

    return 0;
}


------------------------------------------------------------

#include <iostream>

int main() {
    int* ptr = new int(10);  // Allocate memory
    std::cout << *ptr << std::endl;  // Output: 10

    delete ptr;  // Free memory
    ptr = nullptr;

    return 0;
}


------------------------------------------------------------


#include <iostream>
#include <fstream>
#include <stdexcept>

// RAII class for file handling 
class FileHandle { 
public:
    FileHandle(const std::string& filename) { 
        file.open(filename);
        if ( !file.is_open() ) {
            throw std::runtime_error("Failed to open file");
        }
    }

    ~FileHandle() {
        if (file.is_open()) {
            file.close();
        }
    }

    std::ifstream& getFile() {
        return file;
    }

private:
    std::ifstream file;
};

int main() {
    try {
        FileHandle file("example.txt");
        std::string line;
        while (std::getline(file.getFile(), line)) {
            std::cout << line << std::endl;
        }
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}

------------------------------------------------------------
#include <iostream>

// Base class
class Shape {
public:
    virtual void draw() const {
        std::cout << "Drawing a generic shape" << std::endl;
    }

    virtual ~Shape() = default;
};

// Derived class
class Circle : public Shape {
public:
    void draw() const override {
        std::cout << "Drawing a circle" << std::endl;
    }
};

// Another derived class
class Rectangle : public Shape {
public:
    void draw() const override {
        std::cout << "Drawing a rectangle" << std::endl;
    }
};

int main() {
    Shape* shape1 = new Circle();
    Shape* shape2 = new Rectangle();

    shape1->draw();  // Output: Drawing a circle
    shape2->draw();  // Output: Drawing a rectangle

    delete shape1;
    delete shape2;

    return 0;
}



------------------------------------------------------------

/*
 
Key Features of C++
C++ is a powerful programming language that supports a wide range of features, making it suitable for various applications,
 from system programming to game development. Here are some key features:

1. Object-Oriented Programming (OOP)
Classes and Objects: C++ supports defining classes that encapsulate data and functions. Objects are instances of these classes.

Encapsulation: It allows bundling data and functions that operate on the data within a single unit (class).

Inheritance: C++ enables creating new classes based on existing ones, promoting code reuse.

Polymorphism: It supports polymorphism, allowing objects to be treated as instances of their parent class.

Example:--
 
*/
#include <iostream>

// Base class
class Animal {
public:
    virtual void makeSound() const {
        std::cout << "Some generic animal sound" << std::endl;
    }
};

// Derived class
class Dog : public Animal {
public:
    void makeSound() const override {
        std::cout << "Bark" << std::endl;
    }
};

int main() {
    Animal* myAnimal = new Dog();
    myAnimal->makeSound();  // Output: Bark

    delete myAnimal;
    return 0;
}
 
Explanation:
Virtual Functions: The draw() function in the base class Shape is declared as a virtual function, allowing derived classes to override it.
Vtables: At runtime, C++ uses a virtual table (vtable) to determine which function to call, enabling polymorphic behavior.
Runtime Polymorphism: The draw() function call is determined at runtime, allowing the correct function to be called based on the object's type.
What is the Difference Between Deep Copy and Shallow Copy in C++?
Explanation:
In C++, copying an object can be done in two ways: shallow copy and deep copy. The difference between them lies in how they handle dynamic memory allocation.

Shallow Copy: Copies the object's top-level memory. If the object contains pointers, only the pointers are copied, not the data they point to. This can lead to issues if one of the objects modifies the data, as both objects will share the same memory.

Deep Copy: Duplicates the entire object, including the dynamically allocated memory. Each object has its own copy of the data, avoiding shared memory issues.

Example:
cpp
Copy code
#include <iostream>
#include <cstring>

class MyString {
public:
    MyString(const char* str) {
        size_t length = std::strlen(str) + 1;
        data = new char[length];
        std::strcpy(data, str);
    }

    // Copy constructor (deep copy)
    MyString(const MyString& other) {
        size_t length = std::strlen(other.data) + 1;
        data = new char[length];
        std::strcpy(data, other.data);
    }

    // Assignment operator (deep copy)
    MyString& operator=(const MyString& other) {
        if (this == &other) {
            return *this;
        }
        delete[] data;
        size_t length = std::strlen(other.data) + 1;
        data = new char[length];
        std::strcpy(data, other.data);
        return *this;
    }

    ~MyString() {
        delete[] data;
    }

    void print() const {
        std::cout << data << std::endl;
    }

private:
    char* data;
};

int main() {
    MyString str1("Hello");
    MyString str2 = str1;  // Deep copy

    str1.print();  // Output: Hello
    str2.print();  // Output: Hello

    return 0;
}
Explanation:
Deep Copy: The copy constructor and assignment operator perform a deep copy by allocating new memory and copying the data.
Separate Memory: Each MyString object has its own copy of the data, preventing shared memory issues.
Describe the Use of Smart Pointers in C++
Explanation:
Smart pointers are a feature in C++ that helps manage memory automatically, reducing the risk of memory leaks and dangling pointers. They are part of the C++ Standard Library and provide a safer alternative to raw pointers.

std::unique_ptr: A smart pointer that owns a resource and ensures that the resource is deallocated when the std::unique_ptr goes out of scope. It doesn't allow copying but can be moved.

std::shared_ptr: A smart pointer that allows multiple pointers to share ownership of a resource. The resource is deallocated when the last std::shared_ptr is destroyed.

std::weak_ptr: A smart pointer that doesn't own the resource but can observe it. It's used to break circular references that can occur with std::shared_ptr.

Example:
cpp
Copy code
#include <iostream>
#include <memory>

// Example class
class Resource {
public:
    Resource() {
        std::cout << "Resource acquired" << std::endl;
    }
    ~Resource() {
        std::cout << "Resource released" << std::endl;
    }
    void sayHello() const {
        std::cout << "Hello, Resource!" << std::endl;
    }
};

int main() {
    // Using std::unique_ptr
    std::unique_ptr<Resource> uniquePtr = std::make_unique<Resource>();
    uniquePtr->sayHello();  // Output: Hello, Resource!

    // Using std::shared_ptr
    std::shared_ptr<Resource> sharedPtr1 = std::make_shared<Resource>();
    std::shared_ptr<Resource> sharedPtr2 = sharedPtr1;  // Shared ownership
    sharedPtr1->sayHello();  // Output: Hello, Resource!
    sharedPtr2->sayHello();  // Output: Hello, Resource!

    // Using std::weak_ptr
    std::weak_ptr<Resource> weakPtr = sharedPtr1;
    if (auto lockedPtr = weakPtr.lock()) {  // Check if resource is still available
        lockedPtr->sayHello();  // Output: Hello, Resource!
    } else {
        std::cout << "Resource is no longer available" << std::endl;
    }

    return 0;
}
Explanation:
std::unique_ptr: Manages a single instance of a resource, ensuring it is deallocated when the std::unique_ptr goes out of scope. It doesn't allow copying, ensuring unique ownership.
std::shared_ptr: Manages shared ownership of a resource, deallocating the resource only when the last std::shared_ptr is destroyed.
std::weak_ptr: Observes a resource managed by std::shared_ptr, providing a way to access the resource without affecting its lifetime.
Explain the Significance of the const Keyword in C++
Explanation:
The const keyword in C++ is used to define immutable variables, function arguments, and member functions that don't modify the object's state. It helps enforce const-correctness, ensuring that functions don't inadvertently modify data they shouldn't.

Example:
cpp
Copy code
#include <iostream>

// Function with const argument
void printMessage(const std::string& message) {
    std::cout << message << std::endl;
}

// Class with const member function
class Circle {
public:
    Circle(double r) : radius(r) {}

    // Const member function
    double getArea() const {
        return 3.14159 * radius * radius;
    }

    // Non-const member function
    void setRadius(double r) {
        radius = r;
    }

private:
    double radius;
};

int main() {
    const int constantValue = 10;
    // constantValue = 20;  // Error: Cannot modify a const variable

    std::string msg = "Hello, World!";
    printMessage(msg);  // Output: Hello, World!

    const Circle circle(5.0);
    std::cout << "Area: " << circle.getArea() << std::endl;  // Output: Area: 78.53975
    // circle.setRadius(10.0);  // Error: Cannot call non-const member function on a const object

    return 0;
}
---------------------------------------------------------

/*
Explanation:
Immutable Variables: const variables cannot be modified after initialization, ensuring that their value remains constant.
Const Function Arguments: Functions with const arguments guarantee that the arguments won't be modified within the function.
Const Member Functions: Member functions declared as const don't modify the object's state, allowing them to be called on const objects.
What are Templates in C++?
Explanation:
Templates in C++ provide a way to create generic functions and classes that work with any data type. They enable code reuse and type safety, reducing code duplication.

Function Templates: Define generic functions that can operate on different data types.

Class Templates: Define generic classes that can store and manipulate data of different types.

Example:  */
  
#include <iostream>

// Function template
template <typename T>
T add(T a, T b) {
    return a + b;
}

// Class template
template <typename T>
class Box {
public:
    Box(T value) : data(value) {}

    T getValue() const {
        return data;
    }

private:
    T data;
};

int main() {
    std::cout << "Addition of integers: " << add(3, 4) << std::endl;        // Output: 7
    std::cout << "Addition of doubles: " << add(3.5, 4.5) << std::endl;    // Output: 8

    Box<int> intBox(10);
    Box<double> doubleBox(3.14);

    std::cout << "Int box value: " << intBox.getValue() << std::endl;       // Output: 10
    std::cout << "Double box value: " << doubleBox.getValue() << std::endl; // Output: 3.14

    return 0;
}

------------------------------------------------------------

#include <iostream>
#include <stdexcept>

double divide(double a, double b) {
    if (b == 0) {
        throw std::invalid_argument("Division by zero");
    }
    return a / b;
}

int main() {
    try {
        double result = divide(10.0, 0.0);
        std::cout << "Result: " << result << std::endl;
    } catch (const std::invalid_argument& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}

------------------------------------------------------------
#include <iostream>

void createNoMemoryLeak() {
    int* ptr = new int[10];  // Memory allocated
    delete[] ptr;            // Memory deallocated
}

int main() {
    createNoMemoryLeak();
    // No memory leak here
    return 0;
}


#include <iostream>

void createMemoryLeak() {
    int* ptr = new int[10];  // Memory allocated but not deallocated
    // Forgot to delete the allocated memory
}

int main() {
    createMemoryLeak();
    // Memory leak occurs here
    return 0;
}



#include <iostream>
#include <memory>

void createSmartPointer() {
    std::unique_ptr<int[]> ptr(new int[10]);  // Memory managed automatically
}

int main() {
    createSmartPointer();
    // No memory leak here
    return 0;
}


------------------------------------------------------------
/*

How Does C++ Support Multiple Inheritance, and What are the Potential Issues?
Explanation:
C++ supports multiple inheritance, allowing a class to inherit from more than one base class.
 This feature can be powerful but also introduces potential issues, such as the diamond problem.

Multiple Inheritance: A class can inherit from multiple base classes, combining their functionality.

Diamond Problem: Occurs when a class inherits from two classes that have a common base class. 
This can lead to ambiguity and duplication of data.


*/

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
    // obj.sayHello();  // Error: Ambiguity due to diamond problem

    obj.Derived1::sayHello();  // Output: Hello from Base
    obj.Derived2::sayHello();  // Output: Hello from Base

    return 0;
}

/*

Virtual Inheritance Solution:
C++ provides virtual inheritance to resolve the diamond problem
 by ensuring only one instance of the common base class is inherited.
*/

#include <iostream>

// Base class
class Base {
public:
    void sayHello() const {
        std::cout << "Hello from Base" << std::endl;
    }
};

// First derived class
class Derived1 : virtual public Base {
};

// Second derived class
class Derived2 : virtual public Base {
};

// Class with multiple inheritance
class Derived3 : public Derived1, public Derived2 {
};

int main() {
    Derived3 obj;
    obj.sayHello();  // Output: Hello from Base

    return 0;
}


------------------------------------------------------------


------------------------------------------------------------

------------------------------------------------------------



------------------------------------------------------------


------------------------------------------------------------



------------------------------------------------------------



