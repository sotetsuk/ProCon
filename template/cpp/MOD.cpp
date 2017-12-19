const ll MOD = 1000000007;

ll mod_fact(int n){
  ll res = 1;
  for( int i = 1; i <= n; i++ )
    res = (res*i)%MOD;
  return res;
}

ll mod_pow(ll a , ll b){
  ll res = 1;
  while( b != 0 ){
    if( (b&1) == 1 ){
      res *= a;
      res %= MOD;
    }
    a *= a;
    a %= MOD;
    b >>= 1;
  }
  return res;
}

ll mod_comb(int n , int k){
  if( n < 0 || k < 0 || n-k < 0 ) exit(9);
  ll numerator = fact(n);
  ll denominator = (fact(k)*fact(n-k))%MOD;
  return (numerator*modpow(denominator,MOD-2))%MOD;
}
