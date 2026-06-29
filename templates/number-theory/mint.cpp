const ll MOD = 1e9 + 7; // Verify
struct mint {
  ll x; mint(ll x) : x(x) {}
  mint operator+(mint b) { return mint((x + b.x) % MOD); }
  mint operator-(mint b) { return mint((x - b.x + MOD) % MOD); }
  mint operator*(mint b) { return mint((x * b.x) % MOD); }
  mint operator/(mint b) { return *this * invert(b); }
  mint invert(mint a) {
    ll x, y, g = euclid(a.x, MOD, x, y);
    assert(g == 1); return mint((x + MOD) % MOD);
  }
  mint operator^(ll e) {
    if (!e) return mint(1);
    mint r = *this ^ (e / 2); r = r * r;
    return e&1 ? *this * r : r;
  }
};