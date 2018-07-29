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
const int MAX=100;
const int MOD=10000000;

void coutTab(int* tab,int n){
	loop(i,0,n){
		cout<<tab[i]<<" ";
	}
	cout<<"\n";
}
//------------------------------------------
int p[MAX];
int main(){
	ios_base::sync_with_stdio(0);
	int n,m;
	cin>>m>>n;
	int a;
	loop(i,0,n){
		cout<<m<<endl;
		fflush(stdout);
		cin>>a;
		if(a<0) p[i]=1;
		else if(a==0) return 0;
		else p[i]=-1;	
	}
	int s=0,e=m;
	int i=0;
	while(s<e){
		int mid = (s+e)/2;
		cout<<mid<<endl;
		fflush(stdout);
		cin>>a;
		if(a==0) return 0;
		else if(a*p[i]<0) e=mid;
		else s=mid+1;
		i++;
		i=i%n;	
	}
}
