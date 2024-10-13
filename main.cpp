#include <bits/stdc++.h>
using namespace std;

int main () {
    cout << '[';
    for(int i=1; i<=10; i++) {
        cout << '[';
        for(int j=1; j<=9; j++) {
            cout << j << ',';
        }
        cout << "100],";
    }
    cout << ']';
}