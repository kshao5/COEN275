#include <iostream>
using namespace std;



string replace_string(string source_string, string find_string, string replacement_string) {
    string final_result;
    int i = 0;
    int source_string_length = source_string.length();
    int find_string_length = find_string.length();
    while (i <= source_string_length - find_string_length) {
        // the current character is not equal to the first character of find_string
        if (source_string[i] != find_string[0]) {
            final_result.push_back(source_string[i]);
            i++;
        }
        else {
            if (source_string.substr(i, find_string.length()) == find_string){
                final_result.append(replacement_string);
                i += find_string.length();
            }
            else {
                final_result.push_back(source_string[i]);
                i++;
            }
        }
    }
    while (i < source_string.length()) {
        final_result.push_back(source_string[i]);
        i++;
    }
    return final_result;
}

int main()
{
    while (true) {
        string source_string;
        string find_string;
        string new_string;
        cout << "please enter source string: " << endl;
        cin >> source_string;
        cout << "please enter the string you want to be placed with: " << endl;
        cin >> find_string;
        cout << "please enter the new value of string you want to replace: " << endl;
        cin >> new_string;
        string result = replace_string(source_string, find_string, new_string);
        cout << "the new result after replacement is: " << result << endl;

        cout << "==============================" << endl;
    }
    return 0;
}
