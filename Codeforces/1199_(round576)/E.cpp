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
const int MAX=500100;
const int MOD=10000000;

void coutTab(int* tab,int n){
	loop(i,0,n){
		cout<<tab[i]<<" ";
	}
	cout<<"\n";
}
//------------------------------------------
int c[MAX];
bool e[MAX];
int main(){
	ios_base::sync_with_stdio(0);
	int T;
	cin>>T;
	while(T--){
		int n,m;
		cin>>n>>m;
		loop(i,0,3*n) c[i]=-1;
		loop(i,0,m) e[i]=0;
		int a,b;
		int taken = 0;
		loop(i,0,m) {
			cin>>a>>b;
			if(c[a-1] == -1 && c[b-1] == -1){
				e[i] = 1;
				taken++;
				c[a-1] = i;
				c[b-1] = i;
			}
		}
		int cn=n;
		if(taken >= n){
			pln("Matching");
			loop(i,0,m){
				if(e[i]&&cn) { ps(i+1); cn--; }
			}
		} else {
			pln("IndSet");
			loop(i,0,3*n){
				if(c[i]==-1&&cn) { ps(i+1); cn--; }
			}
		}
		entr;
	}
}
