// BRACU_Ravens
#include <bits/stdc++.h>
using namespace std;

#ifndef DeBuG
#define dbg(...)
#endif

#define sz(x) (int)(x).size()
#define all(x) begin(x), end(x)
#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define pb push_back
#define eb emplace_back

using ll = long long;
using pii = pair<int, int>;	
using pll = pair<long long, long long>;
using vi = vector<int>;
template<class T> using V = vector<T>;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
#define rand(l, r) uniform_int_distribution<ll>(l, r)(rng)

const double PI = acos(-1.);

template<class T> int sgn (T x) { return (x > 0) - (x < 0); }
template <class T> struct Point {
	typedef Point P;
	T x, y;
	explicit Point (T _x = 0, T _y = 0) : x(_x), y(_y) {}
	bool operator<(P p) const { return tie(x, y) < tie(p.x, p.y); }
	bool operator==(P p) const { return tie(x, y) == tie(p.x, p.y); }

	P operator+(P p) const { return P(x + p.x, y + p.y); }
	P operator-(P p) const { return P(x - p.x, y - p.y); }
	P operator*(T d) const { return P(x * d, y * d); }
	P operator/(T d) const { return P(x / d, y / d); }

	T dot (P p) const { return x * p.x + y * p.y; }
	T cross (P p) const { return x * p.y - y * p.x; }
	T cross (P a, P b) const { return (a - *this).cross(b - *this); }
	T dist2() const { return x * x + y * y; }
	double dist() const { return sqrt((double)dist2()); }
	double angle() const { return atan2(y, x); }
	P unit() const { return *this / dist(); }
	P perp() const { return P(-y, x); }
	P normal() const { return perp().unit(); }
	P rotate (double a) const {
		return P(x * cos(a) - y * sin(a), x * sin(a) + y * cos(a));
	}
	friend ostream& operator<<(ostream& os, P p) {
		return os << "(" << p.x << "," << p.y << ")"; 
	}
};

using P = Point<ll>;

int half (P p) {
	if (p.y > 0 || (p.x >= 0 && p.y == 0)) return 0;
	return 1;
}

struct p3 {
	P p;
	ll val;
	bool operator<(p3 o) const {
		if (o.p == p) return val < o.val;
		if (half(p) != half(o.p)) return half(p) < half(o.p);
		if (p.cross(o.p) == 0) return p.dist2() < o.p.dist2();
		return p.cross(o.p) > 0;
	}
};

double angle (P p, P q) {
	double t1 = p.angle(), t2 = q.angle();
	if (t1 < 0) t1 += 2 * PI;
	if (t2 < 0) t2 += 2 * PI;

	if (t1 <= t2) return t2 - t1;
	return (t2 - t1) + 2 * PI;
}

template <class T>
struct RMQ {
	V<V<T>> jmp;
	RMQ (const V<T> &V) : jmp(1, V) {
		for (int pw = 1, k = 1; pw * 2 <= sz(V); pw *= 2, ++k) {
			jmp.emplace_back(sz(V) - pw * 2 + 1);
			rep(j, 0, sz(jmp[k]))
				jmp[k][j] = max(jmp[k - 1][j], jmp[k - 1][j + pw]);
		}
	}
	T query (int a, int b) {
		assert(a < b);
		int dep = 31 - __builtin_clz(b - a);
		return max(jmp[dep][a], jmp[dep][b - (1 << dep)]);
	}
};

ll solve1 (int n, double rad, double A, const V<p3> &p) {
	for (int i = 0; i < n + n; ++i) {
		dbg(p[i].p, p[i].val);
	}

	double theta_max = 2 * A / (rad * rad);
	dbg(theta_max);
	V<int> r(n, -1);
	int ptr = 0;

	dbg(angle(p[2].p, p[3].p));

	for (int i = 0; i < n; ++i) {
		ptr = max(ptr, i);
		while (ptr + 1 < i + n && angle(p[i].p, p[ptr + 1].p) <= theta_max) ++ptr;
		r[i] = ptr;
	}

	V<ll> sum(n + n);
	sum[0] = p[0].val;
	for (int i = 1; i < n + n; ++i) sum[i] = sum[i - 1] + p[i].val;

	RMQ rmq(sum);
	dbg(sum);
	dbg(r);

	ll ans = 0;
	for (int i = 0; i < n; ++i) {
		ll here = 0;
		if (r[i] == i) here = max(here, p[i].val);
		else {
			if (i == 0) {
				here = rmq.query(0, r[i] + 1);
			}
			else {
				here = rmq.query(i, r[i] + 1) - sum[i - 1];
			}

		}
		dbg(i, here);
		ans = max(ans, here);
	}
	dbg(ans);
	return ans;
}

void solvetc(int cs) {
	int n;
	double rad, A;
	cin >> n >> rad >> A;

	V<p3> p(n);
	for (int i = 0; i < n; ++i) cin >> p[i].p.x >> p[i].p.y >> p[i].val;
	sort(all(p));

	V<p3> new_p;
	for (int i = 0; i < n; ++i) {
		int j = i;
		while (j + 1 < n && p[j + 1].p.cross(p[j].p) == 0) ++j;
		ll sum = 0;
		for (int k = i; k <= j; ++k) sum += p[k].val;
		new_p.emplace_back(p[i].p, sum);
		i = j;
	}

	p = new_p;
	n = sz(p);
	for (int i = 0; i < n; ++i)
		p.push_back(p[i]);

	ll ans = solve1(n, rad, A, p);

	for (int i = 0; i < n + n; ++i) p[i].val = -p[i].val;
	ans = max(ans, solve1(n, rad, A, p));

	cout << ans << "\n";
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int tc = 1;
	cin >> tc; // comment out
	for (int cs = 1; cs <= tc; ++cs) solvetc(cs);
	return 0;
}