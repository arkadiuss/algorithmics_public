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
const int MAX=500100;
const int MOD=10000000;

void coutTab(int* tab,int n){
	loop(i,0,n){
		cout<<tab[i]<<" ";
	}
	cout<<"\n";
}
//------------------------------------------
int n,m;
vector< vector<int> > G(MAX);
int gil[MAX];
bool checked[MAX];

bool check(){
	loopback(i,n-1,0){
		if(G[i].size()==0)
			return false;
	}
	return true;
}

int bfs(int v){
	queue<int> Q;
	Q.push(v);
	gil[v]=0;
	while(!Q.empty()){
		v=Q.front();
		loop(i,0,G[v].size()){
			if(!checked[G[v][i]]){
				gil[G[v][i]]=(gil[v]+1)%2;
				checked[G[v][i]]=1;
				Q.push(G[v][i]);	
			}	
		}
		Q.pop();
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin>>n>>m;
	int a,b;
	loop(i,0,m){
		cin>>a>>b;
		G[a-1].push_back(b-1);
		G[b-1].push_back(a-1);
	}
	if(check()){
		loop(i,0,n){
			gil[i]=-1;
			checked[i]=0;
		}
		loop(i,0,n){
			if(gil[i]==-1)
				bfs(i);
		}	
		pln("TAK");
		loop(i,0,n){
			if(gil[i]==0)
				pln("K");
			else
				pln("S");	
		}
	}else{
		pln("NIE");
	}
}
