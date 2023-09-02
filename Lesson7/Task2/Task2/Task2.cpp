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

void runBFS(int** adjacency_matrix, int verticies_number, int start_vertice)
{
    bool* visited = new bool[verticies_number] {false};
    int* queue = new int[verticies_number] {};
    int queue_head = -1;
    int queue_end = -1;

    queue_head++;
    queue[queue_head] = start_vertice;
    queue_end = queue_head;

    std::cout << "Verticies order: ";

    for (int queue_head = 0; queue_head < verticies_number; ++queue_head)
    {
        int vertice_index = queue[queue_head];
        if (vertice_index == 0) vertice_index = queue_head;

        if (!visited[vertice_index - 1])
        {
            visited[vertice_index - 1] = true;
            std::cout << vertice_index << " ";
        }

        for (int i = 0; i < verticies_number; ++i)
        {
            if (!visited[i] && adjacency_matrix[vertice_index - 1][i] != 0)
            {
                visited[i] = true;
                std::cout << i + 1 << " ";
                queue_end++;
                if (queue_end < verticies_number) queue[queue_end] = i + 1;
            }
        }
    }
    std::cout << std::endl;

    delete[] queue;
    delete[] visited;
}

int main()
{
    std::ifstream in_file{ "input4.txt" };
    int verticies_number;
    in_file >> verticies_number;
    int** adjacency_matrix = getAdjacencyMatrixFromFile(in_file, verticies_number);
    std::cout << "Adjacency matrix:\n";
    printTwoDimArray(adjacency_matrix, verticies_number, verticies_number);

    int start_vertice;
    for (;;)
    {
        std::cout << "Enter start vertice: ";
        std::cin >> start_vertice;
        if (start_vertice > 0 && start_vertice <= verticies_number)
        {
            break;
        }
        else
        {
            std::cout << "Wrong vertice number! Try again.\n";
        }
    }
    
    runBFS(adjacency_matrix, verticies_number, start_vertice);
    deleteTwoDimArray(adjacency_matrix, verticies_number, verticies_number);
    return 0;
}
