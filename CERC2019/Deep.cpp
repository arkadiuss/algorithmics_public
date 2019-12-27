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
typedef pair<int, int> PII;
typedef vector<vector<int> > VVI;
const int INFTY=20000000;
const int MAX=300100;
const int MOD=10000000;

void coutTab(int* tab,int n){
	loop(i,0,n){
		cout<<tab[i]<<" ";
	}
	cout<<"\n";
}

template<class T> void coutVec(vector<T> tab){
	for(T t : tab){
		cout<<t.ff<<" "<<t.ss<<"\n";
	}
	cout<<"\n";
}
//------------------------------------------
#define double long double
typedef pair<double, double> PDD;
PDD ps[MAX];
int N;
double A,B,R;

double r(double x, double y) {
	return sqrt(x*x+y*y);
}

void rotate(double cos, double sin) {
	loop(i,0,N) {
		double x = ps[i].ff;
		double y = ps[i].ss;
		//ps("xy");ps(x);pln(y);
		ps[i].ff = cos*x+sin*y;
		ps[i].ss = -sin*x+cos*y;
	}
}
double eps=1e-3;
	
vector<double> count(PDD p) {
	if(!(p.ss<R || abs(p.ss-R) < eps)) return {};
	// (x-p.ff)^2 + (p.ss)^2 = R^2
	return {-sqrt(R*R-p.ss*p.ss) + p.ff, sqrt(R*R-p.ss*p.ss) + p.ff};
} 

struct ev {
	double p;
	int t;
	
	ev(double _p,int _t) : p(_p), t(_t) {};

	bool operator<(const ev & b) {
		if(abs(p-b.p)<eps) return t<b.t;
		return p<b.p;
	}
};


bool onSeg(double x) {
	return x >= 0 || x <= r(A,B) || abs(x)<eps || abs(x-r(A,B))<eps;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin>>N>>R>>A>>B;
	loop(i,0,N) {
		cin>>ps[i].ff>>ps[i].ss;	
	}
	if(A==0&&B==0) {
		int b=0;
		loop(i,0,N) {
			if(r(ps[i].ff,ps[i].ss) <= R) b++;
		}
		pln(b);
		return 0;
	}
	rotate(A/r(A,B), B/r(A,B));
	vector<ev> evs;
	loop(i,0,N) {
		//ps("aft");ps(ps[i].ff);pln(ps[i].ss);
		vector<double> P = count(ps[i]);
		if(!P.empty() && (onSeg(P[0]) || onSeg(P[1]))) {
			evs.pb(ev(P[0],1));
			evs.pb(ev(P[1],2));
			//ps("xs");ps(P[0]);pln(P[1]);
		} 
	}
	sort(ALL(evs));
	int b=0;
	int c=0;
	for(auto e: evs){
		if(e.t==1) {
			c++;
		} else {
			c--;
		}
		b=max(c,b);
	}
	pln(b);
}
