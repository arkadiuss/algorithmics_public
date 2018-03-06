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
const int MAX=24;
const int MOD=10000000;

void coutTab(int* tab,int n){
	loop(i,0,n){
		cout<<tab[i]<<" ";
	}
	cout<<"\n";
}
//------------------------------------------
ll a[MAX],b[MAX];
bool was[MAX];
int n;
bool can(int p){
	if(p==0) return 1;
	int N=(1<<p);
	if(p==n-1) N--;
	for(int mask=0;mask<N;mask++){
		int mask2=mask;
		//pln(mask2);
		ll Sa=a[p];
		ll Sb=b[p];
		loop(j,0,p){
			if(1<<j&mask2){
				Sa+=a[j];
				Sb+=b[j];
			}
		}
		//ps(Sa);pln(Sb);
		if(Sa==Sb) return 0;
	}
	return 1;
}
bool gen(int p){
	//pln(p);
	if(p==n) return 1;
	loop(i,0,n){
		if(!was[i]&&p!=i){
			b[p]=a[i];
			was[i]=1;
			//loop(j,0,n){
			//	ps(b[j]);
			//}
			//entr;
			if(can(p)){
				if(gen(p+1)) return 1;
			} 
			was[i]=0;
		}
	}
	return 0;
}
int main(){
	ios_base::sync_with_stdio(0);
	cin>>n;
	loop(i,0,n) cin>>a[i];
	if(n==1||gen(0)){
		if(n==1) b[0]=a[0];
		loop(i,0,n){
			ps(b[i]);
		}
		entr;
	}else{
		pln("-1");
	}
}
