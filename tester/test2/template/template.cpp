#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <set>
#include <algorithm>
#include <math.h>
#include <utility>
#include <type_traits>
using namespace std;

template<typename...> using void_t = void;
#define TT template <typename T

TT,typename=void> struct cerrok:false_type {};
TT> struct cerrok <T, void_t<decltype(cerr << declval<T>() )>> : true_type {};

TT> constexpr void p1 (const T& x);
TT, typename V> void p1(const pair<T, V>& x) {
	cerr << "{"; p1(x.first); cerr << ", ";
	p1(x.second); cerr << "}";
}

TT> constexpr void p1 (const T& x) {
	if constexpr (cerrok<T>::value) cerr << x;
	else { int f = 0; cerr << '{'; 
		for (auto& i : x) cerr << (f++ ? ", " : ""), p1(i);
		cerr << '}';
	}
}
void p2() { cerr << "]\n"; }
TT, typename... V> void p2(T t, V... v) {
	p1(t);
	if (sizeof...(v)) cerr << ", ";
	p2(v...);
}

#ifndef DeBug
	#define dbg(...) { cerr << "\t\e[93m"<< __func__<<":"<<__LINE__<<" [" << #x << "] = [";
	p2(x); cerr << "\e[0m"; } 
#endif

#define sz(x) (int)(x).size()
#define all(x) begin(x), end(x)
#define pb push_back
#define em emplate_back
#define endl '\n'
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define int long long

using ll = long long;
using vi = vector<int>;
using pii = pair<int, int>;
template<class T> using V = vector<T>;

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	freopen("input.text", "r", stdin);
	freopen("output.text", "w", stdout);

	string s; cin >> s;
	cout << s;
}