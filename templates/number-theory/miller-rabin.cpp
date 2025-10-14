using ull = unsigned long long;
using u128 = __uint128_t;

ull modmul(ull a, ull b, ull m) { return (u128)a * b % m; }

ull modpow(ull a, ull n, ull m) {
    ull r = 1;
    while (n) {
        if (n & 1) r = modmul(r, a, m);
        a = modmul(a, a, m);
        n >>= 1;
    }
    return r;
}

bool isPrime(ull n) {
    if (n < 2 || n % 6 % 4 != 1) return (n | 1) == 3;
    ull A[] = { 2, 325, 9375, 28178, 450775, 9780504, 1795265022 }, s = __builtin_ctzll(n - 1), d = n >> s;
    for (ull a : A) { // ^ count trailing zeros
        ull p = modpow(a % n, d, n), i = s;
        while (p != 1 && p != n - 1 && a % n && i--)
            p = modmul(p, p, n);
        if (p != n - 1 && i != s) return 0;
    }
    return 1;
}