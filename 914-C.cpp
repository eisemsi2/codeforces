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
    cout<<; 

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
    int n,k;
    cin>>n>>k;

    vi a(n);
    for (int i=0 ;i <n; i++) cin>>a[i];

    if (k>=3) {
        cout<<0<<nl;
        return;
    }

    sort(a.begin(), a.end());

    set<ll> diff;

    for (int i=0 ;i<n; i++) {
        for (int j=i+1; j<n; j++) {
            diff.insert(abs(a[i] - a[j]));
        }
    }

    if (k == 1) {
        ll ans = min(a[0],*diff.begin());
        cout<<ans<<nl;
        return;
    }
    if (k == 2) {
        ll mn = 1E18+1;
        for (int i=0; i<n; i++) {
            auto it = diff.lower_bound(a[i]);
            ll x = 1E18+1;
            if (it == diff.end()) {
                x = abs(a[i] - *prev(it));
            }
            else {
                auto it1 = it;
                auto it2 = it;
                if (it != diff.begin()) it1 = prev(it);
                
                if (it != diff.end()) it2 = next(it);

                if (it2 == diff.end()) it2 = it;

                // ll x = min(abs(a[i]-*it2),min(abs(a[i] - *it),abs(a[i] - *it1)));
                ll y = abs(a[i]-(*it));
                ll z = abs(a[i]-(*it1));
                ll d = abs(a[i]- (*it2));
                ll x = min(y,min(z,d));
            } 

            mn = min(x,mn);
        }

        ll ans = min(a[0],min(*diff.begin(),mn));
        cout<<ans<<nl;
        return;
    }



    
    
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    cin>>t;
    while(t--) solve();
    return 0;
}