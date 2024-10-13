#include <bits/stdc++.h>
using namespace std;

class Trie2 {
  public:
    int child[26];
    bool isWord;
    int idx;
};

void example()
{
    vector<string> words;

    int volum = 0;
    for (string &s : words)
        volum += s.size() + 1;

    Trie2 tree[volum];
    int bound = 0;
    memset(tree, 0, sizeof tree);

    auto insert = [&](string &word, int id) {
        int t = 0;
        for (auto c : word) {
            if (tree[t].child[c - 'a'] == 0) {
                tree[t].child[c - 'a'] = ++bound;
            }
            t = tree[t].child[c - 'a'];
        }
        tree[t].isWord = true;
        tree[t].idx = id;
    };

    // insert
    for (int i = 0; i < words.size(); i++) {
        insert(words[i], i);
    }

    auto search = [&](string s) -> int {
        int p = 0;
        for (int i = 0; i < s.size(); i++) {
            if (tree[p].child[s[i] - 'a'] == 0) {
                break;
            }
            p = tree[p].child[s[i] - 'a'];
            if (tree[p].isWord) {
                return tree[p].idx;
            }
        }
        return -1;
    };
}

class Trie {
    Trie *child[26];
    bool isWord;

  public:
    Trie()
    {
        isWord = false;
        for (int i = 0; i < 26; i++) {
            child[i] = nullptr;
        }
    }

    void insert(string word)
    {
        Trie *t = this;
        for (auto c : word) {
            if (t->child[c - 'a'] == nullptr) {
                t->child[c - 'a'] = new Trie;
            }
            t = t->child[c - 'a'];
        }
        t->isWord = true;
    }

    bool search(string word)
    {
        Trie *t = this;
        for (auto c : word) {
            if (t->child[c - 'a'] == nullptr) {
                return false;
            }
            t = t->child[c - 'a'];
        }
        return t->isWord;
    }

    bool startsWith(string prefix)
    {
        Trie *t = this;
        for (auto c : prefix) {
            if (t->child[c - 'a'] == nullptr) {
                return false;
            }
            t = t->child[c - 'a'];
        }
        return true;
    }
};