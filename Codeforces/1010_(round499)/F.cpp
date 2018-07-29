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
const int MAX=1000100;
const int MOD=10000000;

void coutTab(int* tab,int n){
	loop(i,0,n){
		cout<<tab[i]<<" ";
	}
	cout<<"\n";
}
//------------------------------------------
int n,m;
struct V{
	int p;
	int nxt[2];
	string op;
	int res[2];
	bool init;
};
V tree[MAX];
bool operation(bool a,bool b,string op){
	if(op=="NOT"){
		return !a;
	}else if(op=="AND"){
		return a&&b;
	}else if(op=="OR"){
		return a||b;
	}else{
		return a^b;
	}
}
bool initdfs(V & v){
	if(v.op=="IN")
		return v.init;
	else if(v.op=="NOT")
		v.init = operation(initdfs(tree[v.nxt[0]]),0,v.op);
	else
		v.init = operation(initdfs(tree[v.nxt[0]]),initdfs(tree[v.nxt[1]]),v.op);
	return v.init;		
}
bool dfs(int i,int l,int val){
	if(i==-1)
		return val;
	bool op;
	if(tree[i].op=="NOT"){
		op = operation(val,0,tree[i].op);
	}else{
		bool b;
		if(tree[i].nxt[0]==l)
			b=tree[tree[i].nxt[1]].init;
		else
			b=tree[tree[i].nxt[0]].init;
		op = operation(val,b,tree[i].op);
	}
	if(tree[i].res[op]!=-1){
		return tree[i].res[op];
	}else{
		tree[i].res[op] = dfs(tree[i].p,i,op);
		return tree[i].res[op];
	}	
}
int main(){
	ios_base::sync_with_stdio(0);
	cin>>n;
	loop(i,0,n){
		tree[i].p=-1;
		tree[i].res[0]=-1;
		tree[i].res[1]=-1;
		tree[i].nxt[0]=-1;
		tree[i].nxt[1]=-1;
	}
	loop(i,0,n){
		cin>>tree[i].op;
		if(tree[i].op=="IN")
			cin>>tree[i].init;
		else if(tree[i].op=="NOT"){
			cin>>tree[i].nxt[0];
			tree[i].nxt[0]--;
			tree[tree[i].nxt[0]].p=i;
		}else{
			cin>>tree[i].nxt[0]>>tree[i].nxt[1];	
			tree[i].nxt[0]--;
			tree[tree[i].nxt[0]].p=i;
			tree[i].nxt[1]--;
			tree[tree[i].nxt[1]].p=i;
		}	
	}
	initdfs(tree[0]);
	loop(i,0,n){
		if(tree[i].op=="IN"){
			cout<<dfs(tree[i].p,i,!tree[i].init);
		}
	}
	entr;
}
