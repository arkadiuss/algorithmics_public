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
const int MAX=30;
const int MOD=1000000000;
const int INFTY=1000000000;
typedef vector<int> VI;
typedef pair<int,int> PII;
void coutTab(int * tab, int n){
	loop(i,0,n){
		ps(tab[i]);
	}
	entr;
}
//---------------------------------
set<ll> hshs;
vector<VI > g(MAX);
int n;
bool was(ll hsh){
	if(hshs.find(hsh)!=hshs.end()) return 1;
	return 0;
}
int hm[MAX];
unsigned ll B=29;
unsigned ll hs(){
	unsigned ll h=0;
	loop(i,0,n){
		h=h*B+hm[i];
	}
	return h;
}
unsigned ll shsh;
vector<ll> pref;
vector<ll> befpref;
PII count(){
	VI toCheck;
	loop(i,0,n){
		if(hm[i]>0) toCheck.pb(i);
		hm[i]=0;
	}
	//pln("from");
	foreach(it,toCheck){
		//ps((*it));
		loop(j,0,SIZE(g[(*it)])){
			hm[g[(*it)][j]]++;
		}
	}
	//entr;
	/*pln("to");
	loop(i,0,n){
		ps(hm[i]);
	}
	entr;*/
	loop(i,0,n){
		hm[i]=hm[i]%2;
	}
	unsigned ll hsh=hs();
	//pln(hsh);
	//pln(SIZE(toCheck));
	if(was(hsh)){
		//pln("mam cykl");
		shsh=hsh;
		pref.pb(SIZE(toCheck));
		return mp(-1,SIZE(toCheck));
	}else{
		hshs.insert(hsh);
		PII res=count();
		//ps(res.ff);pln(res.ss);
		if(hsh==shsh){
			res.ff=0;
			res.ff+=SIZE(toCheck);
			befpref.pb(SIZE(toCheck));
			return res;
		}else{
			if(res.ff!=-1){ 
				res.ff+=SIZE(toCheck);
				befpref.pb(SIZE(toCheck));
			}
			else{ 
				res.ss+=SIZE(toCheck);
				pref.pb(SIZE(toCheck));
			}
			return res;
		}
	}
} 
int main(){
	ios_base::sync_with_stdio(0);
	ll s;
	cin>>n>>s;
	int m,a;
	loop(i,0,n){
		cin>>m;
		loop(j,0,m){
			cin>>a;
			g[i].pb(a-1);
		}
	}
	PII res;
	loop(i,0,n){
		loop(j,0,n) hm[j]=0;
		hm[i]=1;
		hshs.insert(hs());
		res=count();
		//pln(res.ff);
		if(res.ff==-1) res.ff++;
		hshs.clear();
		//ps(res.ff);pln(res.ss);
		reverse(pref.begin(),pref.end());
		reverse(befpref.begin(),befpref.end());
		loop(j,1,SIZE(pref))
			pref[j]+=pref[j-1];
		loop(j,1,SIZE(befpref))
			befpref[j]+=befpref[j-1];
		/*foreach(it,pref) ps((*it));
		
		entr;
		foreach(it,befpref) ps((*it));
		
		entr;*/
		ll w;
		ll s2=s;
		if(g[i].size()==0){
			ps(0);
		}else if(s<befpref.size()){
			ps(befpref[s]);
		}else{
			s2=s2-befpref.size();
			ps((pref[s2%pref.size()]+res.ss*(s2/pref.size())-1));
		}
		pref.clear();befpref.clear();
	}
}
