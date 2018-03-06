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
typedef pair<ll,ll> PLL;
const int INFTY=20000000;
const int MAX=200100;
const int MOD=10000000;
const double PI=3.14159;

void coutTab(int* tab,int n){
	loop(i,0,n){
		cout<<tab[i]<<" ";
	}
	cout<<"\n";
}
//------------------------------------------
int n;
struct vec{
	PLL v;
	double deg;
};
bool sortByDeg(vec a,vec b){
	return a.deg<b.deg;
}
vec vs[MAX];
ll len(PLL a){
	return a.ff*a.ff+a.ss*a.ss;
}
PLL add(PLL a,PLL b){
	PLL c;
	c.ff=a.ff+b.ff;
	c.ss=a.ss+b.ss;
	return c;
}
double getAlfa(PLL v){
	double d=sqrt(v.ff*v.ff+v.ss*v.ss);
	double cs=v.ff/d;
	double alfa;
	if(v.ff<=0&&v.ss<0) alfa=PI+(PI-acos(cs));
	else if(v.ff>0&&v.ss<0) alfa=PI+(PI-acos(cs));
	else{alfa=acos(cs);}
	return alfa;
}
void printPLL(PLL a){
	cout<<"("<<a.ff<<","<<a.ss<<") ";
}
vector< PLL > Q;
int main(){
	ios_base::sync_with_stdio(0);
	cin>>n;
	loop(i,0,n){
		cin>>vs[i].v.ff>>vs[i].v.ss;
		vs[i].deg=getAlfa(vs[i].v);	
	}
	sort(vs,vs+n,sortByDeg);
	ll maxlen=0;
	loop(i,0,n){
		double f1=vs[i].deg;
		double f2=vs[i].deg+PI;
		double g1=vs[i].deg+PI;
		double g2=vs[i].deg+2*PI;
		PLL vec,vecr;
		vec=mp(0,0);
		vecr=mp(0,0);
		//printPLL(vec);cout<<": ";
		loop(j,0,n){
			if(i!=j){
				if((f1<=vs[j].deg&&vs[j].deg<f2)||(f1<=vs[j].deg+2*PI&&vs[j].deg+2*PI<f2)){
					//printPLL(vs[j].v);
					vec=add(vec,vs[j].v);	
				}
				if((g1<=vs[j].deg&&vs[j].deg<g2)||(g1<=vs[j].deg+2*PI&&vs[j].deg+2*PI<g2)){
					//cout<<"r:";printPLL(vs[j].v);
					vecr=add(vecr,vs[j].v);	
				}
			}
		}
		//entr;
		maxlen=max(maxlen,len(vec));
		maxlen=max(maxlen,len(vecr));
		vec=add(vec,vs[i].v);
		vecr=add(vecr,vs[i].v);
		maxlen=max(maxlen,len(vec));
		maxlen=max(maxlen,len(vecr));
	}
	pln(maxlen);
}
