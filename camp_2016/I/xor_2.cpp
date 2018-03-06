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
int n,x,howManyxor=0;
int a[MAX];bool xored[MAX]={0};
bool check(int p,int k){
	loop(i,p,k){
		if(a[i]>a[i+1])
			return false;
	}
	return true;
}
void xorrange(int p,int k){
	loop(i,p,k+1){
		a[i]=a[i] xor x;
	}
}
int divide(int p,int k){
	
	if(check(p,k)) return 0;
	else{ 
		xorrange(p,k);
		if(check(p,k)) return 1;
		else{
			xorrange(p,k);
			return divide(p,(p+k)/2)+divide((p+k)/2+1,k);
		}
	}
}
int main(){
	ios_base::sync_with_stdio(0);
	srand(time(NULL));
	cin>>n>>x;
	loop(i,0,n) cin>>a[i];
	cout<<divide(0,n-1);
}
