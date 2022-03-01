#include "Person.h"

Person::Person(string first_name, string last_name) {
    this -> first_name = first_name;
    this -> last_name = last_name;
}

string Person::getFirstName() {
    return this -> first_name;
}

string Person::getLastName() {
    return this -> last_name;
}

void Person::setFirstName(string new_val) {
    this -> first_name = new_val;
}

void Person::setLastName(string new_val) {
    this -> last_name = new_val;
}

Person::Person (const Person & p1) {
    this -> first_name = p1.first_name;
    this -> last_name = p1.last_name;
}

Person& Person::operator=(const Person& p) {
    this -> first_name = p.first_name;
    this -> last_name = p.last_name;
    return *this;
}

Person::~Person() {
    cout << "destructor is triggered" << endl;
}

int main() {
    Person personOne("Michael", "Jack");
    // test with firstname and lastname getters
    cout << "Test with firstname and lastname getters" << endl;
    cout << "first person's first name is: " << personOne.getFirstName() << endl;
    cout << "first person's last name is: " << personOne.getLastName() << endl;

    cout << "============================" << endl;
    // test with firstname and lastname setters
    cout << "Test with firstname and lastname setters" << endl;
    personOne.setFirstName("Tom");
    personOne.setLastName("Nick");
    cout << "first person's new first name is: " << personOne.getFirstName() << endl;
    cout << "first person's new last name is: " << personOne.getLastName() << endl;

    cout << "============================" << endl;

    // test with copy constructor
    cout << "Test with copy constructor" << endl;
    Person personTwo(personOne);
    cout << "second person's first name is: " << personTwo.getFirstName() << endl;
    cout << "second person's last name is: " << personTwo.getLastName() << endl;

    cout << "============================" << endl;

    // test with assignment operator
    cout << "Test with assignment operator" << endl;
    Person personThree = personTwo;
    cout << "third person's first name is: " << personThree.getFirstName() << endl;
    cout << "third person's last name is: " << personThree.getLastName() << endl;

    cout << "============================" << endl;
    
}