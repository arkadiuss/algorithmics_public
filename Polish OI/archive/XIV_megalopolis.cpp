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
const int MAX=250100;
const int MOD=10000000;

void coutTab(int* tab,int n){
	loop(i,1,n+1){
		cout<<tab[i]<<" ";
	}
	cout<<"\n";
}
//------------------------------------------
vector< vector<int> > G(MAX);
int n,m,nr_postorder=1;
int postToNr[MAX],nrToPost[MAX],minPost[MAX];
int len[MAX],tree[3*MAX],d;
int postorder(int v,int l){
	if(G[v].size()==1&&v!=1){
		postToNr[nr_postorder]=v;
		nrToPost[v]=nr_postorder;
		minPost[nr_postorder]=nr_postorder;
		nr_postorder++;
		return nr_postorder-1;
	}else{
		int minP=INFTY;
		loop(i,0,G[v].size())
			if(G[v][i]!=l) minP=min(minP,postorder(G[v][i],v));
	
		postToNr[nr_postorder]=v;
		nrToPost[v]=nr_postorder;
		minPost[nr_postorder]=minP;	
		nr_postorder++;
		return minPost[nrToPost[v]];
	}	
}
void dfs(){
	bool checked[MAX];
	checked[1]=1;
	loop(i,0,n+2){
		checked[i]=0;
	}
	queue<int> S;
	len[nrToPost[1]]=0;
	S.push(1);
	while(!S.empty()){
		int v=S.front();S.pop();
		loop(i,0,G[v].size()){
		//cout<<v<<" "<<G[v].size()<<"\n";
			if(!checked[G[v][i]]){
				
				len[nrToPost[G[v][i]]]=len[nrToPost[v]]+1;
				checked[G[v][i]]=1;
				S.push(G[v][i]);
			}
		}
		
	}
}
void dfs2(int v,int lst,int ln){
	len[nrToPost[v]]=ln;
	loop(i,0,G[v].size())
		if(G[v][i]!=lst) dfs2(G[v][i],v,ln+1);
}
int findTreeSize(int n){
	int a =1;
	while(a<n){
		a=a*2;
	}
	return a;
}
void buildTree(){
	int size=findTreeSize(n);
	d=size;
	loop(i,0,n){
		tree[i+size]=len[i+1];
	}
}
int add(int L,int R,int v){
	L=L+d-1;
	R=R+d-1;
	while(L<=R){
		if(L%2==1) tree[L]=tree[L]+v;
		if(R%2==0) tree[R]=tree[R]+v;
		L=(L+1)/2;
		R=(R-1)/2;
	}
}
int read(int v){
	v=v+d;
	int val=0;
	while(v>0){
		val=val+tree[v];
		v=v/2;
	}
	return val;
}
int main(){
	ios_base::sync_with_stdio(0);
	cin>>n;
	int a,b;
	loop(i,0,n-1){
		cin>>a>>b;
		G[a].push_back(b);
		G[b].push_back(a);
	}
	postorder(1,-1);
	//coutTab(postToNr,n);
	//coutTab(nrToPost,n);
	//coutTab(minPost,n);
	dfs2(1,-1,0);
	//coutTab(len,n);
	buildTree();
	//coutTab(tree,2*d);
	char tmp;
	cin>>m;
	loop(i,0,n+m-1){
		cin>>tmp;
		if(tmp=='A'){
			cin>>a>>b;
			//cout<<minPost[nrToPost[b]]<<" "<<nrToPost[b]<<"\n";
			add(minPost[nrToPost[b]],nrToPost[b],-1);
			//coutTab(tree,2*d);
		}else{
			cin>>a;
			cout<<read(nrToPost[a]-1)<<"\n";
		}
	}
}
