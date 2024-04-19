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
    int n;
    cin>>n;

    vi a(n);
    vi b(n);

    map<int,vector<int>> hash;

    for (int i=0; i<n; i++) cin>>a[i];
    for (int i=0; i<n; i++) {
        cin>>b[i];
        if (a[i] != b[i]) hash[b[i]].push_back(i);
    }

    bool ans = true;

    for (auto e : hash) {
        int num = e.first;
        vector<int> v = e.second;

        for (int i=0; i<v.size(); i++) {
            int j = v[i];
            if (a[j] == b[j]) continue;
            if (a[j] > b[j]) {
                ans = false;
                break;
            }

            int k = j;
            int l = j;
            bool safe = false;

            while (k < n || l >= 0) {
                if (k<n) k++;
                if (l>=0) l--;

                if ( k < n && a[k] == b[j]) {
                    for (int i = k; i>=j; i-- ) a[i] = b[j];
                    break;
                }
                else if (k < n && a[k] == b[k]) {
                    safe = true;
                    k = n;
                }
                else if (k < n && a[k] > b[j]) {
                    k = n;
                }


                if (l >= 0 && a[l] == b[j]) {
                    for (int i=l; i<=j; i++) a[i] = b[j];
                    break;
                }                
                else if (l >=0 && a[l] == b[l]) {
                    safe = true;
                    l = -1;
                }
                else if (l >=0 && a[l] > b[j]) l = -1;
            }
            if (safe == false && l == -1 && k == n) {
                ans = false;
                break;
            } 
        }
        if (ans == false) break;
    }

    for (int i=0; i<n; i++) {
        if (a[i] != b[i]) ans = false;
    }
    
    string s = (ans ? "YES":"NO");

    cout<<s<<nl;

}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    cin>>t;
    while(t--) solve();
    return 0;
}