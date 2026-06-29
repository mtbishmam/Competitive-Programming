#include "bits/stdc++.h"
using namespace std;

#ifndef DeBuG
	#define dbg(...)
#endif

#define int int64_t

#define endl '\n'
#define sz(x) (int) (x).size()
#define all(x) begin(x), end(x)
template<class T> using V = vector<T>;
using ll = long long; using pii=pair<int,int>;
using vi = V<int>; using vvi = V<vi>;
using vb = V<bool>;

void solve(int cs) {
    int n; cin >> n;
    vi a(n); for (auto& i : a) cin >> i;
}

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int tc = 1;
// #ifdef DeBuG
	cin >> tc;
// #endif
	for (int cs = 1; cs <= tc; cs++) solve(cs);
}
