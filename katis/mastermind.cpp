#include<iostream>
#include<string>
using namespace std;
int main() {

    int n;
    cin >> n;
    string code, guess;
    cin >> code >> guess;
    int r = 0;
    int s = 0;
    for (int i = 0; i < n; i++) {
        if (i>=code.length())
            break;
        if (code[i] == guess[i]) {
            r++;
            code.erase(i,1);
            guess.erase(i,1);
            i--;
        }
    }

    for (int i = 0; i < n; i++) {
        if (i>=code.length())
            break;
        if (size_t position = code.find(guess[i]); position != string::npos) {
            s++;
            code.erase(position,1);
            guess.erase(i,1);
            i--;
        }
    }
    cout << r << " " << s;
}