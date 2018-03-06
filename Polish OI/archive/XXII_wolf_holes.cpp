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
const int MAX=2000100;
const int MOD=10000000;

void coutTab(int* tab,int n){
	loop(i,0,n){
		cout<<tab[i]<<" ";
	}
	cout<<"\n";
}
//------------------------------------------
int n,d;
ll p;
ll w[MAX],pref[MAX],x[MAX];
struct elQ{
	ll v;
	int counter; //value, counter
};
deque<elQ> Q;
elQ me(ll v, int counter){
	elQ e;
	e.v=v;
	e.counter=counter;
	return e;
}
//sum from range
ll sum(int a,int b){
	if(a==0) return pref[b];
	else return pref[b]-pref[a-1];
}
//Q controller
int s=0,e=0; //start and end of range
void add(ll a){
	int counter=1;
	while(!Q.empty()&&a>Q.back().v){
		counter+=Q.back().counter;
		Q.pop_back();
	}
	Q.push_back(me(a,counter));
}
void remove(){
	if(!Q.empty()){
		Q.front().counter--;
		if(Q.front().counter==0) Q.pop_front();
	}
}
ll getMax(int a, int b){
	while(s<a){ 
		remove();
		s++;
	}
	while(e<b) add(x[++e]);
	return Q.front().v;
}
int main(){
	ios_base::sync_with_stdio(0);
	cin>>n>>p>>d;
	loop(i,0,n) cin>>w[i];
	//prefixes
	pref[0]=w[0];
	loop(i,1,n) pref[i]=pref[i-1]+w[i];
	//count x
	loop(i,d-1,n) x[i]=sum(i-d+1,i);
	int j=d-1;
	add(x[j]);
	s=j;e=j;
	int maxLen=0;
	loop(i,0,n-d+1){
		while(j<n-1&&sum(i,j+1)-getMax(i+d-1,j+1)<=p){ 
			j++;
		}
		maxLen=max(j-i+1,maxLen);
	}
	pln(maxLen);
}
