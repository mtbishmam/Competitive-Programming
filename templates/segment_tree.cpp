/* 1. Sum only (long long) */
struct node_sum {
    ll val;
    node_sum(ll val = 0) : val(val) {}
    node_sum operator+(const node_sum& r) const {
        return node_sum(val + r.val);
    }
};
/* 2. Max only (int) */
struct node_max {
    int val;
    node_max(int val = -INF) : val(val) {}
    node_max operator+(const node_max& r) const {
        return node_max(max(val, r.val));
    }
};
/* 3. Min only (int) */
struct node_min {
    int val;
    node_min(int val = INF) : val(val) {}
    node_min operator+(const node_min& r) const {
        return node_min(min(val, r.val));
    }
};
/* 4. Node or (int) */
struct node_or {
    int val;
    node_or(int val = 0) : val(val) {}
    node_or operator+(const node_or& r) const {
        return node_or(val | r.val);
    }
};
template<class T>
struct segment_tree {
    int n;
    vector<T> sg;
    segment_tree(int _n) {
        n = _n;
        sg.assign(4 * _n, T());
    }
    void build(int i, int l, int r, vector<int>& a) {
        if (l == r) {
            sg[i] = T(a[l]);
        }
        else {
            int mid = (l + r) >> 1;
            build(i * 2, l, mid, a);
            build(i * 2 + 1, mid + 1, r, a);
            sg[i] = sg[i * 2] + sg[i * 2 + 1];
        }
    }
    T query(int L, int R, int i, int l, int r) {
        if (R < L) return T();
        if (r < L || R < l) return T();
        if (L <= l && r <= R) return sg[i];
        int mid = (l + r) >> 1;
        T left = query(L, R, i * 2, l, mid);
        T right = query(L, R, i * 2 + 1, mid + 1, r);
        return left + right;
    }
    void update(int pos, T cur, int i, int l, int r) {
        if (l == r) {
            sg[i] = cur;
        }
        else {
            int mid = (l + r) >> 1;
            if (pos <= mid) update(pos, cur, i * 2, l, mid);
            else update(pos, cur, i * 2 + 1, mid + 1, r);
            sg[i] = sg[i * 2] + sg[i * 2 + 1];
        }
    }
    // Wrappers
    void build(vector<int>& a) { build(1, 0, n - 1, a); }
    T query(int L, int R) { return query(L, R, 1, 0, n - 1); }
    void update(int pos, int x) { update(pos, T(x), 1, 0, n - 1); }
};