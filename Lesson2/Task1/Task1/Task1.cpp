#include <iostream>

// Time complexity O(2^n).
// More precisely, the time complexity will tend to ~1.6^n.
// 
// The number of function calls increases approximately 1.6 times 
// as the ordinal number of the fibbonacci number increases by one.
// 
// Number of function calls for the 6th fibbonacci number: 15
// Number of function calls for the 7th fibbonacci number: 25
// Number of function calls for the 8th fibbonacci number: 41
// Number of function calls for the 9th fibbonacci number: 67
// 
// Memory complexity O(n). The maximum depth of the call stack 
// will linearly depend on the ordinal number of the calculated 
// fibonacci number. The maximum number of calls will go along the 
// function call branch calcFibonacciNumber(number_index - 1)

int calcFibonacciNumber(int number_index)
{
    /*
    static int call_number = 0;
    call_number++;
    std::cout << "Call number: " << call_number << std::endl;
    */

    if (number_index == 1)
        return 0;

    if (number_index == 2)
        return 1;

    return calcFibonacciNumber(number_index - 1) + calcFibonacciNumber(number_index - 2);
}

int main()
{
    std::cout << "Enter Fibonacci number index: ";
    int number_index;
    std::cin >> number_index;
    std::cout << "Fibonacci number: " << calcFibonacciNumber(number_index) << std::endl;
    return 0;
}
