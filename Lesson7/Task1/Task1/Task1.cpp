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

    std::cout << "Verticies order: ";

    for (int i = 0; i < verticies_number; ++i)
    {
        if (!visited[i])
        {
            visited[i] = true;
            std::cout << i + 1 << " ";
        }

        for (int j = 0; j < verticies_number; ++j)
        {
            if (adjacency_matrix[i][j] != 0 && !visited[j])
            {
               std::cout << j + 1 << " ";
               visited[j] = true;
               i = j;
               j = 0;
            }
        }

    }
    std::cout << std::endl;
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
