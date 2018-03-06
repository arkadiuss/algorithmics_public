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
typedef pair<int,int> PLL;
const int INFTY=20000000;
const int MAX=200100;
const int MOD=10000000;

void coutTab(int* tab,int n){
	loop(i,0,n){
		cout<<tab[i]<<" ";
	}
	cout<<"\n";
}
//------------------------------------------
int n;
PLL vs[MAX];
int vcs[4],bvcs[4];
int main(){
	ios_base::sync_with_stdio(0);
	cin>>n;
	loop(i,0,n){
		cin>>vs[i].ff>>vs[i].ss;
	}
	int maxlen=0;
	for(int mask=0;mask<(1<<n);mask++){
		PLL vec;
		vec.ff=0;
		vec.ss=0;
		loop(i,0,4) vcs[i]=0;
		loop(i,0,n){
			if(mask&(1<<i)){
				vec.ff=vec.ff+vs[i].ff;
				vec.ss=vec.ss+vs[i].ss;
				if(vs[i].ff>0&&vs[i].ss>0) vcs[0]++;
				if(vs[i].ff<0&&vs[i].ss>0) vcs[1]++;
				if(vs[i].ff<0&&vs[i].ss<0) vcs[2]++;
				if(vs[i].ff>0&&vs[i].ss<0) vcs[3]++;	
			}
		}
		/*char a[1000];
		sprintf(a,"echo %d%d%d%d %d %d-%d",vcs[0],vcs[1],vcs[2],vcs[3],(vec.ff*vec.ff+vec.ss*vec.ss),vec.ff,vec.ss);
		system(a);*/
		if(vec.ff*vec.ff+vec.ss*vec.ss>maxlen) loop(i,0,4) bvcs[i]=vcs[i];
		maxlen=max(maxlen, vec.ff*vec.ff+vec.ss*vec.ss);
	}	
	pln(maxlen);
	/*char a[1000];
	sprintf(a,"echo %d%d%d%d",bvcs[0],bvcs[1],bvcs[2],bvcs[3]);
	system(a);
	sprintf(a,"echo %d%d%d%d",vcs[0],vcs[1],vcs[2],vcs[3]);
	system(a);*/
}
