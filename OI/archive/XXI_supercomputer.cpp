#include<bits/stdc++.h>
#define loop(i,j,n) for(int i=j;i<n;i++)
#define loopback(i,n,j) for(int i=n;i>=j;i++)
#define entr cout<<"\n"
#define ps( v ) cout<<v<<" "
#define pln( v ) cout<<v<<"\n"
#define pb( v ) push_back( v )
using namespace std;

const int MAX=1000100;

void coutTab(int* tab,int n){
	loop(i,0,n){
		ps(tab[i]);
	}
	entr;
}
//------------------------------------
int n,q;
struct V{
	int size,lvl;
};
vector<vector<int> > G(MAX);
V vs[MAX];
int k[MAX];
int pref[MAX];
int ans[MAX];
bool toSort(V a, V b){
	if(a.lvl==b.lvl) return a.size>b.size;
	return a.lvl<b.lvl;
}
void bfs(){
	queue<int> Q;
	Q.push(0);
	vs[0].lvl=0;
	while(!Q.empty()){
		int v=Q.front();
		//cout<<v+1<<" "<<j<<" "<<r<<"\n";
		loop(i,0,G[v].size()){
			vs[G[v][i]].lvl=vs[v].lvl+1;
			Q.push(G[v][i]);
		}		
		Q.pop();
	}
}
void coutVS(){
	loop(i,0,n){
		cout<<"("<<vs[i].lvl<<","<<vs[i].size<<") ";
	}
	entr;
}
void countPrefs(){
	pref[0]=0;
	pref[1]=vs[0].size;
	loop(i,1,n){
		pref[i+1]=pref[i]+vs[i].size;
	}
}
int count(int k){
	int ava=1,newava=0;
	int i=0;
	int t=0;
	int r=0;
	int last;
	while(i<n){
		t=0;
		newava=0;
		last=i;
		i=i+min(ava,k);
		ava=ava-min(ava,k);
		newava=pref[i]-pref[last];
		ava=ava+newava;
		r++;
	}
	return r;
}
int main(){
	//ios_base::sync_with_stdio(0);
	cin>>n>>q;
	loop(i,0,q){
		cin>>k[i];
	}
	int a;
	loop(i,1,n){
		cin>>a;
		G[a-1].pb(i);
	}
	bfs();
	loop(i,0,n){
		vs[i].size=G[i].size();
	}
	sort(vs,vs+n,toSort);
	countPrefs();
	//coutVS();
	loop(i,0,n+1){
		ans[i]=-1;
	}
	int res;
	loop(i,0,q){
		if(ans[k[i]]!=-1)
			res=ans[k[i]];
		else{
			res=count(k[i]);
			ans[k[i]]=res;
		}		
		printf("%d ",res);
	}
	printf("\n");
	//entr;
}
