#include <iostream>
#include <string>

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

void shift_array_left_by_one(int* arr, int size)
{
    for (int i = 1; i < size; ++i)
    {
        arr[i - 1] = arr[i];
    }
}

int* remove_dynamic_array_head(int* arr, int& logical_size, int& actual_size)
{
    int new_logical_size = logical_size - 1;

    if (new_logical_size > actual_size / 3)
    {
        shift_array_left_by_one(arr, logical_size);
        logical_size = new_logical_size;
        return arr;
    }
    else
    {
        int new_actual_size = actual_size / 3;
        int* new_arr = new int[new_actual_size];
        shift_array_left_by_one(arr, logical_size);
        copy_array(arr, new_arr, new_logical_size);
        logical_size = new_logical_size;
        if (logical_size != 0) actual_size = new_actual_size;
        delete[] arr;
        return new_arr;
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

    std::string input;
    for (;;)
    {
        std::cout << "Delete first element? (Y/N): ";
        std::cin >> input;

        if (input == "N")
            break;
        
        if (logical_size > 0)
        {
            arr = remove_dynamic_array_head(arr, logical_size, actual_size);
            print_dynamic_array(arr, logical_size, actual_size);
        }
        else
        {
            std::cout << "Can't delete element! Array is empty. Goodbye!\n";
            return 0;
        }
    }

    std::cout << "Thanks! ";
    print_dynamic_array(arr, logical_size, actual_size);
    delete[] arr;
    return 0;
}
