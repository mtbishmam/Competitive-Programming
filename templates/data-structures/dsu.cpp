struct dsu {
    int n;
    vi _sz, _par, _mx, _mn;
    dsu(int _n) : n(_n), _sz(n, 1), _par(n, -1), _mx(n, -1), _mn(n, INF) {}
    int find(int x) { return (_par[x] == -1 ? x : _par[x] = find(_par[x])); }
    int unite(int a, int b) {
        int oa = a, ob = b;
        a = find(a), b = find(b);
        if (a != b) {
            if (_sz[a] < _sz[b]) swap(a, b);
            _par[b] = a;
            _mx[a] = max({ _mx[a], ob, oa, _mx[b] });
            _mn[a] = min({ _mn[a], ob, oa, _mn[b] });
            _sz[a] += _sz[b];
            return 1;
        }
        return 0;
    }
};