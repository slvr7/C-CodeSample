#include <string>
#include <iostream>
#include <memory>
#include <functional>
#include <sstream>
using namespace std;


struct Address
{
    string street, city;
    int suite;

    Address(const string& street, const string& city, const int suite)
        : street{ street },
        city{ city },
        suite{ suite }
    {
    }

    friend ostream& operator<<(ostream& os, const Address& obj)
    {
        return os
            << "street: " << obj.street
            << " city: " << obj.city
            << " suite: " << obj.suite;
    }
};

struct Contact
{
public:
    string name;
    Address* address;

    Contact(const string& name, Address* address) : name(name), address(address)
    {

    }

    Contact(const Contact& other)
        : name{ other.name }
        //, address{ new Address{*other.address} }
    {
        address = new Address(
            other.address->street,
            other.address->city,
            other.address->suite
        );
    }

    ~Contact()
    {
        delete address;
    }

    friend ostream& operator<<(ostream& os, const Contact& obj)
    {
        return os
            << "name: " << obj.name
            << " works at " << *obj.address; // note the star here
    }
};

struct EmployeeFactory
{
    static Contact main;
    static Contact aux;

    static unique_ptr<Contact> NewMainOfficeEmployee(string name, int suite)
    {
        //static Contact p{ "", new Address{ "123 East Dr", "London", 0 } };
        return NewEmployee(name, suite, main);
    }

    static unique_ptr<Contact> NewAuxOfficeEmployee(string name, int suite)
    {
        return NewEmployee(name, suite, aux);
    }

private:
    static unique_ptr<Contact> NewEmployee(string name, int suite, Contact& proto)
    {
        auto result = make_unique<Contact>(proto);
        result->name = name;
        result->address->suite = suite;
        return result;
    }
};

Contact EmployeeFactory::main{ "", new Address{ "123 East Dr", "London", 0 } };
Contact EmployeeFactory::aux{ "", new Address{ "123B East Dr", "London", 0 } };

int main()
{
   // Contact john{ "John Doe", new Address{"123 East Dr", "London", 5} };

    string name = "alice";
    Contact alice{ name, new Address{"123 East Dr", "London", 5} };
    cout << alice << endl;

    auto john = EmployeeFactory::NewAuxOfficeEmployee("John Doe", 123);
    cout << *john << endl;
}
