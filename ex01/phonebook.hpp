#include <iostream>
#include <string>

void please_input_contact();
void exit_and_clean_all();
void display_contact();
void search_contact(int indx);

class Contact{
    public:
    int index;
    std::string darkest_secret;
    std::string phone_number;
    std::string first_name;
    std::string last_name;
    std::string nickname;

    Contact() : index(0) {}

    Contact(int idx, std::string first, std::string last,
    std::string nick, std::string phone, std::string secret)
    : index(idx),
    first_name(first), last_name(last), nickname(nick), phone_number(phone),
    darkest_secret(secret) {}
    void display_contact() const;
};

class PhoneBook{
    public:
    Contact contacts[8];
    int contact_count;

    PhoneBook() : contact_count(0) {}

    void search_contact(int indx);
    void display_contact();
};

void PhoneBook::search_contact(int indx){
    if (indx < 0 || indx >= contact_count)
    {
        std::cout << "Invalid index" << std::endl;
        return;
    }
    contacts[indx].display_contact();
}

void PhoneBook::display_contact(){
    for (int i = 0; i < contact_count; i++)
    {
        contacts[i].display_contact();
    }
}
