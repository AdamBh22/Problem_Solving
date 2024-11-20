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
int n,m,k;
vl adj[nb];
int vis[nb],p[nb],st=-1,ok=0;
void dfs(int i){
    vis[i] = 1;
    if(st!=-1) return;
    for(auto node : adj[i]){
        if(st!=-1) return ;
        p[node] = i;
        if(!vis[node]) dfs(node);
        else if(vis[node] == 1){
          //  cout<<node<<" "<<i<<endl;
            st = node;
            return;
        }
    }
    vis[i] = 2;
}
int main() {
   // fast;
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        int a,b;
        cin>>a>>b;
        adj[a].pb(b);
    }
    for(int i=1;i<=n;i++){
        if(vis[i]==0) dfs(i);
    }
    if(st==-1){
        cout<<"IMPOSSIBLE";
        return 0;
    }
  /*  for(int i=1;i<=n;i++){
        cout<<p[i]<<" ";
    }
    cout<<endl;*/
    vl ans;
    int ed = st;
    for(int i=1;i<=n;i++){
        ed = p[ed];
    }
    ans.pb(ed);
    st = p[ed];
    while(st!=ed){
        ans.pb(st);
        st = p[st];
    }
    ans.pb(st);
    reverse(all(ans));
    cout<<ans.size()<<endl;
    for(auto e:ans){
        cout<<e<<" ";
    }
}