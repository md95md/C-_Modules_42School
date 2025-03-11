#include <iostream>
#include <string>
#include <fstream>
#include <cctype>
#include <algorithm>
#include <iomanip> // std::setw
#include <csignal>
#include <cstdlib>
#include <limits>
#include <csignal>

#define CYAN  "\033[1;36m"
#define MAGENTA  "\033[1;35m"
#define GREEN  "\033[1;32m"
#define END   "\033[0m"

void please_input_contact();
void exit_and_clean_all();
void load_contact();
void save_contact();
void handle_sigint(int signal);

inline std::string truncate_field(const std::string &str)
{
    if (str.length() > 10)
        return (str.substr(0, 9) + ".");
    else
        return (str);
}

class Contact{
    public:
    int index;
    std::string first_name;
    std::string last_name;
    std::string nickname;
    std::string phone_number;
    std::string darkest_secret;

    Contact() : index(0) {}

    Contact(int idx, std::string first, std::string last,
    std::string nick, std::string phone, std::string secret)
    : index(idx), first_name(first), last_name(last), nickname(nick),
    phone_number(phone), darkest_secret(secret) {}
    void contact_info() const;

    void display_contact_info() const
    {
        std::cout << CYAN << "Index: " << index << END << std::endl;
        std::cout << CYAN << "First Name: " << first_name << END << std::endl;
        std::cout << CYAN << "Last Name: " << last_name << END << std::endl;
        std::cout << CYAN << "Nickname: " << nickname << END << std::endl;
        std::cout << CYAN << "Phone Number: " << phone_number << END << std::endl;
        std::cout << CYAN << "Darkest Secret: " << darkest_secret << END << std::endl;
    }
};

class PhoneBook{
    public:
    Contact contacts[8];
    int contact_count;

    PhoneBook() : contact_count(0) {}
    void search_contact();
    void contact_info();

    void display_contacts_summary() const
    {
        std::cout << std::setw(10) << "     index" << "|" 
                  << std::setw(10) << "first name" << "|" 
                  << std::setw(10) << " last name" << "|" 
                  << std::setw(10) << "  nickname" << std::endl;
        for (int i = 0; i < contact_count; i++)
        {
            std::cout << std::setw(10) << contacts[i].index << "|"
                      << std::setw(10) << truncate_field(contacts[i].first_name) << "|"
                      << std::setw(10) << truncate_field(contacts[i].last_name) << "|"
                      << std::setw(10) << truncate_field(contacts[i].nickname) << std::endl;
        }
    }
};

extern PhoneBook phonebook;
extern Contact contact;
