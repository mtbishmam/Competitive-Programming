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

const int N = 4e4;
vi spf(N + 5), primes;
void sieve() {
	iota(all(spf), 0); primes = {2};
	for (int i = 2; i <= N; i += 2) spf[i] = 2;
	for (int i = 3; i <= N; i += 2) {
		for (int j = i; j <= N; j += i) {
			if (spf[j] == i) spf[j] = i;
		}
		if (spf[i] == i) primes.push_back(i);
	}
}

void solve(int cs) {
	int n; cin >> n; int gg = 0;
	vi a(n); for (auto& i : a) cin >> i, gg = gcd(gg, i);

	// cout << gg * (n - 1) << endl;


	using T = vector<pii>;
	struct comp {
		bool operator() (const int&a, const int&b) const {
			return sz(mp[a]) < sz(mp[b]);
		}
	};
	map<int, T, comp> mp;

	for (int i = 0; i < n; i++) {
		int x = a[i];

		for (auto& p : primes) {
			int cnt = 0;
			while (x % p == 0) {
				x /= p;
				cnt++;
			}
			if (cnt) {
				mp[p].push_back({cnt, i});
			}
		}
		if (x > 1) {
			mp[x].push_back({1ll, i});
		}
	}

	// we don't need to check this hopefully, our approach will still work
	// bool f = true;
	// for (auto& [key, st] : mp) f &= sz(st) == n;
	
	int ans, g; ans = g = 0;
	while (sz(mp)) {
		auto it = *mp.begin();
		auto& [p, v] = it;
		mp.erase(mp.begin());

		if (sz(mp)) {
			auto it2 = *mp.begin();
			auto& [p2, v2] = it2;
			mp.erase(mp.begin());

			sort(all(v)); sort(all(v2));
			for (int i = 0; i < min(sz(v), sz(v2)); i++) {
				if (v[i].second != v2[i].second) {
					g = gcd(g, (int) pow(p, min(v[i].first, v2[i].first)));
					ans += g;
					break;
				}
			}


		} else {
			g = gcd(g, it.first); // we can bc every key, that is prime is unique
			ans += g;
		}
	}
	cout << ans << endl;


	// if sz of all unique primes = n, then answer will be?
}

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int tc = 1;
#ifdef DeBuG
	cin >> tc;
#endif
	sieve();
	for (int cs = 1; cs <= tc; cs++) solve(cs);
	return 0;
}