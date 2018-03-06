#include<bits/stdc++.h>
#define loop(i,j,s) for(int i=j;i<s;i++)
#define loopback(i,j,s) for(int i=j;i>=s;i--)
#define pln( x ) cout << x << "\n"
#define ps( x ) cout << x << " "
#define entr cout << "\n" 
#define pcnt(i) __builtin_popcount(i)
#define ll long long
using namespace std;
const int INFTY=20000000;
const int MAX=500100;
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
	int n,a,b,c;
	cin>>n>>a>>b>>c;
	ll p=1,pot3=1;
	loop(i,0,n-1){
		pot3=(pot3*3)%MOD;
	}
	ll sum=0;
	loop(i,0,n){
		sum=(sum+((a+b+c)*p*pot3)%MOD)%MOD;
		p=(p*10)%MOD;
		
	}
	cout<<sum;
}
