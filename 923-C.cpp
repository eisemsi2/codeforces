#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
// typedef __gnu_pbds::tree<int, __gnu_pbds::null_type, less<int>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update> ordered_set;
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
        int n,m,k;
        cin>>n>>m>>k;

        set<int> seta;
        set<int> setb;

        for (int i=0; i<n; i++) {
            int x;
            cin>>x;
            if (x>k) continue;
            seta.insert(x);
        }
        for (int i=0; i<m; i++) {
            int x;
            cin>>x;
            if (x>k) continue;

            setb.insert(x);
        }

        if (seta.size() < k/2 || setb.size() <k/2) {
            cout<<"NO"<<endl;
            continue;
        }

        // vi t1;
        // vi t2;

        // for (auto e : seta) {
        //     t1.pb(e);
        // }
        // for (auto e : setb)
        // {
        //     t2.pb(e);
        // }

        // sort(t1.begin(),t1.end());
        // sort(t2.begin(),t2.end());

        // vi ans;

        // int i=0;
        // int j=0;
        // int used = 0;

        // bool flag = false;
        // while (i<t1.size() && j<t2.size() && flag == false) {
        //     if (t1[i] > t2[j]) {
        //         used++;
        //         if (t2[j] != used) {
        //             flag = true;
        //             break;
        //         }
        //         else {
        //             ans.pb(t2[j]);
        //         }
        //         j++;
        //     }

        //     else if (t1[j] < t2[j]) {
        //         used++;
        //         if (t1[i] != used) {
        //             flag = true;
        //             break;
        //         }
        //         else ans.pb(t1[i]);
        //         i++;
        //     }
        //     else {
        //         cout<<"notdone"<<endl;
        //         break;
        //     }


        //     if (used == k) {
        //         break;
        //     }
        // }

        // if (flag == true) {
        //     cout<<"NO"<<endl;
        // }
        // else {
        //     cout<<"YES"<<endl;
        // }

        bool flag = false;

        int ua = 0;
        int ub = 0;

        vi hb;

        for (int i=1; i<=k; i++) {
            if (seta.find(i) == seta.end()) {
                if (setb.find(i) == setb.end()) {
                    flag = true;
                    break;
                }
                else {
                    ub++;
                }
            }
            else if (setb.find(i) == setb.end()) {
                if (seta.find(i) == setb.end()) {
                    flag = true;
                    break;
                }
                else {
                    ua++;
                }
            }
            // else if (seta.find(i) == )

            else {
                hb.pb(i);
            }
        }

        if (ub > k/2 || ua > k/2) {
            flag = true;
        }

        if (flag == true) {
            cout<<"NO"<<endl;
        }
        else {
            cout<<"YES"<<endl;
        }




    }
    return 0;
}