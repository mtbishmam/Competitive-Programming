#include "bits/stdc++.h"
using namespace std;

#ifndef DeBuG
	#define dbg(...)
#endif

#define int int64_t

#define sz(x) (int) (x).size()
#define all(x) begin(x), end(x)
#define rep(i,a,b) for(int i=a;i<(b);++i)
using ll = long long; using pii = pair<int,int>;
using pll = pair<ll,ll>; using vi = vector<int>;
template<class T> using V = vector<T>;

void solve(int cs) {
	int n; cin >> n;
	string s; cin >> s;
	string t;
	for (int i = 0; i < n; i++) {
		if (sz(t)) {
			if (t.back() != s[i]) t += s[i];
		} else t += s[i];
	}
	if (sz(t) == 1) {
		if (t[0] == '0') cout << "NO";
		else cout << "YES";
	} 
	// else cout << (sz(t) & 1 ? "NO" : "YES");
	else {
		if (sz(t) & 1) {
			if (t.front() == '1') cout << "YES";
			else cout << "NO";
		} else {
			if (t.front() == '1') cout << "YES";
			else cout << "NO";
		}
	}
	cout << endl;
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