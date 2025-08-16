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
using namespace std;

#define endl "\n"
#define pb push_back
#define eb emplace_back
#define ff first
#define ss second
#define lb lower_bound
#define ub upper_bound
#define em emplace

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

const string cq[2] = { "NO", "YES" };
const vi dx = { -1,  0, 0, 1, 1,  1, -1, -1 };
const vi dy = { 0, -1, 1, 0, 1, -1,  1, -1 };
const int INF = 2147483647;
const ll LINF = 9223372036854775807;
const int MOD = 1e9 + 7;
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
        int n, m;
        cin >> n >> m;
        vvc a(n, vc(m));
        int sx, sy;
        vpii mons, bounds;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> a[i][j];
                if (a[i][j] == 'A') sx = i, sy = j;
                if (a[i][j] == 'M') mons.eb(i, j);
                if (i == 0 or i == n - 1) {
                    if (a[i][j] == '.') bounds.eb(i, j);
                    if (a[i][j] == 'A') {
                        cout << "YES";
                        return 0;
                    }
                }
                if (j == 0 or j == m - 1) {
                    if (a[i][j] == '.') bounds.eb(i, j);
                    if (a[i][j] == 'A') {
                        cout << "YES";
                        return 0;
                    }
                }
            }
        }
        queue<pii> q;
        vvi mdis(n, vi(m, MOD));
        for (auto& [x, y] : mons) {
            q.push({ x, y });
            mdis[x][y] = 0;
        }
        while (q.size()) {
            auto& [x, y] = q.front();
            q.pop();
            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i], ny = y + dy[i];
                if (nx < 0 or nx >= n or ny < 0 or ny >= m or mdis[x][y] + 1 >= mdis[nx][ny] or a[nx][ny] == '#');
                else {
                    mdis[nx][ny] = mdis[x][y] + 1;
                    q.push({ nx, ny });
                }
            }
        }
        q.push({ sx, sy });
        vvi dis(n, vi(m, MOD)), path(n, vi(m));
        dis[sx][sy] = 0;
        while (q.size()) {
            auto& [x, y] = q.front();
            q.pop();
            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i], ny = y + dy[i];
                if (nx < 0 or nx >= n or ny < 0 or ny >= m or dis[x][y] + 1 >= dis[nx][ny] or a[nx][ny] == '#');
                else {
                    dis[nx][ny] = dis[x][y] + 1;
                    path[nx][ny] = i;
                    q.push({ nx, ny });
                }
            }
        }
        sort(all(bounds), [&](pii& a, pii& b) {return dis[a.ff][a.ss] < dis[b.ff][b.ss];});
        for (auto& [x, y] : bounds) {
            if (dis[x][y] < mdis[x][y]) {
                cout << "YES" << endl;
                string ans;
                int ex = x, ey = y;
                while (!(ex == sx and ey == sy)) {
                    int move = path[ex][ey];
                    if (move == 0) ans += "U";
                    else if (move == 1) ans += "L";
                    else if (move == 2) ans += "R";
                    else ans += "D";
                    ex -= dx[move];
                    ey -= dy[move];
                }
                reverse(all(ans));
                cout << ans.size() << endl;
                cout << ans;
                return 0;
            }
        }
        cout << "NO";
    }
    return 0;
}