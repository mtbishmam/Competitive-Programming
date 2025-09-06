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
    // cin >> T;
    for (int Ti = 1; Ti <= T; Ti++) {
        int n, m, k;
        cin >> n >> m >> k;
        vvc a(n, vc(m));
        for (auto& ai : a) cin >> ai;
        queue<pii> q;
        vvb vis(n, vb(m));
        vvi dis(n, vi(m));
        vpii disnodes[n * m + 5];
        auto isvalid = [&](int x, int y) { return (0 <= x and x < n) and (0 <= y and y < m); };

        for (int i = 0; i < n; i++) {
            bool f = 0;
            for (int j = 0; j < m; j++) {
                if (!vis[i][j] && a[i][j] == '.') {
                    q.push({ i, j });
                    vis[i][j] = 1;
                    dis[i][j] = 1;
                    disnodes[dis[i][j]].eb(i, j);
                    f = 1;
                    break;
                }
            }
            if (f) break;
        }

        while (q.size()) {
            auto [x, y] = q.front();
            q.pop();

            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                if (isvalid(nx, ny) && a[nx][ny] != '#' && !vis[nx][ny]) {
                    q.push({ nx, ny });
                    vis[nx][ny] = 1;
                    dis[nx][ny] = dis[x][y] + 1;
                    disnodes[dis[nx][ny]].eb(nx, ny);
                }
            }
        }

        for (int i = n * m + 4; i >= 1; i--) {
            for (auto& [x, y] : disnodes[i]) {
                a[x][y] = 'X';
                k--;
                if (!k) break;
            }
            if (!k) break;
        }

        // for (int i = 0; i < n; i++) {
        //     for (int j = 0; j < m; j++) {
        //         cout << dis[i][j] << " ";
        //     }
        //     cout << endl;
        // }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cout << a[i][j];
            }
            cout << endl;
        }

    }
    return 0;
}

/* Sols
    1. Using bfs to get distance and mark only the ones at maximum distance to be walls
        but, where should we start the bfs from? let's say we start it randomly
        #12# -> works
        32#6
      #345

      #123
        #2#4
        10#65
        987#
        10#8#


    2. Run outer loop from the outer border to the inner ones filling
        #..# -> if we mark (0, 2) it'll be bad
        ##.#

        #..#
        #.##

    3. Mark ones with maximum neighbours, and the only ones that'll be affected are the 6 cells in 6 other directions of it
        #..#
        ..#.
        #...

        #.##
        ..#.
        #...

        #.## -> but if we do this, that's a problem
        ..#.
        ##..

    4. Mark and check?
*/