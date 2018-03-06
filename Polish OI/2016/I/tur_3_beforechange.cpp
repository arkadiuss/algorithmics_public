#include<bits/stdc++.h>
#define loop(i,j,s) for(int i=j;i<s;i++)
#define loopback(i,j,s) for(int i=j;i>=s;i--)
#define pln( x ) cout << x << "\n"
#define ps( x ) cout << x << " "
#define entr cout << "\n" 
#define pcnt(i) __builtin_popcount(i)
#define ll long long
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
using namespace std;
const int INFTY=20000000;
const int MAX=2100;
const int MOD=10000000;

void coutTab(int* tab,int n){
	loop(i,0,n){
		cout<<tab[i]<<" ";
	}
	cout<<"\n";
}
//------------------------------------------
//initialization
//------------------------------------------
bool G[MAX][MAX];
bool transG[MAX][MAX];
int n;
int startVpath,endVpath;
int startVcycle, endVcycle;
int cyclesize;
int componentid[MAX],componentssize;
vector<vector<int> > components;
vector<vector<int> > componentsPath;
vector<vector<int> > componentsCycle;
struct V{
	int v; 
	int p,n;
};
V path[MAX];
V cycle[MAX];
V mv(int v, int p, int n){
	V vs;
	vs.v=v;
	vs.p=p;
	vs.n=n;
	return vs;
}
//------------------------------------------
//cout's
//------------------------------------------
void coutG(){
	loop(i,0,n){
		cout<<i<<": ";
		loop(j,0,n){
			cout<<G[i][j]<<" ";
		}
		entr;
	}
}
bool coutPath(){
	cout<<"path: "<<" ";
	int v=startVpath;
	loop(i,0,n){
		cout<<v+1<<" ";
		v=path[v].n;
	}
	entr;
}
void coutCycle(){
	cout<<"cycle size: "<<cyclesize<<"; cycle: ";
	int v=startVcycle;
	loop(i,0,cyclesize+1){
		cout<<v+1<<" ";
		v=cycle[v].n;
	}
	entr;
}
void coutComponents(){
	loop(i,0,componentssize){
		cout<<i<<": ";
		loop(j,0,components[i].size()){
			ps(components[i][j]);
		}
		entr;
	}
}
//------------------------------------------
//divide to strongly connected components
//------------------------------------------
bool checked[MAX];
stack<int> vs;
void dfs(int v){
	checked[v]=1;
	loop(i,0,n){
		if(!checked[i]&&G[v][i])
			dfs(i);
	}
	vs.push(v);
}
void stackdfs(int v, int id){
	//cout<<v<<" "<<id<<"\n";
	componentid[v]=id;
	components[id].pb(v);
	checked[v]=1;
	loop(i,0,n){
		//cout<<i<<" ";
		if(!checked[i]&&transG[v][i]&&i!=v){
			stackdfs(i,id);
		}
	}
	//entr;	
}
void divide(){
	vector<int> emp;
	loop(i,0,n){
		checked[i]=0;
	}
	loop(i,0,n){
		if(!checked[i])
			dfs(i);
	}
	loop(i,0,n){
		loop(j,0,n){
			transG[i][j]=!G[i][j];
		}
	}
	loop(i,0,n){
		checked[i]=0;
		componentid[i]=-1;
	}
	int id=0;
	while(!vs.empty()){
		//cout<<":"<<vs.top()<<"\n";
		if(componentid[vs.top()]==-1){
			components.pb(emp);
			stackdfs(vs.top(),id);
			id++;
		}
		vs.pop();
	}
	componentssize=id;
}

//------------------------------------------
//creating path
//------------------------------------------
int find(int j,int size){
	int v=startVpath;
	loop(i,0,size){
		if(G[v][j]&&G[j][path[v].n])
			return v;
		v=path[v].n;
	}
}

void createPath(){
	loop(i,0,n){
		path[i].p=-1;
		path[i].n=-1;
	}
	startVpath=0;
	endVpath=0;
	int size=1,v;
	loop(i,1,n){
		if(G[i][startVpath]){
			path[startVpath].p=i;
			path[i].n=startVpath;
			startVpath=i;
		}else if(G[endVpath][i]){
			path[endVpath].n=i;
			path[i].p=endVpath;
			endVpath=i;
		}else{
			v=find(i,size);
			//cout<<v<<"\n";
			path[path[v].n].p=i;
			path[i].n=path[v].n;
			path[v].n=i;
			path[i].p=v;
			
		}
		size++;
	}
}
//--------------------------------------
//creating cycle
//--------------------------------------
pair<int,int> checkDomination(int j){
	int v = startVcycle;
	loop(i,0,cyclesize){
		if(G[j][v]) return mp(1,v);
		v=cycle[v].n;
	}
	return mp(0,0);
}
bool createCycle(){
	loop(i,0,n){
		cycle[i].n=-1;
		cycle[i].p=-1;
	}
	int k=endVpath;
	loopback(i,n-1,2){
		if(G[k][startVpath]) break;
		k=path[k].p;
	}
	if(!G[k][startVpath]) return 0;
	int v=startVpath;
	startVcycle=startVpath;
	endVcycle=k;
	cyclesize=0;
	do{
		cyclesize++;
		cycle[v]=path[v];
		v=path[v].n;
	}while(v!=path[k].n);
	cycle[k].n=startVcycle;
	if(cyclesize==n) return 1;
	//coutCycle();
	int j=path[k].n;
	while(j!=-1&&cyclesize<n){
		pair<int,int> dom=checkDomination(j);
		//cout<<"dom: "<<j<<" "<<dom.ff<<"\n";
		if(dom.ff==1){
			int i=dom.ss;
			//cout<<"dominated "<<i<<" "<<cycle[i].p<<"\n";
			cycle[cycle[i].p].n=j;
			cycle[j].p=cycle[i].p;
			cycle[j].n=i;
			cycle[i].p=j;
			cyclesize++;
			j=path[j].n;
		}else{
			int p=path[j].n;
			bool was=0;
			int r;
			pair<int,int> tmp;
			tmp.ff=0;
			while(tmp.ff!=1&&p!=-1){
				//cout<<p<<" ";
				tmp = checkDomination(p);
				if(tmp.ff){
					was=1;
					r=tmp.ss;
					//cout<<"dominate "<<p<<" "<<r<<"\n";
					cycle[cycle[r].p].n=j;
					cycle[j].p=cycle[r].p;
					//cout<<j<<" "<<cycle[j].p<<"\n";
					cycle[j].n=path[j].n;
					cyclesize++;
					v=path[j].n;
					//cout<<v<<"\n";
					while(v!=p&&v!=-1){
						cyclesize++;
						cycle[v]=path[v];
						//cout<<"copying "<<v<<" "<<cycle[v].p<<" "<<cycle[v].n<<"\n";
						v=path[v].n;
					}
					cyclesize++;
					cycle[p].p=path[p].p;
					cycle[p].n=r;
					cycle[r].p=p;
					//cout<<r<<" "<<cycle[r].p<<"\n";
				}
				p=path[p].n;
			}
			j=p;
			if(!was) return 0;
		}
		//coutCycle();
	}
}

int main(){
	//ios_base::sync_with_stdio(0);
	cin>>n;
	int a;
	loop(i,0,n){
		loop(j,0,n){
			G[i][j]=0;
		}
	}
	loop(i,0,n){
		loop(j,0,i){
			cin>>a;
			if(a==1){
				G[j][i]=1;
			}else
				G[i][j]=1;
		}
	}
	divide();
	coutComponents();
	/*//coutG();
	createPath();
	//coutPath();
	createCycle();
	//coutCycle();
	loop(i,0,n){
		if(cyclesize==0||cycle[i].n==-1)
			cout<<"0"<<"\n";
		else{	
			cout<<cyclesize<<" "<<i+1<<" ";
			int v=cycle[i].n;
			while(v!=i&&v!=-1){
				cout<<v+1<<" ";
				v=cycle[v].n;
			}
			cout<<"\n";
		}
	}*/
}
