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
};
obstc obs[MAX];
struct group : vector<obstc>{
	int maxR;
};
vector<group> gr;
double d(obstc a, obstc b){
	return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}
bool intersect(obstc a, obstc b){
	if(d(a,b)>a.r+b.r) return 0;
	return 1;
}
bool toSort(obstc a, obstc b){
	return max(0,a.x-a.r)<max(0,b.x-b.r);
}
void coutObs(){
	loop(i,0,k){
		ps(obs[i].x);ps(obs[i].y);pln(obs[i].r);
	}
}
void coutGr(){
	loop(i,0,SIZE(gr)){
		ps(i);ps(":");
		foreach(it,gr[i]){
			ps(it->x);ps(it->y);pln(it->r);
		}
	}
}
bool check(){
	foreach(it,gr){
		if(it->maxR>=m) return 0;
	}
	return 1;
}
int main(){
	ios_base::sync_with_stdio(0);
	int T;
	cin>>T;
	while(T--){
		cin>>n>>m>>k;
		loop(i,0,k){
			cin>>obs[i].y>>obs[i].x>>obs[i].r;
		}
		sort(obs,obs+k,toSort);	
		//coutObs();
		group g;
		g.pb(obs[0]);
		gr.clear();
		loop(i,0,k){
			if(obs[i].x-obs[i].r<=0){
				g[0]=obs[i];
				g.maxR=obs[i].x+obs[i].r;
				gr.pb(g);
			}else{
				loop(g,0,SIZE(gr)){
					loopback(j,SIZE(gr[g])-1,0){
						if(intersect(gr[g][j],obs[i])){
							gr[g].pb(obs[i]);
							gr[g].maxR=max(obs[i].x+obs[i].r,gr[g].maxR);
						}
					}
				}
			}
		}

		//coutGr();
		if(check()) pln("TAK");
		else pln("NIE");
	}
}
