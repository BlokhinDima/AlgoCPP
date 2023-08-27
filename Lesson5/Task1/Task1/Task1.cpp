#include <iostream>
#include <string>

void print_array(int* arr, const int size)
{
    std::cout << "Array: ";
    for (int i = 0; i < size; ++i)
    {
        std::cout << arr[i] << ' ';
    }
    std::cout << std::endl;
}

void print_node_info(int* arr, const int node_index, const int parent_index)
{
    std::string node_position{};
    int node_value = arr[node_index];
    int parent_value = arr[parent_index];
    int pyramid_level = log2(node_index + 1);

    std::cout << pyramid_level;

    if (node_index == 0)
    {
        std::cout << " root ";
    }
    else 
    {
        if (node_index % 2 == 0)
        {
            std::cout << " right(";
        }
        else
        {
            std::cout << " left(";
        }
        std::cout << parent_value << ") ";
    }

    std::cout << node_value << std::endl;
}

void print_pyramid(int* arr, const int size)
{
    std::cout << "Pyramid: " << std::endl;
    int root_index = 0;
    print_node_info(arr, root_index, root_index);

    for (int i = 1; i < size; i += 2)
    {
        int parent_index = (i - 1) / 2;
     
        for (int j = 1, child_index = 0; j <= 2; ++j) // j = 1 for left child, 2 for right child
        {
            child_index = 2 * parent_index + j;
            if (child_index < size)
            {
                print_node_info(arr, child_index, parent_index);
            }
        }
    }
    std::cout << std::endl;
}

int main()
{
    const int size1 = 6;
    int pyramid_on_array1[] = { 1, 3, 6, 5, 9, 8, };

    const int size2 = 8;
    int pyramid_on_array2[] = { 94, 67, 18, 44, 55, 12, 6, 42, };

    const int size3 = 10;
    int pyramid_on_array3[] = { 16, 11, 9, 10, 5, 6, 8, 1, 2, 4, };

    print_array(pyramid_on_array1, size1);
    print_pyramid(pyramid_on_array1, size1);

    print_array(pyramid_on_array2, size2);
    print_pyramid(pyramid_on_array2, size2);

    print_array(pyramid_on_array3, size3);
    print_pyramid(pyramid_on_array3, size3);

    return 0;
}
