#include <iostream>
#include <string>

int real_string_hash(std::string& string, int p, int n)
{
    long long sum = 0;
    for (int i = 0; i < string.size(); ++i)
    {
        sum += static_cast<int>(string[i]) * pow(p, i);
    }
    return sum % n;
}

int main()
{
    std::string input;
    int p;
    int n;
    std::cout << "Enter p value: ";
    std::cin >> p;
    std::cout << "Enter n value: ";
    std::cin >> n;

    while (input != "exit")
    {
        std::cout << "Enter string (enter \"exit\" to finish): ";
        std::cin >> input;
        std::cout << input << " string simple hash: " << real_string_hash(input, p, n) << std::endl;
    }
    return 0;
}
