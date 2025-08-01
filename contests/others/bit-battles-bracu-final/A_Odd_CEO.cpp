#include <bits/stdc++.h>
using namespace std;

/*
   Odd CEO – reference implementation
   ----------------------------------
   Time   : O(N)
   Memory : O(N)
*/

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    if (!(cin >> N)) return 0;

    vector<int> deg(N + 1, 0);
    for (int i = 1, u, v; i < N; ++i) {
        cin >> u >> v;
        ++deg[u];
        ++deg[v];
    }

    // If total number of employees is even, impossible by parity argument
    if (N % 2 == 0) {
        cout << 0 << '\n';
        return 0;
    }

    int even_deg_cnt = 0;        // vertices with even degree
    for (int i = 1; i <= N; ++i)
        if (deg[i] % 2 == 0) ++even_deg_cnt;

    // Exactly one vertex must have even degree – that one can be CEO
    cout << (even_deg_cnt == 1 ? 1 : 0) << '\n';
    return 0;
}
