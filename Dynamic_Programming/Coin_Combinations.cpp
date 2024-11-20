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
int n,tar,mod=1e9+7;
int main() {
    fast;
    cin>>n>>tar;
    vi v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    vi dp(tar+1,0);
    dp[0]=1;
    for(auto ele:v){
        for(int x=1;x<=tar;x++){
            if(x-ele>=0) dp[x]=(dp[x]%mod+dp[x-ele]%mod)%mod;
        }
    }
    cout<<dp[tar]%mod<<endl;
}
