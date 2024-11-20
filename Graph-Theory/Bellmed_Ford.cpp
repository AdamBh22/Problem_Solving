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
const int mod=1e9+7,nb1=2500;
int n,m;
bool vis1[nb1],vis2[nb1];
vi adj1[nb1],adj2[nb1];
void dfs1(int i){
    vis1[i] = 1;
    for(auto node :adj1[i]){
        if(!vis1[node]) dfs1(node);
    }
}
void dfs2(int i){
    vis2[i] = 1;
    for(auto node :adj2[i]){
        if(!vis2[node]) dfs2(node);
    }
}
int main() {
    fast;
    cin>>n>>m;
    vector<vl> edges;
    vector<ll> dp(n+1,-1e17);
    for(int i=1;i<=m;i++){
    	int a,b,c;
    	cin>>a>>b>>c;
    	edges.pb({a,b,c});
        adj1[a].pb(b);
        adj2[b].pb(a);
    }
    dfs1(1);
    dfs2(n);
    bool ok = 1;
    dp[1] = 0 ;
    for(int x=1;x<=n;x++){
    	for(auto e:edges){
    		ll a = e[0], b = e[1] , c = e[2];
            ll val = dp[a] + c;
            if(val > dp[b]){
                dp[b] = dp[a] + c;
                if(vis1[b] && vis2[b] && x==n) {
                   // cout<<a<<" "<<b<<" "<<c<<" "<<x<<endl;
                    ok=0;
                }
            }  
    	} 
    }
    if(ok) cout<<dp[n];
    else cout<<"-1";
}
