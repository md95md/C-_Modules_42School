#include <iostream>
#include <string>
#include <fstream>

#define CYAN  "\033[1;36m"
#define MAGENTA  "\033[1;35m"
#define GREEN  "\033[1;32m"
#define END   "\033[0m"

void please_input_contact();
void exit_and_clean_all();
void contact_info();
void search_contact(int indx);

void load_contact();
void save_contact();

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
    : index(idx),
    first_name(first), last_name(last), nickname(nick), phone_number(phone),
    darkest_secret(secret) {}
    void contact_info() const;
};

class PhoneBook{
    public:
    Contact contacts[8];
    int contact_count;

    PhoneBook() : contact_count(0) {}

    void search_contact(int indx);
    void contact_info();
};

extern PhoneBook phonebook;
extern Contact contact;
