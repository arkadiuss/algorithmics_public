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
const int MAX=1000100;
const int MOD=10000000;

void coutTab(int* tab,int n){
	loop(i,0,n){
		cout<<tab[i]<<" ";
	}
	cout<<"\n";
}
//------------------------------------------
vector< vector<int> > G(MAX);
int cpcty[MAX];
int lecs[MAX];
int father[MAX];
int n;
int serverOfFile[MAX];
int fileCapa[MAX];
int idfile=0;
int idserv;
void sortLecs(){
	stack<int> S;
	S.push(0);
	bool visited[MAX];
	loop(i,0,n){
		visited[i]=0;
	}
	int idlecs=1;
	visited[0]=1;
	father[0]=-1;
	while(!S.empty()){
		int v = S.top();
		S.pop();
		lecs[v]=idlecs;
		idlecs++;
		loopback(i,G[v].size()-1,0){
			if(!visited[G[v][i]]){
				visited[G[v][i]]=1;
				S.push(G[v][i]);
			}else{
				father[v]=G[v][i];
			}
		}
	}
}
bool visited[MAX];
void insertInto(int x, int y){
	stack<int> S;
	S.push(y);
	
	loop(i,0,idserv){
		visited[i]=0;
	}
	visited[0]=1;
	serverOfFile[idfile]=-2;
	while(!S.empty()){
		int v = S.top();
		S.pop();
		
		if(cpcty[v]>=x){
			serverOfFile[idfile]=v;
			cpcty[v]=cpcty[v]-x;
			break;
		}
		loopback(i,G[v].size()-1,0){
			if(!visited[G[v][i]]&&G[v][i]!=father[v]){
				visited[G[v][i]]=1;
				S.push(G[v][i]);
			}
		}
	}
}
int main(){
	ios_base::sync_with_stdio(0);
	int q;
	cin>>n>>q;
	loop(i,0,n){	
		cin>>cpcty[i];
	}
	int a,b;
	loop(i,0,n-1){
		cin>>a>>b;
		G[a-1].push_back(b-1);
		G[b-1].push_back(a-1);
	}
	loop(i,0,n){
		sort(G[i].begin(),G[i].end());
	}
	/*loop(i,0,n){
		cout<<i<<": ";
		loop(j,0,G[i].size()){
			ps(G[i][j]);
		}
		entr;
	}*/
	sortLecs();
	//coutTab(lecs,n);
	//coutTab(father,n);
	//
	int x,y;
	idserv=n;
	while(q--){
		cin>>a;
		if(a==1){
			cin>>x>>y;
			fileCapa[idfile]=x;
			insertInto(x,y-1);
			cout<<serverOfFile[idfile]+1<<"\n";
			idfile++;
		}else if(a==2){
			cin>>x>>y;
			G[idserv].push_back(y-1);
			G[y-1].push_back(idserv);
			cpcty[idserv]=x;
			idserv++;
		}else{
			cin>>x;
			x--;
			if(serverOfFile[x]!=-1) cpcty[serverOfFile[x]]+=fileCapa[x];
			serverOfFile[x]=-1;
		}
		//coutTab(cpcty,idserv);
	}
}
