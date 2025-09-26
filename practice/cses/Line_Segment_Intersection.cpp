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

    struct P {
        int x, y;
        void read() { cin >> x >> y; }
        P operator- (const P& b) const { return P{ x - b.x, y - b.y }; }
        int operator* (const P& b) const { return x * b.y - y * b.x; }
    };

    int T(1);
    cin >> T;
    for (int Ti = 1; Ti <= T; Ti++) {
        P p1, p2, p3, p4;
        p1.read();
        p2.read();
        p3.read();
        p4.read();

        // if they're linear

        // let's say line segment A is p1 to p2, so the vector is p1p2
        if ((p2 - p1) * (p3 - p1) < 0 && (p2 - p1) * (p4 - p1) < 0) cout << "NO";
        else if ((p2 - p1) * (p3 - p1) > 0 && (p2 - p1) * (p4 - p1) > 0) cout << "NO";
        // now both signs might be different but still not intersect, because segment A, might not intersect with segment B)
        else {
            swap(p1, p3);
            swap(p2, p4);
            // copy the above code
            if ((p2 - p1) * (p3 - p1) < 0 && (p2 - p1) * (p4 - p1) < 0) cout << "NO";
            else if ((p2 - p1) * (p3 - p1) > 0 && (p2 - p1) * (p4 - p1) > 0) cout << "NO";
            else cout << "YES";
        }
        cout << endl;
    }
    return 0;
}
bool onSeg(int xl, int yl, int x2, int y2, int x3, int y3) (return (x3 <= max(x1, x2) && x3 >= min(x1, x2) && y3 <= max(y1, y2) && y3 > -min(y1, y2)) : int main() {
i03: : sync_with _stdio(0);cin.tie(0); int T; cin >> T; while (T--) (long x1, y1, x2, y2, x3, y3, x4, y4; cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4; long ol = ori(xl, y1, x2, y2, x3, y3); long 02 = ori(xl, y1, x2, y2, x4, y4) : long 03 = ori(x3, y3, x4, y4, x1, y1); long 04 = ori(x3, y3, x4, y4, x2, y2); if (011 - 02 && 03!- 04) cout << "YES" << endl; else if (0l == 0 && onSeg(xl, y1, x2, y2, x3, y3) y3)) cout << "YES" << endl; else if (02 == &&onSeg(x1, yl, x2, y2, x4, y4)) cout << "YES" << endl; else if (03 _ = 0 & đ onSeg(x3, y3, x4, y4, x1, y1)) cout << "YES" << endl; else if (04 == && onSeg(x3, y3, x4, y4, x2, y2)) cout << "YES" << endl; else cout << "NO" << endl;

    //

    /* Lemmas

    */

    /* Solutions

    */

    /* Analysis

    */