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
struct V{
	int v; 
	int p,n;
};
vector<vector<V> > components;
vector<vector<V> > componentsPath;
vector<vector<V> > componentsCycle;
pair<int,int> startendComp[MAX];
pair<int,int> startendCompCycle[MAX];
V path[MAX];
V cycle[MAX];
V mv(int v, int p, int n){
	V vs;
	vs.v=v;
	vs.p=p;
	vs.n=n;
	return vs;
}
int startVcomponentsPath,endVcomponentsPath;
V pathOfComp[MAX];
int pathsize[MAX];
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
	cout<<"paths: "<<componentsPath.size()<<"\n";
	loop(i,0,componentsPath.size()){
		cout<<"path "<<i<<": ";
		//ps(componentsPath[i].size());
		int v=startendComp[i].ff;
		loop(j,0,componentsPath[i].size()){//componentsPath[i].size()){
			cout<<componentsPath[i][v].v+1<<" ";
			v=componentsPath[i][v].n;
		}
		entr;
	}
}
void coutCycle(){
	cout<<"cycles: "<<componentsCycle.size()<<"\n";
	loop(i,0,componentsCycle.size()){
		cout<<"cycle "<<i<<": ";		
		int v=startendCompCycle[i].ff;
		loop(j,0,componentsCycle[i].size()+1){
			cout<<componentsCycle[i][v].v+1<<" ";
			v=componentsCycle[i][v].n;
		}
		entr;
	}
}
void coutComponents(){
	cout<<"components "<<"\n";
	loop(i,0,componentssize){
		cout<<i<<": ";
		loop(j,0,components[i].size()){
			ps(components[i][j].v+1);
		}
		entr;
	}
}
void coutToCheck(){
	cout<<componentsCycle.size()<<"\n";
	loop(i,0,componentsCycle.size()){
		cout<<componentsCycle[i].size()<<"\n";
		int v=startendCompCycle[i].ff;
		loop(j,0,componentsCycle[i].size()){
			cout<<componentsCycle[i][v].v+1<<" ";
			v=componentsCycle[i][v].n;
		}
		entr;
	}
}
void coutPathOfComponents(){
	cout<<"pathOfComponents: ";
	int v = startVcomponentsPath;
	loop(i,0,components.size()){
		ps(v);
		v=pathOfComp[v].n;
	}
	entr;
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
	components[id].pb(mv(v,-1,-1));
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
	vector<V> emp;
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
//creating paths
//------------------------------------------
int find(int j,int size,int idcomp){
	int v=startendComp[idcomp].ff;
	loop(i,0,size){
		//cout<<v<<" ";
		if(G[componentsPath[idcomp][v].v][componentsPath[idcomp][j].v]&&G[componentsPath[idcomp][j].v][componentsPath[idcomp][componentsPath[idcomp][v].n].v])
			return v;
		v=componentsPath[idcomp][v].n;
	}
}

void createPath(int idcomp){
	loop(i,0,componentsPath[idcomp].size()){
		componentsPath[idcomp][i].p=-1;
		componentsPath[idcomp][i].n=-1;
	}
	startendComp[idcomp].ff=0;
	startendComp[idcomp].ss=0;
	int size=1,v;
	loop(i,1,componentsPath[idcomp].size()){
		if(G[componentsPath[idcomp][i].v][componentsPath[idcomp][startendComp[idcomp].ff].v]){
			componentsPath[idcomp][startendComp[idcomp].ff].p=i;
			componentsPath[idcomp][i].n=startendComp[idcomp].ff;
			startendComp[idcomp].ff=i;
			
		}else if(G[componentsPath[idcomp][startendComp[idcomp].ss].v][componentsPath[idcomp][i].v]){
			componentsPath[idcomp][startendComp[idcomp].ss].n=i;
			componentsPath[idcomp][i].p=startendComp[idcomp].ss;
			startendComp[idcomp].ss=i;
		}else{
			v=find(i,size,idcomp);
			//cout<<v<<"\n";
			//cout<<componentsPath[idcomp][v].n<<"\n";
			componentsPath[idcomp][componentsPath[idcomp][v].n].p=i;
			componentsPath[idcomp][i].n=componentsPath[idcomp][v].n;
			componentsPath[idcomp][v].n=i;
			componentsPath[idcomp][i].p=v;
		}
		size++;
	}
}
//--------------------------------------
//creating cycles
//--------------------------------------
pair<int,int> checkDomination(int j,int idcomp){
	int v = startendCompCycle[idcomp].ff;
	loop(i,0,cyclesize){
		//cout<<v<<"->";
		if(G[componentsCycle[idcomp][j].v][componentsCycle[idcomp][v].v]) return mp(1,v);
		v=componentsCycle[idcomp][v].n;
	}
	return mp(0,0);
}
bool createCycle(int idcomp){
	if(componentsCycle[idcomp].size()==1){
		startendCompCycle[idcomp].ss=0;
		startendCompCycle[idcomp].ff=0;
		componentsCycle[idcomp][0].n=0;
		componentsCycle[idcomp][0].p=0;
		return 1;
	}
	loop(i,0,componentsCycle[idcomp].size()){
		componentsCycle[idcomp][i].n=-1;
		componentsCycle[idcomp][i].p=-1;
	}
	int k=startendComp[idcomp].ss;//endVpath;
	loopback(i,n-1,2){
	//	cout<<componentsPath[idcomp][k].v<<" "<<startendComp[idcomp].ff<<"\n";
		if(G[componentsPath[idcomp][k].v][componentsPath[idcomp][startendComp[idcomp].ff].v]) break;
		k=componentsPath[idcomp][k].p;
	}
	//if(!G[componentsPath[idcomp][k].v][startendComp[idcomp].ff]) return 0;
	int v=startendComp[idcomp].ff;//startVpath;
	startendCompCycle[idcomp].ff=startendComp[idcomp].ff;
	startendCompCycle[idcomp].ss=k;
	cyclesize=0;
	do{
		cyclesize++;
		componentsCycle[idcomp][v]=componentsPath[idcomp][v];
		v=componentsPath[idcomp][v].n;
	}while(v!=componentsCycle[idcomp][k].n);
	componentsCycle[idcomp][k].n=startendCompCycle[idcomp].ff;
	componentsCycle[idcomp][startendCompCycle[idcomp].ff].p=k;
	//cout<<startendCompCycle[idcomp].ff<<"dsjkfhjd\n";
	if(cyclesize==n) return 1;
	//coutCycle();
	int j=componentsPath[idcomp][k].n;
	while(j!=-1&&cyclesize<n){
		pair<int,int> dom=checkDomination(j,idcomp);
		//cout<<"dom: "<<componentsCycle[idcomp][j].v<<" "<<dom.ff<<"\n";
		if(dom.ff==1){
			int i=dom.ss;
			//cout<<"dominated "<<i<<" "<<componentsCycle[idcomp][i].p<<"\n";
			componentsCycle[idcomp][componentsCycle[idcomp][i].p].n=j;
			componentsCycle[idcomp][j].p=componentsCycle[idcomp][i].p;
			componentsCycle[idcomp][j].n=i;
			componentsCycle[idcomp][i].p=j;
			cyclesize++;
			j=componentsPath[idcomp][j].n;
		}else{
			int p=componentsPath[idcomp][j].n;
			bool was=0;
			int r;
			pair<int,int> tmp;
			tmp.ff=0;
			while(tmp.ff!=1&&p!=-1){
				//cout<<p<<" ";
				tmp = checkDomination(p,idcomp);
				if(tmp.ff){
					was=1;
					r=tmp.ss;
					//cout<<"dominate "<<p<<" "<<r<<"\n";
					componentsCycle[idcomp][componentsCycle[idcomp][r].p].n=j;
					componentsCycle[idcomp][j].p=componentsCycle[idcomp][r].p;
					//cout<<j<<" "<<cycle[j].p<<"\n";
					componentsCycle[idcomp][j].n=componentsPath[idcomp][j].n;
					cyclesize++;
					v=componentsPath[idcomp][j].n;
					//cout<<v<<"\n";
					while(v!=p&&v!=-1){
						cyclesize++;
						componentsCycle[idcomp][v]=componentsPath[idcomp][v];
						//cout<<"copying "<<v<<" "<<cycle[v].p<<" "<<cycle[v].n<<"\n";
						v=componentsPath[idcomp][v].n;
					}
					cyclesize++;
					componentsCycle[idcomp][p].p=componentsPath[idcomp][p].p;
					componentsCycle[idcomp][p].n=r;
					componentsCycle[idcomp][r].p=p;
					//cout<<r<<" "<<cycle[r].p<<"\n";
				}
				p=componentsPath[idcomp][p].n;
			}
			j=p;
			if(!was) return 0;
		}
		//coutCycle();
	}
}
//---------------------------------------------
//path of strongly connected components
//---------------------------------------------
bool connection(int comp1,int comp2){
	return G[components[comp1][0].v][components[comp2][0].v];
}

int findComp(int j,int size){
	int v=startVcomponentsPath;
	loop(i,0,size){
		if(connection(v,j)&&connection(j,pathOfComp[v].n))
			return v;
		v=pathOfComp[v].n;	
	}
}

void createPathOfComponents(){
	loop(i,0,n){
		pathOfComp[i].n=-1;
		pathOfComp[i].p=-1;
	}
	startVcomponentsPath=0;
	endVcomponentsPath=0;
	int size=1,v;
	loop(i,1,components.size()){
		if(connection(i,startVcomponentsPath)){
			pathOfComp[startVcomponentsPath].p=i;
			pathOfComp[i].n=startVcomponentsPath;
			startVcomponentsPath=i;
		}else if(connection(endVcomponentsPath,i)){
			pathOfComp[endVcomponentsPath].n=i;
			pathOfComp[i].p=endVcomponentsPath;
			endVcomponentsPath=i;
		}else{
			v=findComp(i,size);
			pathOfComp[pathOfComp[v].n].p=i;
			pathOfComp[i].n=pathOfComp[v].n;
			pathOfComp[v].n=i;
			pathOfComp[i].p=v;
		}
		size++;
	}
}
void countSizeOfPath(){
	loop(i,0,n){
		pathsize[i]=0;
	}
	int v=endVcomponentsPath;
	while(v!=-1){	
		
		if(pathOfComp[v].n!=-1)
			pathsize[v]=componentsCycle[v].size()+pathsize[pathOfComp[v].n];
		else
			pathsize[v]=componentsCycle[v].size();
		v=pathOfComp[v].p;
		//cout<<v<<" "<<pathsize[v]<<"\n";
	}
	//entr;
}
//---------------------------------------------
//result
//---------------------------------------------
void printResult(int i){
	int comp=componentid[i];
	cout<<pathsize[comp]<<" ";
	int v=startendCompCycle[comp].ff;
	while(componentsCycle[comp][v].v!=i)
		v=componentsCycle[comp][v].n;
	loop(i,0,componentsCycle[comp].size()){
		cout<<componentsCycle[comp][v].v+1<<" ";
		v=componentsCycle[comp][v].n;
	}
	comp=pathOfComp[comp].n;
	while(comp!=-1){
		int v=startendCompCycle[comp].ff;
		loop(i,0,componentsCycle[comp].size()){
			cout<<componentsCycle[comp][v].v+1<<" ";
			v=componentsCycle[comp][v].n;
		}
		comp=pathOfComp[comp].n;
	}
	entr;
}
//---------------------------------------------
int main(){
	ios_base::sync_with_stdio(0);
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
	//coutComponents();
	//coutG();
	componentsPath=components;
	componentsCycle=components;
	loop(i,0,n){
		startendComp[i].ff=-1;
		startendComp[i].ss=-1;
		startendCompCycle[i].ff=-1;
		startendCompCycle[i].ss=-1;
	}
	loop(i,0,componentsPath.size()){
		createPath(i);
		//entr;
	}
	//coutPath();
	loop(i,0,componentsCycle.size()){
		createCycle(i);
		//entr;
	}
	//coutCycle();
	//coutToCheck();
	createPathOfComponents();
	countSizeOfPath();
	//coutPathOfComponents();
	/*loop(i,0,n){
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
	loop(i,0,n){
		printResult(i);
	}
}
