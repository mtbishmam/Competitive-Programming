// author: mtbishmam
#include <bits/stdc++.h>
using namespace std;
using vi = vector<int>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    if (!(cin >> T)) return 0;
    while (T--) {
        int n; cin >> n;
        vi a(n);
        for (int i = 0; i < n; ++i) { cin >> a[i]; --a[i]; }

        vector<unordered_set<int>> adj(n);
        for (int i = 0; i < n; ++i) {
            int j = a[i];
            if (i == j) continue; // shouldn't happen per statement
            adj[i].insert(j);
            adj[j].insert(i);
        }

        vector<char> vis(n, 0);
        int comps = 0, cycles = 0;
        for (int i = 0; i < n; ++i) {
            if (vis[i]) continue;
            comps++;
            // DFS this component
            stack<int> st;
            st.push(i);
            vis[i] = 1;
            bool allDegTwo = true;
            while (!st.empty()) {
                int u = st.top(); st.pop();
                if (adj[u].size() != 2) allDegTwo = false;
                for (int v : adj[u]) {
                    if (!vis[v]) { vis[v] = 1; st.push(v); }
                }
            }
            if (allDegTwo) ++cycles;
        }

        int paths = comps - cycles;
        int mn = cycles + (paths > 0 ? 1 : 0);
        int mx = comps;
        cout << mn << " " << mx << '\n';
    }
    return 0;
}

//

/* Lemmas
    1. Complete cycles with length > 2 will always contribute to answer and cannot be compressed
    2. All length 2 cycles can be compressed to 1, and that 1 can be used to combine 2 incomplete cycles
    3. Incomplete cycles can be compressed with each other as well
*/

/* Solutions

*/

/* Analysis

*/