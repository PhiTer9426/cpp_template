#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

struct Node
{
    i64 l, r, sum, lazytag;
};

// 区间加值，区间查询和
class SegTree {
public:
    vector<Node> tree;    

    SegTree(int n) 
    {
        tree.resize(n * 4);
        build(1, 0, n - 1);
    }

    void build(int id, int l, int r)
    {
        tree[id] = {l, r, 0, 0};
        if(l == r) return;

        int mid = (l + r) >> 1;
        build(2 * id, l, mid);
        build(2 * id + 1, mid + 1, r);
        pushup(id);
    }

    void pushup(int x)
    {
        tree[x].sum = tree[2 * x].sum + tree[2 * x + 1].sum;
    }

    void pushdown(int x)
    {
        if(tree[x].lazytag != 0) 
        {
            int lt = tree[x].lazytag;
            tree[2 * x].lazytag += lt;
            tree[2 * x].sum += lt * (tree[2 * x].r - tree[2 * x].l + 1);
            tree[2 * x + 1].lazytag += lt;
            tree[2 * x + 1].sum += lt * (tree[2 * x + 1].r - tree[2 * x + 1].l + 1);
            tree[x].lazytag = 0;
        }
    }

    void modify(int id, int l, int r, int k) //这里的k是增加的值
    {   
        if(tree[id].l >= l && tree[id].r <= r)
        {
            tree[id].sum += k * (tree[id].r - tree[id].l + 1);
            tree[id].lazytag += k;
        } 
        else 
        {
            pushdown(id);
            int mid = (tree[id].l + tree[id].r) >> 1;
            if(tree[2 * id].r >= l) modify(2 * id, l, r, k);            
            if(tree[2 * id + 1].l <= r) modify(2 * id + 1, l, r, k);
            pushup(id);
        }
    }

    i64 query(int id, int l, int r)
    {
        if(tree[id].l >= l && tree[id].r <= r) return tree[id].sum;            
        if(tree[id].r < l || tree[id].l > r) return 0;            
        pushdown(id);
        i64 s = 0;
        if(tree[2 * id].r >= l) s += query(2 * id, l, r);            
        if(tree[2 * id + 1].l <= r) s += query(2 * id + 1, l, r);            
        return s;
    }

    void rangeModify(int l, int r, int k) //这里的k是增加的值
    {  
        modify(1, l, r, k);
    }
    
    i64 rangeQuery(int left, int right) 
    {
        return query(1, left, right);
    }
};

struct NodeMx
{
    i64 l, r, mx, lazytag;
};

// 区间赋值，区间查询最大值
class SegTreeMx {
public:
    vector<NodeMx> tree;    

    SegTreeMx(int n) 
    {
        tree.resize(n * 4);
        build(1, 0, n - 1);
    }

    void build(int id, int l, int r)
    {
        tree[id] = {l, r, 0, 0};
        if(l == r) return;

        int mid = (l + r) >> 1;
        build(2 * id, l, mid);
        build(2 * id + 1, mid + 1, r);
        pushup(id);
    }

    void pushup(int x)
    {
        tree[x].mx = max(tree[2 * x].mx, tree[2 * x + 1].mx);
    }

    void pushdown(int x)
    {
        if(tree[x].lazytag != 0) 
        {
            int lt = tree[x].lazytag;
            tree[2 * x].lazytag = lt;
            tree[2 * x].mx = lt;
            tree[2 * x + 1].lazytag = lt;
            tree[2 * x + 1].mx = lt;
            tree[x].lazytag = 0;
        }
    }

    void modify(int id, int l, int r, int k)
    {   
        if(tree[id].l >= l && tree[id].r <= r)
        {
            tree[id].mx = k;
            tree[id].lazytag = k;
        } 
        else 
        {
            pushdown(id);
            int mid = (tree[id].l + tree[id].r) >> 1;
            if(tree[2 * id].r >= l) modify(2 * id, l, r, k);            
            if(tree[2 * id + 1].l <= r) modify(2 * id + 1, l, r, k);
            pushup(id);
        }
    }

    i64 query(int id, int l, int r)
    {
        if(tree[id].l >= l && tree[id].r <= r) return tree[id].mx;            
        if(tree[id].r < l || tree[id].l > r) return 0;            
        pushdown(id);
        i64 s = 0;
        if(tree[2 * id].r >= l) s = query(2 * id, l, r);            
        if(tree[2 * id + 1].l <= r) s = max(s, query(2 * id + 1, l, r));            
        return s;
    }

    void rangeModify(int l, int r, int k)
    {  
        modify(1, l, r, k);
    }
    
    i64 rangeQuery(int left, int right) 
    {
        return query(1, left, right);
    }
};

struct NodeSimple
{
    i64 l, r, lazytag;
};

// 区间赋值，单点查询
class SegTreeSimple {
public:
    vector<NodeSimple> tree;    

    SegTreeSimple(int n) 
    {
        tree.resize(n * 4);
        build(1, 0, n - 1);
    }

    void build(int id, int l, int r)
    {
        tree[id] = {l, r, 0};
        if(l == r) return;

        int mid = (l + r) >> 1;
        build(2 * id, l, mid);
        build(2 * id + 1, mid + 1, r);
    }

    void pushdown(int x)
    {
        if(tree[x].lazytag != -1) 
        {
            int lt = tree[x].lazytag;
            tree[2 * x].lazytag = lt;
            tree[2 * x + 1].lazytag = lt;
            tree[x].lazytag = -1;
        }
    }

    void modify(int id, int l, int r, int k)
    {   
        if(tree[id].l >= l && tree[id].r <= r)
        {
            tree[id].lazytag = k;
        } 
        else 
        {
            pushdown(id);
            int mid = (tree[id].l + tree[id].r) >> 1;
            if(tree[2 * id].r >= l) modify(2 * id, l, r, k);            
            if(tree[2 * id + 1].l <= r) modify(2 * id + 1, l, r, k);
        }
    }

    i64 query(int id, int idx)
    {
        if(tree[id].lazytag != -1) return tree[id].lazytag;            
        if(tree[2 * id].r >= idx) return query(2 * id, idx);            
        return query(2 * id + 1, idx);
    }

    void rangeModify(int l, int r, int k)
    {  
        modify(1, l, r, k);
    }
    
    i64 query(int idx) 
    {
        return query(1, idx);
    }
};