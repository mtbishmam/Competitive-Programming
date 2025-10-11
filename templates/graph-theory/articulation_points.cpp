int n;
vvi g;
vb vis;
vi in, low;
int timer;

void dfs(int node, int p = -1) {
    vis[node] = true;
    in[node] = low[node] = timer++;
    int children = 0;
    for (int child : g[node]) {
        if (child == p) continue;
        if (vis[child]) {
            low[node] = min(low[node], in[child]);
        }
        else {
            dfs(child, node);
            low[node] = min(low[node], low[child]);
            if (low[child] >= in[node] && p != -1)
                CUTPOINT(node);
            ++children;
        }
    }
    if (p == -1 && children > 1)
        CUTPOINT(node);
}