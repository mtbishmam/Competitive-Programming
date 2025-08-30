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

#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

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
        ll n, k;
        cin >> n >> k;
        vl p(n), d(n);
        cin >> p >> d;
        ll q; cin >> q;
        vl start(q); cin >> start;

        ordered_set<pair<ll, ll>> os;
        for (ll i = 0; i < sz(p); i++) os.insert({ p[i], i });

        auto run = [&](ll pos) {
            bool flag = 1, dir = 1;
            ll ttime = 0, ctime;
            map<ll, ll> vis;

            auto skey_pos = os.order_of_key({ pos, -1 });
            if (skey_pos >= sz(os)) return flag;
            auto spit = os.find_by_order(skey_pos);
            auto spos = spit->ff;
            auto sidx = spit->ss;

            ctime = abs(pos - spos);
            ll ntime = ttime + ctime;
            if (ntime >= d[sidx] && (ntime - d[sidx]) % k == 0) dir ^= 1;
            vis[spos]++;
            ttime = ntime;
            // debug(ttime, pos, spos, dir);
            pos = spos;
            while (1) {
                ll npos, idx;
                if (dir) {
                    auto nkey_pos = os.order_of_key({ pos, INF }); // working like upper_bound
                    if (nkey_pos >= sz(os)) break; // that is >= sz(os)
                    auto npit = os.find_by_order(nkey_pos);
                    npos = npit->ff;
                    idx = npit->ss;
                }
                else {
                    auto nkey_pos = os.order_of_key({ pos, -1 }); // working like lower_bound
                    if (nkey_pos == 0) break;
                    nkey_pos--;
                    auto npit = os.find_by_order(nkey_pos);
                    npos = npit->ff;
                    idx = npit->ss;
                }

                if (vis[npos] >= 505) {
                    flag = 0;
                    break;
                }

                ctime = abs(pos - npos);
                ll ntime = ttime + ctime;
                if (ntime >= d[idx] && (ntime - d[idx]) % k == 0) {
                    dir ^= 1;
                }
                vis[npos]++;
                ttime = ntime;
                // debug(ttime, pos, npos, dir);
                pos = npos;
            }
            return flag;
            };

        for (int i = 0; i < q; i++) {
            ll pos = start[i];
            cout << (run(pos) ? "YES" : "NO") << endl;
        }
    }
    return 0;
}
// handle the first starting position

/**/


/*
    need to get faster in lower_bound/upper_bound calculations
    like how to get the one before and how to get the one after

*/