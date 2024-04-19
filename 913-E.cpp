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

vi ways;

void solve() {
    int n;
    cin>>n;
    ll ans = 1;

    while (n!=0) {
        ll x = n%10;
        ans = ans*ways[x];

        n = n/10;
    }
    
    cout<<ans<<nl;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    ways.clear();
    ways.resize(10,0);
    ways[0] = 1;
    ways[1] = 3;
    ways[2] = 6;
    ways[3] = 10;
    ways[4] = 15;
    ways[5] = 21;
    // ways[6] = 
    for (int x = 6; x<=9; x++) {
        for (int i=0; i<=x; i++) {
            for (int j=0; j<=x; j++) {
                for (int k = 0; k<=x; k++) {
                    if (i+j+k == x) {
                        ways[x]++;
                    }
                }
            }
        }
    }
    cin>>t;

    while(t--) solve();
    return 0;
}