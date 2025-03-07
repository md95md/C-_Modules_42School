#include "phonebook.hpp"

PhoneBook phonebook;
Contact contact;

void please_input_contact()
{
    Contact new_contact;

    new_contact.index = phonebook.contact_count;
    std::cout << CYAN << "Please input the following information:" << END << std::endl;
    std::cout << "First Name: " << std::endl;
    std::cin >> new_contact.first_name;
    std::cout << "Last Name: " << std::endl;
    std::cin >> new_contact.last_name;
    std::cout << "Nickname: " << std::endl;
    std::cin >> new_contact.nickname;
    std::cout << "Phone Number(numbers only): " << std::endl;
    std::cin >> new_contact.phone_number;
    std::cout << "Darkest Secret: "<< std::endl;
    std::cin >> new_contact.darkest_secret;
    phonebook.contacts[phonebook.contact_count] = new_contact;
    phonebook.contact_count++;
    save_contact();
    std::cout << CYAN << "Contact added successfully!" << END << std::endl;
}

void exit_and_clean_all()
{
    if (std::remove("contacts.txt") == 0) {
        std::cout << CYAN << "\nPhonebook deleted successfully!" << END << std::endl;
    } else {
        std::cout << MAGENTA << "Error deleting phonebook" << END << std::endl;
    }
}