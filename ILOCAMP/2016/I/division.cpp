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
vector< vector<int> > G(MAX);
int n;
bool dfs(int a, int b){
	bool used[MAX];
	loop(i,0,2*n+1){
		used[i]=0;
	}
	queue<int> Q;
	Q.push(a);
	used[a]=1;
	while(!Q.empty()){
		int v = Q.front();
		//cout<<v<<" ";
		loop(i,0,G[v].size()){
			if(!used[G[v][i]]){
				Q.push(G[v][i]);
				used[G[v][i]]=1;
			}
		}
		Q.pop();
	}
	//entr;
	if(used[b]) return 1;
	return 0;
}
int main(){
	ios_base::sync_with_stdio(0);
	int mp,mj,p,j;
	cin>>n>>p>>j;
	cin>>mp;
	int a,b;
	loop(i,0,mp){
		cin>>a>>b;
		G[a-1].push_back(b-1);
	}
	cin>>mj;
	loop(i,0,mj){
		cin>>a>>b;
		G[a+n-1].push_back(b+n-1);
	}
	int mins=INFTY;
	for(int mask = 1; mask<pow(2,n);mask++){
		loop(z,0,n){
			if(1<<z&mask){
				G[z].push_back(z+n);
				G[z+n].push_back(z);
			}
		}
		if(dfs(p-1,j-1+n)) mins=min(mins,pcnt(mask));
		loop(z,0,n){
			if(1<<z&mask){
				G[z].pop_back();
				G[z+n].pop_back();
			}
		}
	}		
	cout<<mins;	
	
}
