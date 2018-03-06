#include<bits/stdc++.h>
#define loop(i,j,s) for(int i=j;i<s;i++)
#define loopback(i,j,s) for(int i=j;i>=s;i--)
#define pln( x ) cout << x << "\n"
#define ps( x ) cout << x << " "
#define entr cout << "\n" 
#define pcnt(i) __builtin_popcount(i)
#define ll long long
using namespace std;
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
string pi,s;
bool check(){
	loop(i,0,s.size()){
		if(s[i]!=pi[i])
			return false;
	}
	return true;
}

int main(){
	ios_base::sync_with_stdio(0);
	pi="141592653589793238462643383279502884197169399375105820974944592307816406286208998628034825342117067982148086513282306647093844609550582231725359408128481";
	int T;
	cin>>T;
	while(T--){
		cin>>s;
		if(check())
			cout<<"TAK";
		else
			cout<<"NIE";
		entr;		
	}
}
