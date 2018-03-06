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
const int MAX=51;
const int MOD=10000000;

void coutTab(int* tab,int n){
	loop(i,0,n){
		cout<<tab[i]<<" ";
	}
	cout<<"\n";
}
//------------------------------------------
int h,w;
int n,m;
bool P[MAX][MAX];
bool res[2*MAX][2*MAX];
int main(){
	ios_base::sync_with_stdio(0);
	cin>>h>>w;
	cin>>n>>m;
	char t;
	loop(i,0,n){
		loop(j,0,m){
			cin>>t;
			P[i][j]=(t=='#');
		}
	}
	loop(i,0,h-n+1){
		loop(j,0,w-m+1){
			loop(k,i,i+n){
				loop(l,j,j+m){
					res[k][l]=res[k][l]||P[k-i][l-j];
				}
			}
		}
	}
	ll c=0;
	loop(i,0,h){
		loop(j,0,w){
			//ps(res[i][j]);
			if(!res[i][j]) c++;
		}
		//entr;
	}
	pln(c);
}
