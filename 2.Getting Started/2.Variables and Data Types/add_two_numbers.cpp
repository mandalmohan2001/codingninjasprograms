#include <iostream>
using namespace std;

int main() {
    int a = 10; // 'a' is an integer variable which takes 4 bytes to store the data
    int b = 15;
    int c = a + b; 

    cout << c << endl;

    char d = 'x'; // 'd' is a character variable which takes 1 bytes to store the data 
    cout << d << endl;

    float f = 1.23; // 'f' is is a floating point variable which takes 4 bytes to store the data

    bool b1 = true; // 'b1' is a boolean variable which takes 1 bits to store the data
    
    int size = sizeof(f);
    cout << size << endl;
}
