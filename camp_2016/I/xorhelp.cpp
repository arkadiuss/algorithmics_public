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
int main(){
	ios_base::sync_with_stdio(0);
	srand(time(NULL));
	cin>>x;
	//n=rand()%1000+1;
	n=1;
	cout<<n<<" "<<x<<"\n";
	loop(i,n,n+100){
		cout<<(i xor x)<<" ";
	}
	
}
