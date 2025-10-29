struct node {
    ll val;
    node(ll val = 0) : val(val) {}
};
template<class T>
struct segtree {
    T f(T& a, T& b) { return a.val + b.val; }
    int n; vector<T> t;
    segtree(int n = 0) : n(n), t(4 * n, T()) {}
    T query(int L, int R, int i, int l, int r) {
        if (r < L || R < l || R < L) return T();
        if (L <= l && r <= R) return t[i];
        int mid = (l + r) >> 1;
        T lc = query(L, R, i << 1, l, mid);
        T rc = query(L, R, i << 1 | 1, mid + 1, r);
        return f(lc, rc);
    }
    void update(int pos, T val, int i, int l, int r) {
        if (l == r) return void(t[i] = val);
        int mid = (l + r) >> 1;
        if (pos <= mid) update(pos, val, i << 1, l, mid);
        else update(pos, val, i << 1 | 1, mid + 1, r);
        t[i] = f(t[i << 1], t[i << 1 | 1]);
    }
    T query(int L, int R) { return query(L, R, 1, 0, n - 1); }
    void update(int pos, int x) { update(pos, T(x), 1, 0, n - 1); }
};