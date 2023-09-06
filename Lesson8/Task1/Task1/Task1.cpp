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

void printOrientedGraph(int** adjacency_matrix, int verticies_number)
{
    std::cout << "Oriented graph:\n";

    for (int vertice = 0; vertice < verticies_number; ++vertice)
    {
        bool vertice_has_out_ways = false;
        std::cout << vertice + 1 << ": ";

        for (int j = 0; j < verticies_number; ++j)
        {
            if (adjacency_matrix[vertice][j] != 0)
            {
                vertice_has_out_ways = true;
                std::cout << j + 1 << " ";
            }
        }

        if (!vertice_has_out_ways)
        {
            std::cout << "NO";
        }

        std::cout << std::endl;
    }

    std::cout << std::endl;
}

int main()
{
    std::ifstream in_file{ "input4.txt" };
    int verticies_number;
    in_file >> verticies_number;
    int** adjacency_matrix = getAdjacencyMatrixFromFile(in_file, verticies_number);
    std::cout << "Adjacency matrix:\n";
    printTwoDimArray(adjacency_matrix, verticies_number, verticies_number);
    printOrientedGraph(adjacency_matrix, verticies_number);
    deleteTwoDimArray(adjacency_matrix, verticies_number, verticies_number);
    return 0;
}