// author: mtbishmam
#include <bits/stdc++.h>
using namespace std;
using vi = vector<int>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        int n; cin >> n;
        vi a(n);
        for (int i = 0; i < n; ++i) { cin >> a[i]; --a[i]; } // zero-index
        vector<vector<int>> adj(n);
        // add undirected edge {i, a[i]} once
        for (int i = 0; i < n; ++i) {
            int j = a[i];
            if (i < j) {
                adj[i].push_back(j);
                adj[j].push_back(i);
            }
            else if (j < i) {
                // that edge was or will be added when min(i,j) processed
                // do nothing here
            }
        }
        vector<char> vis(n, 0);
        int comp = 0, cyc = 0;
        for (int i = 0; i < n; ++i) {
            if (vis[i]) continue;
            // BFS/DFS to collect component
            comp++;
            int nodes = 0;
            bool allDegTwo = true;
            stack<int> st;
            st.push(i);
            vis[i] = 1;
            while (!st.empty()) {
                int u = st.top(); st.pop();
                nodes++;
                // degree in this undirected simple graph:
                int deg = adj[u].size();
                if (deg != 2) allDegTwo = false;
                for (int v : adj[u]) {
                    if (!vis[v]) { vis[v] = 1; st.push(v); }
                }
                // Note: there might be nodes whose only incident edge was added when
                // i<ai or ai<i; if a node's edge wasn't added because i>ai, it still
                // has adjacency via the other side. We added both directions when creating edges.
            }
            if (allDegTwo) cyc++;
        }
        int paths = comp - cyc;
        int mn = cyc + (paths > 0 ? 1 : 0);
        int mx = comp;
        cout << mn << " " << mx << "\n";
    }
    return 0;
}

//

/* Lemmas
    1. Complete cycles with length > 2 will always contribute to answer and cannot be compressed
    2. All length 2 cycles can be compressed to 1, and that 1 can be used to combine 2 incomplete cycles
    3. Incomplete cycles can be compressed
*/

/* Solutions

*/

/* Analysis

*/