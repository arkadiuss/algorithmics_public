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
const int MAX=200100;
const int MOD=10000000;

void coutTab(int* tab,int n){
	loop(i,0,n){
		cout<<tab[i]<<" ";
	}
	cout<<"\n";
}

template<class T> void coutVec(vector<T> tab){
	for(T t : tab){
		cout<<t<<" ";
	}
	cout<<"\n";
}
//------------------------------------------
double a[MAX];
int n;

double longest_positive(double x) {
	double l = 0;
	ll c = 0;
	ll d = 0;
	loop(i,0,n) {
		c += a[i];
		d++;
		if(c-d*x<0) { 
			c=0;
			d=0;
		}
		l = max(l,c-d*x);
	}
	return l;
}

double forx(double x) {
	double lp = longest_positive(x);
	loop(i,0,n) a[i] *= -1;
	double ln = longest_positive(-x);
	loop(i,0,n) a[i] *= -1;
	return max(lp, ln);
}

double search() {
	double s = 10000;
	loop(i,0,n) s=min(s,a[i]);
	double e = -10000;
	loop(i,0,n) e=max(e,a[i]);
	loop(t,0,100) {
		double x1 = (2.0*s+e)/3.0;
		double x2 = (s+2.0*e)/3.0;
		//ps(s);ps(x1);ps(x2);pln(e);
		//ps(forx(s));ps(forx(x1));ps(forx(x2));pln(forx(e));
		//entr;
		double y1 = forx(x1);
		double y2 = forx(x2);
		if(y1>y2) {
			s=x1;
		} else {
			e=x2;
		}
	}
	return forx(e);
}

int main(){
	ios_base::sync_with_stdio(0);
	cin>>n;
	loop(i,0,n) cin>>a[i];
	cout<<fixed<<setprecision(7)<<search()<<endl;
}
