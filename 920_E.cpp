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

void solve(){
    int h,w,xa,ya,xb,yb;
        cin>>h>>w>>xa>>ya>>xb>>yb;

        if (xb - xa <= 0) {
            cout<<"Draw"<<'\n';
            return;
        }

        string winner = "Draw";
        if ((xb-xa)%2 == 1) {
            //Allice has a chance at winning
            //Allice will try to minimise the horizontal distance
            //Bob Maximise
            int chance = 0;
            while (xb-xa != 0) {
                if (chance % 2 == 0) {
                    if (yb-ya > 0) {
                        xa++;
                        if (ya != w)
                            ya++;
                    }
                    else if (yb-ya == 0) {
                        xa++; 
                    }
                    else {
                        xa++;
                        if (ya != 1)
                            ya--;
                    }
                }
                else {
                    if (yb - ya > 0)
                    {
                        xb--;
                        if (yb != w)
                            yb++;
                    }
                    else if (yb - ya == 0)
                    {
                        xb--;
                        if (yb != w)
                            yb++;
                        else if (yb != 1)
                            yb--;
                    }
                    else
                    {
                        xb--;
                        if (yb != 1)
                            yb--;
                    }
                }
                chance++;
            }
            if (ya == yb) {
                winner = "Alice";
            }
        }
        else {
            int chance = 0;
            while (xb - xa != 0)
            {
                if (chance % 2 == 0)
                {
                    if (yb - ya > 0)
                    {
                        xa++;
                        if (ya != 1)
                            ya--;
                    }
                    else if (yb - ya == 0)
                    {
                        xa++;
                        if (ya != w)
                            ya++;
                        else if (ya != 1) {
                            ya--;
                        }
                    }
                    else
                    {
                        xa++;
                        if (ya != w)
                            ya++;
                    }
                }
                else
                {
                    if (yb - ya > 0)
                    {
                        xb--;
                        if (yb != 1)
                            yb--;
                    }
                    else if (yb - ya == 0)
                    {
                        xb--;
                        // if (yb != w) {
                        //     yb++;
                        // }
                        // else if (yb != 1) {
                        //     yb--;
                        // }
                    }
                    else
                    {
                        xb--;
                        if (yb!= w) 
                            yb++;
                    }
                }
                chance++;
            }
            if (ya == yb)
            {
                winner = "Bob";
            }
        }

        cout<<winner<<'\n';
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while(t--) solve();
}