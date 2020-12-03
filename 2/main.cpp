#include <vector>
#include <istream>
#include <fstream>
#include <iostream>
#include <algorithm>

struct Rule
{
    int m_min;
    int m_max;
    char m_character;
};

std::vector<std::pair<Rule, std::string>> load_data()
{
    std::vector<std::pair<Rule, std::string>> data;
    std::ifstream input_file("input.txt");
    if(input_file.is_open())
    {
        std::streampos file_size = input_file.tellg();
        input_file.seekg( 0, std::ios::end );
        file_size = input_file.tellg() - file_size;
        input_file.seekg(0);

        data.reserve(static_cast<std::size_t>(file_size));
        while(input_file.good())
        {   
            char temp[256];
            input_file.getline(temp, 256, '\n');
            Rule r;
            char password[100];
            std::sscanf(temp, "%d-%d %c: %s", &r.m_min, &r.m_max, &r.m_character, password);
            data.emplace_back(std::make_pair(std::move(r), std::move(password)));
        }
    }
    return data;
}
int main(int argc, char const *argv[])
{
    const std::vector<std::pair<Rule, std::string>> data = load_data();
    const int total_correct = std::count_if(data.begin(), data.end(), [](const std::pair<Rule, std::string>& var)
    {
        auto check_value = [&var](int x)
        {
            return x < var.second.length() && var.second.at(x) == var.first.m_character;
        };
        return check_value(var.first.m_min) || check_value(var.first.m_max);
    });
    std::cout << total_correct << std::endl;
    return 0;
}
