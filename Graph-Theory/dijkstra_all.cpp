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
/*
    what is the minimum price of such a route?
    how many minimum-price routes are there? (modulo 10^9+7)
    what is the minimum number of flights in a minimum-price route?
    what is the maximum number of flights in a minimum-price route?
*/
int n,m;
vi adj[nb];
int main() {
    fast;
    cin>>n>>m;
    vi inDegree(n+1,0);
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        inDegree[b]++;
        adj[a].pb(b);
    }
    queue<int> q;
    vi ans;
    for(int i=1;i<=n;i++){
        if(inDegree[i]==0) q.push(i);
    }
    while(!q.empty()){
        int node=q.front();
        q.pop();
        ans.pb(node);
        for(auto e : adj[node]){
            inDegree[e]--;
            if(inDegree[e]==0) q.push(e); 
        }
    }
    if(ans.size()==n){
        for(auto e:ans){
            cout<<e<<" ";
        }
    }
    else cout<<"IMPOSSIBLE"<<endl;
