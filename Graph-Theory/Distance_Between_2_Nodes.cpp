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
const int mod=1e9+7,nb1=2e5+10,nb2 = 30;
int n,q;
vi adj[nb1];
int dp[nb1][nb2],depth[nb1],p[nb1];
void dfs(int i,int j,int k){
    depth[i] = k;
    p[i] = j;
    for(auto node : adj[i]){
       if(node!=j)dfs(node,i,k+1);
    }
}
int main() {
    fast;
    cin>>n>>q;
    for(int i=1;i<n;i++){
        int a,b;
        cin>>a>>b;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    dfs(1,0,0);
    dp[1][0] = -1;
    for(int i=2;i<=n;i++){
        dp[i][0] = p[i];
    }  
    for(int j=1;j<nb2;j++){
        for(int i=1;i<=n;i++){
            int node = dp[i][j-1];
            if(node == -1) dp[i][j] = -1;
            else{
                dp[i][j] = dp[node][j-1];
            }
        }
    }
 //   dfs(1,0,0);
    while(q--){
        int x,y;
        cin>>x>>y;
        int a = x,b = y,lca;
        if(depth[b]<depth[a]) swap(a,b);
        int d = depth[b] - depth[a];
        for(int j=0;j<nb2;j++){
            if(d&(1<<j)) b = dp[b][j];
        }
        if(a==b) lca = a;
        else{
            for(int j=19;j>=0;j--){
                if(dp[a][j]!=dp[b][j]){
                    a = dp[a][j];
                    b = dp[b][j];
                    //break;
                }
            }
            lca = dp[a][0];
        }
      //  cout<<"**********************"<<endl;
      //  cout<<lca<<" "<<depth[lca]<<endl;
      //  cout<<depth[x]<<" "<<depth[y]<<endl;
        cout<<depth[x] + depth[y] - 2*depth[lca]<<endl;
    }
}