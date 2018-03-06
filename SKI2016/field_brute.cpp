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
const int MOD=10000000;

void coutTab(int* tab,int n){
	loop(i,0,n){
		cout<<tab[i]<<" ";
	}
	cout<<"\n";
}
//------------------------------------------
bool check(ll A){
	while(A>0&&A%2==0)
		A=A/2;
	if(A==1||A==5) return 1;
	return 0;	
}
int main(){
	ios_base::sync_with_stdio(0);
	int T,n;
	ll A;
	//cin>>n;
	//loop(A,0,n){
	cin>>T;
	while(T--){
		if(check(A))
			cout<<"TAK";
		else
			cout<<"NIE";
		entr;
	}
}
