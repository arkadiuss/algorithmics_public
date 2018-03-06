#include<bits/stdc++.h>
#define loop(i,j,n) for(int i=j;i<n;i++)
#define ll long long
#define VAR(i,n) __typeof(n) i = (n)
#define foreach(i,c) for(VAR(i,c.begin());i!=c.end();i++)
#define pb push_back
#define ff first
#define ss second
#define mp make_pair
#define SIZE(c) c.size()
#define ps(v) cout<<v<<" "
#define pln(v) cout<<v<<"\n"
#define entr cout<<"\n"

using namespace std;
typedef vector<int> VI;
const int MAX=1000010;
//------------------

int sum(ll p){
	if(p==0) return 0;
	else return sum(p/10)+p%10;
}
int fact(ll n){
	int hm2=0,hm5=0;
	while(n%2==0){ 
		n=n/2;
		hm2++;
	}
	while(n%5==0){ 
		n=n/5;
		hm5++;
	}
	if(n!=1) return -1;
	else return max(hm2,hm5);
}
int main(){
	ios_base::sync_with_stdio(0);
	int s,m,q;
	cin>>s>>m>>q;
	ll k;
	int l;
	int ki=fact(m);
	//pln(ki);
	loop(i,0,q){
		cin>>k;
		if(s==1){
			if(ki<0&&k>200||ki+k>200){
				pln("NIE");
				continue;
			}
			cout<<1;
			loop(j,0,ki)
				cout<<0;
			loop(j,0,k-1)
				cout<<0;	
		}else if(k>100000000LL){
			pln("NIE");
		}else{
			int j=m;
			l=0;
			while(l<k){
				if(sum(j)==s){
					l++;
				}	
				//entr;
				j+=m;
			}
			pln(j-m);
		}	
	}
	return 0;
}
