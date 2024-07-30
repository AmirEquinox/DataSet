#include <iostream>

int fibonacciIterative(int n)
{
   if (n <= 1)
      return n;

   int prev = 0, curr = 1;
   for (int i = 2; i <= n; i++)
   {
      int next = prev + curr;
      prev = curr;
      curr = next;
   }
   return curr;
}

int main()
{
   int n = 10;
   std::cout << "Fibonacci (Iterative) of " << n << ": " << fibonacciIterative(n) << std::endl; // Output: 55
   return 0;
}

 