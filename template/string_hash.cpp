#include <bits/stdc++.h>
using namespace std;

void exp(string word) {
    int n = word.size();

    srand(time(0));
    int MOD = 998244353 + rand() % 10007;
    int BASE = 33 + rand() % 233;

    long long P[n + 1];
    P[0] = 1;
    for (int i = 1; i <= n; i++) P[i] = P[i - 1] * BASE % MOD;

    long long H[n + 1];
    H[0] = 0;
    for (int i = 1; i <= n; i++) H[i] = (H[i - 1] * BASE + word[i - 1] - 'a') % MOD;

    auto query = [&](int L, int R) {
        return (H[R] - H[L - 1] * P[R - L + 1] % MOD + MOD) % MOD;
    };

}