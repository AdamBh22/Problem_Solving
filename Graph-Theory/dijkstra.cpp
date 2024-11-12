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
const int mod=1e9+7,nb2=2e5+1;
int n,m;
vector<vi> adj[nb2];
vl dist;
 
void dijkstra(ll s){
    priority_queue<pl> pq;
    dist[s]=0ll;
    pq.push({0ll,s});
    while(!pq.empty()){
        ll node = pq.top().s;
        ll d = - pq.top().f;
        pq.pop();
        if(dist[node]!=d) continue;
        for(int i=0;i<adj[node].size();i++){
            int v = adj[node][i][0];
            int w = adj[node][i][1];
            if(w+d<dist[v]){
                dist[v]=w+d;
                pq.push({-w-d,v});
            }
        }
    }
}
 
int main() {
    fast;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int a,b,c;
        cin>>a>>b>>c;
        adj[a].pb({b,c});
       // adj[b].pb({a,c});
    }
    for(int i=1;i<=n+1;i++){
        dist.pb(1e18);
    }
    dijkstra(1);
    for(int i=1;i<=n;i++){
        cout<<dist[i]<<" ";
    }
    cout<<endl;
}