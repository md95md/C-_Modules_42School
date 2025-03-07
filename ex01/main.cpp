#include "phonebook.hpp"

void input_handle(const std::string &input)
{
    if (input == "ADD")
    {
        please_input_contact();
    }
    else if (input == "SEARCH")
    {
        if (phonebook.contact_count == 0)
            return;
        int indx;
        std::cout << std::endl << CYAN <<
        "Please input the index of the contact you want to display: " << END;
        std::cin >> indx;
        phonebook.search_contact(indx);
    }
    else if (input == "EXIT")
    {
        if (phonebook.contact_count == 0)
            return;
        exit_and_clean_all();
    }
}

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        std::cout << MAGENTA << "\nEmpty input!\n" << CYAN << "\nCorrect usage:" <<
        "\n./phonebook ADD\n./phonebook SEARCH\n./phonebook EXIT\n" << END;
        return 1;
    }
    std::string input = argv[1];
    if (argc != 2 || (input != "ADD" && input != "SEARCH" && input != "EXIT"))
    {
        std::cout  << MAGENTA << "\nWrong input!\n" << CYAN <<"\nCorrect usage:" <<
        "\n./phonebook ADD\n./phonebook SEARCH\n./phonebook EXIT\n" << END;
        return 1;
    }
    load_contact();
    input_handle(input);
    return 0;
}
