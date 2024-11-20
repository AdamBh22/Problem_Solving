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
const int mod=1e9+7 , nb = 2e5+10;
int n,m,cnt = 0, assignTo[nb] , val[nb];
ll nodeVal[nb] , dp[nb];
vi adj1[nb],adj2[nb] , nodeAdj[nb];
bool vis1[nb],vis2[nb];
vi topological , v;
void dfs1(int i){
    vis1[i] = 1;
    for(auto e:adj1[i]){
        if(!vis1[e]) dfs1(e);
    }
    topological.pb(i);
}
 
void dfs2(int i){
    vis2[i] = 1;
    v.pb(i);
    for(auto e:adj2[i]){
        if(!vis2[e]) dfs2(e);
    }
}
ll solve(int i){
    if(dp[i]!=-1) return dp[i];
    dp[i] = nodeVal[i];
    for(auto node : nodeAdj[i]){
        dp[i] = max(dp[i],nodeVal[i]+solve(node));
    }
    return dp[i];
}
int main() {
    fast;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>val[i];
    }
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        adj1[a].pb(b);
        adj2[b].pb(a);
    }
    for(int i=1;i<=n;i++){
        if(!vis1[i]) dfs1(i);
    }
    reverse(all(topological)) ;
    for(auto e:topological){
        if(!vis2[e]){
            cnt++;
            dfs2(e);
            for(auto e1:v){
                assignTo[e1] = cnt;
                nodeVal[cnt] += val[e1] ; 
            }
            v.clear();
        }
    }
    for(int i=1;i<=n;i++){
        for(auto e : adj1[i]){
            if(assignTo[i]!=assignTo[e]){
                nodeAdj[assignTo[i]].pb(assignTo[e]);
            }
        }
    }
    for(int i=1;i<=cnt;i++){
        dp[i] = -1 ;
    }
    ll ans = 0;
    for(int i=1;i<=cnt;i++){
        ans = max(ans,solve(i));
    }
    cout<<ans<<endl;
}