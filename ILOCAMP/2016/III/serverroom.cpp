#include<bits/stdc++.h>
#define loop(i,j,s) for(int i=j;i<s;i++)
#define loopback(i,j,s) for(int i=j;i>=s;i--)
#define pln( x ) cout << x << "\n"
#define ps( x ) cout << x << " "
#define entr cout << "\n" 
#define pcnt(i) __builtin_popcount(i)
#define ll long long
#define ff first
#define ss second
using namespace std;
const int INFTY=20000000;
const int MAX=900100;
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
//questions
int que[MAX][4];
//--servers data---
int cpcty[MAX];

int idpre=0;
int no_pre[MAX];
int pre_cpcty[MAX];
int pre_no[MAX];

int tme=-1;
pair<int,int> inout[MAX];

int tree[2*MAX];
int d;
//-----files data----
int idfile=0;
int serverOfFile[MAX];
int fileCapa[MAX];

void preorder(int v, int l){
	tme++;
	inout[v].ff=tme;
	no_pre[v]=idpre;
	pre_cpcty[idpre]=cpcty[v];
	pre_no[idpre]=v;	
	idpre++;
	loop(i,0,G[v].size()){
		if(G[v][i]!=l) preorder(G[v][i],v);
	}
	inout[v].ss=tme;
}

void findD(){
	d=1;
	while(d<n){
		d=d*2;
	}
}

void createTree(){
	loop(i,0,n){
		tree[i+d]=pre_cpcty[i];
	}
	loopback(i,d-1,1){
		tree[i]=max(tree[2*i],tree[2*i+1]);
	}
}
void update(int v, int x){
	tree[v+d]=x;
	v=v+d;
	int i=v/2;
	while(i>0){
		tree[i]=max(tree[2*i],tree[2*i+1]);
		i=i/2;
	}
}
bool ifEdge(int i){
	int k=0;
	while(((1<<k)-1)<2*d){
		if(((1<<k)-1)==i) return true;
		k++;
	}
	return false;
}
int find(int x,int y){
	if(tree[y+d]>=x) return pre_no[y];
	int i=y+d;
	//ps("find");
	//ps(i);
	while(i>0&&tree[i]<x&&!ifEdge(i)){
		i=(i+1)/2;
		//ps(i);
	}
	//entr;
	if(tree[i]<x) return -2;
	while(i<2*d){
		//ps(i);
		if(tree[2*i]>=x)
			i=i*2;
		else
			i=i*2+1;	
	}
	i=i/2;
	//ps(i);
	//entr;
	if(i-d>=inout[pre_no[y]].ff&&i-d<=inout[pre_no[y]].ss)
		return pre_no[i-d];
	else
		return -2;	
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
	int x,y;
	loop(z,0,q){
		cin>>a;
		if(a==1){
			cin>>x>>y;
		}else if(a==2){
			cin>>x>>y;
			G[y-1].push_back(n);
			G[n].push_back(y-1);
			cpcty[n]=0;
			que[z][3]=n;
			n++;
		}else{
			cin>>x;
		}
		que[z][0]=a;
		que[z][1]=x;
		if(a<3) que[z][2]=y;
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
	loop(i,0,n){
		no_pre[i]=-1;
	}
	preorder(0,-1);
	//coutTab(no_pre,n);
	/*coutTab(pre_cpcty,n);
	loop(i,0,n){
		cout<<inout[i].ff<<"-"<<inout[i].ss<<" ";
	}
	entr;*/
	findD();
	//cout<<d;
	createTree();
	//coutTab(tree,2*d);
	loop(z,0,q){
		if(que[z][0]==1){
			
			int serv=find(que[z][1],no_pre[que[z][2]-1]);
			serverOfFile[idfile]=serv;
			fileCapa[idfile]=que[z][1];
			idfile++;
			if(serv>=0){
				update(no_pre[serv],tree[no_pre[serv]+d]-que[z][1]);
			}
			cout<<serv+1<<"\n";		
		}else if(que[z][0]==2){
			update(no_pre[que[z][3]],que[z][1]);
		}else{
			int fl=que[z][1]-1;
			if(serverOfFile[fl]>-1){
				update(no_pre[serverOfFile[fl]],tree[no_pre[serverOfFile[fl]]+d]+fileCapa[fl]);
				serverOfFile[fl]=-1;
			}
		}
	//	coutTab(tree,2*d);
	}
}
