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
const int MAX=500;
const ll MOD=1000000009;

void coutTab(int* tab,int n){
	loop(i,0,n){
		cout<<tab[i]<<" ";
	}
	cout<<"\n";
}
//------------------------------------------
ll P = 31;
ll P2 = 37;
int n;
ll hsh(string s){
	ll hsh = 0;
	loop(i,0,s.size()){
		hsh = ((hsh*P)%MOD + s[i])%MOD;
	}
	return hsh;
}
ll pref[MAX];
ll pwrs[MAX];
void countPwrs(){
	pwrs[0]=1;
	loop(i,1,n){
		pwrs[i]=(pwrs[i-1]*P2)%MOD;
	}
}
ll getPref(int i,int j){
	if(i==0) return pref[j];
	ll h = pref[j]-(pref[i-1]*pwrs[j-i+1])%MOD;
	if(h<0) h+=MOD;
	return h;
}
string w[MAX];
ll h[MAX];
ll solve(){
	loop(i,0,n) h[i]=hsh(w[i]);
	pref[0]=h[0];
	loop(i,1,n) pref[i]=((pref[i-1]*P2)%MOD+h[i])%MOD;
	int best=0;	
	loop(i,0,n){
		loop(j,i,n){
			int l = j-i;
			int len=0;
			loop(k,i,j+1) len+=w[k].size();
			len+=j-i;
			int k=0;
			int c=0;
			while(k+l<n){
			
				if(k+l>=i&&k<=j) k=j+1;
				else{
					if(getPref(i,j)==getPref(k,k+l)){
						c++;
						k=k+l;
					}
					k++;
				}
			}
			
			if(c>0){
				best=max(best,(c+1)*(len-(j-i+1)));
			}
		}
	}
	return best;
}
int main(){
	ios_base::sync_with_stdio(0);
	cin>>n;
	int len=0;
	loop(i,0,n){ 
		cin>>w[i];
		len+=w[i].size();
	}
	len+=n-1;
	countPwrs();
	pln(len - solve());
}
