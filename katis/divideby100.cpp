#include<iostream>
#include<string>
using namespace std;

int main() {
    string divided, divisor;
    cin >> divided >> divisor;
    while (divisor.back() == '0' && divided.back() == '0') {
        divisor.pop_back();
        divided.pop_back();
    }
    int difference = divisor.length();
    difference = divided.length() - difference + 1;

    if (difference == divided.length()) {
        cout << divided;
        return 0;
    }
    if (divided.length() < divisor.length()) {
        cout << "0.";
        for (int i = 0; i < divisor.length() - divided.length() - 1; i++) {
            cout << '0';
        }
        cout << divided;
        return 0;
    }
    for (int i = 0; i < difference; i++) {
        cout << divided[i];
    }
    cout << '.';
    for (int i = difference; i < divided.length();i++) {
        cout << divided[i];
    }
    return 0;

}