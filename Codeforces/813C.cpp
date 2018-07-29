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
vector< VI > T(MAX);
int n,x;
int mx[MAX],d[MAX],father[MAX];

int dfs(int a,int l){
	int maxi=-1;
	loop(i,0,SIZE(T[a])){
		if(T[a][i]!=l) {
			d[T[a][i]]=d[a]+1;
			father[T[a][i]]=a;
			maxi=max(maxi,dfs(T[a][i],a));
		}
	}
	mx[a]=maxi+1;
	return maxi+1;
}
int main(){
	ios_base::sync_with_stdio(0);
	int a,b;
	cin>>n>>x;
	loop(i,0,n-1){
		cin>>a>>b;
		T[a-1].pb(b-1);
		T[b-1].pb(a-1);
	}
	d[0]=0;
	father[0]=-1;
	dfs(0,-1);
	x--;
	//coutTab(d,n);
	//coutTab(father,n);
	//coutTab(mx,n);
	int k=floor((d[x]-1)/2);
	//pln(k);
	a=x;
	int maxi=d[a]+mx[a];
	loop(i,0,k+1){
		maxi=max(d[a]+mx[a],maxi);
		a=father[a];
	}
	pln(maxi*2);
}
