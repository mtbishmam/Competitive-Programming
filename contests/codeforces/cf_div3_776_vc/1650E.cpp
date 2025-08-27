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
        ll n, d;
        cin >> n >> d;
        vl a(n);
        cin >> a;
        a.push_back(0);
        sort(all(a));
        auto get_min_diff = [&](vi a) {
            ll mn = LINF;
            for (int i = 1; i < a.size(); i++) {
                ll dif = a[i] - a[i - 1] - 1;
                ckmin(mn, dif);
            }
            return mn;
            };
        auto chk = [&](int mid) {
            ll mn = LINF;
            vi spaces;
            for (int i = 1; i < a.size(); i++) {
                ll dif = a[i] - a[i - 1] - 1;
                ckmin(mn, dif);
                spaces.push_back(dif);
            }
            // spaces.push_back(n - a[n - 1]);
            sort(all(spaces));

            vi problems;
            int mx_space = spaces.back();
            int mx_space_idx = 0;
            for (int i = 1; i < a.size(); i++) {
                ll dif = a[i] - a[i - 1] - 1;
                if (dif == mn) {
                    problems.pb(i);
                }
                if (dif == mx_space) {
                    mx_space_idx = i - 1;
                }
            }
            int lst_space = d - a[n - 1];
            if (sz(problems) >= 3) return 0;
            if (sz(problems) == 1) {
                if (max((mx_space - 1) / 2, lst_space - 1) >= mid) return true;
            }
            else {

            }
            for (auto& i : problems) {
                int l = i - 1;
                int r = i + 1;
                int other = 0;
                if (0 <= l and r < a.size()) {
                    other = a[r] - a[l] - 1;
                }

                int mx = max((mx_space - 1) / 2, lst_space - 1);
                mx = max(mx, (other - 1) / 2);

                set<int> s(all(a));
                int val = a[i];
                s.erase(val);
                s.insert()
                    vi b(all(s));

            }
            // also put the last space
            };
        ll ans = get_min_diff(a);

    }
    return 0;
}

// consider if he keeps it unchanged

/*
    Solution-
    1. Binary search?
        The problem is that we can only rearrage one exam
        So, we should always go for the exams with the minimum difference?
        But, there can be n exams with minimum difference...
    2. think about the spaces?
        Let's say we can move the maximum number of unused spaces to somwhere?


    so binary search is the way it seems
        set a minium arbitary space between exams
        if there are three of exams with less than that, then that is impossible
        let's say there is only one exam
            then we'll try with both of those pairs?
                and put it in the maximum available space?
                    so if the maximum available space - 1 >= mid, then it's possible


                        so the maximum diff can be max of diffs of other exams
                        orr the max diff excluding that exam and taking the

        let's say there are two such exams

    The ending doesn't matter
*/

/* Gains
I solved this one by inversing the problem


*/