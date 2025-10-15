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
        int q; cin >> q;
        vi a(n); cin >> a;
        for (auto& i : a) i--;

        int cid = 0;
        vi vis(n);
        vi cycleid(n, -1), dis_from_cyc(n), incycle(n), pos_in_cyc(n), cyclen(n);
        auto f = [&](auto&& f, int u) -> void {
            vis[u] = 1;

            int v = a[u];
            if (!vis[v]) f(f, v);
            else if (vis[v] == 1) {
                int c = v;
                vi cyc;
                do {
                    cycleid[c] = cid;
                    incycle[c] = 1;
                    dis_from_cyc[c] = 0;
                    pos_in_cyc[c] = sz(cyc);
                    cyc.eb(c);
                    c = a[c];
                } while (c != v);
                cyclen[cid] = sz(cyc);
                cid++;
            }

            if (cycleid[u] == -1 and vis[v] == 2) { // i get the problem
                cycleid[u] = cycleid[v];
                dis_from_cyc[u] = 1 + dis_from_cyc[v];
                incycle[u] = 0;
            }

            vis[u] = 2;
            };

        for (int i = 0; i < n; i++) if (!vis[i]) f(f, i);


        while (q--) {
            int a, b; cin >> a >> b;
            a--, b--;

            if (cycleid[a] != cycleid[b]) {
                cout << -1 << endl;
                continue;
            }

            // a not in cyc, b not in cyc
            if (!incycle[a] and !incycle[b]) {
                if (dis_from_cyc[a] <= dis_from_cyc[b]) {
                    cout << dis_from_cyc[b] - dis_from_cyc[a] << endl;
                }
                else cout << -1 << endl;
            }
            // a not in cyc, b in cyc
            else if (!incycle[a] and incycle[b]) {
                cout << dis_from_cyc[a] + pos_in_cyc[b] << endl;
            }
            // a in cyc, b not in cyc
            else if (incycle[a] and !incycle[b]) {
                cout << -1 << endl;
            }
            // a in cyc, b in cyc
            else if (incycle[a] and incycle[b]) {
                if (pos_in_cyc[a] <= pos_in_cyc[b]) {
                    cout << pos_in_cyc[b] - pos_in_cyc[a] << endl;
                }
                else cout << (cyclen[cycleid[a]] - pos_in_cyc[a] + pos_in_cyc[b]) << endl;
            }
        }

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

/* Gains
    Start cid or any id type counter from 0
*/