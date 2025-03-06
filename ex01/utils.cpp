#include "phonebook.hpp"

void please_input_contact()
{
    Contact contact;

    contact.index += 1;
    std::cout << "Please input the following information:" << std::endl;
    std::cout << "First Name: " << std::endl;
    std::cin >> contact.first_name;
    std::cout << "Last Name: " << std::endl;
    std::cin >> contact.last_name;
    std::cout << "Nickname: " << std::endl;
    std::cin >> contact.nickname;
    std::cout << "Phone Number: " << std::endl;
    std::cin >> contact.phone_number;
    std::cout << "Darkest Secret: "<< std::endl;
    std::cin >> contact.darkest_secret;
}

void exit_and_clean_all()
{
    std::cout << "Exiting and cleaning all...";
}