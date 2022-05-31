#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;
struct newContact
{
    string firstName;
    string secondName;
    string email;
    string birthDate;
    string gender;
    string phoneNumber;
};
void printAll(vector<newContact> &contact)
{
    if (contact.size() > 0)
    {
        ifstream myFile;
        myFile.open("allContacts.txt", ofstream::in);
        if (myFile.is_open())
        {
            string l;
            while (getline(myFile, l))
            {
                cout << l << endl;
            }
            myFile.close();
        }
    }
    else
    {
        cout << "No student in data base" << endl;
    }
}
void addNewContact(vector<newContact> &contact)
{
    newContact person;
    cout << "--------" << endl;
    cout << "Adding new contact..." << endl;
    cout << "--------" << endl;
    cout << "1.Enter first name: " << endl;
    cin >> person.firstName;
    person.firstName[0] = toupper(person.firstName[0]);
    cout << "2.Enter second name: " << endl;
    cin >> person.secondName;
    person.secondName[0] = toupper(person.secondName[0]);
    cout << "2.Enter user email: " << endl;
    cin >> person.email;
    cout << "3.Enter phone number: " << endl;
    cin >> person.phoneNumber;
    cout << "4.Enter user birth date: " << endl;
    cin >> person.birthDate;
    cout << "5.Enter user gender: " << endl;
    cin >> person.gender;
    person.gender[0] = toupper(person.gender[0]);
    contact.push_back(person);
}
void addContactToDataBase(vector<newContact> &contact)
{
    ofstream myFile;
    myFile.open("allContacts.txt", ofstream::out);
    myFile << "List of all contacts: " << endl;
    if (myFile.is_open())
    {
        for (int i = 0; i < contact.size(); i++)
        {
            myFile << i + 1 << "."
                   << " ";
            myFile << "Name: " << contact[i].firstName << " ";
            myFile << contact[i].secondName << " ";
            myFile << " Email: " << contact[i].email << " ";
            myFile << " Phone number: " << contact[i].phoneNumber << " ";
            myFile << " Birth date: " << contact[i].birthDate << " ";
            myFile << " Gender: " << contact[i].gender << endl;
        }
        myFile.close();
    }
    system("clear");
}
void deleteContact(vector<newContact> &contact)
{
    if (contact.size() > 0)
    {
        system("clear");
        printAll(contact);
        cout << "Enter the index of contact to delete: " << endl;
        int index;
        cin >> index;
        vector<newContact>::iterator it;
        it = contact.begin() + index;
        index++;
        ifstream is("allContacts.txt");
        ofstream ofs;
        ofs.open("temp.txt", ofstream::out);
        char c;
        int line = 1;
        while (is.get(c))
        {
            if (c == '\n')
            {
                line++;
            }
            if (line != index)
            {
                ofs << c;
            }
        }

        ofs.close();
        is.close();
        remove("allContacts.txt");
        rename("temp.txt", "allContacts.txt");
        contact.erase(it);
        system("clear");
    }
    else
    {
        cout << "No student in data base" << endl;
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector<newContact> contact;
    while (true)
    {
        cout << "---------" << endl;
        cout << "MENU" << endl;
        cout << "---------" << endl;
        cout << "1.Add new contact" << endl;
        cout << "2.Delete existing contact" << endl;
        cout << "3.Print all contacts: " << endl;
        cout << "4.Clear the screen: " << endl;
        cout << "5.EXIT: " << endl;
        cout << "Choose what you wanna do: " << endl;
        int choice;
        cin >> choice;
        system("clear");
        switch (choice)
        {
        case 1:
            addNewContact(contact);
            addContactToDataBase(contact);
            break;
        case 2:
            deleteContact(contact);
            break;
        case 3:
            printAll(contact);
            break;
        case 4:
            system("clear");
            break;
        case 5:
            cout << "Thank you for using !" << endl;
            exit(0);
        default:
            cout << "You have choosen a wrong number, try one more time" << endl;
            break;
        }
    }
    return 0;
}