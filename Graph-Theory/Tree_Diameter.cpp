#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define f first
#define s second
#define make_pair mp 
#define fast ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define vi vector<int>
#define vl vector<long long int>
#define pi pair<int,int>
#define pl pair<long long int ,long long int>
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define ll long long
#define endl '\n'
const double eps=1e-12;
int gcd (int a, int b) { return b ? gcd (b, a % b) : a; }
int lcm (int a, int b) { return a / gcd(a, b) * b; }
const int mod=1e9+7,nb=2e5+10;
int n,m;
vi adj[nb];
int depth[nb],p[nb];
int dfs(int i,int j){
    p[i] = j;
    for(auto node : adj[i]){
        if(node!=j) depth[i] = max(depth[i] , 1 + dfs(node,i));
    }
    return depth[i];
}
int main() {
    fast;
    cin>>n;
    for(int i=1;i<n;i++){
        int a,b;
        cin>>a>>b;
        adj[a].pb(b);
        adj[b].pb(a);
    }    
    dfs(1,0);
    ll ans = 0;
    for(int i=1;i<=n;i++){
        vl v;
        for(auto node : adj[i]){
            if(p[i]!=node) v.pb(depth[node]);
        }
        sort(rall(v));
        ll sm = 0;
        if(v.size() == 1) ans = max(ans , 1+v[0]);
        else if(v.size() >1) ans = max(ans , 2 + v[0] + v[1]);
    }
    cout<<ans;
}
