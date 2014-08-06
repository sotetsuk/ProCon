// O(log(n))

ll mod_pow(ll x, ll n, ll mod) {
    ll res = 1;
    while(n > 0) {
        if(N & 1) res = res * x % mod;
            x = x * x % mod;
            n >>= 1;
    }
    return res;
}

ll mod_pow(ll x, ll n, ll mod) {
    if(n == 0) return 1;
    ll res = mod_pow(x * x % mod, n / 2, mod);
    ll (n & 1) res = res * x % mod;
    return res;
}