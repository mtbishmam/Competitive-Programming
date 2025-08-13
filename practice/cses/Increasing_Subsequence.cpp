// author: mtbishmam
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <unordered_map>
#include <stack>
#include <queue>
#include <bitset>
#include <algorithm>
#include <numeric>
#include <math.h>
#include <iomanip>
#include <cstring>
// #include <cassert>
#include <functional>
#include <chrono>
using namespace std;

#define endl "\n"
#define pb push_back
#define eb emplace_back
#define ff first
#define ss second
#define lb lower_bound
#define ub upper_bound
#define em emplace
// #define int long long

template <typename T> istream& operator>>(istream& is, vector<T>& a) { for (auto& i : a) is >> i; return is; }
template <typename T> ostream& operator<<(ostream& os, vector<T>& a) { for (auto& i : a) os << i << " "; return os; };
template <typename T> ostream& operator<<(ostream& os, set<T>& s) { for (auto i : s) os << i << " "; return os; }
template <typename A, typename B> ostream& operator<<(ostream& os, pair<A, B>& i) { return os << i.ff << " " << i.ss; }
void dbg_out() { cerr << endl; }
template <typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
#define debug(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)

using ll = long long;
using ld = long double;
using ull = unsigned long long;
using vi = vector<int>; using vvi = vector<vi>;
using vl = vector<ll>; using vvl = vector<vl>;
using vb = vector<bool>; using vvb = vector<vb>;
using vc = vector<char>; using vvc = vector<vc>;
using pii = pair<int, int>; using vpii = vector<pii>;
using vs = vector<string>;
using tiii = tuple<int, int, int>; ; using vtiii = vector<tiii>;

#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define uniq(x) sort(all(x)), (x).erase(unique(all(x)), (x).end())
#define bug cerr << "!Bugged..." << endl
#define add(x, y) (x + y >= MOD ? x + y - MOD : x + y)
#define mul(x, y) (((x % MOD) * (y % MOD)) % MOD)
#define sz(x) (int)(x).size()

const string cq[2] = { "NO", "YES" };
const int dx[8] = { -1,  0, 0, 1, 1,  1, -1, -1 };
const int dy[8] = { 0, -1, 1, 0, 1, -1,  1, -1 };
const int INF = 2147483647;
const ll LINF = 9223372036854775807;
const int MOD = 1e9 + 7;
const int N = 2e5 + 1;

/* 1. Sum only (long long) */
struct node_sum {
    ll val;
    node_sum(ll val = 0) : val(val) {}
    node_sum operator+(const node_sum& r) const {
        return node_sum(val + r.val);
    }
};
/* 2. Max only (int) */
struct node_max {
    int val;
    node_max(int val = -INF) : val(val) {}
    node_max operator+(const node_max& r) const {
        return node_max(max(val, r.val));
    }
};
/* 3. Min only (int) */
struct node_min {
    int val;
    node_min(int val = INF) : val(val) {}
    node_min operator+(const node_min& r) const {
        return node_min(min(val, r.val));
    }
};
template<class T>
struct segment_tree {
    int n;
    vector<T> sg;
    segment_tree(int _n) {
        n = _n;
        sg.assign(4 * _n, T());
    }
    void build(int i, int l, int r, vector<int>& a) {
        if (l == r) {
            sg[i] = T(a[l]);
        }
        else {
            int mid = (l + r) >> 1;
            build(i * 2, l, mid, a);
            build(i * 2 + 1, mid + 1, r, a);
            sg[i] = sg[i * 2] + sg[i * 2 + 1];
        }
    }
    T query(int L, int R, int i, int l, int r) {
        if (L > R) return T();
        if (r < L || R < l) return T();
        if (L <= l && r <= R) return sg[i];
        int mid = (l + r) >> 1;
        T left = query(L, R, i * 2, l, mid);
        T right = query(L, R, i * 2 + 1, mid + 1, r);
        return left + right;
    }
    void setval(int pos, T cur, int i, int l, int r) {
        if (l == r) {
            sg[i] = cur;
        }
        else {
            int mid = (l + r) >> 1;
            if (pos <= mid) setval(pos, cur, i * 2, l, mid);
            else setval(pos, cur, i * 2 + 1, mid + 1, r);
            sg[i] = sg[i * 2] + sg[i * 2 + 1];
        }
    }
    // Wrappers
    void build(vector<int>& a) { build(1, 0, n - 1, a); }
    T query(int L, int R) { return query(L, R, 1, 0, n - 1); }
    void update(int pos, int x) { setval(pos, T(x), 1, 0, n - 1); }
};

int n;
vi a(N);
segment_tree<node_max> tree(N);

// #include<ext/pb_ds/assoc_container.hpp>
// #include<ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
// template<class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

int32_t main()
{
#ifndef ONLINE_JUDGE
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    // freopen("error.txt", "a", stderr);
#endif
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    // cout.tie(NULL);

    int T(1);
    // cin >> T;
    for (int Ti = 1; Ti <= T; Ti++) {
        cin >> n;
        vi vals;
        map<int, vi> mp;
        for (int i = 0; i < n; i++) cin >> a[i], mp[a[i]].eb(i), vals.eb(a[i]);
        uniq(vals); sort(rall(vals));
        int ans = 1;
        for (auto& val : vals) {
            auto& idxs = mp[val];
            vi dp(idxs.size(), 1);
            for (int i = 0; i < idxs.size(); i++) {
                auto& mx = dp[i];
                int idx = idxs[i];
                int prev_mx_sub = tree.query(idx + 1, n).val;
                mx = max(mx, 1 + prev_mx_sub);
                ans = max(ans, mx);
            }
            for (int i = 0; i < idxs.size(); i++) {
                auto& mx = dp[i];
                int idx = idxs[i];
                tree.update(idx, mx);
            }
        }
        cout << ans;
    }
    return 0;
}