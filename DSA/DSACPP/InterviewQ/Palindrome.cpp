#include <iostream>
#include <string>

 bool isPalindrome(const std::string& str)
 {
    int left = 0;
    int right = str.length()-1;

    while(left<right)
    {
        if(str[left] != str[right])
        {
            return false;
        }

        left++;
        right--;
    }
    // if there are not false if we match all left & right index character/letter in string return True
    return true;
 }

int main() {
    std::string str = "radar";
    std::cout<<  "String index of 2 :  "<< str[2] <<"\n" << std::endl;

    bool result = isPalindrome(str);
    std::cout << "Is Palindrome: " << (result ? "Yes" : "No") << std::endl;  // Output: Yes
    return 0;
}