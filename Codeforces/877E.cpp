#include<bits/stdc++.h>
#define VAR(i,n) __typeof(n) i = (n)
#define loop(i,j,s) for(int i=j;i<s;i++)
#define loopback(i,j,s) for(int i=j;i>=s;i--)
#define foreach(i,c) for(VAR(i,(c).begin());i!=(c).end();i++)
#define pln( x ) cout << x << "\n"
#define ps( x ) cout << x << " "
#define entr cout << "\n"
#define pcnt(i) __builtin_popcount(i)
#define ll long long
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define SIZE(c) (c).size()
#define ALL(c) (c).begin(), (c).end()
using namespace std;
typedef vector<int> VI;
const int INFTY=20000000;
const int MAX=200100;
const int MOD=10000000;

void coutTab(int* tab,int n){
	loop(i,0,n){
		cout<<tab[i]<<" ";
	}
	cout<<"\n";
}
//------------------------------------------
struct Vertex{
	int i,pre_i,post_i;
	vector<int> neighbours;
};
struct TNode{
	int val,mod,size;
};
int order(vector<Vertex> & G, int v, int last, int num){
	G[v].pre_i = num;
	loop(i,0,G[v].neighbours.size()){
		if(G[v].neighbours[i]!=last){
			num = order(G,G[v].neighbours[i],v,num+1);
		}
	}
	G[v].post_i = num;
	return num;
}
int countD(int n){
	int i=1;
	while(i<n){
		i*=2;
	}
	return i;
}
void init(TNode * tree, int * A,vector<Vertex> & G, int D,int n){
	loop(i,D,2*D){
		if(i-D<n){
			tree[G[i-D].pre_i+D].val = A[i-D];
			tree[i].size = 1;
		}else
			tree[i].val=0;
		tree[i].mod=1;		
	}
	loopback(i,D-1,1){
		tree[i].mod=1;
		tree[i].size=tree[2*i].size+tree[2*i+1].size;
		tree[i].val=tree[2*i].val+tree[2*i+1].val;
	}
}
void update(TNode * tree,int l, int r, int a, int b,int D){
	int rp = (b+D)/(b-a+1); //range point
	if(l>b||r<a) return;
	else if(l<=a&&b<=r){
		tree[rp].mod *= -1;
		tree[rp].val = tree[rp].size-tree[rp].val;
	}else{
		if(tree[rp].mod==-1){
			tree[2*rp].mod *= -1;
			tree[2*rp].val = tree[2*rp].size-tree[2*rp].val;
			tree[2*rp+1].mod *= -1;
			tree[2*rp+1].val = tree[2*rp+1].size-tree[2*rp+1].val;
			tree[rp].mod=1;
		}
		update(tree,l,r,a,(a+b)/2,D);
		update(tree,l,r,(a+b)/2+1,b,D);
		tree[rp].val = tree[2*rp].val + tree[2*rp+1].val;
	}
}
int query(TNode * tree,int l,int r,int a,int b,int D){
	int rp = (b+D)/(b-a+1); //range point
	//ps(l);ps(r);ps(a);ps(b);pln(rp);
	if(l>b||r<a) return 0;
	else if(l<=a&&b<=r){
		return tree[rp].val;
	}else{
		if(tree[rp].mod==-1){
			tree[2*rp].mod *= -1;
			tree[2*rp].val = tree[2*rp].size-tree[2*rp].val;
			tree[2*rp+1].mod *= -1;
			tree[2*rp+1].val = tree[2*rp+1].size-tree[2*rp+1].val;
			tree[rp].mod=1;
		}
		return query(tree,l,r,a,(a+b)/2,D)+query(tree,l,r,(a+b)/2+1,b,D);
	}
}
void coutTree(TNode * tree, int D){
	pln("tree");
	loop(i,1,2*D){
		cout<<i<<" "<<tree[i].val<<" "<<tree[i].mod<<" "<<tree[i].size<<"\n";
	}
	entr;
}
int main(){
	ios_base::sync_with_stdio(0);
	TNode * tree = new TNode[10*MAX];
	int * A = new int[MAX];
	vector<Vertex> G(MAX);
	int n,D,p;
	cin>>n;
	loop(i,1,n){
		cin>>p;
		G[p-1].neighbours.pb(i);
		G[i].neighbours.pb(p-1);
	}
	order(G,0,-1,0);
	
	/*loop(i,0,n){
		cout<<i<<": "<<G[i].pre_i<<" "<<G[i].post_i<<"\n";
	}
	entr;*/
	loop(i,0,n){
		cin>>A[i];
	}
	D=countD(n);
	init(tree,A,G,D,n);
	//coutTree(tree,D);
	int q,v;
	cin>>q;
	string com;
	while(q--){
		cin>>com>>v;
		if(com=="get"){
			pln(query(tree,G[v-1].pre_i,G[v-1].post_i,0,D-1,D));
		}else{
			update(tree,G[v-1].pre_i,G[v-1].post_i,0,D-1,D);
		}
		//coutTree(tree,D);
	}
	delete [] tree;
	delete [] A;
}
