#include<bits/stdc++.h>
#define VAR(i,n) __typeof(n) i = (n)
#define loop(i,j,n) for(int i=j;i<n;i++)
#define loopback(i,n,j) for(int i=n;i>=j;i--)
#define foreach(i,c) for(VAR(i,(c).begin());i!=(c).end();i++)
#define SIZE(c) (c).size()
#define ALL(c) (c).begin(), (c).end()
#define pb push_back
#define mp make_pair
#define ps(v) cout<<v<<" "
#define pln(v) cout<<v<<"\n"
#define entr cout<<"\n"
#define ll long long
using namespace std;
typedef vector<int> VI;

const int MAX=1000100;
const int INFTY=100000000;

void coutTab(int* tab, int n){
	loop(i,0,n){
		ps(tab[i]);
	}
	entr;
}

//------------------------------
bool was[MAX];
bool marked[MAX];
int startPos[MAX];
int maxMarked;
vector<ll> bought;
int n,m;
int main(){
	ios_base::sync_with_stdio(0);
	cin>>m;
	int a;
	loop(i,0,m){
		cin>>a;
		marked[a]=1;
		maxMarked=max(maxMarked,a);
	}
	loop(i,0,maxMarked+1){
		startPos[i]=i;
	}
	cin>>n;
	ll nr=0;
	loop(i,0,n){
		cin>>a;
		int j=startPos[a];
		ll k=0;
		while(k<a&&j<=maxMarked){
			if(!was[j]){
				k++;
				if(marked[j]) bought.pb(nr+k);	
				was[j]=1;
			}
			j=j+a;
		}
		startPos[a]=j;
		nr=nr+a;
	}
	pln(bought.size());
	foreach(it,bought){
		pln((*it));
	}
}
