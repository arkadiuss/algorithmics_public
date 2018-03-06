#include<bits/stdc++.h>
#define loop(i,j,s) for(int i=j;i<s;i++)
#define loopback(i,j,s) for(int i=j;i>=s;i--)
#define pln( x ) cout << x << "\n"
#define ps( x ) cout << x << " "
#define entr cout << "\n" 
#define pcnt(i) __builtin_popcount(i)
#define ll long long
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
using namespace std;
const int INFTY=20000000;
const int MAX=5000;
const int MOD=10000000;
const int DELTA=1011;
//------------------------------------------
struct obstcl{
    int x;
    int a,b;
};
int n,X;
int maxY, minY;
obstcl obstcls[MAX]; //obstacles
int dp[MAX][MAX]; //min cost to point
int count(){
    int o=0;
    
    loop(i,0,X+1){
        dp[i][maxY*2]=INFTY;
        if(i==0){
            loop(j,0,maxY*2+1){
                dp[i][j]=INFTY;
                dp[X][j]=INFTY;
            }
            dp[0][DELTA]=0;
        }else{
            loop(j,0,maxY*2){
                if(obstcls[o].x==i){
                	if(obstcls[o].b<=j){
                		dp[i][j]=INFTY;
                	}else if(obstcls[o].a>=j){
                		dp[i][j]=INFTY;
                	}else{ 
                		if(j>0){
                			dp[i][j]=dp[i-1][j-1]+1;
                		}
                		if(j-1<2*maxY){
                			dp[i][j]=min(dp[i][j],dp[i-1][j+1]);
                		}
                		if(j<=0||j>=2*maxY){
                			dp[i][j]=INFTY;
                		}
                	}
                }else{
                	if(j>0){
            			dp[i][j]=dp[i-1][j-1]+1;
            		}
            		if(j-1<2*maxY){
            			dp[i][j]=min(dp[i][j],dp[i-1][j+1]);
            		}
            		if(j<=0||j-1>=2*maxY){
            			dp[i][j]=INFTY;
            		}
                }
            }
            if(obstcls[o].x==i)
            	o++;
        }
    }
    int min_cost=INFTY;
    loop(i,0,2*maxY){
    	min_cost=min(min_cost,dp[X][i]);
    }
    return min_cost;
}
void coutDp(){
	loop(i,0,X+1){
		loop(j,0,2*maxY){
			if(dp[i][j]>=INFTY)
				ps("&");
			else	
				ps(dp[i][j]);
		}
		entr;
	}
}
int main(){
	ios_base::sync_with_stdio(0);
	cin>>n>>X;
	maxY=DELTA;
	minY=INFTY;
	loop(i,0,n){
        cin>>obstcls[i].x>>obstcls[i].a>>obstcls[i].b;
        obstcls[i].a+=DELTA;
        obstcls[i].b+=DELTA;
        maxY=max(obstcls[i].b,maxY);
	}
	int res = count();
	//coutDp();
	if(res>=INFTY)
		cout<<"NIE";
	else	
		pln(res);
	
}
