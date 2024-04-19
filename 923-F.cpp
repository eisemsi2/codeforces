#include "bits/stdc++.h"
using namespace std;

#define rep(i, a, b) for (auto i = a; i < b; i++)
#define sz(x) static_cast<long long>((x).size())
#define all(x) (x).begin(), (x).end()

// #ifndef ONLINE_JUDGE
// #include "debug.h"
// #endif

#define int long long
#define double long double
const long long inf = (long long) 1e18;
const int mod = (int)1e9 + 7;


void solve(){

    int n, m; cin >> n >> m;
    vector<vector<array<int, 3>>> adj(n);
    vector<array<int, 3>> edges;
    rep(i, 0, m){
        int x, y, z; cin >> x >> y >> z; x--; y--;
        adj[x].push_back({y, z, i});
        adj[y].push_back({x, z, i});
        edges.push_back({x, y, z});
    }

    vector<bool> visited(n, false), bridge(m, false);
    vector<int> tin(n, -1), low(n, -1);
    int timer = 0;

    function<void(int, int)> dfsbridge = [&](int v, int p){
        visited[v] = true;
        tin[v] = low[v] = timer++;
        for(auto [child, w, idx]: adj[v]){
            if(child == p) continue;
            if(visited[child]) low[v] = min(low[v], tin[child]);
            else{
                dfsbridge(child, v);
                low[v] = min(low[v], low[child]);
                if(low[child] > tin[v]) bridge[idx] = true;
            }
        }
    };

    for(int i = 0; i < n; i++) if(!visited[i]) dfsbridge(i, -1);

    int idx = -1;
    int mnwt = inf;
    for(int i = 0; i < m; i++){
        if(!bridge[i] && mnwt > edges[i][2]){
            mnwt = edges[i][2];
            idx = i;
        }
    }

    auto [x, y, w] = edges[idx];
    adj[x].erase(find(all(adj[x]), (array<int, 3>){y, w, idx}));
    adj[y].erase(find(all(adj[y]), (array<int, 3>){x, w, idx}));

    queue<int> q;
    q.push(x);
    vector<int> lvl(n, inf), par(n, -1);
    lvl[x] = 0;
    while(!q.empty()){
        int p = q.front();
        q.pop();
        for(auto [i, j, k]: adj[p]){
            if(lvl[i] > lvl[p] + 1){
                lvl[i] = lvl[p] + 1;
                par[i] = p;
                q.push(i);
            }
        }
    }
    
    vector<int> v;
    while(y != -1){
        v.push_back(y);
        y = par[y];
    }

    cout << w << ' ' << sz(v) << '\n';
    for(auto val: v) cout << val + 1 << ' ';
    cout << '\n';


}


signed main(){

    ios::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while(t--) solve();
}	

// stop trying to control everything and let go, just let go