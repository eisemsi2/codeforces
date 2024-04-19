#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define vi vector<long long>
#define vvi vector<vector<long long>>
#define pp pair<ll,ll>
#define pb push_back

#define print(v,a,n) for (int i=a; i<n; i++) cout<<v[i]<<" ";\
    cout<<endl; 

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
        int n,k,m;
        cin>>n>>k>>m;

        string s;
        cin>>s;

        int bm = 0;
        int blocks = 0;
        string t = "";
        for (int i=0; i<m; i++) {
            // if (bm&(1<<(s[i]-'a')) != 0) {
            bm = bm|(1<<(s[i]-'a'));

            if (bm == ((1<<k)-1)) {
                bm = 0;
                blocks++;
                t += s[i];
            }
        }

        if (blocks >= n) {
            cout<<"YES"<<endl;
        }
        else {
            cout<<"NO"<<endl;
            for (int i=0; i<26; i++) {
                if ((bm&(1<<i)) == 0) {
                    t += ('a'+i);
                    break;
                }
            }
            while (t.size() != n) {
                t+='a';
            }
            cout<<t<<endl;
        }
    }
    return 0;
}