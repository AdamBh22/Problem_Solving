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
const int mod=1e9+7,nb=1e6+10;
ll dp[nb][2];
ll solve(int i,int j){
   // cout<<i<<" "<<j<<endl;
    if(i==1){
        dp[i][j]=1;
        return 1;
    }
    if(dp[i][j]!=-1) return dp[i][j];
    dp[i][j]=0;
    if(j==0){
        dp[i][j]=(4*solve(i-1,1)%mod+solve(i-1,0)%mod)%mod;
    }
    else{
        dp[i][j]=(solve(i-1,1)%mod+2*solve(i-1,0)%mod)%mod;
    }
    return dp[i][j];
}
 
int main() {
    fast;
    int t;
    cin>>t;
    int nb1=1e6;
    for(int i=0;i<=nb1;i++){
        dp[i][0]=-1;
        dp[i][1]=-1;
    }
    dp[1][0] = dp[1][1] =1;
    for(int i=2;i<=nb1;i++){
        dp[i][0]=(2*dp[i-1][0]%mod+dp[i-1][1]%mod)%mod;
        dp[i][1]=(dp[i-1][0]%mod+4*dp[i-1][1]%mod)%mod;
    }
    while(t--){
        int n;
        cin>>n;
        cout<<(dp[n][0]%mod+dp[n][1]%mod)%mod<<endl;
    }
}