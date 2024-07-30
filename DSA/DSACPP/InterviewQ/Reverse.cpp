#include <iostream>
#include <string>
#include <algorithm>

void reverseString(std::string& str) {
    std::reverse(str.begin(), str.end());
}

int main() {
    std::string str = "Hello, World!";
    reverseString(str);
    std::cout << "Reversed String: " << str << std::endl;  // Output: !dlroW ,olleH
    return 0;
}
