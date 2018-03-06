#include<bits/stdc++.h>
#define VAR(i,n) __typeof(n) i = (n)
#define loop(i,j,n) for(int i=j;i<n;i++)
#define loopback(i,n,j) for(int i=n;i>=j;i--)
#define foreach(i,c) for(VAR(i,c.begin());i!=c.end();i++)
#define ALL(c) c.begin(), c.end()
#define SIZE(c) c.size()
#define ps(v) cout<<v<<" "
#define pln(v) cout<<v<<"\n"
#define entr cout<<"\n"
#define ll long long
#define pb push_back
#define ff first
#define ss second
using namespace std;
const int MAX=1000100;
const int MOD=1000000000;
const int INFTY=1000000000;
typedef vector<int> VI;

void coutTab(int * tab, int n){
	loop(i,0,n){
		ps(tab[i]);
	}
	entr;
}
//---------------------------------
int n,k;
int a[MAX];
int hm[MAX];
int maxD=1,maxDK=1,maxSD;
int hmia[MAX];
bool was[MAX];
bool prime[MAX];
void sieve(){
	prime[0]=prime[1]=0;
	loop(i,2,MAX){
		prime[i]=1;
	}
	loop(i,2,MAX){
		if(prime[i]){
			int j=2*i;
			while(j<MAX){
				prime[j]=0;
				j=j+i;
			}
		}
	}
}
void fact(int n){
	if(prime[n]){
		hm[1]+=hmia[n];
		hm[n]+=hmia[n];
		if(hm[n]>=k) maxDK=max(maxDK,n);
		return;
	}
	int chc=maxSD;
	if(sqrt(n)<chc) chc=sqrt(n);
	for(int d=1;d<=chc;d++){
		if(n%d==0){
			hm[d]+=hmia[n];
			if(hm[d]>=k) maxDK=max(maxDK,d);
			hm[n/d]+=hmia[n];
			if(hm[n/d]>=k) maxDK=max(maxDK,n/d);
			maxD=max(maxD,max(d,n/d));
		}	
	}
}
bool toSort(int a,int b){
	return a>b;
}
int gcd(int a, int b){
	if(a<b)
		swap(a,b);
	if(b==0) return a;	
	return gcd(b,a%b);
}
int readInt () {
	bool minus = false;
	int result = 0;
	char ch;
	ch = getchar();
	while (true) {
		if (ch == '-') break;
		if (ch >= '0' && ch <= '9') break;
		ch = getchar();
	}
	if (ch == '-') minus = true; else result = ch-'0';
	while (true) {
		ch = getchar();
		if (ch < '0' || ch > '9') break;
		result = result*10 + (ch - '0');
	}
	if (minus)
		return -result;
	else
		return result;
}
int main(){
	ios_base::sync_with_stdio(0);
	n=readInt();
	k=readInt();
	loop(i,0,n){ 
		a[i]=readInt();
		hmia[a[i]]++;
	}
	if(k==1){
		int maxk=0;
		loop(i,0,n) maxk=max(maxk,a[i]);
		pln(maxk); return 0;
	}else if(k==n){
		int agcd=a[0];
		loop(i,1,n) agcd=gcd(a[i],agcd);
		pln(agcd);
		return 0;
	}
	sort(a,a+n,toSort);
	sieve();
	maxSD=a[k-1];
	loop(i,0,n){
		if(a[i]<maxDK) break; 
		if(!was[a[i]]) fact(a[i]);
		was[a[i]]=1;
	}
	pln(maxDK);
}
