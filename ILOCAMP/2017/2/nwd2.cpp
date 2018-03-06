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
int hm[MAX], a[MAX];
int maxa=0;
int n,k;
int main(){
	ios_base::sync_with_stdio(0);
	cin>>n>>k;
	loop(i,0,n){ 
		cin>>a[i];
		hm[a[i]]++;
		maxa=max(maxa,a[i]);
	}
	int s=0,j;
	int maxD=1;
	loop(i,1,maxa+1){
		s=0;
		j=i;
		while(j<=maxa){
			s=s+hm[j];
			j+=i;
		}
		if(s>=k) maxD=i;
	}
	pln(maxD);
}
