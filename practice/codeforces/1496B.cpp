#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <stack>
#include <algorithm>
#include <numeric>
#include <math.h>
#include <iomanip>
#include <cstring>

using namespace std;

#ifdef ONLINE_JUDGE
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx2")
#endif

// template<typename T> ostream& operator<<(ostream &os, const vector<T> &v) { os << '{'; string sep; for (const auto &x : v) os << sep << x, sep = ", "; return os << '}'; }
// template<typename T, size_t size> ostream& operator<<(ostream &os, const array<T, size> &arr) { os << '{'; string sep; for (const auto &x : arr) os << sep << x, sep = ", "; return os << '}'; }
// template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
// void dbg_out() { cerr << endl; }
// template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
// #define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)

//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
//using namespace __gnu_pbds;
//template<typename T>
//using oset = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

// #include <chrono>
// #include <random>
// mt19937 rng(chrono::system_clock::now().time_since_epoch().count());

#define endl "\n"
#define pb push_back
#define eb emplace_back
#define ff first
#define ss second
#define lb lower_bound
#define ub upper_bound

typedef long long ll;
typedef long double ld;
// typedef complex<ld> cd;

typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pd;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef vector<char> vc;
typedef vector<vc> vvc;
typedef vector<ll> vl;
typedef vector<vl> vvl;
// typedef vector<cd> vcd;

template <class T>
using pql = priority_queue<T>;
template <class T>
using pqg = priority_queue<T, vector<T>, greater<T>>;
template <class T1, class T2>
using umap = unordered_map<T1, T2>;

#define add(a, b) (a + b >= MOD ? a + b - MOD : a + b)
#define all(x) (x).begin(), (x).end()
// #define unique(x) sort(all(x)), (x).erase(unique(all(x)), (x).end())
#define tolower(x) transform(all(x), (x).begin(), ::tolower)
#define toupper(x) transform(all(x), (x).begin(), ::toupper)
#define remove_all(x, y) (x).erase(remove(all(x), char(y)), (x).end());

#define input(in) freopen(in, "r", stdin)
#define output(out) freopen(out, "w", stdout)

const int INF = 2147483647;
const ll LINF = 9223372036854775807;
// const double EPS = 1e-10;
// const double gam = 0.5772156649015328606; //euler's constant
// const double PI = acos(-1.0);
const int dx[8] = { -1, 0, 0, 1, 1, 1, -1, -1 };
const int dy[8] = { 0, -1, 1, 0, 1, -1, 1, -1 };
// const int dxx[8] = {1, 1, 2, 2, -1, -1, -2, -2};
// const int dyy[8] = {2, -2, 1, -1, 2, -2, 1, -1};
const int MOD = 1000000007;
const int maxn = 1e5;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int ttt(1);
    cin >> ttt;
    for (int itt = 1; itt <= ttt; itt++) {
        // cerr << "Test " << itt << " :" <<endl;

        int n, k;
        cin >> n >> k;
        vi a(n), b(n);
        iota(all(b), 0);
        umap<int, int> mp;
        for (auto& i : a)
            cin >> i, mp[i]++;
        sort(all(a));
        if (a == b)
            cout << n + k << endl;
        else {
            int mx(0), mex(0);
            mx = *max_element(all(a));
            auto upd = [&](int& mex)
                {
                    for (int i = mex; i <= 1e9 + 1; i++)
                        if (!mp.count(i)) {
                            mex = i;
                            break;
                        }
                };
            upd(mex);
            while (k--) {
                int x = (mx + mex + 1) / 2;
                if (mp.count(x))
                    break;
                else {
                    mp[x] = 1;
                    if (x > mx)
                        mx = x;
                    upd(mex);
                }
            }
            cout << mp.size() << endl;
        }

        // cerr << endl << endl;
    }

    return 0;
}