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
        vpii xy(n);
        struct ob { int x, y, i; };
        vector<ob> a(n);
        for (int i = 0; i < n; i++) {
            // cin >> xy[i].ff >> xy[i].ss;
            cin >> a[i].x >> a[i].y;
            a[i].i = i + 1;
        }
        vector<ob> xlyl, xlyg, ylxl, ylxg, xgyl, xgyg, ygxl, ygxg;
        xlyl = xlyg = ylxl = ylxg = xgyl = xgyg = ygxl = ygxg = a;
        sort(all(xlyl), [&](ob& a, ob& b) { return a.x < b.x || (a.x == b.x && a.y < b.y); });
        sort(all(xlyg), [&](ob& a, ob& b) { return a.x < b.x || (a.x == b.x && a.y > b.y); });
        sort(all(ylxl), [&](ob& a, ob& b) { return a.y < b.y || (a.y == b.y && a.x < b.x); });
        sort(all(ylxg), [&](ob& a, ob& b) { return a.y < b.y || (a.y == b.y && a.x > b.x); });

        sort(all(xgyl), [&](ob& a, ob& b) { return a.x > b.x || (a.x == b.x && a.y < b.y); });
        sort(all(xgyg), [&](ob& a, ob& b) { return a.x > b.x || (a.x == b.x && a.y > b.y); });
        sort(all(ygxl), [&](ob& a, ob& b) { return a.y > b.y || (a.y == b.y && a.x < b.x); });
        sort(all(ygxg), [&](ob& a, ob& b) { return a.y > b.y || (a.y == b.y && a.x > b.x); });
        // sort(all(a), [&](ob& a, ob& b) { return a.x < b.x || (a.x == b.x && a.y < b.y); });
        // sort(all(b), [&](ob& a, ob& b) { return a.y < b.y || (a.y == b.y && a.x < b.x); });
        // int ans1 = 0, ans2 = 0;
        using obb = pair<int, vector<ob>>;
        vector<obb> answers;
        auto do_try = [&](vector<ob>& a) {
            int ret = 0;
            for (int i = 0; i < n / 2; i++) {
                ret += abs(a[i].x - a[n / 2 + i].x) + abs(a[i].y - a[n / 2 + i].y);
            }
            return obb{ ret, a };
            };
        answers.push_back(do_try(xlyl));
        answers.push_back(do_try(xlyg));
        answers.push_back(do_try(ylxl));
        answers.push_back(do_try(ylxg));

        answers.push_back(do_try(xgyl));
        answers.push_back(do_try(xgyg));
        answers.push_back(do_try(ygxl));
        answers.push_back(do_try(ygxg));

        sort(all(answers), [&](obb& a, obb& b) { return a.ff < b.ff; });

        // for (int i = 0; i < n / 2; i++) {
            // ans += abs(xy[i].ff - xy[n - i - 1].ff);
            // ans += abs(xy[i].ss - xy[n - i - 1].ss);

            // ans += abs(xy[i].ff - xy[n / 2 + i].ff);
            // ans += abs(xy[i].ss - xy[n / 2 + i].ss);
            // cout << a[i].i << " " << a[n / 2 + i].i << endl;
            // ans1 += abs(a[i].x - a[n / 2 + i].x) + abs(a[i].y - a[n / 2 + i].y);
            // ans2 += abs(b[i].x - b[n / 2 + i].x) + abs(b[i].y - b[n / 2 + i].y);

        // }
        auto print = [&](vector<ob>& a) {
            for (int i = 0; i < n / 2; i++)
                cout << a[i].i << " " << a[n / 2 + i].i << endl;
            };
        // debug(ans);
        // cout << ans << endl;
        // if (ans1 > ans2) print(a);
        // else print(b);
        print(answers.back().ss);
    }
    return 0;
}

//

/* Lemmas
    1. The fact that first & last matching doesn't get the max for one answer, means it won't work at all
    2. The fact that first & mid_first matching gives max doesn't mean it's the absolute correct one either

    sort less x, sort less y
    sort less x, sort greater y
    sort less y, sort less x
    sort less y, sort greater x

    sort greater x, sort less y
    sort greater x, sort greater y
    sort greater y, sort less x
    sort greater y, sort greater x
*/

/* Solutions
    1. Maybe something with pythagorian theorem?
*/

/* Analysis

*/

/* Doing this bs of ans1 > ans2 rarely ever gets ac
    what can be a brute force for these pair type questions? ask gpt
*/