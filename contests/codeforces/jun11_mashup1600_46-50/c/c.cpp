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

const int MOD = 1e9 + 7;
void solve(int cs) {
	string s; cin >> s;
	int n = sz(s);
	s = '0' + s;
	vi pre(n + 1); 
	map<int, vi> mp; // freqs -> idxs
	map<int, pii> mp2; // freq -> {sum, cnt}
	for (int i = 1; i <= n; i++) {
		int x  = (s[i] == '1' ? 1 : -1);
		pre[i] = pre[i - 1] + x;
		mp[pre[i]].push_back(i);
	}
	mp[0].push_back(0);

	for (auto& [freq, idxs] : mp) {
		int sum = 0, cnt = sz(idxs);
		for (auto& idx : idxs) sum += idx;
		mp2[freq] = {sum, cnt};
	}
	int ans = 0;
	for (int i = 0; i <= n; i++) {
		int freq = pre[i];
		auto& [sum, cnt] = mp2[freq];
		sum -= i; cnt--;
		int left = (i + 1) % MOD;
		int right = ((n + 1) * cnt - sum) % MOD;
		ans = (ans + (left * right % MOD)) % MOD;
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