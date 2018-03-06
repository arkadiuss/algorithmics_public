#include<vector>
#include<iostream>
#include<queue>
#include<math.h>
#define foreach(s) for(int i=0;i<s;i++)
#define loop(i,s) for(int i=0;i<s;i++)

using namespace std;
const int MAXSIZE=40010;
vector< vector<int> > G(MAXSIZE);
int n,logmax;
int p[20][MAXSIZE];
struct V{
	int level,nr_pre,undertree_size,father;
};
V vs[MAXSIZE];
/*poziom każdego wierzchołka*/
void dfs(){
	bool checked[MAXSIZE];
	int v;
	queue<int> Q;
	vs[0].level=0;
	checked[0]=1;	
	Q.push(0);
	while(!Q.empty()){
		v=Q.front();
		Q.pop();
		foreach(G[v].size()) if(!checked[G[v][i]]){
			vs[G[v][i]].level=vs[v].level+1;
			checked[G[v][i]]=1;
			Q.push(G[v][i]);
		}
	}
}
int number=0;
void preorder(int v,int last){
	vs[v].nr_pre=number;
	number++;
	foreach(G[v].size()){
		if(G[v][i]!=last)
			preorder(G[v][i],v);
	}	
}
int countSizeOfUnderTrees(int v,int last){
	int size_tree=0;	
	foreach(G[v].size()){
		if(G[v][i]!=last)
			size_tree=size_tree+countSizeOfUnderTrees(G[v][i],v);
	}
	vs[v].undertree_size=size_tree;
	vs[v].father=last;
	return size_tree+1;
}
bool descendant(int u,int v){
	if(vs[u].nr_pre<vs[v].nr_pre&&vs[v].nr_pre<=vs[u].nr_pre+vs[u].undertree_size)
		return true;
	return false;
}
int LCA(int u,int v){
	int i,j;	
	if(u==v)
		return u;	
	else if(descendant(u,v))
		return u;
	else if(descendant(v,u))
		return v;
	else{
		i=u;
		j=logmax;
		while(j>=0){
			//cout<<i<<j<<endl;
			if(descendant(p[j][i],v))
				j--;
			else
				i=p[j][i];
		}
		return p[0][i];
	}
}
int main(){	
	int m;	
	cin>>n;
	int a,b;
	logmax=log2(n)+1;
	foreach(n-1){
		cin>>a>>b;
		G[a-1].push_back(b-1);
		G[b-1].push_back(a-1);
	}
	dfs();
	preorder(0,0);
	countSizeOfUnderTrees(0,0);
	for(int i=0;i<logmax+2;i++){
		
		for(int j=0;j<n;j++){
			if(i==0){
				if(j==0)
					p[i][j]=0;				
				else				
					p[i][j]=vs[j].father;		
			}else{
				p[i][j]=p[i-1][p[i-1][j]];
			}
		}
		
	}
	int sum=0,lastm=0,actm;	
	cin>>m;
	foreach(m){
		cin>>actm;
		actm--;
		sum=sum+vs[actm].level+vs[lastm].level-2*vs[LCA(lastm,actm)].level;
		lastm=actm;
		//cout<<i<<endl;
	}
	cout<<sum;	
}
