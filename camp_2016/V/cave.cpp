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
int n;
int rub,saf,szek;
int a[MAX],b[MAX];
vector< vector<int> > G(MAX);
void dfs(int v,int l,int d){
	if(d!=0)
		szek=szek+a[d-1]*rub+b[d-1]*saf;
	loop(i,0,G[v].size()){
		if(G[v][i]!=l){
			rub++; 
			dfs(G[v][i],v,d+1);
			saf++;
		}
	}
}
int main(){
	ios_base::sync_with_stdio(0);
	cin>>n;
	loop(i,0,n){
		cin>>a[i];
	}
	loop(i,0,n){
		cin>>b[i];
	}
	int minszek,candidate;
	loop(i,1,n){
		minszek=INFTY;
		candidate=0;
		loop(j,0,i){
			G[i].push_back(j);
			G[j].push_back(i);
			rub=0;
			szek=0;
			saf=0;
			dfs(0,-1,0);
			if(szek<minszek){
				minszek=szek;
				candidate=j;
			}
			G[i].pop_back();
			G[j].pop_back();
		}
		G[candidate].push_back(i);
		G[i].push_back(candidate);
	}
	rub=0;
	szek=0;
	saf=0;
	dfs(0,-1,0);
	loop(i,0,n){
		ps(i+1);
		loop(j,0,G[i].size()){
			ps(G[i][j]+1);
		}
		entr;
	}
	cout<<szek;	
}
