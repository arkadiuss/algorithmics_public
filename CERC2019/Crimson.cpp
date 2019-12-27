#include <bits/stdc++.h>
#define st first
#define nd second
#define fi first
#define se second
#define pb push_back
#define loop(i,j,n) for(int i=j;i<n;i++)
#define ps(v) cout << v << " "
#define pln(v) cout << v << "\n"
#define entr cout << "\n"

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;

const int MAX = 200010;
int t,r,b,l;
int txor() {
	return ((t^b)^l)^r;
}

void omv(string s, int a) {
	if(s=="left") l-=a;
	else if(s=="right") r-=a;
	else if(s=="top") t-=a;
	else if(s=="bottom") b-=a;
}

pair<string, int> findmv() {
	int blr = (b^l)^r;
	int tlr = (t^l)^r;
	int tbr = (t^b)^r;
	int tbl = (t^b)^l;
	if(blr <= t) {
		int tc= t;
		t = blr;
		return {"top", tc-blr};
	}
	
	if(tlr <= b) {
		int bc = b;
		b = tlr;
		return {"bottom", bc-tlr};
	}
	if(tbr <= l) {
		int lc = l;
		l = tbr;
		return {"left", lc-tbr};
	}
	if(tbl <= r) {
		int rc =r;
		r = tbl;
		return {"right", rc-tbl};
	}
	return {"left", 1};
}

int main() {
	ios_base::sync_with_stdio(0);
	int R,C,K;
	cin>>R>>C>>K;
	int minx=200000,miny=2000000, maxx = 0, maxy=0;
	int x,y;
	loop(i,0,K) {
		cin>>x>>y;
		maxx=max(x, maxx);
		maxy=max(y, maxy);
		minx = min(x, minx);
		miny = min(y,miny);
	}
	t=minx-1;
	b=R-maxx;
	l = miny-1;
	r = C-maxy;
	if(txor() == 0) {
		pln("pass");
		string om;
		int a;
		cin>>om;
		if(om == "yuck!") {
			return 0;
		}
		cin>>a;
		omv(om, a);
	}
	string res="";
	while(true) {
		pair<string, int> m = findmv();
		cout<<m.st<<" "<<m.nd<<endl;
		int a;
		cin>>res;
		if(res == "yuck!") {
			return 0;
		}
		cin>>a;
		omv(res, a);
	}
	return 0;
}

