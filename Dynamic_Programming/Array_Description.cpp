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
int n,m,mod=1e9+7;
const int N=1e5+7,M=1e2+7;
int dp[N][M];
int main() {
    cin>>n>>m;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    if(a[0]==0){
        for(int i=1;i<=m;i++) dp[0][i]=1;
    }
    else dp[0][a[0]]=1;
    for(int i=1;i<n;i++){
        if(a[i]==0){
            for(int v=1;v<=m;v++){
                for(int e=v-1;e<=v+1;e++){
                    if(e>=1 && e<=m) dp[i][v]=(dp[i][v]%mod+dp[i-1][e]%mod)%mod;
                }
            }
        }
        else{
            for(int e=a[i]-1;e<=a[i]+1;e++){
                if(e>=1 && e<=m) dp[i][a[i]]=(dp[i][a[i]]%mod+dp[i-1][e]%mod)%mod;
            }
        }
    }
    ll ans=0;
    for(int i=1;i<=m;i++)
        ans=(ans%mod+dp[n-1][i]%mod)%mod;
    cout<<ans%mod<<endl;
}