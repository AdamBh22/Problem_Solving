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
int n,m;
ll p[nb],r[nb];
vector<pair<ll,pl>> edges;
void make_set(int v){
    p[v] = v;
    r[v] = 1;
}
int find_set(int v) {
    if (v == p[v])
        return v;
    return p[v] = find_set(p[v]);
}
void union_set(int a,int b){
    a = find_set(a);
    b = find_set(b);
    if(a!=b){
        if(r[a]<r[b]) swap(a,b);
        p[b] = a;
        r[a] += r[b];
    }
}
bool same(int a,int b){
    return find_set(a) == find_set(b);
}
int calculate(int a){
    a = find_set(a);
    return r[a];
}
int main() {
    fast;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        make_set(i);
    }
    int cnt = n , mx = 1;
    for(int i=1;i<=m;i++){
        int a,b;
        cin>>a>>b;
        if(!same(a,b)){
            cnt--;
            union_set(a,b);
            mx = max( mx , calculate(a) );
        }
        cout<<cnt<<" "<<mx<<endl;
    }
}