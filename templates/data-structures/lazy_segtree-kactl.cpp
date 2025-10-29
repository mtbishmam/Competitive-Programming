template<class S>
struct lazy_segtree {
    int n; V<S> t;
    lazy_segtree(int n = 0) : n(n), t(2 * n, S()) {}
    void init(const V<S>& v) {
        n = sz(v); t.assign(2 * n, S());
        build(0, 0, n - 1, v);
    } template <typename... T>
        void update(int l, int r, const T&... v) {
        assert(0 <= l && l <= r && r < n);
        update(0, 0, n - 1, l, r, v...);
    }
    S query(int l, int r) {
        assert(0 <= l && l <= r && r < n);
        return query(0, 0, n - 1, l, r);
    }
private:
    inline void push(int u, int b, int e) {
        if (t[u].lazy == 0) return;
        int mid = (b + e) >> 1;
        int rc = u + ((mid - b + 1) << 1);
        t[u + 1].update(b, mid, t[u].lazy);
        t[rc].update(mid + 1, e, t[u].lazy);
        t[u].lazy = 0;
    }
    void build(int u, int b, int e, const V<S>& v) {
        if (b == e) return void(t[u] = v[b]);
        int mid = (b + e) >> 1;
        int rc = u + ((mid - b + 1) << 1);
        build(u + 1, b, mid, v); build(rc, mid + 1, e, v);
        t[u] = t[u + 1] + t[rc];
    } template<typename... T>
        void update(int u, int b, int e, int l, int r, const T&... v) {
        if (l <= b && e <= r) return t[u].update(b, e, v...);
        push(u, b, e);
        int mid = (b + e) >> 1;
        int rc = u + ((mid - b + 1) << 1);
        if (l <= mid) update(u + 1, b, mid, l, r, v...);
        if (mid < r) update(rc, mid + 1, e, l, r, v...);
        t[u] = t[u + 1] + t[rc];
    }
    S query(int u, int b, int e, int l, int r) {
        if (l <= b && e <= r) return t[u];
        push(u, b, e);
        S res;
        int mid = (b + e) >> 1;
        int rc = u + ((mid - b + 1) << 1);
        if (r <= mid) res = query(u + 1, b, mid, l, r);
        else if (mid < l) res = query(rc, mid + 1, e, l, r);
        else res = query(u + 1, b, mid, l, r) + query(rc, mid + 1, e, l, r);
        t[u] = t[u + 1] + t[rc];
        return res;
    }
};
struct node {
    int val = 0, lazy = 0;
    node(int s = 0, int lz = 0) : val(s), lazy(lz) {}
    node operator+(const node& obj) const {
        return { val + obj.val, 0 };
    }
    void update(int b, int e, const node& x) {
        val += (e - b + 1) * x.val, lazy += x.val;
    }
};