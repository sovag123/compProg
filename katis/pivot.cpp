#include<iostream>
#include<vector>
using namespace std;
int main() {
    vector<int> possibleValues;
    int n;
    cin >>n;
    vector<int> aPrime(n);
    for (int &x : aPrime){
        cin >> x;
    }
    vector<bool> rightCandidates(n, false);
    vector<bool> leftCandidates(n, false);
    int prefixMax = aPrime[0];
    for (int i = 1; i < n; i++) {
        if (aPrime[i] > prefixMax) {
            prefixMax = aPrime[i];
            leftCandidates[i]=true;
            cout << "lijevi ovaj " << aPrime[i] << endl;
        }
    }
    int prefixMin  = aPrime[n];
    for (int i = n-1; i >= 0; i--) {
        if (aPrime[i] < prefixMin) {
            prefixMin = aPrime[i];
            rightCandidates[i]=true;
            cout << "desni ovaj " << aPrime[i] << endl;
        }
    }
    leftCandidates[0] = true;
    rightCandidates[n-1] = true;
    int counter = 0;
    for (int i = 0; i <n ; i++ ) {
        if (rightCandidates[i] && leftCandidates[i]) {
            counter++;
        }
    }
    cout << counter;
}