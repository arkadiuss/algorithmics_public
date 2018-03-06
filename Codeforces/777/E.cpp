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

void coutTab(ll* tab,int n){
	loop(i,0,n){
		cout<<tab[i]<<" ";
	}
	cout<<"\n";
}
//------------------------------------------
struct el{
	ll a,b,h;
};
el me(ll a, ll b, ll h){
	el e;
	e.a=a;
	e.b=b;
	e.h=h;
	return e;
}
bool sortEls(el a, el b){
	if(a.b==b.b) return a.a>b.a;
	else return a.b>b.b; 
}
bool sortElsByA(el a, el b){
	return a.a<b.a;
}
bool sortElsByB(el a, el b){
	return a.b<b.b;
}
el els[MAX];
ll dp[MAX];
int n;
int D;
ll tree[4*MAX];
void renumber(){
	vector<ll> nums;
	loop(i,0,n){
		nums.pb(els[i].a);
		nums.pb(els[i].b);
	}
	sort(ALL(nums));
	nums.erase(unique(ALL(nums)),nums.end());
	sort(els,els+n,sortElsByA);
	int  j=0;
	loop(i,0,n){
		while(nums[j]<els[i].a) j++;
		els[i].a=j+1;
	}
	sort(els,els+n,sortElsByB);
	j=0;
	loop(i,0,n){
		while(nums[j]<els[i].b) j++;
		els[i].b=j+1;
	}
}
void countD(){
	D=1;
	while(D<=els[0].b) D*=2;
}
void update(int i, ll v){
	i=i+D;
	tree[i]=max(tree[i],v);
	i=i/2;
	while(i>0){
		tree[i]=max(tree[2*i],tree[2*i+1]);
		i=i/2;
	}
}
ll read(int L,int R){
	L+=D;
	R+=D;
	ll maxi=0;
	while(L<R){
		if(L%2==1) maxi=max(maxi,tree[L]);
		if(R%2==0) maxi=max(maxi,tree[R]);
		L=(L+1)/2;
		R=(R-1)/2; 
	}
	maxi=max(maxi,tree[L]);
	return maxi;
}
int main(){
	ios_base::sync_with_stdio(0);
	cin>>n;
	loop(i,0,n){
		cin>>els[i].a>>els[i].b>>els[i].h;
	}
	renumber();
	/*loop(i,0,n){
		ps(els[i].a);pln(els[i].b);
	}*/
	sort(els,els+n,sortEls);
	countD();//pln(D);
	dp[0]=els[0].h;
	update(els[0].a,els[0].h);
	//coutTab(tree,2*D+1);
	loop(i,1,n){
		dp[i]=read(0,els[i].b-1);
		//pln(dp[i]);
		dp[i]+=els[i].h;
		update(els[i].a,dp[i]);
		//coutTab(tree,2*D+1);
	}
	
	ll maxi=0;
	loop(i,0,n){
		maxi=max(maxi,dp[i]);
	}
	pln(maxi);
}
