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

int* topologicalSort(int** adjacency_matrix, int verticies_number)
{
    bool* visited = new bool[verticies_number] {false};
    int* order = new int[verticies_number] {};
    int order_start = verticies_number;
    int* stack = new int[verticies_number] {};
    int stack_top = -1;
  
    for (int vertice = 0; vertice < verticies_number; ++vertice)
    {
        if (!visited[vertice])
        {
            stack_top++;
            stack[stack_top] = vertice;

            while (stack_top != -1)
            {
                vertice = stack[stack_top];
                
                bool vertice_has_out_ways = false;
                for (int j = 0; j < verticies_number; ++j)
                {
                    if (adjacency_matrix[vertice][j] != 0 && !visited[j])
                    {
                        stack_top++;
                        stack[stack_top] = j;
                        vertice_has_out_ways = true;
                    }
                }

                if (!vertice_has_out_ways)
                {
                    vertice = stack[stack_top];
                    if (!visited[vertice])
                    {
                        order_start--;
                        order[order_start] = vertice + 1;
                        visited[vertice] = true;
                    }
                    stack_top--;
                }
            }
        }
    }

    delete[] stack;
    delete[] visited;
    return order;
}

int main()
{
    std::ifstream in_file{ "input5.txt" };
    int verticies_number;
    in_file >> verticies_number;
    int** adjacency_matrix = getAdjacencyMatrixFromFile(in_file, verticies_number);
    std::cout << "Adjacency matrix:\n";
    printTwoDimArray(adjacency_matrix, verticies_number, verticies_number);

    int* topological_order = topologicalSort(adjacency_matrix, verticies_number);
    std::cout << "Topological verticies order: ";
    for (int i = 0; i < verticies_number; ++i)
    {
        std::cout << topological_order[i] << " ";
    }
    std::cout << std::endl;

    deleteTwoDimArray(adjacency_matrix, verticies_number, verticies_number);
    delete[] topological_order;
    return 0;
}
