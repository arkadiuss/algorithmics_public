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
using namespace std;
const int MAX=1100;
const int MOD=1000000000;
const int INFTY=1000000000;
typedef vector<int> VI;

void coutTab(int* tab, int n){
	loop(i,0,n){
		ps(tab[i]);
	}
	entr;
}
//---------------------------------
int n,m,k;
struct obstc{
	int x,y,r;
	int id;
};
obstc obs[MAX];
vector<vector<int> > G(MAX+2);
double d(obstc a, obstc b){
	return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}
bool intersect(obstc a, obstc b){
	if(d(a,b)>a.r+b.r) return 0;
	return 1;
}
void coutObs(){
	loop(i,0,k){
		ps(obs[i].x);ps(obs[i].y);pln(obs[i].r);
	}
}
bool checked[MAX];
bool dfs(int i){
	//ps(i);
	if(i==1003) return 1;
	bool res=0;
	checked[i]=1;
	foreach(it,G[i]){
		if(!checked[(*it)]){
			res=res||dfs((*it));
		}
	}
	return res;
}
int main(){
	ios_base::sync_with_stdio(0);
	int T;
	cin>>T;
	while(T--){
		cin>>n>>m>>k;
		loop(i,0,k){
			cin>>obs[i].y>>obs[i].x>>obs[i].r;
			obs[i].id=i;
		}
		//ps("size");pln(G.size());
		loop(i,0,k){
			if(obs[i].x-obs[i].r<=0){ 
				G[obs[i].id].pb(1002);
				G[1002].pb(obs[i].id);
			}
			if(obs[i].x+obs[i].r>=m){ 
				G[obs[i].id].pb(1003);
				G[1003].pb(obs[i].id);
			}
			loop(j,i,k){
				if(intersect(obs[i],obs[j])){
					G[obs[i].id].pb(obs[j].id);
					G[obs[j].id].pb(obs[i].id);
				}
			}
		}
		//coutGr();
		/*entr;
		loop(i,0,m){
			ps(i);ps(": ");
			loop(j,0,SIZE(G[i])){
				ps(G[i][j]);
			}
			entr;
		}*/
		if(dfs(1002)) pln("NIE");
		else pln("TAK");
		G.clear();
		G.resize(MAX);
		loop(i,0,MAX) checked[i]=0;
	}
}
