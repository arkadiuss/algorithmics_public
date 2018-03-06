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
const int MAX=500100;
const int MOD=10000000;

void coutTab(int* tab,int n){
	loop(i,0,n){
		cout<<tab[i]<<" ";
	}
	cout<<"\n";
}
//------------------------------------------
struct point{
	int x,y;
};
int dp[MAX][2];
bool toSort(point a,point b){
	if(a.x==b.x) return a.y<b.y;
	return a.x<b.x;
}
point points[MAX];
int n;
void countL(){
	int sumx=0;
	int ans=0;
	dp[n][0]=0;
	int howmany=0;
	loopback(i,n-1,0){
		if(i!=n-1) sumx=sumx+points[i].x;
		ans=ans+(n-i-1)*points[n-1].x-sumx;
		loop(j,i+1,n)
			ans=ans+abs(points[i].y-points[j].y);
		//cout<<ans<<" ";
		while(i-1>=0&&points[i-1].x==points[i].x){
			i--;
			howmany++;
			if(i!=n-1) sumx=sumx+points[i].x;
			ans=ans+i*points[n-1].x-sumx;
			loop(j,i+1,n)
				ans=ans+abs(points[i].y-points[j].y);
		}
		while(howmany-->0)
			dp[i][0]=ans;
		//cout<<ans<<"\n";
	}
}
void countR(){
	int sumx=0;
	int ans=0;
	int howmany=0;
	dp[0][0]=0;
	loop(i,0,n){
		ans=ans+i*points[i].x-sumx;
		sumx=sumx+points[i].x;
		loopback(j,i-1,0)
			ans=ans+abs(points[i].y-points[j].y);
		//cout<<ans<<" ";
		while(i+1<n&&points[i+1].x==points[i].x){
			i++;
			howmany++;
			ans=ans+i*points[i].x-sumx;
			sumx=sumx+points[i].x;
			loopback(j,i-1,0)
			ans=ans+abs(points[i].y-points[j].y);
		}
		while(howmany--)
			dp[i+1][1]=ans;
	}
}
int main(){
	ios_base::sync_with_stdio(0);
	cin>>n;
	loop(i,0,n){
		cin>>points[i].x>>points[i].y;
	}
	sort(points,points+n,toSort);
	//countL();
	countR();
	int mini=INFTY;
	loop(i,1,n){
		cout<<dp[i][0]<<" "<<dp[i][1]<<"\n";
		mini=min(mini,dp[i][0]+dp[i][1]);
	}
	cout<<mini<<"\n";
	//cout<<ans<<"\n";
}
