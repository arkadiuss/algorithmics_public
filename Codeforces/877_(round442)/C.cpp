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
int main(){
	ios_base::sync_with_stdio(0);
	int n;
	cin>>n;
	if(n==2){
		pln(3);ps(2);ps(1);pln(2);
	}else if(n==3){
		pln(4);ps(2);ps(1);ps(3);pln(2);
	}else if(n==4){
		pln(6);ps(2);ps(1);ps(3);ps(4);ps(3);pln(2);
	}else{
		pln(n+n/2);
		for(int i=2;i<=n;i+=2) ps(i);
		for(int i=1;i<=n;i+=2) ps(i);
		for(int i=2;i<=n;i+=2) ps(i);
		entr;
	}
}
