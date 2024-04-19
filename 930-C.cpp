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
    int n;
    cin>>n;

    ll x = n-1;
    ll lsb = 0;

    for (int i=0; i<31; i++) {
        ll z = (x)&(1LL<<i);
        if (z != 0 ) {
            lsb = i;
        }
    }

    // cout<<lsb<<nl;

    ll maxxor = (1LL<<(lsb+1))-1;

    ll y = 0;
    for (int i=0; i<=lsb; i++) {
        ll z = (x)&(1LL<<i);
        if (z == 0) {
            y += 1LL<<i;
        }
    }

    // cout<<x<<" "<<y<<nl;

    cout<<"? 0 0 1 1"<<endl;
    char a;
    cin>>a;

    int ix = (a == '>' ? 0 : 1);

    for (int i=2; i<n; i++) {
        cout<<"? "<<ix<<" "<<ix<<" "<<i<<" "<<i<<endl;
        cin>>a;

        ix = (a == '<' ? i : ix);
    }

    // cout<<"? "<<ix<<" 0 "<<ix<<" 1"<<endl;
    // cin>>a;

    // int ix = (a == '>' ? 0 : 1);

    // for (int i = 2; i<n; i++) {
    //     cout<<"? "<<ix<<" "<<ix<<" "<<ix<<" "<<i<<endl;
    //     cin>>a;

    //     ix = (a == '<' ? i : ix);
    // }
    // ll c = (1<<(lsb+1)) - 1 ;
    // if (x == c) {
    //     cout<<"! "<<ix<<" "<<ix<<endl;
    // }
    // else {
    //     cout<<"? "<<ix<<" 0 "<<ix<<" 1"<<endl;
    //     cin>>a;

    //     int iy = (a == '>' ? 0 : 1);

    //     for (int i = 2; i<n; i++) {
    //         cout<<"? "<<ix<<" "<<iy<<" "<<ix<<" "<<i<<endl;
    //         cin>>a;

    //         iy = (a == '<' ? i : iy);
    //     }

    //     cout<<"! "<<ix<<" "<<iy<<endl;
    // }

    vi list;
    cout<<"? "<<ix<<" 0 "<<ix<<" 1"<<endl;
    cin>>a;
    int iy;
    if (a == '>') {
        iy = 0;
        list.pb(0);
    }
    else if (a == '=') {
        iy = 0;
        list.pb(0);
        list.pb(1);
    }
    else {
        iy = 1;
        list.pb(1);
    }

    for (int i=2; i<n; i++) {
        cout<<"? "<<ix<<" "<<iy<<" "<<ix<<" "<<i<<endl;
        cin>>a;

        if (a == '=') {
            list.pb(i);
        }
        else if (a == '<') {
            list.clear();
            iy = i;
            list.pb(i);
        }
    }

    if (list.size() == 1 ) {
        cout<<"! "<<ix<<" "<<list[0]<<endl;
        return;
    }

    // int mi = 0;
    cout<<"? "<<list[0]<<" "<<list[0]<<" "<<list[1]<<" "<<list[1]<<endl;
    cin>>a;

    int mi = (a == '<' ? list[0] : list[1]); 
    for (int i=2; i<list.size(); i++) {
        cout<<"? "<<mi<<" "<<mi<<" "<<list[i]<<" "<<list[i]<<endl;
        cin>>a;

        mi = (a == '>' ? list[i] : mi); 
        
    }

    cout<<"! "<<ix<<" "<<mi<<endl;



  
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    cin>>t;
    while(t--) solve();
    return 0;
}