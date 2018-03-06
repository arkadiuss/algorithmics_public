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
int father[MAX],con[MAX];
void bfs(){
	bool checked[MAX];
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
int main(){
	ios_base::sync_with_stdio(0);
	cin>>n;
	int a,b;
	loop(i,0,n-1){
		cin>>a>>b;
		G[a-1].push_back(b-1);
		G[b-1].push_back(a-1);
	}
	//coutTab(father,n);
	bfs();
	loop(i,0,n){
		con[i]=G[i].size();
	}
	//coutTab(father,n);
	//coutTab(con,n);
	int vi=0; //ile v takich ze
	int vf=0;
	bool was[MAX];
	int l=0;
	loop(i,1,n){
		if(con[i]==1){
			l++;
			if(con[father[i]]>2){
				vi++;
				if(!was[father[i]]){
					was[father[i]]=1;
					vf++;
				}
			}
		}		
		
	}
	vi=vi-vf;
	cout<<vi<<" "<<l<<"\n";
	bool deleted[MAX];
	loop(i,0,n-1){
		//cout<<vi<<" ";
		loop(j,1,n){
			
			if(!deleted[j]&&con[j]==1){
				if(vi>0&&(con[father[j]]>2||(father[j]==0&&con[father[j]]>1))){
					deleted[j]=1;
					l--;
					con[father[j]]--;
					vi--;
					cout<<j+1<<" ";
					break;
				}else{
					if(con[j]==1&&vi==0){
						cout<<j+1<<" ";
						con[father[j]]--;
						if(father[j]!=0&&con[father[father[j]]]>2&&con[father[j]]==1)
							vi++;
						deleted[j]=1;
						if(father[j]==0)
							l--;
						break;	
					}
					
				}
				
			}
		}
		if(i==n-2)
			cout<<0<<"\n";
		else
			cout<<l<<"\n";
	}
}
