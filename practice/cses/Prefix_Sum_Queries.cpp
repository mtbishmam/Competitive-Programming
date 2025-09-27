#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <unordered_map>
#include <queue>
#include <bitset>
#include <algorithm>
#include <numeric>
#include <math.h>
#include <iomanip>
#include <cstring>
using namespace std;

#define endl "\n"
#define pb push_back
#define eb emplace_back
#define ff first
#define ss second
#define lb lower_bound
#define ub upper_bound
#define e emplace

template <typename T> istream& operator>>(istream& is, vector<T>& a) { for (auto& i : a) is >> i; return is; }
template <typename T> ostream& operator<<(ostream& os, vector<T>& a) { for (auto& i : a) os << i << " "; return os; };
// template <typename T> ostream& operator<<(ostream &os, const vector<T>& v) { os << '{'; string s; for (const auto &x : v) os << s << x, s = " "; return os << '}'; }
template <typename A, typename B> istream& operator>>(istream& is, pair<A, B>& i) { return is >> i.ff >> i.ss; }
template <typename A, typename B> ostream& operator<<(ostream& os, const pair<A, B>& i) { return os << i.ff << " " << i.ss; }
// template <typename A, typename B> ostream& operator<<(ostream& os, const pair<A, B>& i) { return os << '{' << i.ff << ", " << i.ss << '}'; }
void dbg_out() { cerr << endl; }
template <typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
#define debug(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)

using ll = long long;
using ld = long double;
using pii = pair<int, int>; using pli = pair<ll, int>;  using pil = pair<int, ll>;
using pll = pair<ll, ll>;   using vl = vector<ll>;     using vvl = vector<vl>;
using vi = vector<int>;    using vb = vector<bool>;   using vc = vector<char>;
using vvi = vector<vi>;     using vvb = vector<vb>;     using vvc = vector<vc>;
using vpii = vector<pii>;    using vpll = vector<pll>;    using vs = vector<string>;
using vvpii = vector<vpii>;   using tiii = tuple<int, int, int>;
using vtiii = vector<tiii>;
template <class A, class B> using umap = unordered_map<A, B>;

#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define add(x, y) (x + y >= MOD ? x + y - MOD : x + y)

const int dx[8] = { -1,  0, 0, 1, 1,  1, -1, -1 };
const int dy[8] = { 0, -1, 1, 0, 1, -1,  1, -1 };
const int INF = 2147483647;
const ll LINF = 9223372036854775807;
const int MOD = 1e9 + 7;
const int maxn = 1e5 + 1;

struct node {
    // ll bp, p; // best_prefix & prefix
    // node(ll _mx = 0, ll _p = 0)
    //     : bp(max(0ll, _mx)), p(_p) {}
    // node operator+(node&r) {
    //     node ret;
    //     ret.bp = max(bp, p + r.bp);
    //     ret.p = p + r.p;
    //     return ret;
    // }

    ll mx, sum, pre;
    node(ll mx = 0, ll sum = 0, ll pre = 0) : sum(sum), pre(pre), mx(max({ mx, sum, pre })) {}
    node operator+(node& r) {
        node ret;
        ret.pre = max(pre, sum + r.pre);
        ret.sum = sum + r.sum;
        ret.mx = max(ret.pre, ret.sum);
        return ret;
    }
};
struct SegmentTree {
    int n;
    vector<node> sg;
    SegmentTree(int _n) {
        n = _n;
        sg = vector<node>(4 * _n);
    }
    void build(int i, int start, int end, vi& a) {
        if (start == end) {
            sg[i] = { a[start], a[start], a[start] }; // ------------------------->
        }
        else {
            int mid = (start + end) >> 1;
            build(i * 2, start, mid, a);
            build(i * 2 + 1, mid + 1, end, a);
            sg[i] = sg[i * 2] + sg[i * 2 + 1];
        }
    }
    node query(int l, int r, int i, int start, int end) {
        if (end < l or r < start) return node();    // ------------------------->
        if (l <= start and end <= r) return sg[i];
        int mid = (start + end) >> 1;
        node left = query(l, r, i * 2, start, mid);
        node right = query(l, r, i * 2 + 1, mid + 1, end);
        return left + right;
    }
    void update(int l, int r, node cur, int i, int start, int end) {
        if (end < l or r < start) return;
        if (l <= start and end <= r) sg[i] = cur;  // ------------------------->
        else {
            int mid = (start + end) >> 1;
            update(l, r, cur, i * 2, start, mid);
            update(l, r, cur, i * 2 + 1, mid + 1, end);
            sg[i] = sg[i * 2] + sg[i * 2 + 1];
        }
    }
    node query(int l, int r) { return query(l, r, 1, 1, n - 1); }
    void update(int l, int r, node cur) { update(l, r, cur, 1, 1, n - 1); }
};

int main()
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
        vi a(n + 1);
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }
        node cur;
        SegmentTree tree(n + 1);
        tree.build(1, 1, n, a);
        while (m--) {
            int op, l, r;
            cin >> op >> l >> r;
            if (op == 1) {
                int k = l, u = r;
                cur = { u, u };
                tree.update(k, k, cur);
            }
            else cout << tree.query(l, r).mx << endl;

        }

    }
    return 0;
}