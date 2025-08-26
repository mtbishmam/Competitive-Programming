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
#include <climits>
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
// const int INF = 2147483647;
// const ll LINF = 9223372036854775807;
const int INF = 1e9;
const ll LINF = 1e18;
const int MOD = 1e9 + 7;
// const int MOD = 998244353;
const double EPS = 1e-9;
const double PI = acos(-1);
const int N = 1e5 + 1;

#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

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
    void update(int pos, T cur, int i, int l, int r) {
        if (l == r) {
            sg[i] = cur;
        }
        else {
            int mid = (l + r) >> 1;
            if (pos <= mid) update(pos, cur, i * 2, l, mid);
            else update(pos, cur, i * 2 + 1, mid + 1, r);
            sg[i] = sg[i * 2] + sg[i * 2 + 1];
        }
    }
    // Wrappers
    void build(vector<int>& a) { build(1, 0, n - 1, a); }
    T query(int L, int R) { return query(L, R, 1, 0, n - 1); }
    void update(int pos, int x) { update(pos, T(x), 1, 0, n - 1); }
};

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

    // ordered_set<int> os2;
    // os2.insert(1);
    // os2.insert(3);
    // os2.insert(4);
    // auto it = os2.find(3);
    // os2.erase(it);
    // for (auto x : os2) cerr << x << endl;

    int T(1);
    cin >> T;
    for (int Ti = 1; Ti <= T; Ti++) {
        int n;
        cin >> n;
        vl a(n), b(n);
        cin >> a >> b;
        // sort(all(a));
        // sort(all(b));
        // auto f = [&](vl a, vl b) -> ll {
        //     ll ret = 0;
        //     segment_tree<node_sum> tree(n);
        //     ordered_set<pii> os;
        //     for (int i = 0; i < n; i++) {
        //         tree.update(i, b[i]);
        //         os.insert({ b[i], i });
        //     }
        //     // debug(tree.query(0, n - 1).val);

        //     // ll mn = LINF; int bestidx = 0;
        //     // for (int i = 0; i < n; i++) {
        //     //     os.insert({ a[i], i + 2 * n });
        //     //     int pos = os.order_of_key({ a[i], i + 2 * n });
        //     //     ll suf = tree.query(pos, n - 1).val;
        //     //     ll pre = tree.query(0, pos - 1).val;
        //     //     debug(suf, a[i], n - pos);
        //     //     debug(pre, a[i], pos);
        //     //     ll cur = (suf - a[i] * (n - pos)) + (a[i] * pos - pre);
        //     //     debug(cur);
        //     //     debug();
        //     //     if (cur < mn) {
        //     //         mn = cur;
        //     //         bestidx = i;
        //     //     }
        //     //     os.erase(os.find({ a[i], i + 2 * n }));
        //     //     for (auto x : os) cerr << x.ff << " ";
        //     //     cerr << endl;
        //     // }
        //     // ret += mn;

        //     auto get_diff = [&](int big, int small) -> ll {
        //         if (big >= os.size() || small < 0) return LINF;
        //         auto [val1, didx1] = *os.find_by_order(big);
        //         auto [val2, didx2] = *os.find_by_order(small);
        //         return abs(val1 - val2);
        //         };

        //     ll other1, other2;
        //     other1 = other2 = LINF;
        //     for (int i = 0; i < n; i++) {
        //         if (i == bestidx) continue;
        //         os.insert({ a[i], i + 2 * n });
        //         int pos = os.order_of_key({ a[i], i + 2 * n });
        //         ll cur = min(get_diff(pos, pos - 1), get_diff(pos + 1, pos));
        //         other = min(other, cur);
        //         os.erase(os.find({ a[i], i + 2 * n }));
        //     }
        //     ret += other1;
        //     for (int i = 0; i < n; i++) {
        //         if (i == bestidx) continue;
        //         os.insert({ a[i], i + 2 * n });
        //         int pos = os.order_of_key({ a[i], i + 2 * n });
        //         ll cur = min(get_diff(pos, pos - 1), get_diff(pos + 1, pos));
        //         other2 = min(other, cur);
        //         os.erase(os.find({ a[i], i + 2 * n }));
        //     }
        //     ret += other2;
        //     return ret;
        //     };

        // cout << min(f(a, b), f(b, a)) << endl;

        ll ret = abs(a[n - 1] - b[n - 1]) + abs(a[0] - b[0]);
        ll cur = 0;
        auto get = [&](int i, int j) { return abs(a[i] - b[j]); };
        for (int i = 2; i < n; i++) {
            int i2 = i;
            int i1 = i - 2;
            int j = i - 1;
            cur += get(i1, j);
            cur += get(i2, j);
        }
        for (int j = 2; j < n; j++) {
            int j1 = j;
            int j2 = j - 2;
            int i = j - 1;
            cur += get(i, j1);
            cur += get(i, j2);
        }
        cout << min(ret, cur) << endl;
    }
    return 0;
}

/*
    find one such
*/

/* Gains
    Got really slow in os operations, forgot which ones which
    learned the best way to use ordered_set with duplicates, because we don't know

    solve sample test cases first and foremost
    wasted 1 hour implementing a complex solution which doesn't even work

*/

/* Solution
    1. The corner nodes from each lines need to be connected. So, a0 can be connected to (b0, bn, minimum_dis(a0, b))
        So, b0 should be connected to (a0, aN, minimum_dis(b0, a))
        the same will happen for aN & bN


*/