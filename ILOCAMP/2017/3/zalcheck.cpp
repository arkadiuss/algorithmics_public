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
bool was[MAX];
int main(){
	int n;
	cin>>n;
	loop(i,0,n){
		char* s;
		sprintf(s,"echo %d | ./zg > in",(i+232));
		system(s);
		system("./z < in > pout");
		system("./z3 < in > bout");
		if(system("diff pout bout")){
			pln("wrong");
			return 0;
		}else{
			
			pln("ok");//system("head -1 pout");
		}
	}
}
