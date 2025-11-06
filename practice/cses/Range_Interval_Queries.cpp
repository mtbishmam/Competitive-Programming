#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>
#include <tuple>

using namespace std;

// CRITICAL FIX: Increased node storage to safely accommodate N * log N nodes.
const int MAX_NODES = 4500000; // Increased to 4.5 million nodes

// --- Node Structure for Persistent Segment Tree ---
struct Node {
    int count;
    int left, right;
};

Node tree[MAX_NODES];
int roots[200005];
int node_count = 0;

// --- Persistent Segment Tree Functions ---

// 1. Build: Initialize a dummy tree over the range [1, M]
int build(int L, int R) {
    // Check for bounds before allocating
    if (node_count >= MAX_NODES - 1) return 0; // Emergency break for safety

    int current = ++node_count;
    tree[current].count = 0;
    if (L == R) {
        return current;
    }
    int mid = L + (R - L) / 2;
    tree[current].left = build(L, mid);
    tree[current].right = build(mid + 1, R);
    return current;
}

// 2. Update: Creates a new tree version 
int update(int prev_root, int L, int R, int val) {
    // Check for bounds before allocating
    if (node_count >= MAX_NODES - 1) return 0;

    int current = ++node_count;
    tree[current] = tree[prev_root];
    tree[current].count++;

    if (L == R) {
        return current;
    }

    int mid = L + (R - L) / 2;
    if (val <= mid) {
        tree[current].left = update(tree[prev_root].left, L, mid, val);
    }
    else {
        tree[current].right = update(tree[prev_root].right, mid + 1, R, val);
    }
    return current;
}

// 3. Query: Get the count difference between two versions (R_b - R_a-1)
int query(int root_a, int root_b, int L, int R, int queryL, int queryR) {
    // If the query range is completely outside the current node's range OR queryL > queryR
    if (queryL > R || queryR < L || queryL > queryR || L > R) {
        return 0;
    }

    // If the query range completely covers the current node's range
    if (queryL <= L && R <= queryR) {
        // Safe access: root indices are guaranteed to be > 0 if they exist in roots[0...N]
        return tree[root_b].count - tree[root_a].count;
    }

    int mid = L + (R - L) / 2;

    // Recurse and sum the differences
    return query(tree[root_a].left, tree[root_b].left, L, mid, queryL, queryR) +
        query(tree[root_a].right, tree[root_b].right, mid + 1, R, queryL, queryR);
}

// --- Main Solution ---

void solve() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, Q;
    if (!(cin >> N >> Q)) return;

    vector<int> X(N + 1);
    vector<int> all_values;

    for (int i = 1; i <= N; ++i) {
        cin >> X[i];
        all_values.push_back(X[i]);
    }

    vector<tuple<int, int, int, int>> orig_queries(Q);
    for (int i = 0; i < Q; ++i) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        orig_queries[i] = { a, b, c, d };
    }

    // --- 1. Coordinate Compression ---

    sort(all_values.begin(), all_values.end());
    all_values.erase(unique(all_values.begin(), all_values.end()), all_values.end());

    int M = all_values.size();

    // --- 2. Build Persistent Segment Tree ---

    // Root 0 represents the empty set (index prefix 0)
    roots[0] = build(1, M);

    // Build N versions
    for (int k = 1; k <= N; ++k) {
        auto it = lower_bound(all_values.begin(), all_values.end(), X[k]);
        int comp_val = distance(all_values.begin(), it) + 1;

        // Update must use a valid root from the previous state
        if (roots[k - 1] != 0) {
            roots[k] = update(roots[k - 1], 1, M, comp_val);
        }
        else {
            // Should not happen if build worked, but for safety
            roots[k] = 0;
        }
    }

    // --- 3. Process Queries ---

    for (int i = 0; i < Q; ++i) {
        auto [a, b, c, d] = orig_queries[i];

        // Find C_comp: smallest rank >= c
        auto it_c = lower_bound(all_values.begin(), all_values.end(), c);
        int C_comp = (it_c != all_values.end())
            ? distance(all_values.begin(), it_c) + 1
            : M + 1; // Map outside to ensure no count

        // Find D_comp: largest rank <= d
        auto it_d = upper_bound(all_values.begin(), all_values.end(), d);
        int D_comp = (it_d != all_values.begin())
            ? distance(all_values.begin(), it_d - 1) + 1
            : 0; // Map outside to ensure no count

        // Handle edge case where a or b are invalid (though constraints say 1 <= a <= b <= n)
        if (a < 1 || b > N || a > b) {
            cout << 0 << "\n";
            continue;
        }

        // Final query: Count(R_b, [C_comp, D_comp]) - Count(R_a-1, [C_comp, D_comp])
        long long result = query(roots[a - 1], roots[b], 1, M, C_comp, D_comp);
        cout << result << "\n";
    }
}

int main() {
    // Setting buffer to null can sometimes prevent issues, though it's mainly for performance.
    // char dummy_buffer[100000];
    // setvbuf(stdout, dummy_buffer, _IOFBF, sizeof(dummy_buffer)); 

    solve();
    return 0;
}