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

struct UF {
	vi e;
	UF (int n) : e(n, -1) {}
	bool sameSet(int a, int b) { return find(a) == find(b); }
	int find(int x) { return e[x] < 0 ? x : e[x] = find(e[x]); }
	int size(int x) { return -e[find(x)]; }
	bool join(int a, int b) {
		a = find(a), b = find(b);
		if (a == b) return false;
		if (e[a] > e[b]) swap(a, b);
		e[a] += e[b]; e[b] = a;
		return true;
	}
	
};

void solve(int cs) {
	int n, q; cin >> n >> q;
	V<string> a(n); V<vi> g(n + 4);
	UF dsu(n + 4); V<set<int>> st(4);
	map<string, vi> mp;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		for (char& c : a[i]) {
			if (c == 'B') c = 'A';
			else if (c == 'G') c = 'B';
			else if (c == 'R') c = 'C';
			else c = 'D';
			int x = i, y = n + c - 'A';
			g[x].push_back(y);
			g[y].push_back(x);
			dsu.join(x, y);
			st[c - 'A'].insert(i);
		}
		mp[a[i]].push_back(i);
		// dbg(a[i], mp[a[i]]);
	}
	for (auto& i : mp) sort(all(i.second));
	while (q--) {
		int x, y;
		cin >> x >> y; x--, y--;
		if (x > y) swap(x, y);
		if (x == y) cout << 0 << endl;
		else if (dsu.sameSet(x, y)) {
			int ans = 1e9;
			for (auto& c : a[x]) {
				if (st[c - 'A'].find(x) != st[c - 'A'].end() && st[c - 'A'].find(y) != st[c - 'A'].end()) {
					ans = min(ans, y - x);
				}
			}


			for (auto& c1 : a[x]) {
				for (auto& c2 : a[y]) {
					if (c1 == c2) continue;
					string ns; ns += c1; ns += c2;
					sort(all(ns));
					// dbg(ns);
					if (!mp.count(ns)) continue;
					auto it = lower_bound(all(mp[ns]), x);
					if (it != mp[ns].end()) {
						if (*it <= y) ans = min(ans, y - x);
						else {
							ans = min(ans, abs(x - *it) + abs(*it - y));
							if (it != mp[ns].begin()) {
								it--;
								ans = min(ans, abs(x - *it) + abs(*it - y));
							}
						}
					} else {
						if (it != mp[ns].begin()) {
							it--;
							ans = min(ans, abs(x - *it) + abs(*it - y));
						}
					}	
				}
			}


			if (ans == (int)1e9) cout << -1 << endl;
			else cout << ans << endl;

		} else {
			cout << -1 << endl;
		}
	}
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