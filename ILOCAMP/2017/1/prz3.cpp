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
#define mp make_pair
using namespace std;
const int MAX=1000100;
const int MOD=1000000000;
const int INFTY=1000000000;
typedef vector<int> VI;
typedef pair<int, int> PII;
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
set<int> lack;
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
	vector<PII> rng;
	loop(i,0,SIZE(msd)){
		//ps(msd[i]);
		if(i!=0) l+=msd[i]-msd[i-1];
		else l=msd[0];
		has[a[msd[i]]-1]=1;
		if(lack.find(a[msd[i]]-1)!=lack.end()) lack.erase(lack.find(a[msd[i]]-1));
		if(!has[msd[i]]) lack.insert(msd[i]);
		//entr;
		//coutTab(has,n);
		//ps(checkHas(i));
		if(lack.empty()){
			//ps(SIZE(msd));pln(i+1);
			if(i!=SIZE(msd)-1&&msd[i]+1!=msd[i+1]){
				rng.pb(mp(msd[c],msd[i]));
				c=i+1;
			}else if(i==SIZE(msd)-1){
				rng.pb(mp(msd[c],msd[i]));
			}	
		}  
		//pln(l);
	}
	l=rng[0].ss;
	loop(i,0,SIZE(rng)){
		if(i!=0) l+=rng[i].ss-rng[i-1].ss;
		l=l+2*(rng[i].ss-rng[i].ff)	;
	}
	l=l-(rng[SIZE(rng)-1].ss-rng[SIZE(rng)-1].ff);
	int minl=l;
	loopback(i,SIZE(rng)-2,0){
		l=l-(rng[i].ss-rng[i].ff)+(rng[i+1].ff-rng[i].ss);
		minl=min(minl,l);	
	}
	pln(minl);
}
