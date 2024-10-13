#include <bits/stdc++.h>
using namespace std;

vector<int> discretize(vector<int> &nums) {
    auto num = nums;
    auto arr = nums;
    sort(num.begin(), num.end());
    num.erase(unique(num.begin(), num.end()), num.end());
    int cnt = num.size();
    for(int i = 0; i < arr.size(); i++){
        arr[i] = lower_bound(num.begin(), num.end(), arr[i]) - num.begin() + 1;
    }
    return arr;
}

// 排序 去重
vector<int> discretize2(vector<int> &nums) {
    vector<int> cp = nums;
    sort(cp.begin(), cp.end());
    cp.erase(unique(cp.begin(), cp.end()), cp.end());
    unordered_map<int, int> mp;
    for(int i=0; i<cp.size(); i++) {
        mp[cp[i]] = i+1;
    }
}