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
unsigned ll hsh[MAX][MAX];
void coutOrd(){
	pln("order");
	loop(i,0,n){
		loop(j,0,m){
			ps(ord[i][j]);
		}
		entr;
	}
}
void hashI(int i){
	unsigned ll h=0;
	unsigned ll B=29;
	unsigned ll p=1;
	loop(j,0,m){
		h=0;
		B=29;
		p=1;
		loop(k,j,m){
			h+=ord[i][k]*p;
			p*=B;
		}
		loop(k,0,j){
			h+=ord[i][k]*p;
			p*=B;
		}
		hsh[i][j]=h;
	}
}
void coutHash(){
	loop(i,0,n){
		loop(j,0,m){
			ps(hsh[i][j]);
		}
		entr;
	}
}
bool check(int i, int j){
	return hsh[i][0]==hsh[j][0];	
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
	int r;
	loop(i,0,n){
		r=ord[i][0];
		loop(j,0,m){
			ord[i][j]-=r;
		}
	}
	loop(i,0,n){
		loop(j,0,m-1){
			ord[i][j]=ord[i][j+1]-ord[i][j];
		}
		ord[i][m-1]=p-ord[i][m-1];
	}	
	//coutOrd();	
		
	//coutOrd();
	loop(i,0,n) hashI(i);
	//coutHash();
	loop(i,0,n) sort(hsh[i],hsh[i]+m);
	//coutHash();
	int c=0;
	loop(i,0,n){
		loop(j,i+1,n){
			if(check(i,j)) c++;
		}
	}
	pln(c);
}
