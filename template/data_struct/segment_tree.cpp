#include <bits/stdc++.h>
using namespace std;

const int N = 200010;

struct Node
{
    int l, r;
    int v;  // 区间[l, r]中的最大值
};

class SegTree {
public:
    SegTree(int n) {
        tr.resize(4*n);
        build(1, 0, n-1);
    }
    
    void pushup(int u)  // 由子节点的信息，来计算父节点的信息
    {
        tr[u].v = max(tr[u << 1].v, tr[u << 1 | 1].v);
    }
    
    void build(int u, int l, int r)
    {
        tr[u] = {l, r};
        if (l == r) return;
        int mid = l + r >> 1;
        build(u << 1, l, mid), build(u << 1 | 1, mid + 1, r);
    }
    
    int query(int u, int l, int r)
    {
        if (tr[u].l >= l && tr[u].r <= r) return tr[u].v;   // 树中节点，已经被完全包含在[l, r]中了
    
        int mid = tr[u].l + tr[u].r >> 1;
        int v = 0;
        if (l <= mid) v = query(u << 1, l, r);
        if (r > mid) v = max(v, query(u << 1 | 1, l, r));
    
        return v;
    }
    
    void modify(int u, int x, int v)
    {
        if (tr[u].l == x && tr[u].r == x) tr[u].v = v;
        else
        {
            int mid = tr[u].l + tr[u].r >> 1;
            if (x <= mid) modify(u << 1, x, v);
            else modify(u << 1 | 1, x, v);
            pushup(u);
        }
    }
    
    vector<Node> tr;
};
