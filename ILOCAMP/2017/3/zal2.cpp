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
const int MAX=530100;
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
bool was[MAX];
int maxB[MAX];
int ch[MAX];
int n,k;
bool check(){
	loop(i,1,k+1)
		if(!was[i]) return 1;
	return 0;	
}
int main(){
	ios_base::sync_with_stdio(0);
	int q;
	cin>>n>>k>>q;
	loop(i,0,n){
		cin>>ch[i];
	}
	loop(i,0,n){
		maxB[i]=i;
		loop(j,1,k+1) was[j]=0;
		loop(j,i,n){
			was[ch[j]]=1;
			if(check()) maxB[i]=j;
		}
	}
	coutTab(maxB,n);
}
