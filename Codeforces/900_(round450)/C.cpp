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
const int MAX=100100;
const int MOD=10000000;

void coutTab(int* tab,int n){
	loop(i,0,n){
		cout<<tab[i]<<" ";
	}
	cout<<"\n";
}
//------------------------------------------
set<int> was;
int n;
int howMany[MAX];
bool wasBest[MAX];
int main(){
	ios_base::sync_with_stdio(0);
	cin>>n;
	int a;
	int S=0;
	int maxa=0;
	loop(i,0,n){
		cin>>a;
		VAR(it,was.upper_bound(a));
		if(it==was.end()){ 
			S++;
			wasBest[a]=1;
		}else if ((*it)==maxa) howMany[(*it)]++;
		was.insert(a);
		maxa=max(maxa,a);
	}
	//wasBest[1]=0;
	loop(i,1,n+1){
		if(wasBest[i]) howMany[i]+=(S-1);
		else howMany[i]+=S;
	}
	//coutTab(howMany,n+1);
	int br=1;
	int maxadded=howMany[1];
	loop(i,2,n+1){
		if(howMany[i]>maxadded){
			br=i;
			maxadded=howMany[i];
		}
	}
	pln(br);
}
