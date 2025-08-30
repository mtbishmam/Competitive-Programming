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
template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

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
    cin >> T;
    for (int Ti = 1; Ti <= T; Ti++) {
        int n, m;
        cin >> n >> m;
        vi a(n); cin >> a;
        vector<pair<pii, int>> ops[n];
        for (int i = 0; i < m; i++) {
            int e, t, p;
            cin >> e >> t >> p;
            ops[e - 1].push_back({ {t, -p}, i + 1 });
        }
        for (int i = 0; i < n; i++) {
            sort(all(ops[i]));
            for (int j = 0; j < sz(ops[i]); j++) ops[i][j].ff.ss *= -1;
        }

        vi fans;
        bool flag = true;
        ll total_time = 0;
        for (int task = 0; task < n; task++) {
            auto& tp = ops[task];
            int N = tp.size(), P = 100;
            vvi dp(N, vi(P, -1)), next(N, vi(P, -1));
            auto f = [&](auto&& f, int i, int p, ll ai) -> int {
                if (p >= P) return ai;
                if (i == N) return 0;
                auto& ret = dp[i][p];
                if (~ret) return ret;
                ret = 0;
                if (ai + tp[i].ff.ff <= a[task]) {
                    int take = f(f, i + 1, p + tp[i].ff.ss, ai + tp[i].ff.ff);
                    if (take > 0) {
                        if (next[i][p] == -1) next[i][p] = take;
                        else if (take < next[i][p]) next[i][p] = take;
                        return ret = take;
                    }
                }
                int skip = f(f, i + 1, p, ai);
                if (skip > 0) {
                    if (next[i][p] == -1) next[i][p] = 0;
                    else if (skip < next[i][p]) next[i][p] = skip;
                    return ret = skip;
                }
                return ret;
                };
            int possible = f(f, 0, 0, total_time);
            if (possible > 0) {
                int ii = 0, pp = 0;
                ll time = 0;
                while (ii < N && pp < P) {
                    if (next[ii][pp]) {
                        fans.eb(tp[ii].ss);
                        pp += tp[ii].ff.ss;
                        time += tp[ii].ff.ff;
                        ii++;
                    }
                    else ii++;
                }
                total_time += time;
            }
            else flag = false;
        }
        if (flag) {
            cout << fans.size() << endl;
            for (auto& i : fans) cout << i << " ";
            cout << endl;
        }
        else cout << -1 << endl;
    }
    return 0;
}

/* Solutions

    1. DP
        what is our goal?
        if p >= 100 by some combination
        dp[N][P]? if
        dp[N][T]
    2. 2-pointers

*/

/* Notes

    Why is it non-decreasing?
    n + m <= 2e5

    e <= n <= 2e5
    a[i], t <= 10^9
    p <= 100

*/

/* Notes
    m < n always impossible
    100% or more


*/

/* Gains
    Gonna use custom objects from now on
    Sorting gonna be better that way as well
    I shouldn't have given up before trying all my solution variations, that's a bad habit
        implement super fast without any errors


*/