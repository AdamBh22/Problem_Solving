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
const int mod=1e9+7,nb=2e5+10,nb1=8e5+10;
int n,q;
int val[nb],st[nb],en[nb],cnt=0;
vi adj[nb];
ll segTree[nb1];
 
void dfs(int i,int j){
    cnt++;
    st[i] = cnt;
    for(auto node :adj[i]){
        if(node!=j) dfs(node,i);
    }
    en[i]= cnt;
}
 
void update(int x,int val,int p=1,int l=1,int r=n){
    if(l==r){
        segTree[p] = val;
        return;
    }
    int mid = (r+l)/2;
    if(x<=mid){
        update(x,val,2*p,l,mid);
    }
    else{
        update(x,val,2*p+1,mid+1,r);
    }
    segTree[p] = segTree[2*p] + segTree[2*p+1];
}
 
ll query(int i,int j,int p=1,int l=1,int r=n){
    if(i>j) return 0;
    if(l>=i && r<=j) return segTree[p];
    int mid = (l+r)/2;
    return query(i,min(j,mid),2*p,l,mid) + query(max(i,mid+1),j,2*p+1,mid+1,r); 
}
 
int main() {
    fast;
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        cin>>val[i];
    }
    for(int i=2;i<=n;i++){
        int a,b;
        cin>>a>>b;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    dfs(1,0);
    for(int i=1;i<=n;i++){
        update(st[i],val[i]);
    }
    while(q--){
        int op,node;
        cin>>op>>node;
        if(op == 2){
            cout<<query(st[node],en[node])<<endl;
        }
        else{
            int value;
            cin>>value;
            update(st[node],value);
        }
    }
}
