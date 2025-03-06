#include "phonebook.hpp"

void input_handle(const std::string &input)
{
    if (input == "ADD")
    {
        please_input_contact();
    }
    else if (input == "SEARCH")
    {
        display_contacts();
    }
    else if (input == "EXIT")
    {
        exit_and_clean_all();
    }
}

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        std::cout << "Usage: ./phonebook [ADD | SEARCH | EXIT]" << std::endl;
        return 1;
    }
    std::string input = argv[1];
    if (input != "ADD" && input != "SEARCH" && input != "EXIT")
    {
        std::cout << "Usage: ./phonebook [ADD | SEARCH | EXIT]" << std::endl;
        return 1;
    }
    input_handle(input);
    return 0;
}
