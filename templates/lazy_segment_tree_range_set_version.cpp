struct node {
    ll val, mn, mx;
    node(ll val = 0, ll mn = 0, ll mx = 0) :
        val(val), mn(mn), mx(mx) {
    }
    node operator+(const node& r) const {
        return { val + r.val, min(mn, r.mn), max(mx, r.mx) };
    }
};

struct Lazy {
    ll add = 0;       // pending add
    ll set = 0;       // pending set
    bool hasSet = false; // is set pending?
};

template<class T> struct lazy_segment_tree {
    int n;
    vector<T> sg;
    vector<Lazy> lazy;

    lazy_segment_tree(int _n) {
        n = _n;
        sg.assign(4 * n, T());
        lazy.assign(4 * n, Lazy());
    }

    void build(int i, int l, int r, vector<ll>& a) {
        if (l == r) {
            sg[i] = { a[l], a[l], a[l] };
        }
        else {
            int mid = (l + r) >> 1;
            build(i * 2, l, mid, a);
            build(i * 2 + 1, mid + 1, r, a);
            sg[i] = sg[i * 2] + sg[i * 2 + 1];
        }
    }

    void applySet(int i, int l, int r, ll x) {
        sg[i].val = (r - l + 1) * x;
        sg[i].mn = x;
        sg[i].mx = x;
        if (l != r) {
            lazy[i * 2].hasSet = lazy[i * 2 + 1].hasSet = true;
            lazy[i * 2].set = lazy[i * 2 + 1].set = x;
            lazy[i * 2].add = lazy[i * 2 + 1].add = 0;
        }
    }

    void applyAdd(int i, int l, int r, ll x) {
        sg[i].val += (r - l + 1) * x;
        sg[i].mn += x;
        sg[i].mx += x;
        if (l != r) {
            if (lazy[i * 2].hasSet) lazy[i * 2].set += x;
            else lazy[i * 2].add += x;

            if (lazy[i * 2 + 1].hasSet) lazy[i * 2 + 1].set += x;
            else lazy[i * 2 + 1].add += x;
        }
    }

    void prop(int i, int l, int r) {
        if (lazy[i].hasSet) {
            applySet(i, l, r, lazy[i].set);
            lazy[i].hasSet = false;
        }
        if (lazy[i].add != 0) {
            applyAdd(i, l, r, lazy[i].add);
            lazy[i].add = 0;
        }
    }

    T query(int L, int R, int i, int l, int r) {
        prop(i, l, r);
        if (R < l || r < L) return T(0, LINF, -LINF);
        if (L <= l && r <= R) return sg[i];
        int mid = (l + r) >> 1;
        return query(L, R, i * 2, l, mid) + query(L, R, i * 2 + 1, mid + 1, r);
    }

    void updateAdd(int L, int R, ll x, int i, int l, int r) {
        prop(i, l, r);
        if (R < l || r < L) return;
        if (L <= l && r <= R) {
            lazy[i].add += x;
            prop(i, l, r);
            return;
        }
        int mid = (l + r) >> 1;
        updateAdd(L, R, x, i * 2, l, mid);
        updateAdd(L, R, x, i * 2 + 1, mid + 1, r);
        sg[i] = sg[i * 2] + sg[i * 2 + 1];
    }

    void updateSet(int L, int R, ll x, int i, int l, int r) {
        prop(i, l, r);
        if (R < l || r < L) return;
        if (L <= l && r <= R) {
            lazy[i].hasSet = true;
            lazy[i].set = x;
            lazy[i].add = 0;
            prop(i, l, r);
            return;
        }
        int mid = (l + r) >> 1;
        updateSet(L, R, x, i * 2, l, mid);
        updateSet(L, R, x, i * 2 + 1, mid + 1, r);
        sg[i] = sg[i * 2] + sg[i * 2 + 1];
    }

    // wrappers
    void build(vector<ll>& a) { build(1, 0, n - 1, a); }
    T query(int L, int R) { return query(L, R, 1, 0, n - 1); }
    void updateAdd(int L, int R, ll x) { updateAdd(L, R, x, 1, 0, n - 1); }
    void updateSet(int L, int R, ll x) { updateSet(L, R, x, 1, 0, n - 1); }
};