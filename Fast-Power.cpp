    typedef long long ll;
     
    int fast_power(ll x, ll n, int mod) { //where 1 < mod < max_int;
        ll ans = 1, base = x % mod;
        while(n){
            if(n&1){
                ans = (ans * base) % mod;
                n--;
            }else{
                base = (base * base) % mod;
                n /= 2;
            }
        }
        if (ans < 0) ans += mod;
        return ans;
    }
     
