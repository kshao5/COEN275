#include <stdio.h>
#include <string.h>
#include <iostream>
#include "CustomString.h"
using namespace std;

CustomString::CustomString() {
    string_size = 0;
    string_value = nullptr;
}

CustomString::CustomString(const char* input_value) {
    string_size = strlen(input_value);
    string_value = new char[string_size + 1];
    memcpy(string_value, input_value, string_size);
    string_value[string_size] = '\0';
}

CustomString::CustomString(const CustomString& other) {
    cout << "Copy constructor is invoked" << endl;
    string_size = other.string_size;
    string_value = new char[string_size + 1];
    memcpy(string_value, other.string_value, string_size);
    string_value[string_size] = '\0';
}

CustomString::CustomString(CustomString&& other) {
    cout << "Move constructor is invoked" << endl;
    string_size = other.string_size;
    string_value = other.string_value;

    other.string_size = 0;
    other.string_value = nullptr;
}

CustomString::~CustomString() {
    string_size = 0;
    string_value = nullptr;
}

CustomString CustomString::operator + (CustomString const & obj) {
    CustomString newString;
    newString.string_size = this->string_size + obj.string_size;
    newString.string_value = new char[newString.string_size + 1];
    int i = 0;
    int current_idx = 0;
    while (i < string_size && i < obj.string_size) {
        (newString.string_value)[current_idx] = string_value[i];
        current_idx ++;
        (newString.string_value)[current_idx] = obj.string_value[i];
        current_idx ++;
        i++;
    }
    while (i < string_size) {
        (newString.string_value)[current_idx] = string_value[i];
        current_idx ++;
        i++;
    }
    while (i < obj.string_size) {
        (newString.string_value)[current_idx] = (obj.string_value)[i];
        current_idx ++;
        i++;
    }
    newString.string_value[newString.string_size] = '\0';
    return newString;
}

bool isEqual(CustomString& first, CustomString& second) {
    // compare lengths
    if (first.string_size != second.string_size) {
        return false;
    }
    int size = first.string_size;
    for (int i = 0; i < size; i++) {
        if (first.string_value[i] != second.string_value[i]) {
            return false;
        }
    }
    return true;
}

int main() {
    // test with default constructor
    CustomString emptyString;
    cout << "the number of characters in empty custom string is: " << emptyString.string_size << endl;
    if (emptyString.string_value == nullptr) {
        cout << "The value of empty custom string is null" << endl;
    }
    else {
        cout << "The value of empty custom string is: " << emptyString.string_value << endl;
    }
    
    cout << "==================================================" << endl;

    // test with another constructor that takes char* as parameter
    char firstInput[] = "Hello World";
    CustomString secondCustomString(firstInput);
    cout << "The number of characters in second custom string is: " << secondCustomString.string_size << endl;
    cout << "The value of second custom string is: " << secondCustomString.string_value << endl;

    cout << "==================================================" << endl;

    // test with copy constructor
    CustomString thirdCustomString(secondCustomString);
    cout << "The number of characters in third custom string is: " << thirdCustomString.string_size << endl;
    cout << "The value of third custom string is: " << thirdCustomString.string_value << endl;

    cout << "==================================================" << endl;

    // test with move constructor
    CustomString fromString("Banana");
    cout << "The number of characters in fromString is: " << fromString.string_size << endl;
    cout << "The value of fromString is: " << fromString.string_value << endl;

    CustomString toString(std::move(fromString));
    if (fromString.string_size == 0) {
        cout << "After move constructor is called, the value of fromString is null" << endl;
    }
    cout << "The number of characters in toString is: " << toString.string_size << endl;
    cout << "The value of toString is: " << toString.string_value << endl;
    
    cout << "==================================================" << endl;

    // test with + operator (input string lengths are the same)
    CustomString stringOne("cat");
    CustomString stringTwo("dog");
    CustomString stringSumOne = stringOne + stringTwo;
    cout << "The number of characters in first string sum is: " << stringSumOne.string_size << endl;
    cout << "The value of first string sum is: " << stringSumOne.string_value << endl;
    
    cout << "==================================================" << endl;

    // test with + operator (input string lengths are different)
    CustomString stringThree("apple");
    CustomString stringFour("oranges");
    CustomString stringSumTwo = stringThree + stringFour;
    cout << "The number of characters in second string sum is: " << stringSumTwo.string_size << endl;
    cout << "The value of second string sum is: " << stringSumTwo.string_value << endl;

    cout << "==================================================" << endl;

    // test with + operator (one of input string is empty)
    CustomString stringFive("");
    CustomString stringSix("tomorrow");
    CustomString stringSumThree = stringFive + stringSix;
    cout << "The number of characters in the third string sum is: " << stringSumThree.string_size << endl;
    cout << "The value of third string sum is: " << stringSumThree.string_value << endl;

    cout << "==================================================" << endl;

    // test with + operator (both input strings are empty)
    CustomString stringSeven("");
    CustomString stringEight("");
    CustomString stringSumFour = stringSeven + stringEight;
    cout << "The number of characters in the fourth string sum is: " << stringSumFour.string_size << endl;
    cout << "The value of fourth string sum is: " << stringSumFour.string_value << endl;

    cout << "==================================================" << endl;

    // test with + operator (both input strings have significantly different lengths)
    CustomString stringNine("objectorientedprogramming");
    CustomString stringTen("cat");
    CustomString stringSumFive = stringNine + stringTen;
    cout << "The number of characters in the fifth string sum is: " << stringSumFive.string_size << endl;
    cout << "The value of fifth string sum is: " << stringSumFive.string_value << endl;

    cout << "==================================================" << endl;

    // test with compare function (two Custom Strings are the same)
    CustomString inputOne("orange");
    CustomString inputTwo("orange");
    cout << "Test case 1: ";
    if (isEqual(inputOne, inputTwo)) {
        cout << "Two custom strings are equal" << endl;
    }
    else {
        cout << "Two custom strings are not equal" << endl;
    }

    // test with compare function (two Custom Strings have different lengths)
    CustomString inputThree("apple");
    CustomString inputFour("banana");
    cout << "Test case 2: ";
    if (isEqual(inputThree, inputFour)) {
        cout << "Two custom strings are equal" << endl;
    }
    else {
        cout << "Two custom strings are not equal" << endl;
    }

    // test with compare function (two custom strings are different but have same length)
    CustomString inputFive("yesterday");
    CustomString inputSix("tomorrowa");
    cout << "Test case 3: ";
    if (isEqual(inputFive, inputSix)) {
        cout << "Two custom strings are equal" << endl;
    }
    else {
        cout << "Two custom strings are not equal" << endl;
    }

    // test with compare function (two custom strings are the same except one letter is upper case, the other letter is lower case )
    CustomString inputSeven("Saturday");
    CustomString inputEight("saturday");
    cout << "Test case 4: ";
    if (isEqual(inputSeven, inputEight)) {
        cout << "Two custom strings are equal" << endl;
    }
    else {
        cout << "Two custom strings are not equal" << endl;
    }

}
