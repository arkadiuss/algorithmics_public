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
const int MAX=1005100;
const int MOD=10000000;

void coutTab(int* tab,int n){
	loop(i,0,n+1){
		cout<<tab[i]<<" ";
	}
	cout<<"\n";
}
void coutVec(vector< vector<int> > G,int n){
	loop(i,0,n+1){
		cout<<i<<": ";
		loop(j,0,G[i].size()){
			cout<<G[i][j]<<" ";
		}
		cout<<"\n";
	}
}
//------------------------------------------
int n,nums[MAX],M,pos[MAX];
bool prime[MAX],inS[MAX];
int d[MAX],m[MAX],dsv[MAX],msv[MAX];
vector< vector<int> > G(MAX);
struct dbl{
	int fp,sp;
};
dbl dbls[MAX];
void createG(){
	loop(i,2,M+1){
		prime[i]=1;
	}
	loop(i,2,M+1){
		if(prime[i]){
			int j=i+i;
			G[i].push_back(1);
			G[1].push_back(i);
			while(j<=M){
				prime[j]=0;
				G[j].push_back(j/i);
				G[j/i].push_back(j);
				j=j+i;
			}
		}
	}
}

void bfs(){
	queue<int> Q;
	bool checked[MAX];
	loop(i,0,n){
		if(dbls[nums[i]].fp==i+1){
			d[nums[i]]=0;
			m[nums[i]]=i;
			Q.push(nums[i]);
			checked[nums[i]]=1;
		}
	}
	while(!Q.empty()){
		int v=Q.front();
		loop(i,0,G[v].size()){
			if(!checked[G[v][i]]){
				checked[G[v][i]]=1;
				d[G[v][i]]=d[v]+1;
				m[G[v][i]]=m[v];
				Q.push(G[v][i]);
			}else if(d[G[v][i]]==d[v]+1&&m[v]<m[G[v][i]])
				m[G[v][i]]=m[v];	
		}
		Q.pop();
	}
}

void solve(){
	int v,w,len;
	loop(i,0,M+1){
		dsv[i]=INFTY;
	}
	loop(i,0,M+1){
		loop(j,0,G[i].size()){
			v=m[i];
			w=m[G[i][j]];
			if(v!=w){
				len=d[i]+d[G[i][j]]+1;	
				if(len<dsv[v]||(len==dsv[v]&&w<msv[v])){
					dsv[v]=len;
					msv[v]=w;
				}
			}
		}
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	loop(i,0,MAX){
		pos[i]=-1;
		dbls[i].fp=-1;
		dbls[i].sp=-1;
	}
	cin>>n;
	loop(i,0,n){
		cin>>nums[i];
		M=max(M,nums[i]);
		inS[nums[i]]=1;
		if(pos[nums[i]]==-1){ 
			pos[nums[i]]=i+1;
			dbls[nums[i]].fp=i+1;
		}else if(dbls[nums[i]].sp==-1){
			dbls[nums[i]].sp=i+1;
		}	
	}
	//coutTab(pos,M);
	createG();
	//coutVec(G,M);
	bfs();
	//coutTab(d,M);
	//coutTab(m,M);
	solve();
	//coutTab(dsv,M);
	//coutTab(msv,M);
	loop(i,0,n){
		if(dbls[nums[i]].sp==-1)
			cout<<msv[i]+1<<"\n";
		else{
			if(i+1==dbls[nums[i]].fp)
				cout<<dbls[nums[i]].sp<<"\n";
			else
				cout<<dbls[nums[i]].fp<<"\n";	
		}	
	}
}
