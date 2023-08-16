#include <iostream>

static const int MIN_DATA_VALUE = 10;
static const int MAX_DATA_VALUE = 24;

void count_sort(int* arr, int size)
{
    const int buffer_size = MAX_DATA_VALUE - MIN_DATA_VALUE + 1;
    int buffer[buffer_size] = {};

    for (int i = 0; i < size; ++i)
    {
        buffer[arr[i] - MIN_DATA_VALUE]++;
    }

    for (int i = 0, j = 0; i < buffer_size; ++i)
    {
        for (int k = buffer[i]; k > 0; --k)
        {
            arr[j] = i + MIN_DATA_VALUE;
            ++j;
        }
    }
}

void printArray(int* arr, int size)
{
    for (int i = 0; i < size; ++i)
    {
        std::cout << arr[i] << ' ';
    }
    std::cout << std::endl;
}

int main()
{
    int arr1_size = 30;
    int arr1[] = { 19, 14, 22, 22, 17, 22, 13, 21, 20, 24,
                   18, 10, 17, 16, 17, 20, 22, 11, 20, 16,
                   14, 13, 10, 22, 18, 14, 16, 24, 19, 17, };

    int arr2_size = 40;
    int arr2[] = { 16, 17, 14, 20, 22, 20, 17, 22, 16, 19,
                   23, 24, 20, 22, 21, 18, 14, 16, 17, 21,
                   10, 11, 19, 23, 11, 11, 17, 17, 11, 21,
                   17, 11, 17, 16, 12, 11, 16, 22, 23, 16, };

    int arr3_size = 45;
    int arr3[] = { 21, 15, 19, 18, 23, 12, 18, 18, 19, 23,
                   12, 20, 15, 22, 21, 18, 19, 20, 12, 16,
                   20, 14, 17, 13, 10, 23, 19, 14, 10, 22,
                   19, 12, 24, 23, 22, 15, 13, 22, 18, 18, 
                   11, 23, 24, 17, 10, };


    std::cout << "Array before sort: ";
    printArray(arr1, arr1_size);
    count_sort(arr1, arr1_size);
    std::cout << "Array after sort: ";
    printArray(arr1, arr1_size);
    std::cout << std::endl;

    std::cout << "Array before sort: ";
    printArray(arr2, arr2_size);
    count_sort(arr2, arr2_size);
    std::cout << "Array after sort: ";
    printArray(arr2, arr2_size);
    std::cout << std::endl;

    std::cout << "Array before sort: ";
    printArray(arr3, arr3_size);
    count_sort(arr3, arr3_size);
    std::cout << "Array after sort: ";
    printArray(arr3, arr3_size);
    std::cout << std::endl;

    return 0;
}


