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

const int maxn = 1000;
int H[maxn + 5][maxn + 5]; // make sure to reset this

void solve(int cs) {
	for (int i = 1; i <= maxn; i++) {
		for (int j = 1; j <= maxn; j++) {
			H[i][j] = 0;
		}
	}

	int n, k;
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		int h, w; cin >> h >> w;
		H[h][w] += w;
	}

	for (int i = 1; i <= maxn; i++) {
		for (int j = 1; j <= maxn; j++) {
			H[i][j] += H[i][j - 1];
		}
	}

	for (int cq = 0; cq < k; cq++) {
		int h1, w1, h2, w2;
		cin >> h1 >> w1 >> h2 >> w2;
		int ans = 0;
		for (int i = h1 + 1; i <= h2 - 1; i++) {
			if (w1 + 1 <= w2 - 1) {
				ans += i * (H[i][w2 - 1] - H[i][w1]);
				// dbg(H[i].first, H[i].second);
			}
		}
		cout << ans << endl;
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