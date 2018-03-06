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
const int MAX=5100;
const int MOD=10000000;

void coutTab(int* tab,int n){
	loop(i,0,n){
		cout<<tab[i]<<" ";
	}
	cout<<"\n";
}
//------------------------------------------

int n;
int len[MAX];
vector< vector<int> > G(MAX);
struct compare{
	bool operator()(const int & a,const int & b){
		return len[a]>len[b];
	}
};
void coutG(){
	loop(i,0,n){
		cout<<i+1<<": ";
		loop(j,0,G[i].size()){
			cout<<G[i][j]+1<<" ";
		}
		cout<<"\n";
	}
}
bool checked[MAX];
int dijkstra(int v){
	
	loop(i,0,n){
		checked[i]=0;
		len[i]=-1;
	}
	len[v]=0;
	
	priority_queue<int,vector<int>,compare> Q;
	Q.push(v);
	checked[v]=1;
	while(!Q.empty()){
		v=Q.top();
		Q.pop();
		//cout<<v<<"\n";
		loop(i,0,G[v].size()){
			if((!checked[G[v][i]])&&len[G[v][i]]<len[v]+1){
				len[G[v][i]]=len[v]+1;
				checked[G[v][i]]=1;
				Q.push(G[v][i]);
			}
		}
	}
	loop(i,0,n){
		cout<<len[i]<<" ";
	}
	entr;
}
int main(){
	ios_base::sync_with_stdio(0);
	cin>>n;
	string a;
	loop(i,0,n){
		cin>>a;
		loop(j,0,n){
			if(a[j]=='1'){
				G[i].push_back(j);
			}
		}
	}
	coutG();
	int maxi=0;
	loop(i,0,n){
		maxi=max(maxi,dijkstra(i));
	}
}
