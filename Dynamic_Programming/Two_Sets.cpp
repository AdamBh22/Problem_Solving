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
const int mod=1e9+7,nb1=5e5,nb2=501;
int dp[nb2][nb1];
ll n,sm=0;
long long power(long long a, long long b) {
    a %= mod;
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}
 
int main() {
    fast;
    cin>>n;
    sm=n*(n+1)/4;
    if(sm*4 != n*(n+1)) cout<<0<<endl;
    else{
        dp[0][0]=1;
        for(int i=1;i<=n;i++){
        	for(int x=1;x<=sm;x++){
        		dp[i][x]=(dp[i][x]%mod+dp[i-1][x]%mod)%mod;
        		if(x-i>=0) dp[i][x]=(dp[i][x]%mod+dp[i-1][x-i]%mod)%mod;
        	}
        }
        cout<<dp[n][sm]<<endl;
    }
}