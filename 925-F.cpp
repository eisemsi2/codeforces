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
        ll n,k;
        cin>>n>>k;
     
        // map<pp,char> m;
        // bool contradiction = false;
     
        vvi a(k, vi(n));
     
        for (int i=0; i<k; i++) {
            for (int j=0; j<n; j++) {
                cin>>a[i][j];
            }
        }
     
        if (k == 1) {
            cout<<"yes"<<nl;
            return;
        }
     
        vi order1(n);
        vi order2(n);
     
        ll aj = a[0][0];
        if (a[1][1] == aj) {
            order1 = a[0];
            for (int i=0 ; i<n; i++) order2[i] = order1[i];
            swap(order2[0],order2[1]);
        } 
        else {
            int i= 2;
            for (; i<n; i++) {
                if (a[1][i] == aj) {
                    break;
                }
            }
            ll ajd = a[1][i-1];
            bool added = false;
            int addedat = -1;
            for (int i=0; i<n; i++) {
                if (added == false) {
                    order1[i] = a[0][i+1];
                }
                else {
                    order1[i] = a[0][i];
                }
     
                if (a[0][i+1] == ajd) {
                    i++;
                    order1[i] = aj;
                    added = true;
                    addedat = i;
                }
            }    
            for (int i=0; i<n; i++) order2[i] = order1[i];
            if (addedat < n-1 && addedat != -1) swap(order2[addedat],order2[addedat+1]);    
        }
     
        // print(order1,0,n);
     
        bool contradiction1 = false;
        bool contradiction2 = false;
     
        for (int i=1; i<k; i++) {
            ll e = a[i][0];
     
            ll chckd = 1;
            for (int j=0;j<n; j++) {
                if (order1[j] == e) continue;
     
                if (order1[j] != a[i][chckd]) {
                    contradiction1 = true;
                    // break;
                    // cout<<"no"<<nl;
                    // return;
                }
                chckd++;
            }
     
        }
        for (int i=1; i<k; i++) {
            ll e = a[i][0];
     
            ll chckd = 1;
            for (int j=0;j<n; j++) {
                if (order2[j] == e) continue;
     
                if (order2[j] != a[i][chckd]) {
                    contradiction2 = true;
                    // break;
                    // cout<<"no"<<nl;
                    // return;
                }
                chckd++;
            }
        }
     
        if (contradiction1 == true && contradiction2 == true) {
            cout<<"no"<<nl;
        }
        else
            cout<<"yes"<<nl;
        
    }
    int main() {
        ios::sync_with_stdio(0);
        cin.tie(0);
        int t = 1;
        cin>>t;
        while(t--) solve();
        return 0;
    }