#include<bits/stdc++.h>
#define VAR(i,n) __typeof(n) i = (n)
#define loop(i,j,n) for(int i=j;i<n;i++)
#define loopback(i,n,j) for(int i=n;i>=j;i--)
#define foreach(i,c) for(VAR(i,c.begin());i!=c.end();i++)
#define ALL(c) c.begin(), c.end()
#define SIZE(c) c.size()
#define ps(v) cout<<v<<" "
#define pln(v) cout<<v<<"\n"
#define entr cout<<"\n"
#define ll long long
#define pb push_back
#define ff first
#define ss second
using namespace std;
const int MAX=1000100;
const int MOD=1000000000;
const int INFTY=1000000000;
typedef vector<int> VI;

void coutTab(int * tab, int n){
	loop(i,0,n){
		ps(tab[i]);
	}
	entr;
}
//---------------------------------
int n;
ll a[MAX];
int k;
int main(){
	ios_base::sync_with_stdio(0);
	cin>>n;
	k=2*n-1;
	int m=0;
	ll S=0;
	ll mini=INFTY;
	loop(i,0,k){
		cin>>a[i];
		S+=abs(a[i]);
		mini=min(mini,abs(a[i]));
		if(a[i]<0) m++;
	}
	
	if(n==1||m%2==0){
		pln(S);
	}else{
		if(n%2==1) pln(S);	
		else pln(S-2*mini);
	}
}
