#include <iostream>
#include <string>

class PhoneBook{


    public:
    char contacts[8];


};

class Contact{

    public:
    std::string first_name;
    std::string last_name;
    std::string nickname;
    std::string phone_number;
    std::string darkest_secret;
};

void please_input_contact();
void add_new_contact();
void display_contacts();
void exit_and_clean_all();