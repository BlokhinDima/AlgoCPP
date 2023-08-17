#include <iostream>

int min(int x, int y) { return (x < y) ? x : y; }

void printArray(int* arr, int size)
{
    std::cout << "Array: ";
    for (int i = 0; i < size; ++i)
    {
        std::cout << arr[i] << ' ';
    }
    std::cout << std::endl;
}

void merge(int* arr, int left_start, int mid_index, int right_end)
{
    int left_array_size = mid_index + 1 - left_start;
    int right_array_size = right_end - mid_index;

    int* left_array = new int[left_array_size]{};
    int* right_array = new int[right_array_size]{};

    for (int i = 0; i < left_array_size; ++i)
    {
        left_array[i] = arr[left_start + i];
    }

    for (int j = 0; j < right_array_size; j++)
    {
        right_array[j] = arr[mid_index + 1 + j];
    }

    int i = 0;
    int j = 0;
    int k = left_start;
    while (i < left_array_size && j < right_array_size)
    {
        if (left_array[i] <= right_array[j])
        {
            arr[k] = left_array[i];
            i++;
        }
        else
        {
            arr[k] = right_array[j];
            j++;
        }
        k++;
    }

    while (i < left_array_size)
    {
        arr[k] = left_array[i];
        i++;
        k++;
    }

    while (j < right_array_size)
    {
        arr[k] = right_array[j];
        j++;
        k++;
    }

    delete[] left_array;
    delete[] right_array;
}

void merge_sort(int* arr, int size)
{
    for (int sub_arr_size = 1; sub_arr_size < size; sub_arr_size *= 2)
    {
        for (int left_start = 0; left_start < size - 1; left_start += 2 * sub_arr_size)
        {
            int mid = min(left_start + sub_arr_size - 1, size - 1);
            int right_end = min(left_start + 2 * sub_arr_size - 1, size - 1);
            merge(arr, left_start, mid, right_end);
        }
    }
}

int main()
{
    int arr1_size = 10;
    int arr1[] = { 3, 43, 38, 29, 18, 72, 57, 61, 2, 33 };

    int arr2_size = 15;
    int arr2[] = { 88, 91, 87, 59, 53, 49, 29, 16, 4, 27, 28, 89, 2, 25, 74 };

    int arr3_size = 18;
    int arr3[] = { 24, 66, 20, 79, 30, 16, 19, 62, 94, 59, 0, 7, 59, 90, 84, 60, 95, 62 };

    std::cout << "Array before sort: ";
    printArray(arr1, arr1_size);
    merge_sort(arr1, arr1_size);
    std::cout << "Array after sort: ";
    printArray(arr1, arr1_size);
    std::cout << std::endl;

    std::cout << "Array before sort: ";
    printArray(arr2, arr2_size);
    merge_sort(arr2, arr2_size);
    std::cout << "Array after sort: ";
    printArray(arr2, arr2_size);
    std::cout << std::endl;

    std::cout << "Array before sort: ";
    printArray(arr3, arr3_size);
    merge_sort(arr3, arr3_size);
    std::cout << "Array after sort: ";
    printArray(arr3, arr3_size);
    std::cout << std::endl;

    return 0;
}
