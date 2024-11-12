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
int n,m;
vector<vector<int>> g;
map<pi,pi> p;
vector<pi> monsters;
pi si,se;
vector<pair<int,int>> moves = {{-1,0},{1,0},{0,1},{0,-1}}; 

bool isValid(int x, int y, int timer)
{
  if(x<0 or y<0 or x>=n or y>=m){
    return false;
  }
  if(g[x][y] <= timer){
    return false;
  }
  return true;
}
bool ok(int x, int y, int timer)
{
  if(!isValid(x,y,timer)) return false;
  if(x == 0 or y == 0 or 
    x == n-1 or y == m-1) return true;
  return false;
}

void preprocess(){
	queue<pair<pi,int>> q;
	for(auto e:monsters){
		q.push({e,0});
	}
	while(!q.empty()){
		int x=q.front().first.first;
		int y=q.front().first.second;
		int time=q.front().second;
		time++;
		q.pop();
		for(auto e:moves){
			int x1=x+e.f;
			int y1=y+e.s;
			if(isValid(x1,y1,time)){
				g[x1][y1]=time;
				q.push({{x1,y1},time});
			}
		}
	}
}


bool bfs(pi s){
	queue<pair<pi,int>> q;
	q.push({s,0});
	while(!q.empty()){
		int x=q.front().first.first;
		int y=q.front().first.second;
		int time=q.front().second;
		time++;
		q.pop();
		//cout<<x<<" "<<y<<" "<<time<<endl;
		for(auto e:moves){
			int x1=x+e.f;
			int y1=y+e.s;
			if(ok(x1,y1,time)){
				se={x1,y1};
				p[se]={x,y};
				return 1;
			}
			else if(isValid(x1,y1,time)){
				q.push({{x1,y1},time});
				p[{x1,y1}]={x,y};
				g[x1][y1]=time;
			}
		}		
	}
	return 0;
}

int main() {
    fast;
    cin >> n >> m;
    g.resize(n);
    for(int i = 0; i < n; ++i){ 
    g[i].resize(m);
    }
    for(int i = 0; i < n; ++i){
        for (int j = 0; j < m; ++j){
            g[i][j] = mod;
        }
    }  
    vector<string> tab(n);
    for(int i=0;i<n;i++){
    	cin>>tab[i];
    }
    for(int i=0;i<n;i++){
    	for(int j=0;j<m;j++){
    		if(tab[i][j]=='A') si={i,j},g[i][j]=0;
    		else if(tab[i][j]=='M'){
    			monsters.pb({i,j});
    			g[i][j]=0;
    		}
    		else if(tab[i][j]=='#') g[i][j]=0;
    		else g[i][j]=mod;
    	}
    }
    if(si.f == 0 || si.f == n-1 || si.s == 0 || si.s == m-1) cout<<"YES"<<endl;
    else{
    	preprocess();
    	bool ok1=bfs(si);
    	if(!ok1) cout<<"NO"<<endl;
    	else{
    		vector<char> ans;
    		while(se!=si){
    			cout<<se.f<<" "<<se.s<<" "<<p[se].f<<" "<<p[se].s<<endl;
    			if(se.s==p[se].s+1) ans.pb('R');
    			else if(se.s==p[se].s-1) ans.pb('L');
    			else if(se.f==p[se].f+1) ans.pb('D');
    			else ans.pb('U');
    			se=p[se];
    		}
    		reverse(all(ans));
    		cout<<"YES"<<endl;
    		for(auto e:ans){
    			cout<<e;
    		}
    		cout<<endl;
    	}    	
    }
}
