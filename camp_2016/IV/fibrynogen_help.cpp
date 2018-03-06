#include<bits/stdc++.h>
#define loop(i,j,s) for(ll i=j;i<s;i++)
#define loopback(i,j,s) for(int i=j;i>=s;i--)
#define pln( x ) cout << x << "\n"
#define ps( x ) cout << x << " "
#define entr cout << "\n" 
#define pcnt(i) __builtin_popcount(i)
#define ll long long
using namespace std;
const int INFTY=20000000;
const int MAX=1000100;
const ll MOD=1000000009;

void coutTab(int* tab,int n){
	loop(i,0,n){
		cout<<tab[i]<<" ";
	}
	cout<<"\n";
}
//------------------------------------------

int main(){
	ios_base::sync_with_stdio(0);
	ll a,b;
	int n;
	cin>>a>>b;
	cout<<(a*b)%MOD;
}
