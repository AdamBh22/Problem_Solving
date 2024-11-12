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
const int mod=1e9+7,nb1=2e5+10,nb2=32;
int dp[nb1][nb2];
int p[nb1];
int n,q; 
int main() {
    fast;
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        cin>>p[i];
        dp[i][0] = p[i];
    }
    for(int j=1;j<nb2;j++){
        for(int i=1;i<=n;i++){
            dp[i][j]=dp[dp[i][j-1]][j-1];
        }
    }
    while(q--){
        int node,k;
        cin>>node>>k;
        for(int j=0;j<nb2;j++){
            ll mask=(1<<j);
            ll clc=mask&k;
            if(clc!=0) node=dp[node][j];
        }
        cout<<node<<endl;
    }
}