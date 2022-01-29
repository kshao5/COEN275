#include <iostream>
using namespace std;

template <typename T>
class OutOfBoundDetector {
    public:
        checkOutOfBound(T* arr, int index) {
            int size = sizeof(*arr);
            if (index >= size) {
                throw std::out_of_range("array index is out of bound");
            }
            else {
                cout << "array index is not out of bound" << endl;
            }
        }

        checkOutOfBound(string s, int index) {
            if (index >= s.length()) {
                throw std::out_of_range("string index is out of bound");
            }
            else {
                cout << "string index is not out of bound" << endl;
            }
        }
};

int main() {
    OutOfBoundDetector<int> myDetector;
    int input[] = {1,3,5,6};
    myDetector.checkOutOfBound(input, 2);
    cout << "============================" << endl;
    // OutOfBoundDetector<char> charDetector;
    // char input2[] = {'a','b','c','d'};
    // charDetector.checkOutOfBound(input2, 5);
    cout << "============================" << endl;
    OutOfBoundDetector<string> stringDetector;
    string input3 = "abcdef";
    stringDetector.checkOutOfBound(input3, 7); 
}
