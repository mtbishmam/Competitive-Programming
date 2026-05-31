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
	V<string> res;
	auto gen = [&](auto&&f, int i, string t) {
		if (i == n) {
			res.push_back(t);
			return;
		}
		if (s[i] == '0') {
			f(f, i + 1, t + ')');
			f(f, i + 1, t + '(');
		} else f(f, i + 1, t + s[i]);
	}; gen(gen, 0, "");
	bool flag = 0;
	for (auto& t : res) {
		bool cur = 1;
		for (int i = 0; i < sz(t); i++) {
			if (t[i] == '(') {
				if (i + 1 < sz(t) && t[i + 1] == '1') {
					if (i + 2 < sz(t) && t[i + 2] == ')');
					else cur = 0;
				}
			} else if (t[i] == ')') {
				if (i - 1 >= 0 && t[i - 1] == '1') {
					if (i - 2 >= 0 && t[i - 2] == '(');
					else cur = 0;
				}
			}
		}
		flag |= cur;
	}
	cout << (flag ? "YES\n" : "NO\n");
}

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int tc;
	cin >> tc;
	for (int cs = 1; cs <= tc; cs++) solve(cs);
	return 0;
}
