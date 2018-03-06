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

void coutTab(int * tab, int n){
	loop(i,0,n){
		ps(tab[i]);
	}
	entr;
}
//---------------------------------
int n,m,p;
int ord[MAX][MAX];
void coutOrd(){
	pln("order");
	loop(i,0,n){
		loop(j,0,m){
			ps(ord[i][j]);
		}
		entr;
	}
}
bool check(int i, int j){
	loop(k,0,m){
		if(ord[i][k]!=ord[j][k]) return 0;
	}
	return 1;
}
int main(){
	ios_base::sync_with_stdio(0);
	cin>>n>>m>>p;
	loop(i,0,n){
		loop(j,0,m){
			cin>>ord[i][j];
		}
	}
	loop(i,0,n)
		sort(ord[i],ord[i]+m);
	//coutOrd();	
	int r;
	loop(i,0,n){
		r=ord[i][0];
		loop(j,0,m){
			ord[i][j]-=r;
		}
	}	
	//coutOrd();
	int c=0;
	loop(i,0,n){
		loop(j,i,n){
			if(i!=j&&check(i,j)) c++;
		}
	}
	pln(c);
}
