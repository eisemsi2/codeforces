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
    string s;
    cin>>s;

    int n = s.size();
    if (n == 1) {
        cout<<"NO"<<nl;
        return;
    }
    if (n == 2) {
        if (s[0] == s[1]) {
            cout<<"NO"<<nl;
        }
        else {
            cout<<"YES"<<nl;
            cout<<1<<nl;
            cout<<s<<nl;
        }
        return;
    }
    
    int i = 0;
    int j = n-1;
    bool pal = true;

    while (i < j) {
        if (s[i] != s[j]) {
            pal = false;
            break;
        }

        i++;
        j--;
    }

    if (pal == false) {
        cout<<"YES"<<nl;
        cout<<1<<nl;
        cout<<s<<nl;
        return;
    }

    // claim ---> Even length palidromes cant be partioned into non palindromic
    // substrings iff s is identically single letter.

    char x = s[0];
    bool alleq = true;
    for (int i=0; i<n; i++) {
        if (s[i] != x) {
            alleq = false;
            break;
        }
    }

    if (alleq == true) {
        cout<<"NO"<<nl;
        return;
    }

    // int i;
    for (i=0; i<n; i++) {
        if (s[i] != s[0]) break;
    }

    pal = true;
    int id = i+1;
    j = n-1;
    while (id < j) {
        if (s[id] != s[j]) {
            pal = false;
            break;
        }

        id++;
        j--;
    }

    if (pal == false) {
        cout<<"YES"<<nl;
        cout<<2<<nl;
        cout<<s.substr(0,i+1)<<" "<<s.substr(i+1,n-i-1)<<nl;
        return;
    }

    if (i == 1) {
        cout<<"NO"<<nl;
        return;
    }

    cout<<"YES"<<nl;
    cout<<2<<nl;
    cout<<s.substr(0,i+2)<<" "<<s.substr(i+2,n-i-2)<<nl;





    
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    cin>>t;
    while(t--) solve();
    return 0;
}