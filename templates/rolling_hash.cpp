#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ull = unsigned long long;

const ll MOD1 = 1000000007;
const ll MOD2 = 1000000009;
const ll BASE = 911382323;

struct Hash {
    vector<ll> h1, h2, p1, p2;
    Hash(const string& s) {
        int n = s.size();
        h1.resize(n + 1, 0);
        h2.resize(n + 1, 0);
        p1.resize(n + 1, 1);
        p2.resize(n + 1, 1);
        for (int i = 0; i < n; i++) {
            h1[i + 1] = (h1[i] * BASE + s[i]) % MOD1;
            h2[i + 1] = (h2[i] * BASE + s[i]) % MOD2;
            p1[i + 1] = (p1[i] * BASE) % MOD1;
            p2[i + 1] = (p2[i] * BASE) % MOD2;
        }
    }
    pair<ll, ll> get(int l, int r) { // substring [l, r)
        ll x1 = (h1[r] - h1[l] * p1[r - l]) % MOD1;
        if (x1 < 0) x1 += MOD1;
        ll x2 = (h2[r] - h2[l] * p2[r - l]) % MOD2;
        if (x2 < 0) x2 += MOD2;
        return { x1, x2 };
    }
};

bool check(const string& a, const string& b, int len) {
    if (len == 0) return true;
    Hash ha(a), hb(b);
    unordered_set<ull> seen;
    for (int i = 0; i + len <= (int)a.size(); i++) {
        auto h = ha.get(i, i + len);
        ull key = ((ull)h.ff << 32) ^ h.ss;
        seen.insert(key);
    }
    for (int j = 0; j + len <= (int)b.size(); j++) {
        auto h = hb.get(j, j + len);
        ull key = ((ull)h.ff << 32) ^ h.ss;
        if (seen.count(key)) return true;
    }
    return false;
}

int longest_common_substring(const string& a, const string& b) {
    int l = 0, r = min(a.size(), b.size()), ans = 0;
    while (l <= r) {
        int mid = l + r >> 1;
        if (check(a, b, mid)) ans = mid, l = mid + 1;
        else r = mid - 1;
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string A, B;
    cin >> A >> B;
    cout << longest_common_substring(A, B) << "\n";
}
