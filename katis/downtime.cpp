#include<iostream>
using namespace std;

int main() {
    int requestCount, requestPerSecond;
    cin >> requestCount >> requestPerSecond;
    int requestTracker[101001] = {};
    for (int i = 0; i < requestCount; i++) {
        int currentTime;
        cin >> currentTime;
        requestTracker[currentTime]+=1;
        requestTracker[currentTime+1000]-=1;
    }
    int total = 0;
    int currentMax = 0;
    for (int i = 0; i< 100000; i++) {
        total+=requestTracker[i];
        if (total>currentMax) {
            currentMax=total;
        }
    }
    if (currentMax % requestPerSecond == 0 ) {
        cout << currentMax / requestPerSecond;
    }
    else
        cout << currentMax / requestPerSecond + 1;
}