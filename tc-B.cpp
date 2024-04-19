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

bool chck(vi p) {
    int n = p.size();
    for (int i=0; i<p.size(); i++) {
        for (int j=0; j<p.size(); j++) {
            if (i == j) continue;
            if (i == n-1 || j == n-1) continue;

            if (p[j]%p[i] == 0 && p[j+1]%p[i+1] == 0) {
                return false;
            }
        }
    }

    return true;
}

void solve() {
    int n;
    cin>>n;

    vi p;
    
    int i = 1;
    int j = n;

    while (p.size() != n) {
        p.pb(i++);
        if (p.size() == n) break;
        p.pb(j--);
    }

    // reverse(p.begin()+x,p.end());

    print(p,0,n);
    // if (chck(p) == true) cout<<"yes"<<nl;
    // else cout<<"no"<<nl;
    
    
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    cin>>t;
    while(t--) solve();
    return 0;
}