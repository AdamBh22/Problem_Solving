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
const int mod=1e9+7;
const ll inf=1e17;
int n,m,q;
 
 
int main() {
    fast;
    cin>>n>>m>>q;
    vector<vl> dp(n+1,vl(n+1,inf));
    for(int i=0;i<m;i++){
        ll a,b,c;
        cin>>a>>b>>c;
        dp[a][b]=min(dp[a][b],c);
        dp[b][a]=min(dp[b][a],c);
    }
    for(int i=1;i<=n;i++){
        dp[i][i]=0;
    }
    for(int k=1;k<=n;k++){
        for(int a=1;a<=n;a++){
            for(int b=1;b<=n;b++){
                dp[a][b]=min(dp[a][b],dp[a][k]+dp[k][b]);
            }
        }
    }
    while(q--){
        int a,b;
        cin>>a>>b;
        if(dp[a][b]==inf) cout<<-1<<endl;
        else cout<<dp[a][b]<<endl;
    }
}