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
const int MAX=317;
const int MOD=10000000;

void coutTab(int* tab,int n){
	loop(i,0,n){
		cout<<tab[i]<<" ";
	}
	cout<<"\n";
}
//------------------------------------------
bool row[MAX][3],column[MAX][3];
char board[MAX][MAX];
bool visited[MAX][MAX];
int n;
bool find(int i,int j,int d,int l){
	visited[i][j]=1;
	cout<<i<<" "<<j<<"\n";
	if(i+1<n&&i>=0&&j-1>=0&&j+1<n&&visited[i+1][j]&&visited[i][j+1]&&visited[i-1][j]&&visited[i][j+1]) return true;
	
	loop(k,0,2){
		if(!row[i][l]&&!column[j][l]){
			if(l!=3){ 
				row[i][l]=1;
				column[j][l]=1;
			}	
			if(k==0&&l==0)
				board[i][j]='r';
			else if(k==0&&l==1)
				board[i][j]='a';
			else if(k==0&&l==2)	
				board[i][j]='k';
			else board[i][j]='.';
			int newl=l;
			newl++;
			if(newl>2)
				newl=0;	
			if(d==1){
				if(i+1<n&&!visited[i+1][j]){
					if(find(i+1,j,1,newl)) return true;
				}else if(!visited[i][j+1])
					if(find(i,j+1,2,newl)) return true;
			}else if(d==2){
				if(j+1<n&&!visited[i][j+1]){
					if(find(i,j+1,2,newl)) return true;
				}else if(!visited[i-1][j])
					if(find(i-1,j,3,newl)) return true;
			}else if(d==3){
				if(i-1>=0&!visited[i-1][j]){
					if(find(i-1,j,3,newl)) return true;
				}else if(!visited[i][j-1])
					if(find(i,j-1,4,newl)) return true;
			}else if(d==4){
				if(j-1>=0&&!visited[i][j-1]){
					if(find(i,j-1,4,newl)) return true;
				}else if(!visited[i+1][j])
					if(find(i+1,j,1,newl)) return true;
			}
			if(l!=3){ row[i][l]=0; column[j][l]=0;}			
		}
			
	}
	visited[i][j]=0;
	return false;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin>>n;
	find(0,0,1,0);
	loop(i,0,n){
		loop(j,0,n){
			cout<<board[j][i];
		}
		cout<<"\n";
	}
}
