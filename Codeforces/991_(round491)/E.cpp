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
const int MAX=19;
const int MOD=10000000;

void coutTab(int* tab,int n){
	loop(i,0,n){
		cout<<tab[i]<<" ";
	}
	cout<<"\n";
}
//------------------------------------------
void count(ll a,int * c){
	loop(i,0,10) c[i]=0;
	while(a>0){
		c[a%10]++;
		a/=10;
	}
}

bool check(int * c,int * c2){
	loop(i,0,10){
		if(c[i]>0&&c2[i]==0) return false;
	}
	return true;
}

int nums(ll n){
	int c=0;
	while(n>0){
		c++;
		n/=10;
	}
	return c;
}

ll getSorted(ll a){
	int c[10];
	count(a,c);
	ll res=0;
	loopback(i,9,0){
		while(c[i]--){
			res=res*10+i;
		}
	}
	return res;
}
ll fact(int n){
	ll r = 1;
	for(ll i=2;i<=n;i++) r*=i;
	return r;
}
ll rev(ll n){
	ll res=0;
	while(n>0){
		res=res*10+n%10;
		n/=10;
	}
	return res;
}
ll gen(int * c,ll n){
	set<int> was;
	int nms = nums(n);
	int c2[10];
	ll res=0;
	loop(mask,0,1<<nms){
		ll a=0;
		ll cn=rev(n);
		loopback(j,nms-1,0){
			if(1<<j&mask){
				a=a*10+cn%10;
			}
			cn/=10;
		}
		count(a,c2);
		ll s = getSorted(a);
		if(check(c,c2)&&was.find(s)==was.end()){
			was.insert(s);
			int tnms = nums(a);
			ll all = fact(tnms);
			loop(i,0,10){
				if(c2[i]>0){
					all/=fact(c2[i]);
				}
			}
			if(c2[0]>0){
				ll all0 = fact(tnms-1)/fact(c2[0]-1);
				loop(i,1,10){
					if(c2[i]>0) all0/=fact(c2[i]);
				}
				all-=all0;
			}
			res+=all;
		}
	}
	return res;
}

int main(){
	ll n;
	cin>>n;
	int c[10];
	count(n,c);
	pln(gen(c,n));
}
