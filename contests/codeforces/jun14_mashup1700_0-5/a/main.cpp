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
	int n; 
	cin >> n;
	vi a(n), b(n);
	for (auto& i : a) cin >> i;
	for (auto& i : b) cin >> i;

	int ans = 0;
	deque<pii> dq; dq.push_back({0, 0}); // 0, 0?
	for (int i = 0, j = 0; i < n; i++) {
		int nxt = dq.back().first + 1;
		if (a[j] == nxt || b[j] == nxt) {
			if (a[j] == b[j]) { // extend
				dq.push_back({nxt, j}); j++;
			}	
			else { // reset
				ans += j - i;
				int ni = i;
				while (sz(dq) && dq.front().first == 1) dq.pop_front();
				if (sz(dq)) { // what if it's empty?
					i = dq.front().second();
				}
				dq = deque<pii>(); dq.push_back({0, 0});
				i = ni;
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