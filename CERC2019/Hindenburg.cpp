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


ll A[MAX];
int C[32];

void divd(ll a) {
	int i=0;
	while(a>0) {
		C[i] += a%2;
		//ps(a%2);
		a/=2;
		i++;
	}
	//pln("");
}
bool R[MAX];
int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n,k;
	cin>>n>>k;
	//pln((1ll<<30));
	loop(i,0,n) {
		cin>>A[i];
		divd(A[i]);
	}
	int f=30;
	while(f>=0 && C[f] < k) {
		f--;
	}
	if(f < 0) {
		pln(0);
		return 0;
	}
	ll res = 0;
	loop(i,0,n) if(!(A[i]&(1ll<<f))) R[i] = 1;
	res += (1ll<<f);
	f--;
	vector<int> tR;
	while(f>=0) {
		tR.clear();
		int ss = 0;
		loop(i,0,n) {
			//ps(A[i]);
			if(!(A[i] & (1ll<<f)) || R[i] == 1) tR.pb(i);
			else ss++;
		}
		//pln("");
		if(ss >=k) {
			for(int r : tR) {
				R[r] = 1;
			}	
			res += (1ll<<f);
		}
		f--;
		//pln(res);
	} 
	pln(res);
	return 0;
}

