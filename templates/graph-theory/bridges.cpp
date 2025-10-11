void dfs(int node, int p = -1) {
    vis[node] = true;
    in[node] = low[node] = timer++;
    for (int child : g[node]) {
        if (child == p) continue;
        if (vis[child]) low[node] = min(low[node], in[child]);
        else {
            dfs(child, node);
            low[node] = min(low[node], low[child]);
            if (low[child] > in[node])
                BRIDGE(node, child);
        }
    }
}