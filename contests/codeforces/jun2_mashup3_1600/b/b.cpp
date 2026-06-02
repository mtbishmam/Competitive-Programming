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

const int m = 26;
void solve(int cs) {
	int n; cin >> n;
	V<string> a(n);
	for (auto& i : a) cin >> i;

	V<V<int>> g(m + 5);
	V<int> in(m + 5);
	bool bad = false;
	for (int i = 0; i < n - 1; i++) {
		string s = a[i];
		string t = a[i + 1];
		bool done = false;
		for (int j = 0; j < min(sz(s), sz(t)); j++) {
			if (s[j] != t[j]) {
				in[t[j] - 'a']++;
				g[s[j] - 'a'].push_back(t[j] - 'a');
				done = true;
				break;
			}
		}	
	}

	queue<int> q; set<int> s;
	for (int i = 0; i < m; i++) {
		s.insert(i);
		if (in[i] == 0) q.push(i), s.erase(i);
		sort(all(g[i])); // idk why i'm doing this
	}

	string ans;
	while (sz(q)) {
		int u = q.front();
		q.pop();

		ans += (u + 'a');
		// s.erase(u);

		for (auto& v : g[u]) {
			in[v]--;
			if (!in[v]) {
				q.push(v);
				s.erase(v);
			}
		}
	}

	if (sz(s) or bad) ans = "Impossible";
	dbg(cs, ans, sz(ans));
	cout << ans << endl;
}

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int tc = 1;
#ifdef DeBuG
	cin >> tc;
#endif
	for (int cs = 1; cs <= tc; cs++) solve(cs);
	return 0;
}