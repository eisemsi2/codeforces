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

bool isPalindrome(string s) {
        int n = s.size();
        int i = 0;
        int j = n-1;

        set<char> num = {'0','1','2','3','4','5','6','7','8','9'};

        while (i < j) {
            if (s[i] <= 'z' && s[i] >= 'a') s[i] = 'A' + (s[i] - 'a');
            if (s[j] <= 'z' && s[j] >= 'a') s[j] = 'A' + (s[j] - 'a');

            if (s[i] > 'Z' || s[i] < 'A' && num.find(s[i]) == num.end()){
                i++;
                continue;
            }
            else if (s[j] > 'Z' || s[j] < 'A' && num.find(s[j]) == num.end()){
                j--;
                continue;
            }
            
            if (s[i] != s[j]) return false;
            else{
                i++;
                j--;
            }
            
        }

        return true;
    }


int main()
{
    int t = 1;
    // cin>>t;
    while (t--)
    {
        string s = "0P";
        // cin>>s;
        cout<<isPalindrome(s)<<endl;
        
    }
    return 0;
}