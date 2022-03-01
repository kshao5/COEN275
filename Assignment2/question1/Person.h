#include <iostream>
using namespace std;

class Person {
    private:
        string first_name;
        string last_name;
    
    public:
        Person(string first_name, string last_name);

        string getFirstName();

        string getLastName();

        void setFirstName(string new_val);

        void setLastName(string new_val);

        // copy constructor
        Person (const Person & p1);

        // assignment operator
        Person& operator=(const Person& p);

        // destructor
        ~Person();
};