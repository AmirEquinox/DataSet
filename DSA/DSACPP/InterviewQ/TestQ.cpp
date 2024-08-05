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