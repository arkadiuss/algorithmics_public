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

int main(){
	ios_base::sync_with_stdio(0);
	int n;
	cin>>n;
	int from0=0,from1=1023;
	char c;
	int x;
	//pln((1023&241));
	loop(i,0,n){
		cin>>c>>x;
		if(c=='&'){
			from0=from0&x;
			from1=from1&x;
		}
		else if(c=='|'){
			from0=from0|x;
			from1=from1|x;
		}
		else if(c=='^'){
			from0=from0 xor x;
			from1=from1 xor x;
		}
	}
	int xors=0, ors=0, ands=1023;
	//ps(from0);
	//pln(from1);
	loop(i,0,10){
		//ps(i);ps(":");ps((from0&(1<<i)));pln((from1&(1<<i)));
		if((from0&(1<<i))!=0&&(from1&1<<i)!=0){
			ors=ors|(1<<i);
		}else if((from0&(1<<i))==0&&(from1&1<<i)!=0){
			//ors=ors|(1<<i);
		}else if((from0&(1<<i))!=0&&(from1&1<<i)==0){
			xors=xors|(1<<i);
		}else if((from0&(1<<i))==0&&(from1&1<<i)==0){
			ands=ands^(1<<i);
			//ps(ands);pln(ands);
		}
	}
	if(ands!=1023){
		pln(3);
	}else{
		pln(2);
	}
	if(ands!=1023){ ps("&");pln(ands);}
	ps("^");pln(xors);
	ps("|");pln(ors);

}
