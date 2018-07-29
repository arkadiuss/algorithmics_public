#include<bits/stdc++.h>
#define VAR(i,n) __typeof(n) i = (n)
#define loop(i,j,s) for(int i=j;i<s;i++)
#define loopback(i,j,s) for(int i=j;i>=s;i--)
#define foreach(i,c) for(VAR(i,(c).begin());i!=(c).end();i++)
#define pln( x ) cout << x << "\n"
#define ps( x ) cout << x << " "
#define entr cout << "\n"
#define pcnt(i) __builtin_popcount(i)
#define ll long long
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define SIZE(c) (c).size()
#define ALL(c) (c).begin(), (c).end()
using namespace std;
typedef vector<int> VI;
const int INFTY=20000000;
const int MAX=500100;
const int MOD=10000000;

void coutTab(int* tab,int n){
	loop(i,0,n){
		cout<<tab[i]<<" ";
	}
	cout<<"\n";
}
//------------------------------------------
vector<vector<int> > G(MAX);
int nextToAdd=1;
int n,d,k;
bool visited[MAX];
void dfs(int i,int h1,int h2){
	visited[i]=1;
	//if(nextToAdd==n-1) return;
	while(h1<d&&h2<d&&SIZE(G[i])<k-1&&nextToAdd<n){
		G[i].pb(nextToAdd);
		nextToAdd++;
	}
	loop(j,0,SIZE(G[i])){
		if(!visited[G[i][j]]){
			if(G[i][j]<=d){
				dfs(G[i][j],h1+1,h2-1);
			}else{
				dfs(G[i][j],h1+1,h2+1);
			}
		}
	}
}
bool check(){
	if(nextToAdd!=n) return false;
	return true;
}
int main(){
	ios_base::sync_with_stdio(0);
	cin>>n>>d>>k;
	if(k==1&&n>2){
		pln("NO");
	}else if(n+1>=d){
		loop(i,0,n) visited[i]=0;
		loop(i,1,d+1){
			G[i-1].pb(i);
		}
		nextToAdd=d+1;
		dfs(0,0,d);
		if(check()){
			pln("YES");
			loop(i,0,n){
				loop(j,0,SIZE(G[i])){
					ps(i+1);pln(G[i][j]+1);
				}
			}
		}else{
			pln("NO");
		}
	}else{
		pln("NO");
	}
}
