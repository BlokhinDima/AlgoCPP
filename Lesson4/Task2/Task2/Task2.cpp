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

void copy_array(int* arr1, int* arr2, int size)
{
    for (int i = 0; i < size; ++i)
    {
        arr2[i] = arr1[i];
    }
}

int* append_to_dynamic_array(int* arr, int& logical_size, int& actual_size, int value)
{
    int new_logical_size = logical_size + 1;

    if (new_logical_size > actual_size)
    {
        int new_actual_size = actual_size * 2;
        int* new_arr = new int[new_actual_size];
        copy_array(arr, new_arr, new_logical_size);
        new_arr[new_logical_size - 1] = value;
        logical_size = new_logical_size;
        actual_size = new_actual_size;
        delete[] arr;
        return new_arr;
    }
    else
    {
        arr[new_logical_size - 1] = value;
        logical_size = new_logical_size;
        return arr;
    }
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

    int input;
    for (;;)
    {
        std::cout << "Enter value to add (Enter 0 to finish): ";
        std::cin >> input;
        
        if (input == 0)
            break;

        arr = append_to_dynamic_array(arr, logical_size, actual_size, input);
    }

    print_dynamic_array(arr, logical_size, actual_size);

    delete[] arr;
    return 0;
}