#include <iostream>
using namespace std;

class Contact {
    char* full = nullptr;
    string homePhone;
    string workPhone;
    string mobPhone;
    string addinfo;

public:
    Contact(const char* full = "", const string homePhone = "", const string workPhone = "", const string mobPhone = "", const string addinfo = "") {
        this->full = new char[strlen(full) + 1];  
        strcpy_s(this->full, strlen(full) + 1, full);  
        this->homePhone = homePhone;
        this->workPhone = workPhone;
        this->mobPhone = mobPhone;
        this->addinfo = addinfo;
    }






    inline const string& getName() const
    {
        return this->full;
    }
    inline const string& getHome() const
    {
        return this->homePhone;
    }
    inline const string& getWork() const
    {
        return this->workPhone;
    } 
    inline const string& getMob() const
    {
        return this->mobPhone;
    }
    inline const string& getAdd() const
    {
        return this->addinfo;
    }
    void copyStr(char*& dest, const char* source)
    {
        if (dest != nullptr)
            delete[] dest;
        size_t size = strlen(source) + 1;
        dest = new char[size];
        strcpy_s(dest, size, source);
    }
    inline bool isValid(const char* source)
    {
        return full != nullptr and full[0] != '\0';
    }


    void setName(const char* full) {
        if (isValid(full))
            copyStr(this->full, full);
        else
            copyStr(this->full, "No name");
    }
    inline void setHomePhone(const string& homePhone) {
        this->homePhone = homePhone;
    }

    inline void setWorkPhone(const string& workPhone) {
        this->workPhone = workPhone;
    }

    inline void setMobilePhone(const string& mobPhone) {
        this->mobPhone = mobPhone;
    }

    inline void setAdditionalInfo(const string& addinfo) {
        this->addinfo = addinfo;
    }




    inline const char* getFullName() const {
        return full;
    }

    void printContact() const {
        cout << "Name: " << full << endl;
        cout << "Home Phone: " << homePhone << endl;
        cout << "Work Phone: " << workPhone << endl;
        cout << "Mobile Phone: " << mobPhone << endl;
        cout << "Additional Info: " << addinfo << endl;
           
    }
};
class PhoneBook {
    Contact* contacts = nullptr;
    size_t size = 0;
    size_t capacity = 10;
public:
    PhoneBook(Contact contact)
    {
        contacts = new Contact[capacity];
        contacts[size++] = contact;
    }
    void addContact(Contact other)
    {
        if (size > capacity)
        {
            capacity *= 2;
            Contact* tmp = new Contact[capacity];
            for (size_t i = 0; i < size; i++)
            {
                tmp[i] = contacts[i];
            }
            delete[] contacts;
            contacts = tmp;
        }
        contacts[size++] = other;
    }
    void findContact(const char* name) const {
        for (size_t i = 0; i < size; i++) {
            if (strcmp(contacts[i].getFullName(), name) == 0) {
                contacts[i].printContact();
                return;
            }
        }
        cout << "Not found!" << endl;
    }
    void deleteContact(const char* name) {
        for (size_t i = 0; i < size; i++) {
            if (strcmp(contacts[i].getFullName(), name) == 0) {
                for (size_t j = i; j < size - 1; j++) {
                    contacts[j] = contacts[j + 1];
                }
                size--;
                return;
                cout << "Contact deleted" << endl;
                
            }
        }
        cout << "Contact not found" << endl;
    }
    void showAllContacts() const {
        if (size == 0) {
            cout << "No contacts" << endl;
        }
        else {
            for (size_t i = 0; i < size; i++) {
                contacts[i].printContact();
                cout << "--------------------------" << endl;
            }
        }
    }
};

int main()
{
 Contact contact1("Maksum Rubel", "2303", "23032303", "2303", "Topdwddw");
 Contact contact2("Denus Rubel", "32332", "3233232332", "323329", "Brother");
 PhoneBook phoneBook(contact1);
 phoneBook.addContact(contact2);
 phoneBook.showAllContacts();
 cout << "\n\Search delete \n";
 phoneBook.findContact("Maksum Rubel");
 phoneBook.deleteContact("Denus Rubel");

 cout << "\n\nAfter delete \n";
 phoneBook.showAllContacts();
}
