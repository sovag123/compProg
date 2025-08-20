#include<iostream>
#include<vector>
using namespace std;

int main() {
    unsigned int n;
    cin >> n;
    bool start = false;
    vector<unsigned int> vals(n);
    for (int i = 0; i < n; i++) {
        unsigned int current;
        cin >> current;
        vals[i] = current;
    }
    int startIndex = 0;
    int lastIndex = 0;
    for (int i = 1; i < n; i++) {
        if (!start) {
            if (vals[i] >= vals[i - 1]) {
            } else {
                start = true;
                startIndex = i - 1;
            }
        } else {
            if (i == n - 1) {
                lastIndex = i ;
            }
            if (vals[i] > vals[i - 1]) {
                if (i == n - 1) {
                    lastIndex = i - 1;
                } else {
                    lastIndex = i -1 ;
                }
                break;
            }
        }
    }
    if ((startIndex <= 0 && lastIndex <= 0) || (startIndex == lastIndex)) {
        cout << (n + 1) / 2 << " " << (n + 1) / 2;
        return 0;
    }
    for (int i = startIndex; i >= 0; i--) {
        if (vals[i] != vals[startIndex]) {
            break;
        }
        startIndex = i;
    }
    for (int i = lastIndex; i < n; i++) {
        if (vals[i] != vals[lastIndex]) {
            break;
        }
        lastIndex = i;
    }
    if (lastIndex + 1 < n && vals[startIndex] > vals[lastIndex + 1] ) {
        cout << "impossible";
        return 0;
    }
    if (startIndex - 1 >= 0 && vals[lastIndex] < vals[startIndex- 1] ) {
        cout << "impossible";
        return 0;
    }
    for (int i = lastIndex + 1; i < n; i++) {
        if (vals[i - 1] > vals[i]) {
            cout << "impossible";
            return 0;
        }
    }
    cout << startIndex + 1 << " " << lastIndex + 1;
}
