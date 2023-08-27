#include <iostream>
#include <string>

int simple_string_hash(std::string& string)
{
    int sum = 0;
    for (int i = 0; i < string.size(); ++i)
    {
        sum += static_cast<int>(string[i]);
    }
    return sum;
}

int main()
{
    std::string input;
    while (input != "exit")
    {
        std::cout << "Enter string (enter \"exit\" to finish): ";
        std::cin >> input;
        std::cout << input << " string simple hash: " << simple_string_hash(input) << std::endl;
    }
    return 0;
}
