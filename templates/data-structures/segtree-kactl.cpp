template <class T>
struct segtree {
    T unit = INT_MIN;
    T f(T& a, T& b) { return max(a, b); } // associative function
    int n;
    vector<T> t;

    segtree(int _n = 0) { init(_n); }

    void init(int _n) {
        n = 1;
        while (n < _n) n <<= 1;
        t.assign(2 * n, unit);
    }

    void build(const vector<T>& a) {
        int _n = a.size();
        for (int i = 0; i < _n; ++i) t[n + i] = a[i];
        for (int i = n - 1; i >= 1; --i)
            t[i] = f(t[i << 1], t[i << 1 | 1]);
    }

    void update(int i, T val) {
        t[i += n] = val;
        for (i >>= 1; i >= 1; i >>= 1)
            t[i] = f(t[i << 1], t[i << 1 | 1]);
    }

    T query(int l, int r) {
        T lc = unit, rc = unit;
        for (l += n, r += n; l <= r; l >>= 1, r >>= 1) {
            if (l & 1) lc = f(lc, t[l++]);
            if (!(r & 1)) rc = f(rc, t[r--]);
        }
        return f(lc, rc);
    }
};