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
const int MOD = 998244353;
// const double EPS = 1e-9;
const double PI = acos(-1);
const int N = 1e5 + 1;

// #include<ext/pb_ds/assoc_container.hpp>
// #include<ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
// template<class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

struct Node {
    static const int B = 31; // support up to 1e9
    array<long long, B> cntVal;   // how many elements have bit b set
    array<long long, B> cntCnt;   // sum of cnt[i] for elements with bit b set
    long long sumVal;             // Σ values
    long long sumCntVal;          // Σ values * cnt
    int len;                      // segment length

    Node(int l = 0) {
        cntVal.fill(0);
        cntCnt.fill(0);
        sumVal = sumCntVal = 0;
        len = l;
    }

    Node operator+(const Node& r) const {
        Node res(len + r.len);
        for (int b = 0; b < B; b++) {
            res.cntVal[b] = (cntVal[b] + r.cntVal[b]) % MOD;
            res.cntCnt[b] = (cntCnt[b] + r.cntCnt[b]) % MOD;
        }
        res.sumVal = (sumVal + r.sumVal) % MOD;
        res.sumCntVal = (sumCntVal + r.sumCntVal) % MOD;
        return res;
    }
};

struct LazySegTree {
    int n;
    vector<Node> sg;
    vector<int> lazyXor;
    vector<int> lazyCnt;

    LazySegTree(int _n) {
        n = _n;
        sg.assign(4 * n, Node());
        lazyXor.assign(4 * n, 0);
        lazyCnt.assign(4 * n, 0);
    }

    void build(int i, int l, int r, const vector<int>& a) {
        if (l == r) {
            sg[i] = Node(1);
            sg[i].sumVal = a[l] % MOD;
            sg[i].sumCntVal = sg[i].sumVal; // cnt=1 initially
            for (int b = 0; b < Node::B; b++) {
                if ((a[l] >> b) & 1) {
                    sg[i].cntVal[b] = 1;
                    sg[i].cntCnt[b] = 1; // cnt=1 initially
                }
            }
        }
        else {
            int m = (l + r) / 2;
            build(i * 2, l, m, a);
            build(i * 2 + 1, m + 1, r, a);
            sg[i] = sg[i * 2] + sg[i * 2 + 1];
        }
    }

    void applyCntAdd(int i, int add) {
        sg[i].sumCntVal = (sg[i].sumCntVal + sg[i].sumVal * add) % MOD;
        for (int b = 0; b < Node::B; b++) {
            sg[i].cntCnt[b] = (sg[i].cntCnt[b] + sg[i].cntVal[b] * 1LL * add) % MOD;
        }
        lazyCnt[i] += add;
    }

    void applyXor(int i, int mask) {
        for (int b = 0; b < Node::B; b++) {
            if ((mask >> b) & 1) {
                long long bitVal = (1LL << b) % MOD;
                long long ones = sg[i].cntVal[b];
                long long zeros = sg[i].len - ones;

                // flip cntVal
                sg[i].cntVal[b] = zeros;

                // flip sumVal
                sg[i].sumVal = (sg[i].sumVal + ((zeros - ones) * bitVal) % MOD + MOD) % MOD;

                // flip cntCnt
                long long withBit = sg[i].cntCnt[b];
                long long totalCnt = (1LL * sg[i].len * lazyCnt[i]) % MOD;
                sg[i].cntCnt[b] = (totalCnt - withBit + MOD) % MOD;

                // adjust sumCntVal
                sg[i].sumCntVal = (sg[i].sumCntVal + ((totalCnt - 2 * withBit + MOD) % MOD) * bitVal) % MOD;
            }
        }
        lazyXor[i] ^= mask;
    }

    void push(int i, int l, int r) {
        if (l == r) return;
        int m = (l + r) / 2;
        if (lazyCnt[i]) {
            applyCntAdd(i * 2, lazyCnt[i]);
            applyCntAdd(i * 2 + 1, lazyCnt[i]);
            lazyCnt[i] = 0;
        }
        if (lazyXor[i]) {
            applyXor(i * 2, lazyXor[i]);
            applyXor(i * 2 + 1, lazyXor[i]);
            lazyXor[i] = 0;
        }
    }

    void update(int L, int R, int x, int i, int l, int r) {
        if (R < l || r < L) return;
        if (L <= l && r <= R) {
            applyCntAdd(i, 1); // cnt[i] += 1
            applyXor(i, x);    // apply XOR mask
            return;
        }
        push(i, l, r);
        int m = (l + r) / 2;
        update(L, R, x, i * 2, l, m);
        update(L, R, x, i * 2 + 1, m + 1, r);
        sg[i] = sg[i * 2] + sg[i * 2 + 1];
    }

    Node query(int L, int R, int i, int l, int r) {
        if (R < l || r < L) return Node();
        if (L <= l && r <= R) return sg[i];
        push(i, l, r);
        int m = (l + r) / 2;
        return query(L, R, i * 2, l, m) + query(L, R, i * 2 + 1, m + 1, r);
    }

    // wrappers
    void build(const vector<int>& a) { build(1, 0, n - 1, a); }
    void update(int L, int R, int x) { update(L, R, x, 1, 0, n - 1); }
    long long query(int L, int R) { return query(L, R, 1, 0, n - 1).sumCntVal % MOD; }
};

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
        int n;
        cin >> n;
        vi a(n); cin >> a;
        LazySegTree tree(n);
        tree.build(a);
        ll ans = 0;
        for (int i = n - 1; i >= 0; i--) {
            int l = i + 1, r = n - 1;
            if (l <= r) {
                tree.update(l, r, a[i]);
                ll val = tree.query(l, r);
                ans = (ans + val) % MOD;
            }
        }
        cout << ans;
    }
    return 0;
}

/* SOLs
    1. Segment tree?


*/

/*
    row-wise is impossible, because we don't know any xor sum properties (a + b + c + d + e) * 1 + (a + b + c + d) * 2

*/