#include <iostream>
#include <vector>

void Main()
{
    std::vector<int> numbers = {1, 2, 3, 4, 5};

    for (int number : numbers)
    {
        std::cout << "Number: " << number << std::endl;
    }

    for (int i =0;i<3; i++)
    {
        std::cout << numbers[i]  << ", " ;
    }

}

int main()
{
    Main();
    return 0;
}
