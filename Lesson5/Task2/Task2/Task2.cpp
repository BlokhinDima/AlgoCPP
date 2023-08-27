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

int get_node_parent_index(int* arr, const int size, const int node_index)
{
    if (node_index == 0)
        return -1;

    int parent_index = (node_index - 1) / 2;

    return parent_index;
}

int get_node_left_child_index(int* arr, const int size, const int node_index)
{
    int left_child_index = 2 * node_index + 1;

    if (left_child_index >= size)
        return -1;

    return left_child_index;
}

int get_node_right_child_index(int* arr, const int size, const int node_index)
{
    int right_child_index = 2 * node_index + 2;

    if (right_child_index >= size)
        return -1;

    return right_child_index;
}

void print_node_info(int* arr, const int node_index, const int parent_index)
{
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
        int parent_index = get_node_parent_index(arr, size, i);

        for (int j = 1; j <= 2; ++j) // j = 1 for left child, 2 for right child
        {
            int child_index = 2 * parent_index + j;
            if (child_index < size)
            {
                print_node_info(arr, child_index, parent_index);
            }
        }
    }
    std::cout << std::endl;
}

void travel_through_pyramid(int* arr, const int size)
{
    std::string input{};
    int node_index = 0;
    int new_node_index = 0;
    int node_parent_index = 0;

    while (input != "exit")
    {
        int node_parent_index = get_node_parent_index(arr, size, node_index);
        std::cout << "You are here: ";
        print_node_info(arr, node_index, node_parent_index);

        std::cout << "Enter command (up / left / right / exit): ";
        std::cin >> input;

        if (input == "up")
        {
            new_node_index = get_node_parent_index(arr, size, node_index);
            if (new_node_index == -1)
            {
                new_node_index = node_index;
                std::cout << "Error! Node has no parents\n";
                continue;
            }
        }
        else if (input == "left")
        {
            new_node_index = get_node_left_child_index(arr, size, node_index);
            if (new_node_index == -1)
            {
                new_node_index = node_index;
                std::cout << "Error! Node has no left child\n";
                continue;
            }    
        }
        else if (input == "right")
        {
            new_node_index = get_node_right_child_index(arr, size, node_index);
            if (new_node_index == -1)
            {
                new_node_index = node_index;
                std::cout << "Error! Node has no right child\n";
                continue;
            }
        }

        std::cout << "OK!\n";
        node_index = new_node_index;
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
    travel_through_pyramid(pyramid_on_array1, size1);

    print_array(pyramid_on_array2, size2);
    print_pyramid(pyramid_on_array2, size2);
    travel_through_pyramid(pyramid_on_array2, size2);

    print_array(pyramid_on_array3, size3);
    print_pyramid(pyramid_on_array3, size3);
    travel_through_pyramid(pyramid_on_array3, size3);

    return 0;
}