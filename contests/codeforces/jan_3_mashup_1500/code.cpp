#include "bits/stdc++.h"
using namespace std;

#ifndef DeBuG
	#define dbg(...)
#endif

// #define int int64_t

#define sz(x) (int) (x).size()
#define all(x) begin(x), end(x)
#define rep(i,a,b) for(int i=a;i<(b);++i)
using ll = long long; using pii = pair<int, int>;
using pll = pair<ll,ll>; using vi = vector<int>;
template<class T> using V = vector<T>;

void solve(int cs) {
	int n; cin >> n;
	string s; cin >> s;
	if (n == 1) {
		cout << "YES\n";
		return;
	}
	string t;
	for (int i = 0; i < n; i++) {
		if (s[i] == '0') {
			int j = i + 1;
			while (j < n && s[i] == s[j]) j++;
			i = j - 1;
			t += '0';
		} else t += s[i];
	}
	bool f = 0;
	if (sz(t) == 0) f = 1;
	else if (count(all(t), '1') == sz(t)) f = 1;
	else {
		char c = t.front(); bool cur = 1;
		for (int i = 0; i < sz(t); i++) {
			if (c == t[i]) c = (c == '1' ? '0' : '1');
			else cur = 0;
		}
		f |= cur;
	}
	if (f) cout << "NO\n";
	else cout << "YES\n";
}

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int tc;
	cin >> tc;
	for (int cs = 1; cs <= tc; cs++) solve(cs);
	return 0;
}
