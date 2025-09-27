int n, q;
cin >> n >> q;
vi a(n);
for (int i = 0; i < n; i++) {
    cin >> a[i];
}
vi b = a;
sort(all(b));
b.erase(unique(all(b)), b.end());
vi cnt(b.size());
for (int i = 0; i < n; i++) {
    a[i] = lb(all(b), a[i]) - b.begin();
}
int L, R, blk; L = 0, R = -1, blk = ceil(sqrt(n));
struct ob { int l, r, i; };
vector<ob> queries(q);
for (int i = 0; i < q; i++) {
    int l, r; cin >> l >> r;
    l--, r--;
    queries[i] = { l, r, i };
}
sort(all(queries), [&](ob& a, ob& b) {
    if (a.l / blk != b.l / blk) return a.l / blk < b.l / blk;
    return a.r < b.r;
    });

int unq = 0;
auto del = [&](int i) {
    cnt[a[i]]--;
    if (!cnt[a[i]]) unq--;
    };
auto add = [&](int i) {
    if (!cnt[a[i]]) unq++;
    cnt[a[i]]++;
    };

vi ans(q);
for (auto& [l, r, i] : queries) {
    while (l < L) L--, add(L);
    while (R < r) R++, add(R);
    while (L < l) del(L), L++;
    while (r < R) del(R), R--;
    ans[i] = unq;
}
for (auto& i : ans) cout << i << endl;
