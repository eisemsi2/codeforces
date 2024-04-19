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



void getpremutationsintergers(vi premuation, int i) {
    // vvi premutations;
    // vi premutation;
    int n = premuation.size();

    if (i == n) {
        print(premuation,0,n);
        return;
    }


    for (int j=i; j<n; j++) {
        swap(premuation[i], premuation[j]);
        getpremutationsintergers(premuation,i+1);
        swap(premuation[i], premuation[j]);
    }

}

int main() {
    int t = 1;
    // cin>>t;
    while(t--) {
        vi permutation = {0,1,2,3};
        getpremutationsintergers(permutation,0);
        cout<<endl;

        // permutation.pb(4);
        // getpremutationsintergers(permutation,0);
        // cout<<endl;

        // permutation.pb(5);
        // getpremutationsintergers(permutation, 0);
        // cout<<endl;
    }
    return 0;
}