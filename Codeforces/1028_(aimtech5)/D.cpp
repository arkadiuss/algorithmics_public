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
	set<ll> s2,sr;
	set<ll,std::greater<ll> > s1;
	string s;
	ll p;
	ll res = 1;
	loop(i,0,n){
		cin>>s>>p;
		if(s=="ADD"){
			if(s2.begin()!=s2.end()&&p>*s2.begin())
				s2.insert(p);
			else if(s1.begin()!=s1.end()&&p<*s1.begin())
				s1.insert(p);
			else	
				sr.insert(p);
		}else{
			auto it = sr.lower_bound(p);
			
			if(it!=sr.end()){
				while(!sr.empty()){
					if(*sr.begin()<*it)
						s1.insert(*sr.begin());
					else if(*sr.begin()>*it)
						s2.insert(*sr.begin());
					sr.erase(sr.begin());		
				}
				res = (2*res)%MOD;
			}else{
				if(p==*s1.begin()){
					s1.erase(s1.begin());
				}else if(p==*s2.begin()){
					s2.erase(s2.begin());
				}else{
					res=0;
					break;
				}
			}
		}
	}
	res = (res * (sr.size()+1))%MOD;
	pln(res);
}
