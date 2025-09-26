struct dsu {
    int n;
    vi sz, par, mx, mn;
    dsu(int _n) : n(_n), sz(n, 1), par(n, -1), mx(n, -1), mn(n, INF) {}
    int find(int x) { return (par[x] == -1 ? x : par[x] = find(par[x])); }
    int unite(int a, int b) {
        int oa = a, ob = b;
        a = find(a), b = find(b);
        if (a != b) {
            if (sz[a] < sz[b]) swap(a, b);
            par[b] = a;
            mx[a] = max({ mx[a], ob, oa, mx[b] });
            mn[a] = min({ mn[a], ob, oa, mn[b] });
            sz[a] += sz[b];
            return 1;
        }
        return 0;
    }
};