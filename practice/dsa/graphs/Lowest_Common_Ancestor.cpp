#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = (a); i < (b); i++)
#define sz(x) (int)(x).size()
using vi = vector<int>;
template<class T> using V = vector<T>;

template<class T>
struct RMQ {
    V<V<T>> jmp;
    RMQ() {}
    RMQ(const V<T>& V) : jmp(1, V) {
        for (int pw = 1, k = 1; pw * 2 <= sz(V); pw *= 2, ++k) {
            jmp.emplace_back(sz(V) - pw * 2 + 1);
            rep(j, 0, sz(jmp[k]))
                jmp[k][j] = min(jmp[k - 1][j], jmp[k - 1][j + pw]);
        }
    }
    T query(int a, int b) {
        assert(a < b);
        int dep = 31 - __builtin_clz(b - a);
        return min(jmp[dep][a], jmp[dep][b - (1 << dep)]);
    }
};

struct LCA {
    int T = 0;
    vi time, path, ret;
    RMQ<int> rmq;
    LCA(vector<vi>& C) {
        time.resize(sz(C));
        dfs(C, 0, -1);
        rmq = RMQ<int>(ret);
    }
    void dfs(vector<vi>& C, int v, int par) {
        time[v] = T++;
        path.push_back(v);
        ret.push_back(time[v]);
        for (int y : C[v]) if (y != par) {
            dfs(C, y, v);
            path.push_back(v);
            ret.push_back(time[v]);
        }
    }
    int lca(int a, int b) {
        if (a == b) return a;
        a = time[a], b = time[b];
        if (a > b) swap(a, b);
        int t = rmq.query(a, b + 1);
        // find node with time = t
        rep(i, 0, sz(path))
            if (ret[i] == t) return path[i];
        return -1; // should never happen
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    vector<vi> tree(N);
    rep(i, 1, N) {
        int p;
        cin >> p;
        tree[p].push_back(i);
    }

    int M;
    cin >> M;
    vi U(M);
    rep(i, 0, M) cin >> U[i];

    LCA lca(tree);
    int ans = U[0];
    rep(i, 1, M) ans = lca.lca(ans, U[i]);
    cout << ans << "\n";
    return 0;
}