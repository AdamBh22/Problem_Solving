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
int n,m,cnt = 0;
ll p[nb] , ans[nb];
vi adj1[nb],adj2[nb],topological;
bool vis1[nb],vis2[nb] ;
void dfs1(int i){
    vis1[i] = 1;
    for(auto e:adj1[i]){
        if(!vis1[e]) dfs1(e);
    }
    topological.pb(i);
}
 
void dfs2(int i){
    vis2[i] = 1;
    ans[i] = cnt;
    for(auto e:adj2[i]){
      //  cout<<cnt<<" "<<i<<" "<<e<<endl;
        if(!vis2[e]) dfs2(e);
    }
}
int main() {
    fast;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        adj1[a].pb(b);
        adj2[b].pb(a);
    }
    for(int i=1;i<=n;i++){
        if(!vis1[i]){
            dfs1(i);
        }
    }
    reverse(all(topological));
    for(auto e:topological){
        if(!vis2[e]){
            cnt++;
            dfs2(e);
        }
    }
    cout<<cnt<<endl;
    for(int i=1;i<=n;i++){
        cout<<ans[i]<<" ";
    }
}