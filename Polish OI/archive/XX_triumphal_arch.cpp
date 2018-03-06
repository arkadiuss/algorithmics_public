#include<bits/stdc++.h>
#define VAR(c,n) __typeof(n) c = (n)
#define loop(i,j,n) for(int i=j;i<n;i++)
#define loopback(i,n,j) for(int i=n;i>=j;i--)
#define foreach(i,c) for(VAR(i,c.begin());i!=c.end();i++)
#define ALL(c) (c).begin(), (c).end()
#define SIZE(c) (c).size()
#define ps(v) cout<<v<<" "
#define pln(v) cout<<v<<"\n"
#define entr cout<<"\n"
#define pb(v) push_back(v)
#define mp(a,b) make_pair(a,b)
#define ff first
#define ss second 
using namespace std;
typedef vector<int> VI;
typedef pair<int,int> PII;

const int MAX=301000;
const int INFTY=1000000010;

void coutTab(int* tab, int n){
	loop(i,0,n){
		ps(tab[i]);
	}
	entr;
}
//----------------------
template<class V, class E> struct Tree{
	struct Ed : E {
		E e;
		int v;
		Ed(int w, E ed=E()) : v(w), e(ed) {}	
	};
	
	struct Ve : V, vector<Ed> {};
	
	vector<Ve> g;
	
	Tree(int n=0) : g(n) {};
	
	void EdgeU(int a, int b){
		E e;
		g[a].pb(Ed(b,e));
		g[b].pb(Ed(a,e));
	}
	int checkDfs(int v,int l,int k){
		int sum=0;
		foreach(it,g[v]){
			if(it->v!=l)
				sum=sum+checkDfs(it->v,v,k)+1;
		}
		sum=sum-k;
		return max(sum,0);
	}
	void coutG(){
		loop(i,0,SIZE(g)){
			ps(i+1);
			ps(":");
			foreach(it,g[i]){
				ps((it->v));			
			}
			entr;
		}
	}
};
struct V{
	bool checked;
	int depth;
	int dp;
};
struct E{};
int n;
Tree<V,E> t;
int iter(){
	loop(i,1,n){
		if(t.checkDfs(0,0,i)) return i;
	}
	return n;
}
int bin(){
	int s=1,e=n,m;
	while(s<e){
		m=(s+e)/2;
		if(t.checkDfs(0,0,m)==0) e=m;
		else s=m+1;
	}
	return s;
}
int main(){
	ios_base::sync_with_stdio(0);
	cin>>n;
	t = Tree<V,E>(n);
	int a,b;	
	loop(i,0,n-1){
		cin>>a>>b;
		t.EdgeU(a-1,b-1);	
	}
	if(n==1) pln(0);
	else pln(bin());
}
