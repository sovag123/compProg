#include<iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    string code, guess;
    int r=0, s = 0;
    for (int i = 0; i < n; i++) {
        if (code[i] == guess[i]) {
            r++;
        }
    }
}