#include <iostream>
// #include <algorithm>
 #include <string>


 
 void reverseStr(std::string& str)
 {

    /* function swap first & last till it reach middle letter of string*/
    std::reverse(str.begin(), str.end() );
 }

 int main()
 {
    int arr[3] = {1,3,4};

    // update 
    arr[1] = 2;
    arr[2] = 3;

    std::cout<< "Array: ";
    for (int i =0;i<3; i++)
    {
        std::cout << arr[i]  << ", " ;

    }

    int size =3;
    int start = 0;
    int end = size -1;

    /*
    1 condition : start exceed index of end pointer Loop Stops
    2 Swap : first with last, so on 
    3 Shifting Index: Start Forward ++  & End Backward --
    */
    
    while(start<end)
    {
        std::swap(arr[start],arr[end]);
        start++;
        end--;

    }

    std::cout<< "\n Reverse Array: ";
    for (int i =0;i<3; i++)
    {
        std::cout << arr[i]  << ", " ;

    }


    std::string str = "Array";
    reverseStr(str);
    std::cout<<" \n "<< str<< std::endl;


    return 0;

 }