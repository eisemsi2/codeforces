#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;

typedef __gnu_pbds::tree<int, __gnu_pbds::null_type, less<int>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update> ordered_set;

#define ll long long
#define vi vector<long long>
#define vvi vector<vector<long long>>
#define pp pair<ll,ll>
#define pb push_back
#define nl '\n'

#define print(v,a,n) for (int i=a; i<n; i++) cout<<v[i]<<" ";\
    cout<<nl; 

int inv(int a, int b)
{
    ll x = 1, y = 0;
    ll x1 = 0, y1 = 1, a1 = a, b1 = b;
    while (b1)
    {
        ll q = a1 / b1;
        tie(x, x1) = make_tuple(x1, x - q * x1);
        tie(y, y1) = make_tuple(y1, y - q * y1);
        tie(a1, b1) = make_tuple(b1, a1 - q * b1);
    }
    return x;
}
vi getdivisors(ll n) {
    vi divisors;
    divisors.pb(1);
    for (ll i=2; i*i<=n; i++) {
        if(n%i == 0) {
            divisors.pb(i);
            if (i != n/i) divisors.pb(n/i);
        }
    }
    if (n != 1) divisors.pb(n);
    sort(divisors.begin(), divisors.end());
    return divisors;
}


void solve() {
    ll a,b,l;
    cin>>a>>b>>l;


    // if (a == b) b = INT_MAX;

    if (a > b) swap(a,b);

    vi t = getdivisors(l);
    set<ll> s;
    for (int i=0; i<t.size(); i++) {
        s.insert(t[i]);
    } 

    ll ans = 0;
    if (s.find(a) == s.end() && s.find(b) == s.end()) {
        ans = 1;
    }
    else if (s.find(a) == s.end() || s.find(b) == s.end()) {
        ll d = (s.find(a) == s.end() ? b : a);
        ll x = d;
        while (l % x == 0) {
            ans ++;
            x = x*d;

            if (x > l ) break;
        }
        ans++;
    }
    else {
        // if (__gcd(a,b) == 1) {
        //     ll d = a;
        //     ll x = d;
        //     ll cnt1 = 0;
        //     while (l % x == 0) {
        //         cnt1 ++;
        //         x = x*d;

        //         if (x > l ) break;
        //     }

        //     d = b;
        //     x = d;
        //     ll cnt2 = 0;
        //     while (l % x == 0) {
        //         cnt2 ++;
        //         x = x*d;

        //         if (x > l ) break;
        //     }

        //     ans = (cnt1+1)*(cnt2+1);
        // }

        // else {
        set<ll> k;

        // ll x = 0;
        // ll y = 0;

        ll ad = 1;
        ll bd = 1;

        for (ll x=0; ;x++){
            for (ll y = 0; ;y++) {
                if (l % (ad*bd) == 0) k.insert(l/(ad*bd));
                else break;
                // y++;
                bd = bd*b;
            }

            ad = ad*a;
            bd = 1;
            if (l%ad != 0) break;
        }

        ans = k.size();

        // }

        
    }

    // cout<<ans<<nl;
    cout<<ans<<nl;

}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    cin>>t;
    while(t--) solve();
    return 0;
}