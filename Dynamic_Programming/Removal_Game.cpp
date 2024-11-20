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
const int mod=1e9+7,nb=5e3+10;
int t,n;
ll v[nb],dp[nb][nb];
 
int main() {
    cin>>n;
    ll sm=0;
    for(int i=1;i<=n;i++){
        cin>>v[i];
        sm+=v[i];
    }
    for(int i=1;i<=n;i++) 
        dp[i][i]=v[i];
    for(int i=n;i>=1;i--){
        for(int j=i;j<=n;j++){
            dp[i][j]=max(v[i]-dp[i+1][j],v[j]-dp[i][j-1]);
        }
    }
    ll ans=(dp[1][n]+sm)/2;
    cout<<ans;
}