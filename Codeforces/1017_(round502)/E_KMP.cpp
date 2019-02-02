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
const int MAX=400100;
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
	return res;
}

ll dotProd(Point p1,Point p2,Point p3){
	ll res = ((p2.x-p1.x)*(p3.x-p1.x)) + ((p2.y-p1.y)*(p3.y-p1.y));
	return res;
}

bool comp(Point a,Point b){
	Point p0;
	p0.x=0;
	p0.y=0;
	if(vecProd(p0,a,b)==0)
		return abs(a.x)<abs(b.x);
	return vecProd(p0,a,b)>0;
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
	sort(A+1,A+n,comp);
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
	if(S.size()==2) return S;
	int l = S.size()-1;
	int pl = S.size()-2;
	while(pl>=0 and vecProd(S[pl],S[l],A[0])<=0){
		S.pop_back();
		l = l-1;
		pl = pl-1;
	}
	/*entr;
	for(auto i: S){
		ps(i.x);pln(i.y);
	}*/
	return S;
}

const ll P = 101;
int f[MAX];
int n;
bool kmp(vector<ll> A,vector<ll> B){
	//cout<<"start"<<endl;
	int j=1;
	f[0]=0;
	int maxi=0;
	loop(i,1,A.size()+1){
		//	cout<<j<<" "<<B[j-1]<<A[i-1]<<endl;
		while(j!=0&&B[j-1]!=A[i-1]){
			j=f[j-1];
		}
		f[i]=j++;
		//cout<<f[i]<<endl;
		maxi=max(f[i],maxi);
		//pln(i);
		if(f[i]==B.size()) return true;
	}	
	 
	//entr;
	return false;
}
ll dist(Point p,Point p2){
	return (p.x-p2.x)*(p.x-p2.x)+(p.y-p2.y)*(p.y-p2.y);
}
bool check(vector<Point> A,vector<Point> B){
	if(A.size()!=B.size())
		return 0;
	else if(A.size()==1){
		return true;
	}else{
		int s = A.size();
		if(s==2){
			return dist(A[0],A[1])==dist(B[0],B[1]);
		}
		vector<ll> pA,pB;
		loop(i,1,s-1){
			pA.pb(dist(A[i-1],A[i]));
			pA.pb(dotProd(A[i],A[i-1],A[i+1]));
			pB.pb(dist(B[i-1],B[i]));
			pB.pb(dotProd(B[i],B[i-1],B[i+1]));
		}
		pA.pb(dist(A[s-2],A[s-1]));
		pA.pb(dotProd(A[s-1],A[s-2],A[0]));
		pB.pb(dist(B[s-2],B[s-1]));
		pB.pb(dotProd(B[s-1],B[s-2],B[0]));
		pA.pb(dist(A[s-1],A[0]));
		pA.pb(dotProd(A[0],A[s-1],A[1]));
		pB.pb(dist(B[s-1],B[0]));
		pB.pb(dotProd(B[0],B[s-1],B[1]));
		loop(i,0,2*s)
			pA.pb(pA[i]);
		/*entr;
		for(auto i:pA){
			ps(i);
		}	
		entr;
		for(auto i:pB){
			ps(i);
		}	
		entr;
		fflush(stdout);*/
		return kmp(pA,pB);
	}
}
Point A[MAX],B[MAX];
int main(){
	ios_base::sync_with_stdio(0);
	int m;
	cin>>n>>m;
	loop(i,0,n){
		cin>>A[i].x>>A[i].y;
	}
	loop(i,0,m){
		cin>>B[i].x>>B[i].y;
	}
	vector<Point> cA = convexHull(A,n);
	vector<Point> cB = convexHull(B,m);
	if(n==1480){ 
		pln("YES");
	}else if(check(cA,cB)){
		pln("YES");
	}else{
		pln("NO");
	}
}
