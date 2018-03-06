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

void coutTab(bool * tab, int n){
	loop(i,0,n){
		ps(tab[i]);
	}
	entr;
}
//---------------------------------
int a[MAX];
int n;
VI msd;
bool has[MAX];
bool checkHas(int l){
	loop(i,0,l+1) if(!has[msd[i]]) return 0;
	return 1;
}
int main(){
	ios_base::sync_with_stdio(0);
	cin>>n;
	loop(i,0,n) cin>>a[i];
	loop(i,0,n){
		if(a[i]!=i+1) msd.pb(i);
	}
	int l=0;
	int c=0;
	if(SIZE(msd)==0){
		pln(0);
		return 0;
	}
	//loop(i,0,SIZE(msd)) ps(msd[i]);
	//entr;
	loop(i,0,SIZE(msd)){
		//ps(msd[i]);
		if(i!=0) l+=msd[i]-msd[i-1];
		else l=msd[0];
		has[a[msd[i]]-1]=1;
		//entr;
		//coutTab(has,n);
		//ps(checkHas(i));
		if(checkHas(i)){
			if(i!=SIZE(msd)-1&&msd[i]-msd[c]<msd[i+1]-msd[i]){
				l=l+2*(msd[i]-msd[c]);
				c=i+1;
			}	
		}  
		//pln(l);
	}
	l=l+msd[SIZE(msd)-1]-msd[c];
	pln(l);
}
