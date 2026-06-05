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
	int size(int x) { return -e[find(x)]; }
	int find(int x) { return e[x] < 0 ? x : e[x] = find(e[x]); }
	bool join(int a, int b) {
		a = find(a), b = find(b);
		if (a == b) return false;
		if (e[a] > e[b]) swap(a, b);
		e[a] += e[b]; e[b] = a;
		return true;
	}
};

struct Treemx {
    typedef int T;
    static constexpr T unit = INT_MIN;
    T f(T a, T b) { return max(a, b); } // any associative fn
    V<int> s; int n;
    Tree(int n = 0, T def = unit) : s(2 * n, def), n(n) {}
    void update(int pos, T val) {
        for (s[pos += n] = val; pos /= 2;)
            s[pos] = f(s[pos * 2], s[pos * 2 + 1]);
    }
    T query(int b, int e) {
        T ra = unit, rb = unit;
        for (b += n, e += n; b < e; b /= 2, e /= 2) {
            if (b % 2) ra = f(ra, s[b++]);
            if (e % 2) rb = f(s[--e], rb);
        }
        return f(ra, rb);
    }
};

struct Treemn {
    typedef int T;
    static constexpr T unit = INT_MAX;
    T f(T a, T b) { return min(a, b); } // any associative fn
    V<int> s; int n;
    Tree(int n = 0, T def = unit) : s(2 * n, def), n(n) {}
    void update(int pos, T val) {
        for (s[pos += n] = val; pos /= 2;)
            s[pos] = f(s[pos * 2], s[pos * 2 + 1]);
    }
    T query(int b, int e) {
        T ra = unit, rb = unit;
        for (b += n, e += n; b < e; b /= 2, e /= 2) {
            if (b % 2) ra = f(ra, s[b++]);
            if (e % 2) rb = f(s[--e], rb);
        }
        return f(ra, rb);
    }
};


void solve(int cs) {
	int n; cin >> n;
	vi a(n + 5), pos(n + 5);
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		pos[a[i]] = i;
	}

	vi premn(n + 5), sufmx(n + 5);
	premn[1] = a[1];
	sufmx[n] = a[n];
	for (int i = 2; i <= n; i++) 
		premn[i] = min(premn[i - 1], a[i]);
	for (int i = n - 1; i >= 1; i--)
		sufmx[i] = max(sufmx[i + 1], a[i]);

	UF uf(n + 1);
	auto push = [&](int x, int y) {
		uf.join(x, y);
	};

	bool can = true; V<pii> ans;
	for (int i = 1; i <= n; i++) {
		if (i == 1) {
			if (a[i] < sufmx[i + 1]) push(a[i], sufmx[i + 1]);
			else can = false;
		}
		else if (i == n) {
			if (premn[i - 1] < a[i]) push(a[i], premn[i - 1]);
			else can = false;
		}
		else {
			if (premn[i - 1] < a[i] or a[i] < sufmx[i + 1]) {

				if (a[i] < sufmx[i + 1]) push(a[i], sufmx[i + 1]);
				if (premn[i - 1] < a[i]) push(a[i], premn[i - 1]);

			} else {
				can = false;
			}
		}
	}

	dbg(cs);
	for (int i = 1; i <= n - 1; i++) {
		if (!uf.sameSet(a[i], a[i + 1])) {
			dbg(a[i], a[i + 1]);
			can = false;
		}
	}
	// assert(sz(ans) == n - 1);
	if (can) {
		cout << "Yes\n";
		for (auto& [x, y] : ans) cout << x << " " << y << "\n";
	} else cout << "No\n";
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