#include <iostream>

int calcFibonacciNumber(int number_index)
{
    int first_fibonacci_number = 0;
    int second_fibonacci_number = 1;

    if (number_index == 1)
        return first_fibonacci_number;
    if (number_index == 2)
        return second_fibonacci_number;

    int sum = 0;
    int current_number = second_fibonacci_number;
    int prev_number = first_fibonacci_number;

    for (int i = 3; i <= number_index; ++i)
    {
        sum = current_number + prev_number;
        prev_number = current_number;
        current_number = sum;
    }

    return sum;
}

int main()
{
    std::cout << "Enter Fibonacci number index: ";
    int number_index;
    std::cin >> number_index;
    std::cout << "Fibonacci number: " << calcFibonacciNumber(number_index) << std::endl;
    return 0;
}


