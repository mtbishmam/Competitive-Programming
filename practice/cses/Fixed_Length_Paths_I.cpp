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
#include <cassert>
#include <functional>
#include <chrono>
#include <climits>
using namespace std;

#define endl "\n"
#define V vector
#define pb push_back
#define eb emplace_back
#define ff first
#define ss second
#define lb lower_bound
#define ub upper_bound
#define em emplace
#define int int64_t

template <typename T> istream& operator>>(istream& is, vector<T>& a) { for (auto& i : a) is >> i; return is; }
template <typename T> ostream& operator<<(ostream& os, vector<T>& a) { for (auto& i : a) os << i << " "; return os; };
template <typename T> ostream& operator<<(ostream& os, set<T>& s) { for (auto i : s) os << i << " "; return os; }
template <typename A, typename B> ostream& operator<<(ostream& os, pair<A, B>& i) { return os << i.ff << " " << i.ss; }
void dbg_out() { cerr << endl; }
template <typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
#define debug(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)

using ll = int64_t;
using ld = long double;
using ull = unsigned long long;
using vi = vector<int>; using vvi = vector<vi>;
using vl = vector<ll>; using vvl = vector<vl>;
using vb = vector<bool>; using vvb = vector<vb>;
using vc = vector<char>; using vvc = vector<vc>;
using pii = pair<int, int>; using vpii = vector<pii>;
using pll = pair<ll, ll>; using vpll = vector<pll>;
using vs = vector<string>;
using tiii = tuple<int, int, int>; ; using vtiii = vector<tiii>;

#define rep(i, a, b) for (int i = (a); i < (b); i++)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define uniq(x) sort(all(x)), (x).erase(unique(all(x)), (x).end())
#define bug cerr << "!Bugged..." << endl
#define add(x, y) (x + y >= MOD ? x + y - MOD : x + y)
#define mul(x, y) (((x % MOD) * (y % MOD)) % MOD)
#define sz(x) (int)(x).size()

const string ny[] = { "NO", "YES" };
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
        int n; cin >> n;
        int k; cin >> k;
        vvi g(n);
        rep(i, 1, n) {
            int a, b; cin >> a >> b;
            g[--a].eb(--b);
            g[b].eb(a);
        }
        vb vis(n);
        vi sub(n);
        auto sub_sz = [&](auto&& f, int u, int p = -1) -> int {
            sub[u] = 1;
            for (auto& v : g[u])
                if (v != p && !vis[v])
                    sub[u] += f(f, v, u);
            return sub[u];
            };
        auto cen = [&](auto&& f, int u, int p = -1, int nn) -> int {
            int mx = 0, mxv = -1;
            for (auto& v : g[u])
                if (v != p && !vis[v]) {
                    if (sub[v] > nn / 2) {
                        if (sub[v] > mx) {
                            mx = sub[v];
                            mxv = v;
                        }
                    }
                }
            if (~mxv) return f(f, mxv, u, nn);
            return u;
            };
        auto get_dist = [&](auto&& f, int u, int p = -1, int d, vi& dist) -> void {
            if (d > k) return;
            dist.eb(d);
            for (auto& v : g[u])
                if (v != p && !vis[v]) f(f, v, u, d + 1, dist);
            };
        int ans = 0;
        auto decomp = [&](auto&& f, int u) -> void {
            int nn = sub_sz(sub_sz, u);
            int c = cen(cen, u, -1, nn);
            vis[c] = 1;

            unordered_map<int, int> mp;
            mp[0] = 1;
            for (auto& v : g[c])
                if (!vis[v]) {
                    vi dist;
                    get_dist(get_dist, v, c, 1, dist);
                    for (auto& d : dist)
                        if (k - d >= 0)
                            ans += mp[k - d];
                    for (auto& d : dist)
                        if (k >= d)
                            mp[d]++;
                }

            for (auto& v : g[c])
                if (!vis[v]) f(f, v);
            }; decomp(decomp, 0);
        cout << ans << endl;
    }
    return 0;
}

//

/* Lemmas

*/

/* Solutions

*/

/* Analysis

*/