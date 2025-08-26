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
// template <typename T> ostream& operator<<(ostream &os, const vector<T>& v) { os << '{'; string s; for (const auto &x : v) os << s << x, s = " "; return os << '}'; }
template <typename A, typename B> istream& operator>>(istream& is, pair<A, B>& i) { return is >> i.ff >> i.ss; }
template <typename A, typename B> ostream& operator<<(ostream& os, pair<A, B>& i) { return os << i.ff << " " << i.ss; }
template <typename A, typename B> ostream& operator<<(ostream& os, map<A, B>& mp) { for (auto i : mp) os << i << ", "; return os; }
// template <typename A, typename B> ostream& operator<<(ostream& os, const pair<A, B>& i) { return os << '{' << i.ff << ", " << i.ss << '}'; }
void dbg_out() { cerr << endl; }
template <typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
#define debug(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)

using ll = long long; using ld = long double; using ull = unsigned ll;
using pii = pair<int, int>; using pli = pair<ll, int>; using pil = pair<int, ll>;
using pll = pair<ll, ll>; using vl = vector<ll>; using vvl = vector<vl>;
using vi = vector<int>; using vb = vector<bool>; using vc = vector<char>;
using vvi = vector<vi>; using vvb = vector<vb>; using vvc = vector<vc>;
using vpii = vector<pii>; using vpll = vector<pll>; using vs = vector<string>;
using vvpii = vector<vpii>; using vvvi = vector<vvi>; using vvvl = vector<vvl>;
using vull = vector<ull>;
using tiii = tuple<int, int, int>; ; using vtiii = vector<tiii>;
template <class A, class B> using umap = unordered_map<A, B>;

#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define bug cerr << "!Bugged..." << endl
#define add(x, y) (x + y >= MOD ? x + y - MOD : x + y)
#define sz(x) (int)(x).size()

const string cq[2] = { "NO", "YES" };
const int dx[8] = { -1,  0, 0, 1, 1,  1, -1, -1 };
const int dy[8] = { 0, -1, 1, 0, 1, -1,  1, -1 };
const int INF = 2147483647;
const ll LINF = 9223372036854775807;
const int MOD = 1e9 + 7;
const int N = 1e5 + 1;

#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

int bits(ll x) {
    int bits = 0;
    while (x) x /= 2, bits++;
    return bits;
}

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
    cin >> T;
    for (int Ti = 1; Ti <= T; Ti++) {
        ll n, l, r, k;
        cin >> n >> l >> r >> k;

        if (n == 2) cout << -1 << endl;
        else if (l == r) {
            if (n % 2 == 0) cout << -1 << endl;
            else cout << l << endl;
        }
        else { // atleast 3 elements
            if (n & 1) cout << l << endl;
            else { // n even
                int rbits = bits(r);
                int lbits = bits(l);

                if (rbits - lbits >= 1) {
                    if (k <= n - 2) cout << l << endl;
                    else {
                        cout << (2ll << (lbits - 1ll)) << endl;
                    }
                }
                else cout << -1 << endl;
            }

        }

        // for (int i = 1; i <= 16; i++) {
        //     for (int j = i; j <= 16; j++) {
        //         for (int k = j; k <= 16; k++) {
        //             if ((i & j & k) == (i ^ j ^ k)) {
        //                 debug(i, j, k);
        //             }
        //         }
        //     }
        // }

        // for (int i = 1; i <= 16; i++) {
        //     for (int j = i; j <= 16; j++) {
        //         for (int k = j; k <= 16; k++) {
        //             for (int l = k; l <= 16; l++)
        //                 if ((i & j & k & l) == (i ^ j ^ k ^ l)) {
        //                     debug(i, j, k, l);
        //                 }
        //         }
        //     }
        // }

        // for (int i = 1; i <= 200; i++) {
        //     for (int j = i; j <= 200; j++) {
        //         {
        //             if ((i & j) == (i ^ j)) {
        //                 debug(i, j);
        //             }
        //         }
        //     }
        // }
    }
    return 0;
}

/*

let's say everything will just be one single a[i] in the end

101
110
011


1. we'll only work with the maximum bit and if the number of integers possible is less

2^0 = 1 1
2^1 = 2 3
2^2 = 4 7
2^3 = 8 13
2^4 = 16


l == r
    n even -> no (bc xor will be 0)
    n odd -> yes

l < r (atleast 2)
    n odd -> just take 1 element and repeat it
    n even -> just take 1 element and repeat the other element
        111, 100*5
        111, 100*5

        111, 010*5
        111, 010*5

        111, 110*5
        111, 110*5

    7 6 (r, l) -> 111, 110 -> how many bits left that can we play with? 0
    8 6 -> 1000, 110 -> 1 bit left

        n even -> 8, 6, 6, 6...
                1000, 110, 110, 110 &= 0
                1000, 110, 110, 110 ^= 1000 ^ 110 ^= 110
                to make xor work, we need 8 and 6 two two


*/