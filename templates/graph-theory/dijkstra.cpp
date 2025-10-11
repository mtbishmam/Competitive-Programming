using ll = long long;
using pll = pair<ll, ll>;
using vpll = vector<pll>;
vl dijkstra(vector<vpll>& g, int start) {
    int n = sz(g);
    set<pii> s; s.insert({ 0, start }); // w, u
    vi dis(n, LINF); dis[start] = 0;
    vb vis(n);
    while (sz(s)) {
        auto [w1, u] = *s.begin();
        s.erase(s.begin());
        if (vis[u]) continue;
        vis[u] = 1;
        for (auto& [w2, v] : g[u])
            if (w1 + w2 < dis[v]) {
                dis[v] = w1 + w2;
                s.insert({ dis[v], v });
            }
    }
    return dis;
}