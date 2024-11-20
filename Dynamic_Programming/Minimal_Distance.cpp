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
const int mod=1e9+7,nb=5e3+1;
ll dp[nb][nb];
string ch1,ch2;
int n,m;
ll solve(int i,int j){
    if(i<0) return j+1;
    if(j<0) return i+1;
    if(dp[i][j]!=-1) return dp[i][j];
    if(ch1[i]==ch2[j]){
        dp[i][j]=solve(i-1,j-1);
    }
    else{
        dp[i][j]=1+min(solve(i-1,j-1),min(solve(i-1,j),solve(i,j-1)));
    }
    return dp[i][j];
}
 
 
 
int main() {
    cin>>ch1;
    cin>>ch2;
    n=ch1.size();
    m=ch2.size();
    for(int i=0;i<=n;i++){
        for(int j=0;j<=m;j++){
            dp[i][j]=-1;
        }
    }
    cout<<solve(n-1,m-1);
