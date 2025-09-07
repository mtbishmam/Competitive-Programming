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
#define int long long

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
using pll = pair<ll, ll>; using vpll = vector<pll>;
using vs = vector<string>;
using tiii = tuple<int, int, int>; ; using vtiii = vector<tiii>;

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
    cin >> T;
    for (int Ti = 1; Ti <= T; Ti++) {
        int n;
        cin >> n;
        vi a(n); cin >> a;
        sort(all(a));
        // debug(a);
        int lc = 1;
        multiset<int> s;
        for (auto& i : a) lc = lcm(i, lc), s.insert(i);
        // bool greater = 1;
        // for (auto& i : a) greater &= lc > i;
        // if (greater) cout << lc << endl;
        // else {
        //     cout << lc * lc << endl;
        // }
        if (n == 1) {
            cout << a[0] * a[0] << endl;
            continue;
        }

        int ans = 0;
        bool f = 1;
        int lcm = a[0] * a[n - 1];
        for (int i = 0; i < n / 2; i++) {
            int x = a[i] * a[n - i - 1];
            f &= x == lcm;
        }
        if ((n & 1) && a[n / 2] * a[n / 2] == lcm) {

        }
        else f = 0;
        if (f) ans = lcm;
        if (ans) cout << ans << endl;
        else cout << -1 << endl;
    }
    return 0;
}

/* Analysis
    t <= 25
    n <= 300
    di <= 1e6
    only one x isn't given, how can we use that?

    Time complexity (25 * n^2 * 1e6)

    48
    2 24
    2 (2, 2, 2, 3)

    3 16
    3 (2, 2, 2, 2)

    4 12
    (2, 2) (2, 2, 3)

    27
    3 9

    25
    5

    125
    5 25

    33
    3 11

    35
    5 7

    8
    2 4

    14
    2 7

    36
    2 18
    3 12
    4 9
    6 6
*/