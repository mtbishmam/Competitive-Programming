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
	vi a(n), b(n);
	for (auto& i : a) cin >> i;
	for (auto& i : b) cin >> i;

	auto score = [&](int i, int j) -> vi {
		vi c = {a[i], a[j], b[i], b[j]};
		sort(all(c));
		// return {{c[0], c[3]}, {c[1], c[2]}};
		return c;
	};
	struct node {
		// pii p1; // mn, mx
		// pii p2; // medians
		vi c;
		int l, r;
	};
	struct comp {
		bool operator() (const node& a, const node& b) const {
			// if (a.p1.first > b.p1.first) return true;
			// return a.p1.second > b.p1.second;
			if (a.c[0] != b.c[0]) return a.c[0] > b.c[0];
			if (a.c[3] != b.c[3]) return a.c[3] < b.c[3];
			if (a.c[2] != b.c[2]) return a.c[2] < b.c[2];
			return a.c[1] < b.c[1];
		}
	};
	vi nxt(n, -1), prv(n, -1);
	priority_queue<node, V<node>, comp> pq;
	for (int i = 0; i < n; i++) {
		prv[i] = i - 1;
		if (i + 1 < n) {
			nxt[i] = i + 1;
			// node cur = {score(i, i + 1).first, score(i, i + 1).second, i, i + 1};
			node cur = {score(i, i + 1), i, i + 1};
			pq.push(cur);	
		}
	}
	int ans = min(a[0], b[0]); V<bool> alive(n, 1);
	while(sz(pq)) {
		node u = pq.top();
		// if (sz(pq) == 1) ans = u.p2.first; 
		pq.pop();

		// auto& [p1, p2, l, r] = u;
		// auto& [mn, mx] = p1;
		// auto& [m1, m2] = p2;
		auto& [c, l, r] = u;
		if (!alive[l] || !alive[r]) continue;
		if (nxt[l] != r) continue;

		vi cnew = score(l, r);  // recompute ALWAYS

		dbg(cnew, l, r);

		alive[r] = false;
		a[l] = cnew[1];
		b[l] = cnew[2];
		dbg(l, a[l], b[l]);
		// a[l] = m1;
		// b[l] = m2;

		int L = prv[l];
		int R = nxt[r];
		nxt[l] = R;
		// prv[l] = L; // redundant
		if (R != -1) prv[R] = l;

		// if (L != -1) pq.push({score(L, l).first, score(L, l).second, L, l});
		// if (R != -1) pq.push({score(l, R), score(l, R).second, l, R});
		if (L != -1) {
			pq.push({score(L, l), L, l});
			dbg(L, l);
		}
		if (R != -1) {
			pq.push({score(l, R), l, R});
			dbg(l, R);
		}

		ans = cnew[1]; 
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