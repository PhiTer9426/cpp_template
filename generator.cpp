#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
    cout << 100000 << ' ' << 100000;
    for(int i=0; i<100000; i++) {
        cout << i << ' ' << ((i+1)%100000) << ' ' << 'R' << endl;
    }
    return 0;
}
