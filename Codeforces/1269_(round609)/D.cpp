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
ll dp[MAX];
ll a[MAX];
int n;
set<int> f;
int main(){
	ios_base::sync_with_stdio(0);
	cin>>n;
	loop(i,0,n) cin>>a[i];	
	dp[0]=a[0]-a[0]%2;
	if(n>=2) {
		int j=1;
		if(a[j-1]%2 == a[j]%2){
			dp[j] = a[j-1]+a[j];
		} else if(a[j-1]%2==0) {
			f.insert(0);
			dp[j]=a[j-1]+a[j]-1;
		} else if(a[j]%2==0) {
			f.insert(1);
			dp[j]=a[j-1]+a[j]-1;
		}
	}
	//cout<<"mam"<<endl;
	loop(i,2,n) {
		ll dp1=dp[i-1];
		ll dp2=dp[i-2];
		int f2=-1;
		int sf=0; 
		//-----
		int j=i;
		if(a[j-1]%2 == a[j]%2){
			dp2 += a[j-1]+a[j];
		} else if(a[j-1]%2==0) {
			f2=0;
			sf=1;
			dp2 += a[j-1]+a[j]-1;
		} else if(a[j]%2==0) {
			f2=1;
			sf=1;
			dp2 += a[j-1]+a[j]-1;
		}
		//-----
		int p=-1;
		set<int> nf;
		for(int j:f){
			if(j<a[i]) {
				int r = j-p-1;
				dp1 += r - (r%2) + 2;
				if(r%2!=0) {
					nf.insert(p+1);
				}
				p=j;		
			} else {
				break;
			}
		}
		int r = a[i]-p-1;
		dp1 += r - (r%2);
		if(r%2!=0 && r!=0) {
			nf.insert(p+1);
		}
		//----
		f.clear();
		if(dp1 > dp2) {
			dp[i]=dp1;
			if(f2 != -1) f.insert(f2);
		} else if(dp2 > dp1) {
			dp[i]=dp2;
			for(auto fi:nf) f.insert(fi);
		} else {
			dp[i]=dp1;
			if(sf>nf.size()) {
				f.insert(f2);
			} else {
				for(auto fi:nf) f.insert(fi);
			}
		}
		nf.clear();
		//pln(dp[i]);
	}
	ll maxi = 0;
	loop(i,0,n) maxi=max(maxi,dp[i]);
	pln(maxi/2);	
}
