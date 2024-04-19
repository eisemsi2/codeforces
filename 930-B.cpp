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

#define print(paths,a,n) for (int i=a; i<n; i++) cout<<paths[i]<<" ";\
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
    ll n;
    cin>>n;

    string a1,a2;
    cin>>a1>>a2;


    vector<vi> dp(2, vi(n,-1));

    ll p = n;

    for (int i=n-1; i>=0 ; i--) {
        if (a1[i] == '0') p = i;
        dp[0][i] = p;
    }

    p = n;
    for (int i=n-1; i>=0; i--) {
        if (a2[i] == '0') p = i;

        dp[1][i] = p;
    }

    string a = "";

    p = 0;

    for (int i=0; i<n; i++) {
        if (p == 0) a += a1[i];
        else a += a2[i];

        if (i == n-1) {
            if (p == 0) {
                a += a2[i];
            }
            else break;
        }

        if (p == 0) {
            if (dp[0][i+1] > dp[1][i] + 1) {
                p = 1;
                i--;
            }
        }
    }

    vi h(n,0);

    for (int i=n; i>=1; i--) {
        if (a[i] == a2[i-1] ) {
            h[i-1] = 1;
        }
        else break;
    }

    ll paths = 0;

    bool up = false;

    for (int i=0; i<n; i++) {
        if (a[i] == a1[i] ) {
            up = true;
            if (h[i] != 0) paths++;
        }
        else if (up == true) break;
    }

    cout<<a.substr(0,n+1)<<nl;
    cout<<paths<<nl;

}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    cin>>t;
    while(t--) solve();
    return 0;
}