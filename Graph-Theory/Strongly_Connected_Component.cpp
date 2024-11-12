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
const int mod=1e9+7,nb=1e5+10;
int n,m;
vi adj1[nb],adj2[nb];
bool vis1[nb],vis2[nb];
void dfs1(int cur){
    vis1[cur] = 1 ;
    for(auto node:adj1[cur]){
        if(!vis1[node]){
            dfs1(node);
        }
    }
}
 
void dfs2(int cur){
    //cout<<cur<<endl;
    vis2[cur] = 1 ;
    for(auto node:adj2[cur]){
        if(!vis2[node]){
            dfs2(node);
        }
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
    dfs1(1);
    dfs2(1);
    bool ok= 0;
    for(int i=2;i<=n;i++){
        if(!vis1[i]){
            cout<<"NO"<<endl;
            cout<<1<<" "<<i<<endl;
            ok = 1;
            break;
        }
        else if(!vis2[i]){
            cout<<"NO"<<endl;
            cout<<i<<" "<<1<<endl;
            ok = 1;
            break;
        }
    }
    if(!ok) cout<<"YES";
}