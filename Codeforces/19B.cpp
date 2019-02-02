#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i = a; i < b; ++i)
#define FORD(i,a,b) for(int i = a; i >= b; --i)
using namespace std;
#define ll long long

const int MAX = 2010;
const ll INFTY = 2* 1e17;
ll p[MAX];
ll c[MAX], t[MAX];
int main(){
	int n;
	cin>>n;
	FOR(i,0,n){
		cin>>t[i]>>c[i];
	}
	FOR(i,0,n+1) p[i]=INFTY;
	p[0]=0;
	ll forB=INFTY;		
	FOR(i,0,n){
		FORD(j,n,0){	
			if(p[j]!=INFTY&&j + t[i] + 1 <= n){
				p[j+t[i]+1]=min(p[j+t[i]+1],p[j]+c[i]);
			}else if(p[j]!=INFTY){
				forB = min(forB,p[j]+c[i]);
			}
		}	
	}
	cout<<min(p[n],forB)<<"\n";		
}
