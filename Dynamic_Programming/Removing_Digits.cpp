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
const int mod=1e9+7;
int n;
 
 
int main() {
    fast;
    cin>>n;
    if(n<10) cout<<1<<endl;
    else{
        vl dp(n+1,mod);
        for(int i=0;i<=9;i++) dp[i]=1;
        for(int i=10;i<=n;i++){
            int x=i;
            while(x!=0){
                dp[i]=min(dp[i],1+dp[i-x%10]);
                x/=10;
            }
        }
        cout<<dp[n];
    }
}