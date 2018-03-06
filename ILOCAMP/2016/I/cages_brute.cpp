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
bool was[MAX];
int main(){
	ios_base::sync_with_stdio(0);
	int m;
	ll n,k;
	cin>>m;
	loop(i,0,m){
		cin>>n>>k;
		int howmany=0;
		was[0]=0;
		loop(i,1,n+1){
			if((i%k==0||i==1)&!was[i/k]){ 
				was[i]=1;
				howmany++;
				//ps(i);
			}else if(i%k!=0){
				was[i]=1;
				howmany++;
				//ps(i);
			}
		}
		pln(howmany);
	}
}
