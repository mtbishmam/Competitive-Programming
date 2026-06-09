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
	int n, k; cin >> n >> k;
	string s, t, ans; cin >> s; t = s; ans = s;
	int mnans = 1e9;
	for (int x = 0; x <= k; x++) {
		int y = k - x;
		
		int xx = x;
		for (int i = 0; i < n && xx; i++) {
			if (s[i] == '(' && xx) {
				s[i] = '*';
				xx--;
			}
		}
		int yy = y;
		for (int i = n - 1; i >= 0; i--) {
			if (s[i] == ')' && yy) {
				s[i] = '*';
				yy--;
			}
		}
		vi stk; int cur = 0;
		for (int i = 0; i < n; i++) {
			if (s[i] == '(') stk.push_back(i);
			else if (s[i] == ')') {
				if (sz(stk)) stk.pop_back(), cur++;
			}
		}
		if (cur < mnans) {
			mnans = cur;
			ans = s;
		}
		s = t;
	}
	for (int i = 0; i < n; i++) {
		if (s[i] != ans[i]) cout << '1';
		else cout << '0';
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