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
int findC(int a,int b,int c){
	int i2=0,i5=0;
	int cb=b;
	while(b%2==0) {
		i2++;
		b/=2;
	}
	while(b%5==0){
		i5++;
		b/=5;
	}
	b=cb;
	loop(i,0,max(i2,i5)){
		a*=10;
		//ps(a/b);
		if(a/b==c) return i+1;
		a=a%b;
	}
	//if(a==0) return -1;
	//entr;
	a*=10;
	int f=a/b;
	loop(i,1,10000){
		//ps(a/b);
		if(a/b==c) return max(i2,i5)+i;
		a=a%b;
		a*=10;
	}
	return -1;
}
int main(){
	ios_base::sync_with_stdio(0);
	int a,b,c;
	cin>>a>>b>>c;
	pln(findC(a,b,c));
}
