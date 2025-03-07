#include "phonebook.hpp"

void input_handle(const std::string &input)
{
    if (input == "ADD")
    {
        please_input_contact();
    }
    else if (input == "SEARCH")
    {
        int indx;
        std::cout << std::endl << CYAN << "Please input the index of the contact you want to display: " << END;
        std::cin >> indx;
        phonebook.search_contact(indx);
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
        std::cout << MAGENTA << "\nEmpty input! :(\n" << CYAN << "\nCorrect usage: ./phonebook \n[1]ADD\n[2]SEARCH\n[3]EXIT" << END << std::endl;
        return 1;
    }
    load_contact();
    std::string input = argv[1];
    if (input != "ADD" && input != "SEARCH" && input != "EXIT")
    {
        std::cout  << MAGENTA <<"\nCorrect usage: ./phonebook \n[1] ADD\n[2] SEARCH\n[3] EXIT" << END << std::endl;
        return 1;
    }
    input_handle(input);
    return 0;
}
