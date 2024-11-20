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
int dp[1001][(1<<10)];
int n,m;
const int mod=1e9+7;
void fill(int col,int ind,int mask,int nextmask){
    if(ind==n){
        dp[col+1][nextmask]=(dp[col+1][nextmask]+dp[col][mask])%mod;
        return;
    }
    if((mask)&(1<<ind)){
        fill(col,ind+1,mask,nextmask);
    }
    else{
        fill(col,ind+1,mask,nextmask|(1<<ind));
        if(ind+1<n && (!(mask&(1<<(ind+1)))))
            fill(col,ind+2,mask,nextmask);
    }
}
int main() {
    fast;
    cin>>n>>m;
    dp[0][0]=1;
    for(int i=0;i<m;i++){
        for(int mask=0;mask<(1<<n);mask++){
            if(dp[i][mask]>0) 
                fill(i,0,mask,0);
        }
    }
    cout<<dp[m][0]<<endl;
}