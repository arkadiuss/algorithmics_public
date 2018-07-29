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
const int MAX=1000001;
const ll MOD=1000000007;

void coutTab(int* tab,int n){
	loop(i,0,n){
		cout<<tab[i]<<" ";
	}
	cout<<"\n";
}
//------------------------------------------
int sieve[MAX];
bool onlyOne[MAX];
int * f[30];
int qi[MAX];
int diff[MAX];
int pwr2[30];
int * division[MAX];
void countSieve(int n){
	
	loop(i,2,n+1){
		sieve[i]=-1;
		onlyOne[i]=true;
	}
	loop(i,2,n+1){
		if(sieve[i]==-1){
			sieve[i]=i;
			ll j=i;
			j=2*i;
			while(j<=n){
				if(sieve[j]!=-1) onlyOne[j]=false;
				else sieve[j]=i;
				j+=i;
			}
		}
	}
}
int F(int n,int r){
	//ps(n);pln(r);
	if(n==1) return 1;
	
	if(n/sieve[n]==1) return r+2;
	if(onlyOne[n]) return f[qi[n]][r];
	if(r==0) return pwr2[diff[n]];
	ll res=1;
	//ps(diff[n]);
	loop(i,0,diff[n]){
		//pln(division[n][i]);
		res=(res*F(pwr2[division[n][i]],r))%MOD;
	}
	return res;
}
void prepare(){
	pwr2[0]=1;
	loop(i,1,20){
		pwr2[i]=2*pwr2[i-1];
	}
	loop(i,2,MAX){
		if(onlyOne[i]){
			int j=0;
			int k=i;
			while(k>1){
				j++;
				k/=sieve[k];
			}
			qi[i]=j;
		}
	}
	VI divs;
	loop(i,2,MAX){
		int j=0;
		int k=i;
		while(k>1){
			int l=1;
			int m=0;
			while(k%(l*sieve[k])==0){
				l*=sieve[k];
				m++;
			}
			divs.pb(m);
			k/=l;
			j++;
		}
		diff[i]=j;
		division[i]=new int[j];
		loop(l,0,j){
			division[i][l]=divs[l];
		}
		divs.clear();
	}
	int b=4;
	loop(i,2,20){
		f[i]=new int[MAX+2];
		f[i][0]=2;
		loop(k,1,MAX){
			f[i][k]=(F(b/2,k)+F(b,k-1))%MOD;
		}
		b*=2;
		
	}
}

int main(){
	//ios_base::sync_with_stdio(0);
	countSieve(MAX);
	prepare();
	//pln("end");
	
	/*loop(i,2,5){
		ps(i);ps(":");
		loop(j,0,4){
			ps(f[i][j]);
		}
		entr;
	}*/
	int q,n,r;
	scanf("%d",&q);
	while(q--){
		scanf("%d",&r);
		scanf("%d",&n);
		pln(F(n,r));
	}
}
