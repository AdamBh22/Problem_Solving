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
const int mod=1e9+7,nb=4e5+10;
int n;
vi adj[nb];
int dp[nb];
int ans = -1;
 
void dfs(int i,int j){
    bool ok = 1;
    dp[i] = 1;
    for(auto node :adj[i]){
        if(node==j) continue; 
        dfs(node,i);
        dp[i]+=dp[node];
        ok &= (dp[node]<=(n/2));
    }
    ok &= ((n-dp[i]-1)<=(n/2));
    if(ok) ans = i; 
}
 
 
 
int main() {
    fast;
    cin>>n;
    for(int i=2;i<=n;i++){
        int a,b;
        cin>>a>>b;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    dfs(1,0);
    cout<<ans;
}