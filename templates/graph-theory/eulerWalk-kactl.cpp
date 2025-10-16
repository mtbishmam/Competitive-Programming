vi eulerWalk(vector<vpii>& gr, int nedges, int src = 0) {
    int n = sz(gr);
    vi D(n), its(n), eu(nedges), ret, s = { src };
    D[src]++; // to allow Euler paths, not just cycles
    while (!s.empty()) {
        int x = s.back(), y, e, & it = its[x], end = sz(gr[x]);
        if (it == end) { ret.push_back(x); s.pop_back(); continue; }
        tie(y, e) = gr[x][it++];
        if (!eu[e]) {
            D[x]--, D[y]++;
            eu[e] = 1;
            s.push_back(y);
        }
    }
    for (int& x : D) if (x < 0 || sz(ret) != nedges + 1) return {};
    return { ret.rbegin(), ret.rend() };
}

void solve() {
    int n; cin >> n;
    int m; cin >> m;
    vector<vpii> g(n);
    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        g[--a].eb(--b, i);
        g[b].eb(a, i);
    }
    vi ans = eulerWalk(g, m, 0);
    if (!sz(ans) or ans.front() != ans.back()) cout << "IMPOSSIBLE";
    else for (auto& i : ans) cout << i + 1 << " ";
}