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
const int MAX_VAL=2*(1e6)+3;
int n;
int a[MAX];
int divs[MAX_VAL];
void sieve(){
	divs[1]=1;
	for(int i=2;i<=MAX_VAL;i++) divs[i]=i;
	for(int i=2;i<=sqrt(MAX_VAL);i++){
		if(divs[i]==i){
			int j=i*i;
			while(j<=MAX_VAL){
				if(divs[j]==j) divs[j]=i;
				j+=i;
			}
		}
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin>>n;
	loop(i,0,n){ 
		cin>>a[i];
	}
	sieve();
	int x=0,F;
	loop(i,0,n){
		int b=a[i];
		bool was2=0;
		F=0;
		while(b>1){
			if(divs[b]==2) was2=1;
			else F++;
			b=b/divs[b]; 
		}
		if(was2) F++;
		//ps(F);
		x=x xor F;
	}
	if(x==0) pln(":(");
	else pln(":)");
}
