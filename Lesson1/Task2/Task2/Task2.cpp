#include <iostream>

int countBiggerValuesAmount(int* arr, int size, int value)
{
    int first_index = 0;
    int last_index = size - 1;
    
    while (first_index <= last_index)
    {
        int middle_index = (first_index + last_index) / 2;

        if (arr[middle_index] <= value)
        {
            first_index = middle_index + 1;
            if (arr[middle_index + 1] > value)
            {
                break;
            }
        }
        else
        {
            if (arr[middle_index - 1] < value)
            {
                first_index = middle_index;
                break;
            }
            last_index = middle_index - 1;
        }
    }

    return size - first_index;
}

int main()
{
    int size = 9;
    int arr[] = { 14, 16, 19, 32, 32, 32, 56, 69, 72 };
    int arr2[] = { 1, 6, 9, 32, 56, 61, 77, 89, 90 };

    int start_point;
    std::cout << "Enter start point: ";
    std::cin >> start_point;
    std::cout << countBiggerValuesAmount(arr, size, start_point) << std::endl;

    std::cout << "\nEnter start point: ";
    std::cin >> start_point;
    std::cout << countBiggerValuesAmount(arr2, size, start_point) << std::endl;
    return 0;
}


