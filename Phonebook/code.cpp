#include <iostream>
#include <bits/stdc++.h>
#include <string.h>

using namespace std;

//template for contact data type
typedef struct contact{
    string name;
    long long int no;
    string email;
    string address;
}contact;

//initializing vector of contact data type
vector<contact> Contact;

//function prototype declarations
void display();
void add_contact();
void search_contact_name(string search_name);
void search_contact_no(long long int search_no);
void edit_contact(string old_name);

//function to display PhoneBook
void display()
{
    if (Contact.size() == 0)
        cout << endl << "\aEmpty PhoneBook!" << endl;
    else
    {
        cout << endl << "Your PhoneBook:" << endl;

        int i = 1;
        for (contact cont:Contact)
        {
            cout << i << ")\t";
            cout << "Name: " << cont.name << endl;
            cout << "Phone number: " << cont.no << endl;
            cout << "    Email ID: " << cont.email << endl;
            cout << "     Address: " << cont.address << endl;
            cout << endl;
            i++;
        }
    }
}

//function to enter a new contact in the PhoneBook
void add_contact()
{
    contact new_contact;
    cout << endl << "Enter the name of the new contact: " << endl;
    getline(cin, new_contact.name);     //getline to be able to input strings with spaces
    fflush(stdin);      //to remove any remaining buffer of previous stdin

    cout << endl << "Enter the phone number of the new contact: " << endl;
    cin >> new_contact.no;
    fflush(stdin);

    cout << endl << "Enter the email id of the new contact: " << endl;
    getline(cin, new_contact.email);
    fflush(stdin);

    cout << endl << "Enter the address of the new contact: " << endl;
    getline(cin, new_contact.address);
    fflush(stdin);

    Contact.push_back(new_contact);
}

//function to search for a contact by name
void search_contact_name(string search_name)
{
    int flag = 0;
    for (contact cont:Contact)
    {
        if(cont.name == search_name)
        {
            cout << endl << "The contact you searched for is:" << endl;
            cout << "\tName: " << cont.name << endl;
            cout << "Phone number: " << cont.no << endl;
            cout << "    Email ID: " << cont.email << endl;
            cout << "     Address: " << cont.address << endl;
            cout << endl;
            flag = 1;
        }
    }

    if(flag == 0)
        cout << endl << "\aContact not found!" << endl;
}

//function to search for a contact by its phone number
void search_contact_no(long long int search_no)
{
    int flag = 0;
    for (contact cont:Contact)
    {
        if(cont.no == search_no)
        {
            cout << endl << "The contact you searched for is:" << endl;
            cout << "\tName: " << cont.name << endl;
            cout << "Phone number: " << cont.no << endl;
            cout << "    Email ID: " << cont.email << endl;
            cout << "     Address: " << cont.address << endl;
            cout << endl;
            flag = 1;
        }
    }

    if(flag == 0)
        cout << endl << "\aContact not found!" << endl;
}

//function to edit a contact
void edit_contact(string old_name)
{
    int i = 0, flag = 0;
    for (contact cont:Contact)
    {
        if(cont.name == old_name)
        {
            contact new_contact;
            cout << endl << "Enter the edited name of the contact: " << endl;
            getline(cin, new_contact.name);
            fflush(stdin);

            cout << endl << "Enter the edited phone number of the contact: " << endl;
            cin >> new_contact.no;
            fflush(stdin);

            cout << endl << "Enter the edited Email ID of the contact: " << endl;
            getline(cin, new_contact.email);
            fflush(stdin);

            cout << endl << "Enter the edited address of the contact: " << endl;
            getline(cin, new_contact.address);
            fflush(stdin);

            Contact.at(i).name = new_contact.name;
            Contact.at(i).no = new_contact.no;
            Contact.at(i).email = new_contact.email;
            Contact.at(i).address = new_contact.address;
            flag = 1;
        }

        else
            i++;
    }

    if(flag == 0)
        cout << endl << "\aContact not found!" << endl;
}

// main function block
int main()
{
    int option = 0;
    cout << "!!!\aWelcome to Banergy PhoneBook Systems\a!!!" << endl;

    do
    {
        cout << endl << "Menu of Options:" << endl;
        cout << "1. Display" << endl;
        cout << "2. Add contact" << endl;
        cout << "3. Search contact by name" << endl;
        cout << "4. Search contact by no." << endl;
        cout << "5. Edit contact" << endl;
        cout << "6. Close PhoneBook" << endl;

        cout << endl << "Enter an option from 1 to 6 of your choice:" << endl;
        cin >> option;
        fflush(stdin);

        switch(option)
        {
            case 1:
                display();
                break;

            case 2:
                add_contact();
                break;

            case 3:
                {
                    if (Contact.size() == 0)
                        cout << endl << "\aEmpty PhoneBook!" << endl;

                    else
                    {
                        string sear_name;
                        cout << endl << "Enter the name of the contact to be searched:" << endl;
                        getline(cin, sear_name);
                        search_contact_name(sear_name);
                        fflush(stdin);
                    }
                    break;
                }

            case 4:
                {
                    if (Contact.size() == 0)
                        cout << endl << "\aEmpty PhoneBook!" << endl;

                    else
                    {
                        long long int sear_no;
                        cout << endl << "Enter the phone number of the contact to be searched:" << endl;
                        cin >> sear_no;
                        search_contact_no(sear_no);
                        fflush(stdin);
                    }
                    break;
                }

            case 5:
                {
                    if (Contact.size() == 0)
                        cout << endl << "\aEmpty PhoneBook!" << endl;

                    else
                    {
                        string edit_name;
                        cout << endl << "Enter the name of the contact to be edited:" << endl;
                        getline(cin, edit_name);
                        edit_contact(edit_name);
                        fflush(stdin);
                    }
                    break;
                }

            case 6:
                cout << endl << "\aClosing PhoneBook!" << endl;
                break;

            default:
                cout << endl << "Invalid option. \aPlease enter again." << endl;
        }
    }while(option != 6);

    return 0;
}
