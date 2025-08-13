#include <bits/stdc++.h>
using namespace std;

struct SegTree {
    int size;
    vector<int> tree;
    void init(int n) {
        size = 1;
        while (size < n) size <<= 1;
        tree.assign(2 * size, 0);
    }
    void update(int pos, int val) {
        pos += size;
        tree[pos] = val;
        for (pos /= 2; pos > 0; pos /= 2)
            tree[pos] = max(tree[2 * pos], tree[2 * pos + 1]);
    }
    int query(int l, int r) {
        if (l > r) return 0;
        int res = 0;
        l += size; r += size;
        while (l <= r) {
            if (l & 1) res = max(res, tree[l++]);
            if (!(r & 1)) res = max(res, tree[r--]);
            l >>= 1; r >>= 1;
        }
        return res;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;
    vector<int> h(n);
    for (auto& x : h) cin >> x;

    vector<int> L(n, -1), R(n, n);
    stack<int> st;

    // Nearest strictly greater on left
    for (int i = 0; i < n; i++) {
        while (!st.empty() && h[st.top()] <= h[i]) st.pop();
        if (!st.empty()) L[i] = st.top();
        st.push(i);
    }

    while (!st.empty()) st.pop();

    // Nearest strictly greater on right
    for (int i = n - 1; i >= 0; i--) {
        while (!st.empty() && h[st.top()] <= h[i]) st.pop();
        if (!st.empty()) R[i] = st.top();
        st.push(i);
    }

    // for (auto& i : L) cerr << i << " ";
    // cerr << endl;
    // for (auto& i : R) cerr << i << " ";


    // Group mountains by height
    map<int, vector<int>> height_groups;
    for (int i = 0; i < n; i++) {
        height_groups[h[i]].push_back(i);
    }

    SegTree seg;
    seg.init(n);

    int ans = 1;
    for (auto& [height, positions] : height_groups) {
        vector<int> new_dp(positions.size());
        for (int i = 0; i < (int)positions.size(); i++) {
            int pos = positions[i];
            int left_bound = L[pos] + 1;
            int right_bound = R[pos] - 1;
            int best = seg.query(left_bound, right_bound);
            new_dp[i] = 1 + best;
            ans = max(ans, new_dp[i]);
        }
        for (int i = 0; i < (int)positions.size(); i++) {
            seg.update(positions[i], new_dp[i]);
        }
    }

    cout << ans << "\n";
    return 0;
}