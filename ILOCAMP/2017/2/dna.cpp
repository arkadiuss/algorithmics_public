#include<bits/stdc++.h>
#define VAR(i,n) __typeof(n) i = (n)
#define loop(i,j,n) for(int i=j;i<n;i++)
#define loopback(i,n,j) for(int i=n;i>=j;i--)
#define foreach(i,c) for(VAR(i,c.begin());i!=c.end();i++)
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
const int MAX=1000100;
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
int main(){
	ios_base::sync_with_stdio(0);
	int t,c;
	cin>>t;
	string od="W";
	string nw;
	loop(i,0,t){
		loop(i,0,od.size()){
			if(od[i]=='W'){
				nw.pb('G');nw.pb('W');
			}else{
				nw.pb('W');nw.pb('G');
			}
		}
		c=0;
		loop(i,1,nw.size()){
			if(nw[i-1]=='G'&&nw[i]=='G')
				c++;
		}
		ps(c);ps(2*c-1);pln(2*c+1);
		od=nw;
		nw="";
	}
}
