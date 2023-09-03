#include <iostream>
#include <fstream>

int** createTwoDimArray(int n, int m)
{
    int** array = new int*[n];
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

void runDFS(int** adjacency_matrix, int verticies_number)
{
    bool* visited = new bool[verticies_number] {false};
    int* stack = new int[verticies_number] {};
    int stack_top = -1;
    
    std::cout << "Verticies order: ";

    for (int vertice = 0; vertice < verticies_number; ++vertice)
    {
        if (!visited[vertice])
        {
            stack_top++;
            stack[stack_top] = vertice;

            while (stack_top != -1)
            {
                vertice = stack[stack_top];
                stack_top--;

                if (!visited[vertice])
                {
                    visited[vertice] = true;
                    std::cout << vertice + 1 << " ";
                }

                for (int j = verticies_number - 1; j >= 0; --j)
                {
                    if (adjacency_matrix[vertice][j] != 0 && !visited[j])
                    {
                        stack_top++;
                        stack[stack_top] = j;
                    }
                }
            }
        }
    }
    std::cout << std::endl;

    delete[] visited;
    delete[] stack;
}

int main()
{
    std::ifstream in_file { "input3.txt" };
    int verticies_number;
    in_file >> verticies_number;
    int** adjacency_matrix = getAdjacencyMatrixFromFile(in_file, verticies_number);
    std::cout << "Adjacency matrix:\n";
    printTwoDimArray(adjacency_matrix, verticies_number, verticies_number);
    runDFS(adjacency_matrix, verticies_number);
    deleteTwoDimArray(adjacency_matrix, verticies_number, verticies_number);
    return 0;
}
