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
int MAX_VAL=0;
int n;
int a[MAX];
VI divs[2000000];
void sieve(){
	loop(i,2,MAX_VAL+1){
		divs[i].pb(i);
		reverse(ALL(divs[i]));
		int j=2*i;
		while(j<=MAX_VAL){
			divs[j].pb(i);
			j+=i;
		}
	}
}
/*int F(int a){ //Sprague-Grundem function
	bool all=true;
	loop(i,0,SIZE(divs[a])){
		if(divs[a][i]%2==0) all=false;
	}
	if(all) return 0;
	
	int last=0;
	loop(i,0,SIZE(divs[a])){
		if(divs[a][i]%2==0) return last+1;
		if(a/divs[a][i]!=last+1) return last+1;
		else last++;
	}
	return last+1;
	if(a==1) return 0;
	if(a==2) return 1;
	int x=0;
	loop(i,0,SIZE(divs[a])){
		if(divs[a][i]%2==1) x=x xor F(a/divs[a][i]);
	}
	return x;
}*/
int F[2000000];
int main(){
	ios_base::sync_with_stdio(0);
	cin>>n;
	loop(i,0,n){ 
		cin>>a[i];
		MAX_VAL=max(MAX_VAL,a[i]);
	}
	sieve();
	F[1]=0;
	F[2]=1;
	bool was[20];
	loop(i,3,MAX_VAL+1){
		loop(j,0,MAX_VAL+1) was[j]=0;
		loop(j,0,SIZE(divs[i])){
			if(divs[i][j]%2==1){
				//cout<<divs[i][j]<<":"<<F[i/divs[i][j]]<<" ";
				was[F[i/divs[i][j]]]=true;
			}else{ 
				//cout<<divs[i][j]<<":"<<0<<" ";
				was[0]=true;
			}
		}
		F[i]=MAX_VAL+1;
		loop(j,0,MAX_VAL+1) if(!was[j]){ F[i]=j; break;}
		//ps("wyn");ps(F[i]);
		//entr;
	}
	int x=0;
	loop(i,0,n){
		x=x xor F[a[i]];
	}
	if(x==0) pln(":(");
	else pln(":)");
}
