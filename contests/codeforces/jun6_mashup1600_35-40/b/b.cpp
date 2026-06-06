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
	int m; cin >> m;
	vi a(n); for (auto& i : a) cin >> i;
	vi b(m); for (auto& i : b) cin >> i;
	sort(all(a)); sort(all(b));
	vi ra, rb;
	int i, j;
	for (i = 0, j = 0; i < n && j < m; ) {
		if (a[i] == b[j]) i++, j++;
		else {
			if (a[i] < b[j]) {
				ra.push_back(a[i]);
				i++;
			} else {
				rb.push_back(b[j]);
				j++;
			}
		}
	}
	while (i < n) ra.push_back(a[i++]);
	while (j < m) rb.push_back(b[j++]);
	a = ra;
	b = rb;
	n = sz(ra); 
	m = sz(rb);
	if (!sz(a) && !sz(b)) {
		cout << "Yes\n";
		return;
	} else if (!sz(a) || !sz(b)) {
		cout << "No\n";
		return;
	}
	bool f = 1;
	i = 0, j = 0;
	if (cs == 4) dbg(a, b);
	for (int sum = a[0]; i < n && j < m;) {
		while (i + 1 < n && sum + a[i + 1] <= b[j] && abs(a[i] - a[i + 1]) <= 1) {
			sum += a[i + 1];
			i++;
			if (sum >= b[j]) break;
		}
		if (sum == b[j]) {
			j++;
			if (i + 1 < n) sum = a[i + 1];
			else break;
		} else {
			f = 0;
			break;
		}
	}

	if (cs == 4) {
		dbg(i, j);
	}
	if (i >= n - 1 and j >= m and f) {
		cout << "Yes";
	} else 
		cout << "No";
	cout << '\n';
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