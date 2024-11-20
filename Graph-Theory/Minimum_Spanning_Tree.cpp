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
ll ds[nb];
int find(int u){
    if(ds[u] < 0)   return u;
    ds[u] = find(ds[u]);
    return ds[u];
}
 
bool merge(int u, int v){
    u = find(u); v = find(v);
    if(u == v)  return false;
    if(ds[u] < ds[v])   swap(u, v);
    ds[v] += ds[u];
    ds[u] = v;
    return true;
}
int main() {
    fast;
    cin>>n>>m;
    vector<pair<ll,pi>> edges;
    for(int i=0;i<m;i++){
        ll a,b,c;
        cin>>a>>b>>c;
        edges.push_back({c,{a,b}});
    }
    for(int i=0;i<=n;i++){
        ds[i] = -1;
    }
    sort(all(edges));
    ll sm=0,cnt=n;
    for(auto e:edges){
        ll d = e.f;
        ll a = e.s.f , b = e.s.s;
        if(merge(a,b)){
            sm += d;
            cnt--;
        }
    }
    if(cnt == 1) cout<<sm;
    else cout<<"IMPOSSIBLE";
}