#include <iostream>

void swap(int& x, int& y)
{
    int tmp = x;
    x = y;
    y = tmp;
}

int separation(int* arr, int start, int end)
{
    int pivot = arr[end];
    int pivot_index = start;

    for (int i = start; i < end; ++i)
    {
        if (arr[i] < pivot)
        {
            swap(arr[i], arr[pivot_index]);
            pivot_index++;
        }
    }
    swap(arr[pivot_index], arr[end]);

    return pivot_index;
}

void quick_sort(int* arr, int size)
{
    int start = 0;
    int end = size - 1;

    int* stack = new int[size + 1]{};
    int stack_top_index = -1;

    stack[++stack_top_index] = start;
    stack[++stack_top_index] = end;
   
    while (stack_top_index >= 0)
    {
        end = stack[stack_top_index--];
        start = stack[stack_top_index--];

        int pivot_index = separation(arr, start, end);

        if (pivot_index - 1 > start)
        {
            stack[++stack_top_index] = start;
            stack[++stack_top_index] = pivot_index - 1;
        }

        if (pivot_index + 1 < end)
        {
            stack[++stack_top_index] = pivot_index + 1;
            stack[++stack_top_index] = end;
        }
    }

    delete[] stack;
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
    const int arr1_size = 10;
    int arr1[] = { 3, 43, 38, 29, 18, 72, 57, 61, 2, 33, };

    const int arr2_size = 15;
    int arr2[] = { 88, 91, 87, 59, 53, 49, 29, 16, 4, 27, 28, 89, 2, 25, 74, };

    const int arr3_size = 18;
    int arr3[] = { 24, 66, 20, 79, 30, 16, 19, 62, 94, 59, 0, 7, 59, 90, 84, 60, 95, 62, };

    std::cout << "Array before sort: ";
    printArray(arr1, arr1_size);
    quick_sort(arr1, arr1_size);
    std::cout << "Array after sort: ";
    printArray(arr1, arr1_size);
    std::cout << std::endl;

    std::cout << "Array before sort: ";
    printArray(arr2, arr2_size);
    quick_sort(arr2, arr2_size);
    std::cout << "Array after sort: ";
    printArray(arr2, arr2_size);
    std::cout << std::endl;

    std::cout << "Array before sort: ";
    printArray(arr3, arr3_size);
    quick_sort(arr3, arr3_size);
    std::cout << "Array after sort: ";
    printArray(arr3, arr3_size);
    std::cout << std::endl;

    return 0;
}
