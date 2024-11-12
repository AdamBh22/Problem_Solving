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
ll cnt[nb],dp[nb];
void dfs1(int i,int j,ll depth){
    dp[1]+=depth;
    cnt[i]++;
    for(auto e:adj[i]){
        if(e!=j){
            dfs1(e,i,depth+1);
            cnt[i] += cnt[e];
        }
    }
}
void dfs2(int i,int j){
    for(auto e:adj[i]){
        if(e!=j){
            dp[e] = dp[i] + n - 2*cnt[e];
            dfs2(e,i);
        }
    }
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
    dfs1(1,0,0);
    dfs2(1,0);
    for(int i=1;i<=n;i++){
        cout<<dp[i]<<" ";
    }
}