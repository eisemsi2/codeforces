#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
// typedef __gnu_pbds::tree<int, __gnu_pbds::null_type, less<int>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>> ordered_set;
using namespace std;

#define ll long long
#define vi vector<long long>
#define vvi vector<vector<long long>>
#define pp pair<ll,ll>
#define pb push_back

#define print(v,a,n) for (int i=a; i<n; i++) cout<<v[i]<<" ";\
    cout<<endl; 

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
            divisors.pb(n/i);
        }
    }
    sort(divisors.begin(), divisors.end());
    return divisors;
}

int main() {
    int t;
    cin>>t;
    while(t--) {
        int n,k;
        cin>>n>>k;

        vi ans(n,0);

        int filled = 0;
        int i = 1;
        int j = n;
        int indi ;
        int indj ;
        int rounds = 0;

        while (filled != n) {
            if (rounds % 2 == 0) {
                indi = rounds;
                indj = k-1-rounds;
            }
            else {
                indi = k-1-rounds;
                indj = rounds;
            }

            while (indi < n) {
                ans[indi] = i++;
                indi+=k;
                filled++;
            }
            while (indj < n) {
                ans[indj] = j--;
                indj+=k;
                filled++;
            }
            rounds++;
        }

        print(ans,0,n);
        

    }
    return 0;
}