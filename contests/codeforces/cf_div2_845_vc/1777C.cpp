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

const string cq[2] = { "NO", "YES" };
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
        int n, m;
        cin >> n >> m;
        vi a(n); cin >> a;

    }
    return 0;
}

/*
    Get all primes in m
    And check with a[i] % primeM
    or, we can just do gcd(a[i], mj)

    so, for all mj, there needs to be atleast one a[i], such that a[i] % mj == 0

    let's say we have some way to check divisibility, then the answer would the
    max_prime - min_prime
    1, 2, 3, 4, 5, 6, 7, 8, 9


    for any array of m,
    a = {15, 28}
    (... 14, 15)

    a = {15, 28, 30}
    (... 14, 15)


    a = {15, 56, 60}
    (... 14, 15)

    a = {7, 8, 9, 11, 13, 14, 60}
    ([1, 2, 3, 4, 5, 6, 10, 12, 15, 20, 30], [7], [8], [9], 11, 13, 14, 15)

    a = {7, 8, 9, 11, 13, 14, 15, 60} -> 15 - 7
    ([1, 2, 3, 4, 5, 6, 10, 12, 15, 20, 30], [7], [8], [9], 11, 13, 14, 15)

    for diff to be zero, there has to be atleast an integer which is the gcd of all primes in m
    so, for there to exist an answer, gcd(a) == gcd(m)

    can we say taking the maximum mj is the best?
        probably not, for an array that contains all numbers 1 to 15 and some extra large ones at the end
        and m = 15, then diff =

    let's try processing from every a[i], then we'll get a[i]'s prime facto in log(a[i])
*/

/*
    We don't have any fast way to check whether there exists any number a[i] such that m[j] divides a[i]
    if we get primes factorization for any a[i], and use frequency map?
    or, we can directly store all the primes of any a[i] with nlogn space

    variables for m[j] be the numbers that safisfy m[j]
    15 -> (15, 30, 60)

    after we get prime factorization of any number, we just need to check if for any m[j], there exists

*/

/*. Possible solutions

    we'll probably use a min-max greedy algorithm, where we'll iterate over the values of m in reverse
    order and take the largest a[i] that satisfies m, and set that answer to ans[m[j]] = a[i], and
    update fans = max-min, and then we'll remove that a[i]?
*/

/*. Gains
    prime factorization of any n can have at most log(n) primes
    create these three types of functions for bruteforcing ->
        get_all_suba -> n^3
        get_all_subs -> recursive algorithm O(2^n)


*/