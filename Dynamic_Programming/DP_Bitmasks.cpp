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
int n,limit,mod=1e9;
int main() {
    cin>>n>>limit;
    vi w(n);
    for(int i=0;i<n;i++){
        cin>>w[i];
    }
    vector<pi> dp((1<<n),{1e9,1e9});
    dp[0]={1,0};
    for(int mask=1;mask<(1<<n);mask++){
        for(int bit=0;bit<n;bit++){
            int calc=(1<<bit)&mask;
            if(calc){
                int space=dp[mask^(1<<bit)].s;
                if(space+w[bit]<=limit){
                    dp[mask]=min(dp[mask],{dp[mask^(1<<bit)].f,space+w[bit]});
                }
                else
                    dp[mask]=min(dp[mask],{dp[mask^(1<<bit)].f+1,w[bit]});
            }
        }
    }
    cout<<dp[(1<<n)-1].f<<endl;
}