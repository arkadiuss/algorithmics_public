#include<bits/stdc++.h>
#define VAR(i,n) __typeof(n) i = (n)
#define loop(i,j,n) for(int i=j;i<n;i++)
#define loopback(i,n,j) for(int i=n;i>=j;i--)
#define foreach(i,n) for(VAR(i,c.begin());i!=c.end();i++)
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
const int MAX=510;
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
int n;
int r[MAX];
bool was[MAX*MAX];
int main(){
	ios_base::sync_with_stdio(0);
	cin>>n;
	int a,b;
	loop(i,0,n){
		cin>>a>>b;
		r[i]=abs(a-b);
	}
	was[0]=1;
	int maxS=0;
	loop(i,0,n){
		loopback(j,maxS+1,0){
			if(was[j]&&j+r[i]<MAX*MAX){
				was[r[i]+j]=1;
				maxS=max(maxS,r[i]+j);
			}
		}
	}
	int bestR=maxS;
	loop(i,0,maxS+1){
		if(was[i]){
			bestR=min(bestR,abs((maxS-i)-i));
		}
	}
	pln(bestR);
}
