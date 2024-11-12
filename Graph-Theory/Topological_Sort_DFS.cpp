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
vi adj1[nb];
bool vis1[nb];
int vis2[nb];
int inDegree[nb];
vi topological;
bool ok=1;
 
void dfs1(int cur){
   // cout<<cur<<endl;
    vis1[cur] = 1 ;
    for(auto node:adj1[cur]){
        if(!vis1[node]){
            dfs1(node);
        }
    }
    topological.pb(cur);
}
 
void dfs2(int cur){
   // cout<<cur<<endl;
    vis2[cur] = 1;
    for(auto node:adj1[cur]){
        if(!vis2[node]){
            dfs2(node);
        }
        else if(vis2[node]==1) ok = 0;
    }
    vis2[cur] = 2;
}
 
int main() {
    //fast;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        adj1[a].pb(b);
    }
 //   cout<<"ok1"<<endl;
    for(int i=1;i<=n;i++){
       // cout<<i<<" "<<vis1[i]<<" "<<vis2[i]<<endl;
        if(!vis2[i]){
            dfs2(i);
        }
        if(!vis1[i]) dfs1(i);
    }
    reverse(all(topological));
    if(!ok) cout<<"IMPOSSIBLE";
    else{
        for(int i=0;i<n;i++){
            cout<<topological[i]<<" ";
        }
    }
}