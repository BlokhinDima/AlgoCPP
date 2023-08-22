#include <iostream>

void print_dynamic_array(int* arr, int logical_size, int actual_size)
{
    std::cout << "Dynamic array: ";
    for (int i = 0; i < actual_size; ++i)
    {
        if (i < logical_size)
        {
            std::cout << arr[i] << ' ';
        }
        else
        {
            std::cout << " _ ";
        }
    }
    std::cout << std::endl;
}

int main()
{
    std::cout << "Enter actual size: ";
    int actual_size;
    std::cin >> actual_size;

    std::cout << "Enter logical size: ";
    int logical_size;
    std::cin >> logical_size;

    if (logical_size > actual_size)
    {
        std::cout << "Error! Logical size exceeds actual size.\n";
        return -1;
    }

    int* arr = new int[actual_size];

    for (int i = 0; i < logical_size; ++i)
    {
        std::cout << "Enter arr[" << i << "]: ";
        std::cin >> arr[i];
    }

    print_dynamic_array(arr, logical_size, actual_size);
    return 0;
}
