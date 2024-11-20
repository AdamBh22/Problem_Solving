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
    vl v(n);
    ll sm=0;
    for(int i=0;i<n;i++){
        cin>>v[i];
        sm+=v[i];
    }
    vector<bool> dp(sm+1,0);
    dp[0]=1;
    for(int i=0;i<n;i++){
        for(int x=sm;x>=v[i];x--){
            if(dp[x-v[i]]) dp[x]=1;
        }
    }
    vl ans;
    for(int i=1;i<=sm;i++){
        if(dp[i]) ans.pb(i);
    }
    cout<<ans.size()<<endl;
    for(auto e:ans){
        cout<<e<<" ";
    }
    cout<<endl;
}
Share code to others