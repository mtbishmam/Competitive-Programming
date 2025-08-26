struct node {
    ll val, mn, mx;
    node(ll val = 0, ll mn = 0, ll mx = 0) :
        val(val), mn(mn), mx(mx) {
    }
    node operator+(node& r) {
        node ret;
        ret.val = val + r.val;
        ret.mn = min(mn, r.mn);
        ret.mx = max(mx, r.mx);
        return ret;
    }
};
template<class T> struct lazy_segment_tree {
    int n;
    vector<T> sg, lazy;
    lazy_segment_tree(int _n) {
        n = _n;
        sg = vector<T>(4 * _n);
        lazy = vector<T>(4 * n);
    }
    void prop(int i, int l, int r) {
        if (lazy[i].val) {
            ll len = (r - l + 1);
            sg[i].val += len * lazy[i].val;
            sg[i].mn += lazy[i].val;
            sg[i].mx += lazy[i].val;
            if (l != r) {
                lazy[i * 2].val += lazy[i].val;
                lazy[i * 2 + 1].val += lazy[i].val;
            }
            lazy[i].val = 0;
        }
    }
    void build(int i, int l, int r, vi& a) {
        if (l == r) {
            sg[i] = { a[l], a[l], a[l] }; // ------------------------->
        }
        else {
            int mid = (l + r) >> 1;
            build(i * 2, l, mid, a);
            build(i * 2 + 1, mid + 1, r, a);
            sg[i] = sg[i * 2] + sg[i * 2 + 1];
        }
    }
    T query(int L, int R, int i, int l, int r) {
        prop(i, l, r);
        if (L > R) return T();
        if (r < L or R < l) return T(0, LINF, -LINF);    // ------------------------->
        if (L <= l and r <= R) return sg[i];
        int mid = (l + r) >> 1;
        T left = query(L, R, i * 2, l, mid);
        T right = query(L, R, i * 2 + 1, mid + 1, r);
        return left + right;
    }
    void set(int L, int R, T cur, int i, int l, int r) {
        prop(i, l, r);
        if (L > R) return;
        if (r < L or R < l) return;
        if (L <= l and r <= R) {
            sg[i] = cur;                // ------------------------->
            prop(i, l, r);
        }
        else {
            int mid = (l + r) >> 1;
            set(L, R, cur, i * 2, l, mid);
            set(L, R, cur, i * 2 + 1, mid + 1, r);
            sg[i] = sg[i * 2] + sg[i * 2 + 1];
        }
    }
    void update(int L, int R, T cur, int i, int l, int r) {
        prop(i, l, r);
        if (L > R) return;
        if (r < L or R < l) return;
        if (L <= l and r <= R) {
            lazy[i] = lazy[i] + cur;                // ------------------------->
            prop(i, l, r);
        }
        else {
            int mid = (l + r) >> 1;
            update(L, R, cur, i * 2, l, mid);
            update(L, R, cur, i * 2 + 1, mid + 1, r);
            sg[i] = sg[i * 2] + sg[i * 2 + 1];
        }
    }
    void set(int L, int R, T cur) { set(L, R, cur, 1, 0, n - 1); }
    void set(int L, int R, ll x) { set(L, R, { x, x, x }, 1, 0, n - 1); }
    void update(int L, int R, T cur) { update(L, R, cur, 1, 0, n - 1); }
    void update(int L, int R, ll x) { update(L, R, { x, x, x }, 1, 0, n - 1); }
    T query(int L, int R) { return query(L, R, 1, 0, n - 1); }
};


int main() {
    int n; cin >> n;
    for (int i = 0; i < n; i++) if (s[i] == '?') s[i] = ')', cl.eb(i);
    vi a(n);
    lazy_segment_tree<node> tree(n);
    for (int i = 0, cur = 0; i < n; i++) {
        cur += (s[i] == ')' ? -1 : 1);
        a[i] = cur;
        tree.update(i, i, cur);
    }
    // cerr << s << endl;
    bool ok = 1;
    for (auto& o : op) {
        tree.update(o, n - 1, -2);
        auto it = lb(all(cl), o);
        if (it != cl.end()) {
            int clp = *it;
            tree.update(clp, n - 1, 2);
            auto nd = tree.query(0, n - 1);
            auto lst = tree.query(n - 1, n - 1);
            if (nd.mn >= 0 and !lst.mn) {
                ok = 0;
            }
            tree.update(clp, n - 1, -2);
        }
        tree.update(o, n - 1, 2);
    }
}