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
const int MAX=500100;
const int MOD=10000000;



template<class T> void coutVec(vector<T> tab){
	for(T t : tab){
		cout<<t;
	}
	cout<<"\n";
}
//------------------------------------------
int a[MAX];
int b[MAX];
int n,k;
bool gte() {
	int i=0;
	while(i<n && a[i%k]==b[i]) i++;
	if(i>=n || a[i%k]>b[i]) return true;
	return false;
}

void coutTab(int* tab,int n){
	loop(i,0,n){
		cout<<tab[i%k];
	}
	cout<<"\n";
}

bool inc(int j) {
	loop(i,0,k) a[i]=b[i];
	int l=j;
	while(l>=0&&a[l]==9) {
		a[l]=0;	
		l--;
	}
	if(l>=0)
		a[l]++;
	else 
		return false;
	return true;
}

bool check(int j){
	if(!inc(j)){
		return true;
	}
	return gte();
}

int f() {
	int s=0;int e=k-1;
	while(s<e) {
		int m=(s+e+1)/2;
		//cout<<s<<m<<e<<endl;
		if(check(m)) {
			s=m;
		} else {
			e=m-1;
		}
	}
	return s;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin>>n>>k;
	loop(i,0,n) {
		char c;
		cin>>c;
		b[i]=(c-'0');
		a[i]=b[i%k];
	}
	if(gte()){
		pln(n);
		coutTab(a,n);
	} else {
		int i=f();
		inc(i);
		pln(n);		
		coutTab(a,n);
	}		
}
