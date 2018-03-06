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
#define lastS S[SIZE(S)-1]
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
struct gr{ //group
	ll d;
	int a;
};
ll k;
gr mg(int a, ll d){
	gr g;
	g.a=a;
	g.d=d;
	return g;
}
vector<gr> S;
void add(int a){
	if(!S.empty()&&lastS.a==a){
		lastS.d++;
	}else{
		S.pb(mg(a,1));
	}
	while(!S.empty()&&lastS.d>=k){
		lastS.d-=k;
		if(lastS.d==0) S.pop_back();
	}
}
ll getSum(){
	ll s=0;
	loop(i,0,SIZE(S)){
		s+=S[i].d;
	}
	return s;
}
int main(){
	ios_base::sync_with_stdio(0);
	int n,m;
	cin>>n>>k>>m;
	int a;
	loop(i,0,n){
		cin>>a;
		add(a);
	}
	/*loop(i,0,SIZE(S)){
		ps(S[i].a);pln(S[i].d);
	}
	entr;*/
	int p=0;
	ll sum=getSum();
	while(p<SIZE(S)/2&&S[p].a==S[SIZE(S)-1-p].a&&S[p].d+S[SIZE(S)-1-p].d==k){
		p++;
	}
	p--;
	//pln(p);
	if(SIZE(S)%2==0&&p==SIZE(S)/2-1){
		if(m%2==0) pln(0);
		else pln(sum);
	}else if(SIZE(S)==1){
		pln((m*S[0].d)%k);
	}else if((SIZE(S)%2==1&&p==SIZE(S)/2-1)){
		//pln("jup");
		if((m*S[p+1].d)%k==0) pln(0);
		else pln(sum-S[p+1].d+(m*S[p+1].d)%k);
	}else{
		
		ll toRem=0;
		p=0;
		while(p<SIZE(S)/2&&S[p].a==S[SIZE(S)-1-p].a&&(S[p].d+S[SIZE(S)-1-p].d)==k){
			toRem+=k;
			p++;
		}
		//pln(p);
		if(S[p].a==S[SIZE(S)-1-p].a&&S[p].d+S[SIZE(S)-1-p].d>=k) 
			toRem+=((S[p].d+S[SIZE(S)-1-p].d)/k)*k;
		//pln(toRem);	
		pln(m*sum-toRem*(m-1));
		
	}
}
