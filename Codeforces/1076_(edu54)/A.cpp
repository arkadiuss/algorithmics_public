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
/*bool lw(string & a, string & b){
	int i=0,j=0;
	while(i<a.size()&&j<b.size()&&a[i]==b[j]){
		i++;j++;
	}
	if(i==a.size()) return a;
	else if(j==b.size()) return b;
	else if(a[i]<b[j]) return a;
	return b;
}*/
int main(){
	ios_base::sync_with_stdio(0);
	int n;
	cin>>n;
	string s;
	cin>>s;
	int pos=n-1;
	if(n==1) pln(s);
	else{
		loop(i,1,SIZE(s)){
			if(s[i-1]>s[i]){
				pos=i-1;
				break;
			}
		}
		s.erase(pos,1);
		pln(s);
	}
}
