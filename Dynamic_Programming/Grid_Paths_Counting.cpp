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
const int mod=1e9+7,nb=1e3+10;
int n;
string tab[nb];
ll dp[nb][nb];
bool ok(int i,int j){
    if(i>=0 && i<n && j>=0 && j<n){
        if(tab[i][j]=='.') return 1;
        else return 0;
    }
    return 0;
}
ll solve(int i,int j){
    if(!ok(i,j)) return 0;
    if(i==0 && j==0) return 1;
    if(dp[i][j]!=-1) return dp[i][j];
    dp[i][j]=(solve(i-1,j)%mod+solve(i,j-1)%mod)%mod;
    return dp[i][j]%mod;
}
 
int main() {
    fast;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>tab[i];
    }
    for(int i=0;i<=n;i++){
        for(int j=0;j<=n;j++){
            dp[i][j]=-1;
        }
    }
    cout<<solve(n-1,n-1);
}