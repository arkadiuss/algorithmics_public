#include<bits/stdc++.h>
#define VAR(i,n) __typeof(n) i = (n)
#define loop(i,j,n) for(int i=j;i<n;i++)
#define loopback(i,n,j) for(int i=n;i>=j;i--)
#define foreach(i,n) for(VAR(i,c.begin());i!=c.end();i++)
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
const int MAX=1000010;
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
int n,m;
int r[MAX];
bool was[MAX];
int main(){
	ios_base::sync_with_stdio(0);
	unsigned ll seed;
	cin>>seed;
	srand(seed*time(0));
	n=500000;
	int k=500000;
	int q=500000;
	ps(n);ps(k);pln(q);
	int a,b;
	loop(i,0,n){
		a=500000;
		ps(a);
	}entr;
	loop(i,0,q){
		a=1;
		b=500000;
		if(a>b) swap(a,b);
		ps(a);pln(b);
	}
	entr;
}
