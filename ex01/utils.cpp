#include "phonebook.hpp"

PhoneBook phonebook;
Contact contact;

std::string readDigitString(const std::string &prompt)
{
    std::string input;
    bool valid = false;
    while (!valid)
    {
        std::cout << prompt;
        std::getline(std::cin, input);
        valid = true;
        for (size_t i = 0; i < input.size(); ++i)
        {
            if (!std::isdigit(static_cast<unsigned char>(input[i])) && !std::isspace(static_cast<unsigned char>(input[i])))
            {
                std::cout << MAGENTA << "\nWrong input! Please enter digits only\n" << END;
                valid = false;
                break;
            }
        }
    }
    return input;
}

std::string readAlphaString(const std::string& prompt)
{
    std::string input;
    bool valid = false;
    while (!valid)
    {
        std::cout << prompt;
        std::getline(std::cin, input);
        valid = true;
        for (size_t i = 0; i < input.size(); ++i)
        {
            if (!std::isalpha(static_cast<unsigned char>(input[i])) && !std::isspace(static_cast<unsigned char>(input[i])))
            {
                std::cout << MAGENTA << "\nWrong input! Please enter letters only\n" << END;
                valid = false;
                break;
            }
        }
    }
    return input;
}

void please_input_contact()
{
    Contact new_contact;
    new_contact.index = phonebook.contact_count % 8;
    std::cout << CYAN << "Please input the following information:\n" << END;
    new_contact.first_name = readAlphaString("First Name: ");
    new_contact.last_name  = readAlphaString("Last Name: ");
    new_contact.nickname   = readAlphaString("Nickname: ");
    new_contact.phone_number = readDigitString("Phone Number: ");
    new_contact.darkest_secret = readAlphaString("Darkest Secret: ");
    phonebook.contacts[phonebook.contact_count] = new_contact;
    phonebook.contact_count++;
    save_contact();
    std::cout << CYAN << "Contact added successfully at index " << new_contact.index << "!\n" << END;
}

void exit_and_clean_all()
{
    if (std::remove("contacts.txt") == 0) {
        std::cout << CYAN << "\nPhonebook deleted successfully!\n" << END;
    } else {
        std::cout << MAGENTA << "\nError deleting phonebook\n" << END;
    }
}