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
int main(){
	ios_base::sync_with_stdio(0);
	int T,n,st;
	int a[MAX];
	cin>>T;
	
	while(T--){
		cin>>n>>st;
		loop(i,0,n){
			cin>>a[i];
		}
		if(n==1&&a[0]%2==0&&st==0) cout<<"Parzysty"<<"\n";
		else cout<<"Nieparzysty"<<"\n";
	}
}
