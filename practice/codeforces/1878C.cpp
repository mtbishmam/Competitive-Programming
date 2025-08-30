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

    auto bs = [&](ll n) {
        ll l = 0, r = 2e6, ans = 0;
        while (l <= r) {
            ll mid = l + r >> 1ll;
            if (mid * (mid + 1) <= n * 2) l = mid + 1, ans = mid;
            else r = mid - 1;
        }
        return ans;
        };

    int T(1);
    cin >> T;
    for (int Ti = 1; Ti <= T; Ti++) {
        ll n, k, x;
        cin >> n >> k >> x;
        ll extra = (k - 1) / 2 + x % (x / k);
        ll min_n = x / k + extra;
        ll max_k = bs(x);
        debug(min_n, max_k);
        if (min_n <= n and k <= max_k) cout << "YES";
        else cout << "NO";
        cout << endl;
    }
    return 0;
}

/*
    write a brute force dp to get a general answer

    5 3 10 -> YES
    for n integers the maximum sum will be n * (n + 1) / 2
    40 -> 1 39 -> 1 2 37 -> 1 2 3 34 ->

    What is the minimum number of k we need to take?
    x >= n -> n, n + 1

    so, n * (n + 1) / 2 is the maximum number of k for any integer
    we can combine any of those to

    get_maximum_k(n) < k -> NO
    if x > (n * (n + 1)) / 2 -> NO
    so, we're stating that if x <= n * (n + 1) / 2 and

    10 used -> 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 -> 55
    9 used -> 2, 3, 4, 5, 6, 7, 8, 9, 11 -> 55
    8 used -> 3, 4, 5, 6, 7, 9, 10, 11 -> 55
    7 used -> 4, 6, 7, 8, 9, 10, 11 -> 55
    6 used -> 6, 7, 9, 10, 11, 12 -> 55
    5 used -> 9, 10, 11, 12, 13 -> 55
    4 used -> 11, 12, 13, 19 -> 55
    3 used -> 13, 19, 23 -> 55
    2 used -> 23, 32 -> 55
    2 used -> 27, 28 -> a better result
*/

/*
    n 2 40 -> 19, 21, x / k + (k - 1) / 2 + x % k
    n 3 40 -> 40/3 - 13.3333 & 40%3 - 1 -> 13 + 13 + 13 -> 12 + 13 + 15
        13 + (3 - 1) / 2 + 1

    n 2 20 -> 9, 11
    n 3 20 ->

    n 2 38 -> 19, 19 -> 18, 20
    n 4 38 -> 9, 9, 9, 9, 2 -> 8, 9, 10, 11
        add =
    n 4 39 -> 9, 9, 9, 9, 3 -> 8, 9, 10, 12
    n 4 40 -> 10, 10, 10, 10

*/