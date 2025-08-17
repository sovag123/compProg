#include<iostream>
#include<vector>
#include<string>

using namespace std;

int main() {
    int erases;
    cin >> erases;
    string beforeDelete;
    string afterDelete;
    cin >> beforeDelete;
    cin >> afterDelete;
    for (int i = 0; i < beforeDelete.size(); i++) {
        if ((erases % 2) ==0) {
            if (beforeDelete[i]!=afterDelete[i]) {

                cout << "Deletion failed";
                return 0;
            }
        }
        else {
            if (beforeDelete[i]==afterDelete[i]) {

                cout << "Deletion failed";
                return 0;
            }

        }
    }
    cout << "Deletion succeeded";
    return 0;
}
