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
const int MAX=120;
const int MOD=10000000;

void coutTab(int* tab,int n){
	loop(i,0,n){
		cout<<tab[i]<<" ";
	}
	cout<<"\n";
}
//------------------------------------------

int main(){
	ios_base::sync_with_stdio(0);
	int n,m;
	cin>>n>>m;
	char a;
	int sr=-1,er=-1;
	int sc=-1,ec=-1;
	loop(i,0,n){
		loop(j,0,m){
			cin>>a;
			if(a=='B'){
				if(sr==-1) sr=i;
				if(sc==-1) sc=j;
				er=i;
				ec=j;
			}
		}
	}
	ps((er+sr)/2+1);pln((ec+sc)/2+1);
}
