/*
Example 1: Manual Memory Management
In this example, we'll manually manage the memory for an array of integers. 
The program will demonstrate allocating memory, using it, and deallocating it to prevent memory leaks.

*/

#include <iostream>

// Function to manually manage memory for an integer array
void manageMemoryManually() {
    // Allocate memory for an array of 5 integers
    int* numbers = new int[5];

    // Initialize the array with values
    for (int i = 0; i < 5; ++i) {
        numbers[i] = i + 1;  // Assign values 1 to 5
    }

    // Print the array values
    std::cout << "Numbers: ";
    for (int i = 0; i < 5; ++i) {
        std::cout << numbers[i] << " ";
    }
    std::cout << std::endl;

    // Deallocate memory to prevent a memory leak
    delete[] numbers;
}

int main() {
    manageMemoryManually();  // Call the function to demonstrate manual memory management

    std::cout << "Memory managed manually." << std::endl;

    return 0;
}

/* 
Explanation:

Memory Allocation: Memory for an integer array of size 5 is allocated using new int[5].
Initialization: The array is initialized with values from 1 to 5.
Deallocation: The delete[] statement is used to free the allocated memory, preventing a memory leak.
Example 2: Using Smart Pointers
This example demonstrates using std::unique_ptr to automatically manage memory, showing how to avoid memory leaks with minimal manual intervention.

*/
#include <iostream>
#include <memory>  // Required for std::unique_ptr

// Function to use std::unique_ptr for memory management
void manageMemoryWithSmartPointers() {
    // Create a unique_ptr managing an array of 5 integers
    std::unique_ptr<int[]> numbers(new int[5]);

    // Initialize the array with values
    for (int i = 0; i < 5; ++i) {
        numbers[i] = i + 1;  // Assign values 1 to 5
    }

    // Print the array values
    std::cout << "Numbers: ";
    for (int i = 0; i < 5; ++i) {
        std::cout << numbers[i] << " ";
    }
    std::cout << std::endl;

    // No need to explicitly delete the memory; std::unique_ptr handles it
}

int main() {
    manageMemoryWithSmartPointers();  // Call the function to demonstrate smart pointer memory management

    std::cout << "Memory managed with smart pointers." << std::endl;

    return 0;
}

/*
Explanation:

Smart Pointer Usage: std::unique_ptr is used to manage an array of integers. The memory is automatically deallocated when the unique_ptr goes out of scope.
Automatic Deallocation: Unlike manual memory management, there's no need to call delete[] explicitly. The smart pointer takes care of memory deallocation, reducing the risk of memory leaks.
Example 3: Using std::shared_ptr for Shared Ownership
This example demonstrates using std::shared_ptr for scenarios where multiple entities need to share ownership of a resource.

Destruction of Shared Pointers:

When manageSharedMemory completes and the function scope ends, both numbers and numbersCopy are destroyed.
Their destructors decrease the reference count. Since both are the only owners, their destruction results in the reference count reaching zero.
The custom deleter (std::default_delete<int[]>) then deletes the array.
Memory Deallocation:

After the reference count reaches zero, the dynamically allocated memory for the array is deallocated automatically.

*/

#include <iostream>
#include <memory>
#include <vector>

// Function to create and manage shared memory
void manageSharedMemory() {
    // Create a shared_ptr managing an array of 5 integers
    std::shared_ptr<int[]> numbers(new int[5], std::default_delete<int[]>());

    // Initialize the array with values
    for (int i = 0; i < 5; ++i) {
        numbers[i] = i + 1;  // Assign values 1 to 5
    }

    // Another shared_ptr pointing to the same memory
    std::shared_ptr<int[]> numbersCopy = numbers;

    // Print the array values using the original pointer
    std::cout << "Numbers from original pointer: ";
    for (int i = 0; i < 5; ++i) {
        std::cout << numbers[i] << " ";
    }
    std::cout << std::endl;

    // Print the array values using the copied pointer
    std::cout << "Numbers from copied pointer: ";
    for (int i = 0; i < 5; ++i) {
        std::cout << numbersCopy[i] << " ";
    }
    std::cout << std::endl;

    // Memory will be automatically deallocated when both pointers go out of scope
}

int main() {
    manageSharedMemory();  // Call the function to demonstrate shared pointer usage

    std::cout << "Memory managed with shared pointers." << std::endl;

    return 0;
}

/*
Explanation:

Shared Ownership: std::shared_ptr allows multiple pointers to share ownership of the same resource. Memory is automatically deallocated when the last shared_ptr referencing it goes out of scope.
Reference Counting: std::shared_ptr uses reference counting to keep track of how many pointers reference the same resource. The memory is freed when the reference count drops to zero.
Example 4: Preventing Memory Leaks with Classes
In this example, we'll create a class that demonstrates proper memory management within a class context, using both manual and smart pointer techniques.

*/
#include <iostream>
#include <memory>

class MyClass {
private:
    int* manualArray;                          // Manually managed array
    std::unique_ptr<int[]> uniquePtrArray;     // Unique pointer managed array

public:
    // Constructor
    MyClass() : manualArray(new int[5]), uniquePtrArray(new int[5]) {
        // Initialize arrays with values
        for (int i = 0; i < 5; ++i) {
            manualArray[i] = i + 1;            // Initialize manually managed array
            uniquePtrArray[i] = (i + 1) * 10;  // Initialize smart pointer managed array
        }
    }

    // Destructor
    ~MyClass() {
        // Deallocate manually managed memory
        delete[] manualArray;
    }

    // Method to print arrays
    void printArrays() const {
        std::cout << "Manual Array: ";
        for (int i = 0; i < 5; ++i) {
            std::cout << manualArray[i] << " ";
        }
        std::cout << std::endl;

        std::cout << "Unique Pointer Array: ";
        for (int i = 0; i < 5; ++i) {
            std::cout << uniquePtrArray[i] << " ";
        }
        std::cout << std::endl;
    }
};

int main() {
    MyClass obj;        // Create an object of MyClass
    obj.printArrays();  // Print array contents

    std::cout << "Memory managed within a class context." << std::endl;

    return 0;
}
/*
Explanation:

Manual Management in Classes: The constructor allocates memory for an array, and the destructor ensures it is deallocated, demonstrating proper memory management within a class.
Smart Pointers in Classes: std::unique_ptr automatically manages memory for another array, eliminating the need for manual deallocation.
Conclusion
These examples demonstrate how to effectively manage memory in C++ to prevent memory leaks:

Manual Memory Management: Requires careful pairing of new with delete and new[] with delete[] to avoid leaks.
Smart Pointers: Use std::unique_ptr and std::shared_ptr to automate memory management, reducing the risk of memory leaks and simplifying resource handling.
Classes: Demonstrates proper memory management within class constructors and destructors, showcasing both manual and smart pointer techniques.

*/