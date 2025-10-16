struct Dinic {
    struct Edge {
        int to, rev; ll c, oc;
        ll flow() { return max(oc - c, (int)0); } // using (int) bc ll gives bug
    }; // flow() gives actual flow
    vi lvl, ptr, q;
    vector<vector<Edge>> adj;
    Dinic(int n) : lvl(n), ptr(n), q(n), adj(n) {}
    void addEdge(int a, int b, ll c, ll rcap = 0) {
        adj[a].push_back({ b, sz(adj[b]), c, c });
        adj[b].push_back({ a, sz(adj[a]) - 1, rcap, rcap });
    } // rcap = c on bidirectional
    ll dfs(int v, int t, ll f) {
        if (v == t || !f) return f;
        for (int& i = ptr[v]; i < sz(adj[v]); i++) {
            Edge& e = adj[v][i];
            if (lvl[e.to] == lvl[v] + 1)
                if (ll p = dfs(e.to, t, min(f, e.c))) {
                    e.c -= p, adj[e.to][e.rev].c += p;
                    return p;
                }
        }
        return 0;
    }
    ll calc(int s, int t) {
        ll flow = 0; q[0] = s;
        rep(L, 0, 31) do { // 'int L=30' maybe faster for random data
            lvl = ptr = vi(sz(q));
            int qi = 0, qe = lvl[s] = 1;
            while (qi < qe && !lvl[t]) {
                int v = q[qi++];
                for (Edge e : adj[v])
                    if (!lvl[e.to] && e.c >> (30 - L))
                        q[qe++] = e.to, lvl[e.to] = lvl[v] + 1;
            }
            while (ll p = dfs(s, t, LLONG_MAX)) flow += p;
        } while (lvl[t]);
        return flow;
    }
    bool leftOfMinCut(int a) { return lvl[a] != 0; }
};

void solve() {
    int n; cin >> n;
    int m; cin >> m;
    Dinic d(n);
    for (int i = 0; i < m; i++) {
        int a, b, c; cin >> a >> b >> c;
        d.addEdge(--a, --b, c);
    }
    cout << d.calc(0, n - 1);
}