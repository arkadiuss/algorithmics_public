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
const int INFTY=20000000;
const int MAX=1100;
const int MOD=10000000;

void coutTab(int* tab,int n){
	loop(i,0,n){
		cout<<tab[i]<<" ";
	}
	cout<<"\n";
}
//------------------------------------------
int a[MAX],b[MAX];
int n,m;
bool check(double f){
	double mass = m + f;
	loop(i,0,n){
		double u = mass/a[i];
		f -= u;
		mass -= u;
		if(f<0) return false;
		if(i==n-1){
			u=mass/b[0];
		}else{
			u=mass/b[i+1];
		}
		f-=u;
		mass -=u;
		if(f<0) return false;
		//ps(f);
	}
	return true;
}
double findRes(){
	double s=0,e=1000000000;
	while(abs(s-e)>1e-6){
		double m = (s+e)/2.0;
		//ps(m);pln(check(m));
		if(check(m)){
			e=m;
		}else{
			s=m;
		}
	}
	return e;
}
int main(){
	ios_base::sync_with_stdio(0);
	cin>>n>>m;
	loop(i,0,n) cin>>a[i];
	loop(i,0,n) cin>>b[i];
	double res = findRes();
	//pln(res);
	if(check(res)) cout<<fixed<<setprecision(6)<<findRes()<<"\n";
	else pln(-1);	
}
