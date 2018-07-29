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
	int n,k;
	cin>>n>>k;
	string s;
	cin>>s;
	sort(ALL(s));
	string res="";
	res.pb(s[0]);
	//pln(s);
	int sum=s[0]-'a'+1;
	int j=1;
	loop(i,1,n){
		//pln(s[i]-res[res.size()-1]);
		if(s[i]-res[res.size()-1]>=2&&j<k){
			res.pb(s[i]);
			//ps(s[i]);pln(s[i]-'a'+1);
			sum+=s[i]-'a'+1;
			j++;
		}
	}
	//ps(j);pln(res);
	if(j<k) pln(-1);
	else pln(sum);
}
