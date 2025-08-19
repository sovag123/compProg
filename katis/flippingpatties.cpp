#include<iostream>
#include<tuple>
#include<vector>
#include<cmath>
using namespace std;
int main() {
    int n;
    cin >> n;
    vector<int> max(50000,0);
    vector<tuple<int, int>>  patty(n);
    int currentMax = 0;
    for (int i = 0; i < n; i++) {
        int a,b;
        cin >> a >> b;
        max[b]++;
        max[b-a]++;
        max[b-(2*a)]++;
    }
    for (int i = 0; i < 50000; i++) {
     if (max[i]>currentMax) {
         currentMax = max[i];
     }
    }
    cout << (currentMax + 1)/2;
}