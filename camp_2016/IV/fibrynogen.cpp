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
int m,q;
double sq5;
ll fib[MAX];
ll power(ll a,int n){
	if(n==1)
		return a;
	if(n%2==0){
		a=power(a,n/2);
		return (a*a)%MOD;
	}
	return (power(a,n-1)*a)%MOD;		
}
ll F(int n){
	return round((1/sq5)*power((1+sq5)/2,n)-(1/sq5)*power((1-sq5)/2,n));
}
ll sumF(int n){
	ll sum=0;
	loop(k,1,m+1){
		sum=(sum+fib[k*n]%MOD)%MOD;
	}
	return sum;
}
int main(){
	ios_base::sync_with_stdio(0);
	cin>>q>>m;
	int n;
	sq5=sqrt(5);
	fib[1]=1;
	fib[2]=1;
	loop(i,3,MAX){
		fib[i]=(fib[i-1]+fib[i-2])%MOD;
	}
	loop(i,0,q){
		cin>>n;
		cout<<sumF(n)<<"\n";	
	}
}
