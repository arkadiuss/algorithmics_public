#include<bits/stdc++.h>
#define loop(i,j,s) for(int i=j;i<s;i++)
#define loopback(i,j,s) for(int i=j;i>=s;i--)
#define pln( x ) cout << x << "\n"
#define ps( x ) cout << x << " "
#define entr cout << "\n" 
#define pcnt(i) __builtin_popcount(i)
#define ll long long
using namespace std;
const int INFTY=20000000;
const int MAX=1000100;
const int MOD=10000000;

void coutTab(int* tab,int n){
	loop(i,0,n){
		cout<<tab[i]<<" ";
	}
	cout<<"\n";
}
//------------------------------------------

int n;
struct date{
	ll day;
	ll w;
};
ll k,c;
ll dp[MAX];
vector<date> dates;
bool toSort(date a, date b){
	return a.day<b.day;
}
int main(){
	ios_base::sync_with_stdio(0);
	cin>>n>>k>>c;
	ll t,w;
	loop(i,0,n){
		cin>>t>>w;
		date d;
		d.day=t-1;
		d.w=w;
		dates.push_back(d);
	}
	sort(dates.begin(),dates.end(),toSort);
	/*loop(i,0,n){
		cout<<dates[i].day<<" "<<dates[i].w<<"\n";	
	}*/
	dp[0]=c;
	ll lastday=0;
	loop(i,0,n){
		dp[dates[i].day]=min(dp[lastday]+(dates[i].day-lastday)*c,dates[i].w+c-(dates[i].w+c)%c);
		lastday=dates[i].day;
	}
	dp[k-1]=dp[lastday]+(k-1-lastday)*c;
	cout<<dp[k-1];
}
