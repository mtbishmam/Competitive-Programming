#include <bits/stdc++.h>
using namespace std;

struct SegTree {
    int n;
    vector<int> tree;

    SegTree(string& s) {
        n = s.size();
        tree.resize(4 * n);
        build(s, 1, 0, n - 1);
    }

    void build(string& s, int node, int l, int r) {
        if (l == r) {
            tree[node] = 1 << (s[l] - 'a');
            return;
        }
        int mid = (l + r) >> 1;
        build(s, node * 2, l, mid);
        build(s, node * 2 + 1, mid + 1, r);
        tree[node] = tree[node * 2] | tree[node * 2 + 1];
    }

    void update(int pos, char c, int node, int l, int r) {
        if (l == r) {
            tree[node] = 1 << (c - 'a');
            return;
        }
        int mid = (l + r) >> 1;
        if (pos <= mid) update(pos, c, node * 2, l, mid);
        else update(pos, c, node * 2 + 1, mid + 1, r);
        tree[node] = tree[node * 2] | tree[node * 2 + 1];
    }

    int query(int ql, int qr, int node, int l, int r) {
        if (qr < l || ql > r) return 0;
        if (ql <= l && r <= qr) return tree[node];
        int mid = (l + r) >> 1;
        return query(ql, qr, node * 2, l, mid) |
            query(ql, qr, node * 2 + 1, mid + 1, r);
    }

    int query(int ql, int qr) { return query(ql, qr, 1, 0, n - 1); }
    void update(int pos, char c) { update(pos, c, 1, 0, n - 1); }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s; cin >> s;
    SegTree st(s);

    int q; cin >> q;
    while (q--) {
        int type; cin >> type;
        if (type == 1) {
            int pos; char c;
            cin >> pos >> c;
            pos--; // make 0-based
            st.update(pos, c);
        }
        else {
            int l, r;
            cin >> l >> r;
            l--, r--;
            int mask = st.query(l, r);
            cout << __builtin_popcount(mask) << "\n";
        }
    }
}