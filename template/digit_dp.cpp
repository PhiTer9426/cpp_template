#include <bits/stdc++.h>
using namespace std;

// 计算 1 - n 中每一位都不同的数字个数
int digit_dp(int n) {
    string s = to_string(n);
    int len = s.size();
    int dp[len][1 << 10];
    memset(dp, -1, sizeof dp);

    // mask 是题目限制条件
    auto &&dfs = [&](auto& self, int idx, int mask, bool is_limit, bool is_num)->int {
        if(idx == len) return is_num;
        if(!is_limit && is_num && dp[idx][mask] != -1) return dp[idx][mask];

        int res = 0;
        if(!is_num) res += self(self, idx+1, mask, 0, 0);
        int up = 9;
        if(is_limit) up = s[idx]-'0';
        for(int d = 1-is_num; d<=up; d++) {
            if((mask & (1 << d)) == 0) {
                res += self(self, idx+1, mask | (1<<d), is_limit && d == s[idx]-'0', 1);
            }
        }

        dp[idx][mask] = res;
        return res;
    };
    
    dfs(dfs, 0,0,1,0);
    return dp[0][0];
}