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
const int MAX=4096;

const int MAX2=500100;
const int MOD=10000000;

void coutTab(int* tab,int n){
	loop(i,0,n){
		cout<<tab[i]<<" ";
	}
	cout<<"\n";
}
//------------------------------------------
int w[13];
int c[MAX];
int n;
int wupref[MAX][102];
int conv(string s){
	int res=0;
	int p=1;
	loopback(i,s.size()-1,0){
		res += (s[i]-'0')*p;
		p*=2;
	}
	return res;
}
int cwu(int a,int b){
	int res=0;
	loopback(i,n-1,0){
		if(a%2==b%2){
			res+=w[i];
		}
		a/=2;
		b/=2;
	}
	return res;
}

int main(){
	//ios_base::sync_with_stdio(0);
	int m,q;
	scanf("%d",&n);
	scanf("%d",&m);
	scanf("%d",&q);
	loop(i,0,n) scanf("%d",w+i);
	string s;
	char buf[13];
	loop(i,0,m){
		scanf("%s",buf);
		s=string(buf);
		c[conv(s)]++;
	}
	loop(i,0,1<<n){
		loop(j,0,1<<n){
			if(c[j]>0){
				int ccwu = cwu(i,j);
				if(ccwu<=100)
					wupref[i][ccwu]+=c[j];
			}
		}
		loop(j,1,101){
			wupref[i][j]+=wupref[i][j-1];
		}
	}
	//pln("endi");
	int k;
	while(q--){
		scanf("%s",buf);
		s=string(buf);
		scanf("%d",&k);
		int i = conv(s);
		printf("%d\n",wupref[i][k]);
	}
}
