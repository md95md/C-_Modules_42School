#include "phonebook.hpp"

std::string truncate_field(const std::string &str);

void input_handle()
{
    load_contact();
    std::string input;
    while (true)
    {
        std::cout << "Please input ADD | SEARCH | EXIT:";
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
                std::cout << MAGENTA << "Phonebook is empty\n" << "Try ADD command" << END << std::endl;
            }
            else
            {
                phonebook.search_contact();
            }
        } 
        else
        {
            std::cout << MAGENTA << "Invalid command\n" 
                      << "Only ADD | SEARCH | EXIT are accepted" << END << std::endl;
        }
    }
}

int main(int argc, char **argv)
{
    if (argc > 1)
    {
        std::cout << "Invalid arguments. Usage: ./phonebook" << std::endl;
        return 1;
    }
    if (!argv[0])
    {
        std::cout << "Invalid arguments. Usage: ./phonebook" << std::endl;
        return 1;
    }
    std::signal(SIGINT, handle_sigint);
    input_handle();
    return 0;
}
