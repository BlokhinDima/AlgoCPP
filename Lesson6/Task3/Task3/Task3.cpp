#include <iostream>
#include <string>

int simple_string_hash(const std::string& string)
{
    int sum = 0;
    for (int i = 0; i < string.size(); ++i)
    {
        sum += static_cast<int>(string[i]);
    }
    return sum;
}

int find_substring_light_rabin_karp(std::string& string, std::string& sub_string)
{
    const int sub_string_hash = simple_string_hash(sub_string);
    const int sub_string_size = sub_string.size();
    const int string_size = string.size();

    int search_hash = simple_string_hash(string.substr(0, sub_string_size));
    
    for (int i = 0; i <= string_size - sub_string_size; ++i)
    {
        if (search_hash == sub_string_hash)
        {
            bool match = true;
            for (int j = i, k = 0; k < sub_string_size; ++j, ++k)
            { 
                if (string[j] != sub_string[k])
                {
                    match = false;
                    break;
                }
            }
            
            if (match)
                return i;
        }

        int first_char_hash = simple_string_hash(string.substr(i, 1));
        int next_char_hash = simple_string_hash(string.substr(sub_string_size + i, 1));
        search_hash = search_hash - first_char_hash + next_char_hash;
    }

    return -1;
}

int main()
{
    std::string string;
    std::cout << "Enter a string in which to search for a substring: ";
    std::cin >> string;
   
    std::string input;
    while (input != "exit")
    {
        std::cout << "Enter string to search for (enter \"exit\" to finish): ";
        std::cin >> input;
        int index = find_substring_light_rabin_karp(string, input);
        if (index != -1)
        {
            std::cout << input << " string found by index: " << index << std::endl;
        }
        else
        {
            std::cout << input << " not found in " << string << std::endl;
        }
    }

    return 0;
}