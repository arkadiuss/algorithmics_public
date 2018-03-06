#include<bits/stdc++.h>
#define loop(i,j,n) for(int i=j;i<n;i++)
#define loopback(i,n,j) for(int i=n;i>=j;i--)
#define VAR(i,c) __typeof(c) i=(c)
#define foreach(it,c) for(VAR(it,c.begin());it!=c.end();it++)
#define SIZE(c) c.size()
#define ALL(c) c.begin(), c.end()
#define ps(v) cout<<v<<" "
#define pln(v) cout<<v<<"\n"
#define entr cout<<"\n"
#define ll long long
#define pb push_back
using namespace std;
typedef pair<int,int> PII;
typedef vector<int> VI;

const int MAX=100014;
int n,k;
int hm[MAX];
int g;

void addbrute(int a,int l, int d){
	for(int j=a-1;j<=a-1+(l-1)*d;j+=d){
		hm[j]++;
	}
}

int am[MAX][290];
void solve(){
	
	
	/*loop(i,0,n){
		ps(hm[i]);
	}entr;*/
	loop(i,1,g+1){
		loop(j,0,i){
			int s=0;
			for(int k=j;k<n;k=k+i){
				s+=am[k][i];
				hm[k]+=s;
				//if(k==n-1) ps("tak");
			}
		}
		
	}
	loop(i,0,n){
		ps(hm[i]);
	}
	//pln(g);
}
int main(){
	ios_base::sync_with_stdio(0);
	int k;
	cin>>n>>k;
	int sq=ceil(sqrt(n));
	g=min(288,sq);
	//pln(g);
	int a,l,d;
	loop(i,0,n){
		loop(j,0,g+1){
			am[i][j]=0;
		}
	}
	loop(i,0,k){
		cin>>a>>l>>d;
		if(d<g){
			am[a-1][d]++;
			int pos=a-1+(l)*d;
			if(pos<n){
				am[pos][d]--;
			}
		}else{
			//pln("brute");
			addbrute(a,l,d);
		}
	}
	solve();
	return 0;
}

