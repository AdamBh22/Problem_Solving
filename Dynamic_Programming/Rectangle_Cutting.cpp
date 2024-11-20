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
const int mod=1e9+7,nb=510;
ll dp[nb][nb];
int n,m;
 
int main() {
    fast;
    cin>>n>>m;
    for(int i=0;i<=n+1;i++){
        for(int j=0;j<=m+1;j++){
            if(i!=j) dp[i][j]=1e17;
            else dp[i][j]=0;
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            for(int x=1;x<=i;x++)
                dp[i][j]=min(dp[i][j],1+dp[x][j]+dp[i-x][j]);
            for(int x=1;x<=j;x++)
                dp[i][j]=min(dp[i][j],1+dp[i][x]+dp[i][j-x]);
        }
    }
    cout<<dp[n][m];
}
