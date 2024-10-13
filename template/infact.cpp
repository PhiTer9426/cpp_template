#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const int N = 100001, mod = 1e9 + 7;
int fact[N], infact[N];

int qmi(int a, int k, int p)  // 求a^k mod p
{
    int res = 1 % p;
    while (k)
    {
        if (k & 1) res = (LL)res * a % p;
        a = (LL)a * a % p;
        k >>= 1;
    }
    return res;
}

void get() 
{
    fact[0] = infact[0] = 1;
    for (int i = 1; i < N; i ++ ) {
        fact[i] = (LL)fact[i-1] * i % mod;
        infact[i] = (LL)infact[i-1] * qmi(i, mod-2, mod) % mod;
    }
}