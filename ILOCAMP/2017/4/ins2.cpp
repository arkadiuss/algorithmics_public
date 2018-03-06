#include<bits/stdc++.h>
#define VAR(i,n) __typeof(n) i = (n)
#define loop(i,j,n) for(int i=j;i<n;i++)
#define loopback(i,n,j) for(int i=n;i>=j;i--)
#define foreach(i,c) for(VAR(i,c.begin());i!=c.end();i++)
#define ALL(c) c.begin(), c.end()
#define SIZE(c) c.size()
#define ps(v) cout<<v<<" "
#define pln(v) cout<<v<<"\n"
#define entr cout<<"\n"
#define ll long long
#define pb push_back
#define ff first
#define ss second
#define mp make_pair
using namespace std;
const int MAX=1000100;
const int MOD=1000000000;
const int INFTY=1000000000;
typedef vector<int> VI;

void coutTab(int * tab, int n){
	loop(i,0,n){
		ps(tab[i]);
	}
	entr;
}
//---------------------------------
template<class V, class E> struct Tree{
	struct Ed : E {
		int v;
		Ed(E e, int w) : E(e), v(w) {};
	};
	struct Ve : V, vector<Ed> { };
	
	vector<Ve> g;
	Tree(int n=0) : g(n) {};
	void EdgeU(int a,int b,E e=E()){
		e.rev=SIZE(g[b]);
		g[a].pb(Ed(e,b));
		e.rev=SIZE(g[a])-1;
		g[b].pb(Ed(e,a));
	}
	static bool toSort(Ed a, Ed b){
		return a.v<b.v;
	}
}; 
struct V {
	ll sum;
	set<ll> maxS;
	map<ll,int> hm;
};
struct E {
	ll w;
	int rev;
};
int n;
Tree<V,E> T;
ll res=0;
int find(int a,int b){
	int s=0;
	int e=SIZE(T.g[a]);
	int m;
	while(s<e){
		m=(s+e)/2;
		if(T.g[a][m].v==b) return m;
		else if(T.g[a][m].v<b) s=m+1;
		else e=m;
	}
	return s;
}

void prepare(){
	loop(i,0,SIZE(T.g)){
		sort(T.g[i].begin(),T.g[i].end(),T.toSort);
		ll maxi=0,sum=0;
		foreach(it,T.g[i]){
			maxi=max(maxi,it->w);
			sum+=it->w;
			T.g[i].maxS.insert(it->w);
			if(T.g[i].hm.find(it->w)==T.g[i].hm.end())
				T.g[i].hm.insert(mp(it->w,0));
				T.g[i].hm[it->w]++;
		}
		T.g[i].sum=sum;
		if(maxi>sum-maxi)
			res+=maxi-(sum-maxi);
		else if(sum%2==1)
			res++;	
	}
}
ll ares(int i){
	ll maxi=(*T.g[i].maxS.rbegin());
	while(T.g[i].hm[maxi]==0){
		//T.g[i].maxS.erase(maxi);
		maxi=(*T.g[i].maxS.rbegin());
	}
	ll sum=T.g[i].sum;
	ll ares=0;
	if(maxi>sum-maxi)
		ares+=maxi-(sum-maxi);
	else if(sum%2==1)
		ares++;
	return ares;		
}
void change(int a, int b, ll w){
	if(a>b) swap(a,b);
	int j=find(a,b);
	res-=ares(a);
	res-=ares(b);
	ll ow=T.g[a][j].w;
	/*foreach(it,T.g[a].maxS){
		ps((*it));
	}
	entr;
	foreach(it,T.g[b].maxS){
		ps((*it));
	}
	entr;*/
	T.g[a].sum-=ow;
	T.g[b].sum-=ow;
	T.g[a].hm[ow]--;
	T.g[a].hm[ow]--;
	T.g[a][j].w=w;
	T.g[b][T.g[a][j].rev].w=w;
	T.g[a].sum+=w;
	T.g[b].sum+=w;
	T.g[a].maxS.insert(w);
	T.g[b].maxS.insert(w);
	if(T.g[a].hm.find(w)==T.g[a].hm.end())
		T.g[a].hm.insert(mp(w,0));
	if(T.g[b].hm.find(w)==T.g[b].hm.end())
		T.g[b].hm.insert(mp(w,0));
	T.g[a].hm[w]++;
	T.g[b].hm[w]++;
	/*foreach(it,T.g[a].maxS){
		ps((*it));
	}
	entr;
	foreach(it,T.g[b].maxS){
		ps((*it));
	}
	entr;
	pln("-----------");*/
	res+=ares(a)+ares(b);
}

int main(){
	ios_base::sync_with_stdio(0);
	int q;
	cin>>n;
	T=Tree<V,E>(n+100);
	int a,b,w;
	loop(i,0,n-1){
		E e;
		cin>>a>>b>>e.w;
		if(a>b) swap(a,b);
		T.EdgeU(a-1,b-1,e);
	}
	prepare();
	pln(res/2);
	cin>>q;
	loop(i,0,q){
		cin>>a>>b>>w;
		change(a-1,b-1,w);
		pln(res/2);
	}
}
