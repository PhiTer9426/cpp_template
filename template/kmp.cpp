#include <bits/stdc++.h>
using namespace std;

/*
对于个长度为 n 的字符串 s。
定义函数 z[i] 表示 s 和 s[i,n-1]（即以 s[i] 开头的后缀）的最长公共前缀（LCP）的长度。
z 被称为 s 的 Z 函数。特别地，z[0] = 0。

Z函数的定义就是自己和自己匹配
但部分问题你可以把两个字符串拼起来, pattern 在前, 之间加入非法字符隔开
*/

// z func 朴素实现（便于理解）
vector<int> z_function_trivial(string &s) {
    int n = (int)s.size();
    vector<int> z(n);
    for (int i = 1; i < n; ++i)
        while (i + z[i] < n && s[z[i]] == s[i + z[i]]) ++z[i];
    return z;
}
// z func 线性算法
vector<int> z_function(string &s) {
    int n = (int)s.size();
    vector<int> z(n);
    for (int i = 1, l = 0, r = 0; i < n; ++i) {
        if (i <= r && z[i - l] < r - i + 1) {
            z[i] = z[i - l];
        } else {
            z[i] = max(0, r - i + 1);
            while (i + z[i] < n && s[z[i]] == s[i + z[i]]) ++ z[i];
        }
        if (i + z[i] - 1 > r) l = i, r = i + z[i] - 1;
    }
    return z;
}


// kmp 模板
void getNext(const string &substr, vector<int> &next)
{
    next.clear();
    next.resize(substr.size());
    int j = -1;
    next[0] = -1;
    for(int i = 1; i < substr.size(); ++i)
    {
        while(j > -1 && substr[j + 1] != substr[i]) j = next[j];
        if(substr[j + 1] == substr[i]) ++j;
        next[i] = j;
    }
}

void kmp(const string &str, const string &substr, vector<int> &next, vector<int> &idx)  
{
    getNext(substr, next);
    int j = -1;
    for(int i = 0; i < str.size(); ++i)
    {
        while(j > -1 && substr[j + 1] != str[i]) j = next[j];
        if(substr[j + 1] == str[i]) ++j;
        if(j == substr.size() - 1)
        {
            idx.push_back(i + 1 - substr.size()); // get start idx
            // idx.push_back(i); // get end idx
            j = next[j];
        }
    }
}

void example() {
    vector<int> next, res;
    string s = "bbbbaaabbbaabbbaaa", t = "aaa";
    kmp(s, t, next, res);
}