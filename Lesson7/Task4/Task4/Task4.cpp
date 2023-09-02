#include <iostream>
#include <fstream>

int** createTwoDimArray(int n, int m)
{
    int** array = new int* [n];
    for (int i = 0; i < n; ++i)
    {
        array[i] = new int[m];
    }
    return array;
}

void deleteTwoDimArray(int** array, int n, int m)
{
    for (int i = 0; i < n; ++i)
    {
        delete[] array[i];
    }
    delete[] array;
}

int** getAdjacencyMatrixFromFile(std::ifstream& file, int verticies_number)
{
    int** adjacency_matrix = createTwoDimArray(verticies_number, verticies_number);
    for (int i = 0; i < verticies_number; ++i)
    {
        for (int j = 0; j < verticies_number; ++j)
        {
            file >> adjacency_matrix[i][j];
        }
    }
    return adjacency_matrix;
}

void printTwoDimArray(int** array, int n, int m)
{
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            std::cout << array[i][j] << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

void printCohesionComponents(int** adjacency_matrix, int verticies_number)
{
    int* components_id = new int[verticies_number] {};
    int component_id = 0;
    int* stack = new int[verticies_number] {};
    int stack_top = -1;

    for (int i = 0; i < verticies_number; ++i)
    {
        if (components_id[i] == 0)
        {
            component_id++;
            components_id[i] = component_id;
            stack_top++;
            stack[stack_top] = i;
        }

        while (stack_top != -1)
        {
            for (int j = 0; j < verticies_number; ++j)
            {
                if (adjacency_matrix[i][j] != 0 && components_id[j] == 0)
                {
                    components_id[j] = component_id;
                    stack_top++;
                    stack[stack_top] = j;
                    i = j;
                    j = -1;
                }
            }

            i = stack[stack_top];
            stack_top--;
        }
    }

    std::cout << "Vertice - cohesion component:\n";
    for (int i = 0; i < verticies_number; ++i)
    {
        std::cout << i + 1 << " - " << components_id[i] << std::endl;
    }
    std::cout << "Cohesion components number: " << component_id << std::endl;

    delete[] components_id;
    delete[] stack;
}

int main()
{
    std::ifstream in_file{ "input2.txt" };
    int verticies_number;
    in_file >> verticies_number;
    int** adjacency_matrix = getAdjacencyMatrixFromFile(in_file, verticies_number);
    std::cout << "Adjacency matrix:\n";
    printTwoDimArray(adjacency_matrix, verticies_number, verticies_number);
    printCohesionComponents(adjacency_matrix, verticies_number);
    deleteTwoDimArray(adjacency_matrix, verticies_number, verticies_number);
    return 0;
}
