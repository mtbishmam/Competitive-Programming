template <class T>
struct segtree {
    T unit = INT_MIN;
    T f(T a, T b) { return max(a, b); } // associative fn
    int n; V<T> t;
    segtree(int _n = 0) { init(_n); }
    void init(int _n) {
        n = 1; while (n < _n) n <<= 1;
        t.assign(2 * n, unit);
    }
    void update(int i, T val) {
        i += n; t[i] = val;
        for (i >>= 1; i >= 1; i >>= 1)
            t[i] = f(t[i << 1], t[i << 1 | 1]);
    }
    T query(int l, int r) {
        T lc = unit, rc = unit;
        for (l += n, r += n + 1; l < r; l >>= 1, r >>= 1) {
            if (l & 1) lc = f(lc, t[l++]);
            if (r & 1) rc = f(rc, t[--r]);
        }
        return f(lc, rc);
    }
};