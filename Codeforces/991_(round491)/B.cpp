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
const int MAX=101;
const int MOD=10000000;

void coutTab(int* tab,int n){
	loop(i,0,n){
		cout<<tab[i]<<" ";
	}
	cout<<"\n";
}
//------------------------------------------
int main(){
	ios_base::sync_with_stdio(0);
	int n,a[MAX];
	cin>>n;
	int S=0;
	loop(i,0,n){
		cin>>a[i];
		S+=a[i];
	}
	sort(a,a+n);
	int i=0;
	int r=0;
	while(S/n<4||(S/n==4&&(S%n<(n+1)/2))){
		S+=5-a[i];
		i++;
		r++;
		//pln(S);
	}
	pln(r);
}
