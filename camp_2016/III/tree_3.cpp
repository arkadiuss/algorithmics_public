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
int father[MAX],con[MAX],level[MAX];
bool checked[MAX];
int maxlev=0;
void bfs(){
	loop(i,0,n){
		checked[i]=0;
	}
	queue<int> Q;
	father[0]=-1;
	loop(i,1,n){
		if(G[i].size()==1){
			Q.push(i);
			checked[i]=1;
		}
	}
	while(!Q.empty()){
		int v=Q.front();
		loop(i,0,G[v].size()){
			if(checked[G[v][i]]&&G[v][i]!=0)
				father[G[v][i]]=v;
			else{
				Q.push(G[v][i]);
				checked[G[v][i]]=1;
			}	
		}
		Q.pop();
	}
}
void bfs2(){
	loop(i,0,n){
		checked[i]=0;
	}
	checked[0]=1;
	queue<int> Q;
	Q.push(0);
	level[0]=0;
	while(!Q.empty()){
		int v=Q.front();
		loop(i,0,G[v].size()){
			if(!checked[G[v][i]]){
				if(con[G[v][i]]<3)			
					level[G[v][i]]=level[v]+1;
				else
					level[G[v][i]]=0;	
				maxlev=max(maxlev,level[G[v][i]]);
				Q.push(G[v][i]);
				checked[G[v][i]]=1;
			}
		}
		Q.pop();
	}
}
int main(){
	ios_base::sync_with_stdio(0);
	cin>>n;
	int a,b;
	loop(i,0,n-1){
		cin>>a>>b;
		G[a-1].push_back(b-1);
		G[b-1].push_back(a-1);
	}
	bfs();
	//bfs2();
	int l=0;
	loop(i,0,n){
		con[i]=G[i].size();
		if(con[i]==1&&i!=0)
			l++;
	}
	//coutTab(father,n);
	//coutTab(con,n);
	//coutTab(level,n);
	bool deleted[MAX];
	int candidate=-1,nextdlt;
	bool dlt;
	loop(i,0,n-1){
		candidate=-1;
		dlt=0;
		nextdlt=0;
		loop(j,1,n){
			if(!deleted[j]){
				if(con[j]==1&&(con[father[j]]>2||father[j]==0)){
					if(candidate==-1||(candidate!=-1&&dlt==0)){
						candidate=j;
						dlt=1;
						break;
					}	
				}else if(con[j]==1){
					if(candidate==-1){
						candidate=j;
						int v=father[j];
						nextdlt=0;
						while(v!=0&&con[v]==2){
							nextdlt++;
							v=father[v];
						}
					}else{	
						int v=father[j];
						int nextdlttmp=0;
						while(v!=0&&con[v]==2){
							nextdlttmp++;
							v=father[v];
						}
						if(nextdlttmp<nextdlt){
							nextdlt=nextdlttmp;
							candidate=j;	
						}
					}
					
				}
			}
		}
		if(dlt)
			l--;
		//cout<<candidate+1<<" ";
		cout<<l<<"\n";
		deleted[candidate]=1;
		con[father[candidate]]--;
				
	}
}
