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
        vpii ab(n), cd(n);
        vi a, b, c, d;
        // a = b = c = d = vi(n);
        // int a, b, c, d; a = b = c = d = 0;
        int ans = 0, other = 0;
        for (int i = 0; i < n; i++) {
            int p, q, x, y;
            cin >> p >> q >> x >> y;
            // a[i] = p;
            // b[i] = q;
            // c[i] = x;
            // d[i] = y;
            // a += p;
            // b += q;
            // c += x;
            // d += y;
            // if (p == x && q != y) {
            //     ans += p;
            // }
            // else {
            //     a.eb(p);
            //     b.eb(q);
            //     c.eb(x);
            //     d.eb(y);
            //     other += abs(p - x) + abs(q - y);
            // }

            if (p > x) {
                ans += p - x;
                if (q <= y) { // ones -> do nothing

                }
                else {
                    ans += (p - (p - x)) + abs(q - y);
                }
            }
            else {
                if (q <= y) { // ones -> do nothing

                }
                else {
                    ans += p + abs(q - y);
                }
            }
        }
        sort(all(a));
        sort(all(b));
        sort(all(c));
        sort(all(d));

        cout << ans + other / 2 << endl;
    }
    return 0;
}

//

/* Lemmas
    1. Zeros are the easiest thing to do
        sum(abs(diff_zero)) / 2

        if they are more, we just move the extras
        then we get to both stacks having equal zeros,
        then we match ones ->

        if they are less, we do nothing

        the same can be done for ones

    2. if ones mismatch, we have to move all the zeros

    2. in any stack if zeros match and ones don't
        we'll have to move all the zeros to move ones
*/

/* Solutions

*/

/* Analysis

*/

/* gains
i need to increase focus
a lot and lot more focus

the brains processing power needs to increase
I need to process test cases faster

*/

// test