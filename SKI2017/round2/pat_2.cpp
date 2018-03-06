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
int F[MAX_VAL];
set<int> Fdivs[MAX_VAL];
int maxi=0;
int mex(set<int> & A){
	int last=-1;
	foreach(it,A){
		if((*it)!=last+1) return last+1;
		last++;
	}
	return last+1;
}
int sieve(){ //Sprague-Grundem function count
	Fdivs[2].insert(2);
	for(int d=2;d<=maxi;d++){
		if(d%2==0) Fdivs[d].insert(0);
		else Fdivs[d].insert(F[1]);
		F[d]=mex(Fdivs[d]);
		int j=2*d;
		while(j<=maxi){
			if((j/d)%2==1) Fdivs[j].insert(F[d]);
			else Fdivs[j].insert(0);
			j=j+d;
		}
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin>>n;
	loop(i,0,n){ 
		cin>>a[i];
		maxi=max(maxi,a[i]);
	}
	loop(i,0,maxi+1) F[i]=-1;
	F[1]=0;
	F[2]=1;
	sieve();
	//loop(i,0,21) ps(F[i]);
	//entr;
	int x=0;
	loop(i,0,n){
		x=x xor F[a[i]];
	}
	if(x==0) pln(":(");
	else pln(":)");
}
