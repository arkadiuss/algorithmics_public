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
const int MAX=100100;
const ll MOD=1000000009;

void coutTab(int* tab,int n){
	loop(i,0,n){
		cout<<tab[i]<<" ";
	}
	cout<<"\n";
}
//------------------------------------------
struct Point{
	ll x,y;
};
	
ll vecProd(Point p1,Point p2,Point p3){
	ll res = ((p2.x-p1.x)*(p3.y-p1.y)) - ((p2.y-p1.y)*(p3.x-p1.x));
	return res%MOD;
}

vector<Point> convexHull(Point * A,int n){
	int p = 0;
	loop(i,0,n){
		if(A[i].y<A[p].y or (A[i].y==A[p].y and A[i].x<A[p].x))
			p=i;
	}
	swap(A[0],A[p]);
	loop(i,1,n){
		A[i].x -= A[0].x;
		A[i].y -= A[0].y;
	}
	A[0].x=0;
	A[0].y=0;
	sort(A+1,A+n,[](Point a,Point b) {
		Point p0;
		p0.x=0;
		p0.y=0;
		if(vecProd(p0,a,b)==0)
			return a.x>b.x;
		return vecProd(p0,a,b)>0;
	});
	vector<Point> S;
	S.push_back(A[0]);
	S.push_back(A[1]);
	loop(i,2,n){
		int l = S.size()-1;
		int pl = S.size()-2;
		while(pl>=0 and vecProd(S[pl],S[l],A[i])<=0){
			S.pop_back();
			l = l-1;
			pl = pl-1;
		}
		S.push_back(A[i]);
	}
	int l = S.size()-1;
	int pl = S.size()-2;
	while(pl>=0 and vecProd(S[pl],S[l],A[0])<=0){
		S.pop_back();
		l = l-1;
		pl = pl-1;
	}
	return S;	
}

const ll P = 101;
bool check(vector<Point> A,vector<Point> B){
	if(A.size()!=B.size())
		return 0;
	else{
		int s = A.size();
		vector<ll> pA,pB;
		loop(i,1,s-1){
			pA.pb(vecProd(A[i],A[i-1],A[i+1]));
			pB.pb(vecProd(B[i],B[i-1],B[i+1]));
		}
		pA.pb(vecProd(A[s-1],A[s-2],A[0]));
		pA.pb(vecProd(A[0],A[s-1],A[1]));
		pB.pb(vecProd(B[s-1],B[s-2],B[0]));
		pB.pb(vecProd(B[0],B[s-1],B[1]));	
		ll h1 = 0;
		ll h2 = 0;
		ll PP = 1;
		loop(i,0,SIZE(pA)){
			pA[i]%=MOD;
			while(pA[i]<0) pA[i]+=MOD;
		}
		loop(i,0,SIZE(pB)){
			pB[i]%=MOD;
			while(pB[i]<0) pB[i]+=MOD;
		}
		loop(i,0,s){
			h1 = ((h1*P)%MOD + pA[i])%MOD;
			h2 = ((h2*P)%MOD + pB[i])%MOD;
			if(i>0) PP = (PP*P)%MOD;
		}
		loop(i,0,s){
			if(h1==h2)
				return 1;
			else{
				h1 = h1 - (PP*pA[i])%MOD;
				while(h1<0) {h1+=MOD;};
				h1 = ((h1*P)%MOD + pA[i])%MOD;
			}
		}
		if(h1==h2)
			return 1;
		return 0;
	}
}
Point A[MAX],B[MAX];
int main(){
	ios_base::sync_with_stdio(0);
	int n,m;
	cin>>n>>m;
	loop(i,0,n){
		cin>>A[i].x>>A[i].y;
	}
	loop(i,0,m){
		cin>>B[i].x>>B[i].y;
	}
	vector<Point> cA = convexHull(A,n);
	vector<Point> cB = convexHull(B,m);
	if(check(cA,cB)){
		pln("YES");
	}else{
		pln("NO");
	}
}
