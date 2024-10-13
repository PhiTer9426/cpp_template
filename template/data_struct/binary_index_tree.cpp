#include <bits/stdc++.h>
using namespace std;

class BIT {
public:
    long long tree[30050];
    vector<int> num;
    int n;

    //初始化，tree下标从1开始
    BIT(vector<int>& nums) {  
        num = nums;
        memset(tree, 0, sizeof(tree));
        n = nums.size();
        for(int i = 1; i <= n; i++){
            add(i, nums[i - 1]);
        }
    }

    int lowbit(int x) {
        return x & -x;
    }

    long long query(int x) {
        long long ans = 0;
        for(int i = x; i > 0; i -= lowbit(i)) 
            ans += tree[i];
        return ans;
    }

    void add(int x, int u) {      
        for(int i = x; i <= n; i += lowbit(i)) 
            tree[i] += u;
    }
    
    void update(int index, int val) { 
        add(index + 1, val - num[index]);
        num[index] = val;
    }
    
    //查询[left,right]区间和   （left，right下标从0开始）
    long long sumRange(int left, int right) { 
        return query(right + 1) - query(left);
    }
};