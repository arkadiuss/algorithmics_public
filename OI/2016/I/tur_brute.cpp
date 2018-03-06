#include<bits/stdc++.h>
#define loop(i,j,s) for(int i=j;i<s;i++)
#define loopback(i,j,s) for(int i=j;i>=s;i--)
#define pln( x ) cout << x << "\n"
#define ps( x ) cout << x << " "
#define entr cout << "\n" 
#define pcnt(i) __builtin_popcount(i)
#define ll long long
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
using namespace std;
const int INFTY=20000000;
const int MAX=15;
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
void coutG(){
	loop(i,0,n){
		cout<<i<<": ";
		loop(j,0,G[i].size()){
			cout<<G[i][j]<<" ";
		}
		entr;
	}

}
bool visited[MAX];
vector<int> go(int v){
	vector<int> best,act;
	visited[v]=1;
	loop(i,0,G[v].size()){
		if(!visited[G[v][i]]){
			act=go(G[v][i]);
			
			if(act.size()>best.size())
				best=act;
		}
	}
	best.pb(v);
	visited[v]=0;
	return best;
}
int main(){
	ios_base::sync_with_stdio(0);
	cin>>n;
	int a;
	loop(i,0,n){
		loop(j,0,i){
			cin>>a;
			if(a==1){
				G[j].pb(i);
			}else
				G[i].pb(j);
		}
	}
	//coutG();
	vector<int> res;
	loop(i,0,n){
		res=go(i);
		ps(res.size());
		loopback(j,res.size()-1,0){
			ps(res[j]+1);
		}
		entr;
	}
}
