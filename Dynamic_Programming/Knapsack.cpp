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
int gcd (int a, int b) { return b ? gcd (b, a % b) : a; }
int lcm (int a, int b) { return a / gcd(a, b) * b; }
int n,limit;
 
 
int main() {
    cin>>n>>limit;
    vi price(n+1),pag(n+1);
    for(int i=1;i<=n;i++)
        cin>>price[i];
    for(int i=1;i<=n;i++)
        cin>>pag[i];
    vector<vi> dp(n+1,vi(limit+1,0));
    for(int i=1;i<=n;i++){
        for(int x=0;x<=limit;x++){
            dp[i][x]=dp[i-1][x];
            if(x>=price[i]) dp[i][x]=max(dp[i-1][x],dp[i-1][x-price[i]]+pag[i]);
        }
    }
    cout<<dp[n][limit]<<endl;
}
