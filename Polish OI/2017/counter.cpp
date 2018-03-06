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
vec vs[2*MAX];
ll len(PLL a){
	return a.ff*a.ff+a.ss*a.ss;
}
PLL add(PLL a,PLL b){
	PLL c;
	c.ff=a.ff+b.ff;
	c.ss=a.ss+b.ss;
	return c;
}
PLL remove(PLL a,PLL b){
	PLL c;
	c.ff=a.ff-b.ff;
	c.ss=a.ss-b.ss;
	return c;
}
double getAlfa(PLL v){
	if(v.ff==0&&v.ss==0) return 0;
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

int main(){
	//ios_base::sync_with_stdio(0);
	cin>>n;
	PLL svec;
	svec.ff=0;
	svec.ss=0;
	loop(i,0,n){
		cin>>vs[i].v.ff>>vs[i].v.ss;
		vs[i].deg=getAlfa(vs[i].v);	
		svec=add(svec,vs[i].v);
	}
	sort(vs,vs+n,sortByDeg);
	loop(i,n,2*n){
		vs[i]=vs[i-n];
		vs[i].deg+=2*PI;
	}
	/*loop(i,0,2*n){
		ps(vs[i].deg);
	}
	entr;*/
	ll maxlen=0;
	int j=0;
	PLL avec=vs[0].v;
	loop(i,0,n){
		//ps(i);
		while(j+1<2*n&&(vs[j+1].deg<vs[i].deg+PI)){
			avec=add(avec,vs[j+1].v);
			j++;
		}
		//pln(j);
		maxlen=max(maxlen,len(avec));
		maxlen=max(maxlen,len(remove(svec,avec)));
		avec=remove(avec,vs[i].v);
		maxlen=max(maxlen,len(avec));
	}
	pln(maxlen);
}
