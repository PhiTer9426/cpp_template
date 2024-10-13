#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
int mod = 998244353;

/*
给一个序列 a0 a1 ... an-1
取所有的 0 <= i1 < i2 < i3 < i4 <= n-1 四元组
计算所有 (a_i1 xor a_i2) + (a_i3 xor a_i4) 的和
*/

/*
每个位单独计算
*/ 
void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i=0; i<n; i++) cin >> a[i];

    LL res = 0;
    for(int i=0; i<31; i++) {
        int mul = (a[0] >> i) & 1;
        long long sum = 0;
        for(int j=1; j<n-2; j++) {
            bool t = (a[j] >> i) & 1;
            if(t) {
                sum += (LL)(j-mul) * (n-j-2) * (n-j-1) / 2;
            } else {
                sum += (LL)(mul) * (n-j-2) * (n-j-1) / 2;
            }
            sum %= mod;
            mul += t;
        }
        res += sum << i;
        res %= mod;
    }

    for(int i=0; i<31; i++) {
        int mul = (a[n-1] >> i) & 1;
        long long sum = 0;
        for(int j=n-2; j>=2; j--) {
            bool t = (a[j] >> i) & 1;
            if(t) {
                sum += (LL)(n-1-j-mul) * (j-1) * (j) / 2;
            } else {
                sum += (LL)(mul) * (j-1) * (j) / 2;
            }
            sum %= mod;
            mul += t;
        }
        res += sum << i;
        res %= mod;
    }

    cout << res << endl;
}