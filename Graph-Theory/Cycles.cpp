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
const int mod=1e9+7,nb=2510;
int n,m;
ll dp[nb],p[nb];
vector<vl> edges;
 
int main() {
   // fast;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        dp[i] = 1e18;
        p[i] = -1;
    }
    for(int i=0;i<m;i++){
        int a,b,c;
        cin>>a>>b>>c;
        edges.pb({a,b,c});
    }
    for(int i=1;i<=(n-1);i++){
        for(auto e : edges){
            ll st = e[0];
            ll ed = e[1];
            ll dist = e[2];
            ll val = dist + dp[st];
            if(val < dp[ed]){
                dp[ed] = val;
            }
        }
    }
    bool ok=0;
    for(auto e : edges){
        ll st = e[0];
        ll ed = e[1];
        ll dist = e[2];
        ll val = dist + dp[st];
        if(val < dp[ed]){
            ok = 1;
            break;
        }        
    }
    /*for(int i=1;i<=n;i++){
        cout<<p[i]<<" ";
    }
    cout<<endl;*/
    if(! ok) cout<<"NO";
    else{
        cout<<"YES"<<endl;
        int node = -1;
        for(int i=1;i<=n;i++){
            for(auto e:edges){
                ll st = e[0] , ed = e[1] , val = e[2] + dp[st];
              //  cout<<st<<" "<<ed<<" "<<val<<" "<<dp[ed]<<endl;
                if(val < dp[ed]){
                    dp[ed] = val;
                    p[ed] = st;
                    node = ed;
                }                
            }
        }
        /* for(int i=1;i<=n;i++){
            cout<<p[i]<<" ";
        }
        cout<<endl;*/
        for(int i=1;i<=n;i++){
            node = p[node];
        }
        vl ans;
        ans.pb(node);
        int st1 = p[node];
        while(st1!=node){
            ans.pb(st1);
            st1 = p[st1];
        }
        ans.pb(st1);
        reverse(all(ans));
        for(auto e:ans){
            cout<<e<<" ";
        }
    }
