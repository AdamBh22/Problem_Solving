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
const int mod=1e9+7,nb1=2e5+10,nb2 = 30;
int n,q;
vi adj[nb1];
int dp[nb1][nb2];
int main() {
    fast;
    cin>>n>>q;
    dp[1][0] = -1;
    for(int i=2;i<=n;i++){
        cin>>dp[i][0];
    }  
    for(int j=1;j<nb2;j++){
        for(int i=1;i<=n;i++){
            int node = dp[i][j-1];
            if(node == -1) dp[i][j] = -1;
            else{
                dp[i][j] = dp[node][j-1];
            }
        }
    }
    while(q--){
        int x,k;
        cin>>x>>k;
        for(int j=0;j<nb2;j++){
            int mask = 1<<j;
            int clc = mask&k;
            if(clc) x = dp[x][j];
            if(x==-1) break;
        }
        cout<<x<<endl;
    }
}
