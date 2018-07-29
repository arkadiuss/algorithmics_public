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
const int MAX=500100;
const int MOD=10000000;

void coutTab(int* tab,int n){
	loop(i,0,n){
		cout<<tab[i]<<" ";
	}
	cout<<"\n";
}
//------------------------------------------
int getD(int a){
	int i=0;
	while(a>1){
		i++;
		a/=2;
	}
	return i;
}
int d[MAX];
int hm[50];
int ans(int a){
	int r[50];
	loop(i,0,40) r[i]=0;
	int i=0;
	while(a>0){
		r[i]=a%2;
		i++;
		a/=2;
	}
	loopback(i,40-1,0){
		if(r[i]>hm[i]){
			if(i==0) return -1;
			r[i-1]+=2*(r[i]-hm[i]);
			r[i]=hm[i];
		}
	}
	int s=0;
	loop(i,0,40){
		//ps(r[i]);
		s+=r[i];
	}
	//entr;
	return s;
}
int main(){
	ios_base::sync_with_stdio(0);
	int n,q,a;
	cin>>n>>q;
	loop(i,0,n){
		cin>>a;
		d[i]=getD(a);
	}
	loop(i,0,n){
		hm[d[i]]++;
	}
	while(q--){
		cin>>a;
		pln(ans(a));
	}
}
