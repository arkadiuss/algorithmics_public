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
int n,a[MAX];
int k;
int countS(){
	int s=0;
	loop(i,0,k){
		s+=a[i];
	}
	return s;
}
void change(){
	loop(i,0,n){
		a[i]=-a[i];
	}
}
int main(){
	ios_base::sync_with_stdio(0);
	cin>>n;
	k=2*n-1;
	loop(i,0,k){
		cin>>a[i];
	}
	int s=0, maxS=0;
	maxS=s=countS();
	sort(a,a+k);
	change();
	maxS=max(maxS,countS());
	sort(a,a+k);
	change();
	maxS=max(maxS,countS());
	pln(maxS);
}
