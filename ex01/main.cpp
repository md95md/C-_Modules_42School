#include "phonebook.hpp"

std::string truncate_field(const std::string &str);

void input_handle()
{
    // load_contact();
    std::string input;
    while (true)
    {
        std::cout << "Please input ADD, SEARCH or EXIT: ";
        std::getline(std::cin, input);
        if (input == "EXIT")
        {
            exit_and_clean_all();
            break;
        }
        else if (input == "ADD")
        {
            please_input_contact();
        }
        else if (input == "SEARCH")
        {
            if (phonebook.contact_count == 0)
            {
                std::cout << "Phonebook is empty" << std::endl;
            }
            else
            {
                phonebook.search_contact();
            }
        } 
        else
        {
            std::cout << "Invalid command. " 
                      << "Only ADD, SEARCH or EXIT are accepted." << std::endl;
        }
    }
}

int main()
{
    // if (argc < 2)
    // {
    //     std::cout << MAGENTA << "\nEmpty input!\n" << CYAN << "\nCorrect usage:" <<
    //     "\n./phonebook ADD\n./phonebook SEARCH\n./phonebook EXIT\n" << END;
    //     return 1;
    // }
    // std::string input = argv[1];
    // if (argc != 2 || (input != "ADD" && input != "SEARCH" && input != "EXIT"))
    // {
    //     std::cout << "Invalid command. " 
    //     << "Only ADD, SEARCH or EXIT are accepted." << std::endl;
    //     return 1;
    // }
    // load_contact();
    input_handle();
}
