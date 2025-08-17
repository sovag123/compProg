#include<iostream>
#include<vector>

using namespace std;

int main() {
    long int n;
    cin >> n;
    int A[n];
    for (int i= 0; i < n; i++ ) {
        cin >> A[i];
    }
    if (n == 1) {
        cout << 1 << endl;
        cout << A[0];
    }
    else {
        vector<int> result;
        int current = A[0];
        result.push_back(current);

        for (int i = 0; i< n; i++) {
            if (A[i]> current) {
                current = A[i];
                result.push_back(current);
            }
        }
        cout << result.size() << endl;
        for (int number : result) {
            cout << number << " ";
        }
    }
}