#include "phonebook.hpp"

void load_contact()
{
    std::ifstream infile("contacts.txt");
    if (!infile)
    {
        std::cout << MAGENTA << "\nPhonebook is empty\n" << END << std::endl;
        return;
    }
    phonebook.contact_count = 0;
    while (phonebook.contact_count < 8 && !infile.eof()) {
        Contact temp;
        std::getline(infile, temp.first_name);
        std::getline(infile, temp.last_name);
        std::getline(infile, temp.nickname);
        std::getline(infile, temp.phone_number);
        std::getline(infile, temp.darkest_secret);
        if (temp.first_name == "")
            break;
        temp.index = phonebook.contact_count;
        phonebook.contacts[phonebook.contact_count] = temp;
        phonebook.contact_count++;
    }
    infile.close();
}

void save_contact(){
    std::ofstream outfile("contacts.txt");
    if (!outfile)
        return;
    for (int i = 0; i < phonebook.contact_count; i++) {
        Contact c = phonebook.contacts[i];
        outfile << c.first_name << "\n"
                << c.last_name << "\n"
                << c.nickname << "\n"
                << c.phone_number << "\n"
                << c.darkest_secret << "\n";
    }
    outfile.close();
}

void PhoneBook::contact_info(){
    for (int i = 0; i < contact_count; i++)
    {
        contacts[i].contact_info();
    }
};

void Contact::contact_info() const{
    std::cout << "Index: " << index << std::endl;
    std::cout << "First Name: " << first_name << std::endl;
    std::cout << "Last Name: " << last_name << std::endl;
    std::cout << "Nickname: " << nickname << std::endl;
};

void PhoneBook::search_contact(int indx){
    if (indx < 0 || indx >= contact_count)
    {
        std::cout << MAGENTA << "There is no contact at this index\n" << END;
        return;
    }
    contacts[indx].contact_info();
};


