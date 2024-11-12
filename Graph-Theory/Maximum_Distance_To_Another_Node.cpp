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
int d1[nb],d2[nb],taken[nb],p[nb];
void dfs(int i,int j){
    p[i] = j;
    for(auto node : adj[i]){
        if(node!=j) dfs(node,i);
    }
    for(auto node : adj[i]){
        if(node!=j){
            if(d1[node] + 1 > d1[i]){
                d2[i] = d1[i];
                d1[i] = 1 + d1[node];
                taken[i] = node;
            }
            else d2[i] = max(d2[i] , 1 + d1[node]);
        }
    }
}
void dfs2(int i){
    for(auto node:adj[i]){
        if(node == p[i]) continue;
        if(taken[i] == node){
            if(d2[i] + 1 >d1[node]){
                d2[node] = d1[node];
                d1[node] = d2[i] + 1;
                taken[node] = i;
            }
            else d2[node] = max(d2[node] , d2[i] + 1);
        }
        else{
            d2[node] = d1[node];
            d1[node] = d1[i]+1;
            taken[node] = i;
        }
        dfs2(node);
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
    dfs(1,0);
    dfs2(1);
    for(int i=1;i<=n;i++){
        cout<<d1[i]<<" ";
    }
}