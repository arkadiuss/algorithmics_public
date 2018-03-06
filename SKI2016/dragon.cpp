#include<bits/stdc++.h>
#define loop(i,j,s) for(int i=j;i<s;i++)
#define loopback(i,j,s) for(int i=j;i>=s;i--)
#define pln( x ) cout << x << "\n"
#define ps( x ) cout << x << " "
#define entr cout << "\n" 
#define pcnt(i) __builtin_popcount(i)
#define ll long long
using namespace std;
const int INFTY=20000000;
const int MAX=1100;
const int MOD=10000000;

void coutTab(int* tab,int n){
	loop(i,0,n){
		cout<<tab[i]<<" ";
	}
	cout<<"\n";
}
//------------------------------------------
int n,m;
bool G[MAX][MAX];
bool bfs(int a){
	queue<int> Q;
	bool visited[MAX];
	loop(i,0,n){
		visited[i]=0;
	}
	Q.push(a);
	visited[a]=1;
	while(!Q.empty()){
		int v = Q.front();
		Q.pop();
		loop(i,0,n){
			if(G[v][i]&&!visited[i]){
				Q.push(i);
				visited[i]=1;
			}
		}
	}
	loop(i,0,n){
		if(!visited[i])
			return false;
	}
	return true;
}
int main(){
	ios_base::sync_with_stdio(0);
	int T;
	cin>>T;
	while(T--){
		cin>>n>>m;
		loop(i,0,n){
			loop(j,0,n){
				G[i][j]=1;
			}
		}
		int a,b;
		loop(i,0,m){
			cin>>a>>b;
			G[a-1][b-1]=0;
			G[b-1][a-1]=0;
		}
		if(bfs(0)){
			cout<<"TAK";
		}else{
			cout<<"NIE";
		}
		entr;
	}
}
