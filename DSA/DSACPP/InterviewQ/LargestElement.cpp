#include <iostream>
#include <vector>
#include <limits.h>

int findLargestElement(const std::vector<int> &arr)
{
    int largest = INT_MIN;
    for (int num : arr)
    {
        if (num > largest)
        {
            largest = num;
        }
    }
    return largest;
}

int main()
{
    std::vector<int> arr = {5, 2, 9, 1, 5, 6};
    int largest = findLargestElement(arr);
    std::cout << "Largest Element: " << largest << std::endl; // Output: 9
    return 0;
}
