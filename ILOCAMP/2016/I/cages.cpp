#include<bits/stdc++.h>
#define loop(i,j,s) for(int i=j;i<s;i++)
#define loopback(i,j,s) for(int i=j;i>=s;i--)
#define pln( x ) cout << x << "\n"
#define ps( x ) cout << x << " "
#define entr cout << "\n" 
#define pcnt(i) __builtin_popcount(i)
#define ll long long
#define ull unsigned long long
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
ll howManyPowers(ull n,ull k){
	ll howmany=0;
	ull b=k;
	k=k;
	int i=1;
	while(k<=n){
		if(i%2==0)
			howmany=howmany+n/k;
		else
			howmany=howmany-n/k;	
		ll test=k*b;
		if(test/b!=k)
			break;
		k=k*b;
		i++;
	}
	return howmany;
}

int main(){
	ios_base::sync_with_stdio(0);
	int m;
	ull n,k;
	cin>>m;
	loop(i,0,m){
		cin>>n>>k;
		if(k>1){
			ull ans = n + howManyPowers(n,k);
			pln(ans);
		}else
			pln(n);
	}
}
