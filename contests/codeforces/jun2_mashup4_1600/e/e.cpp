#include "bits/stdc++.h"
using namespace std;

#ifndef DeBuG
	#define dbg(...)
#endif

// #define int int64_t
#define endl '\n'
#define sz(x) (int) (x).size()
#define all(x) begin(x), end(x)
#define rep(i,a,b) for(int i=a;i<(b);++i)
using ll = long long; using pii = pair<int,int>;
using pll = pair<ll,ll>; using vi = vector<int>;
template<class T> using V = vector<T>;

void solve(int cs) {
	int n; cin >> n;
	vi a(n + 5); for (int i = 1; i <= n; i++) cin >> a[i];

	int ans = 0; int maxn = min((long long)(2e5 + 5), 1ll * n * (n - 1ll));
	for (int x = 1; x <= maxn; x++) {
		for (int i = 1; i * i <= x; i++) {
			if (x % i == 0) {
				int j = x / i;
				if (i <= n && j <= n && (j - i) % a[i] == 0 && (j - i) % a[j] == 0 && (j - i) / a[j] == a[i] && (j - i) / a[i] == a[j]) {
					ans++;
				}
			}
		}
	}
	cout << ans << endl;
}

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int tc = 1;
// #ifdef DeBuG
	cin >> tc;
// #endif
	for (int cs = 1; cs <= tc; cs++) solve(cs);
	return 0;
}