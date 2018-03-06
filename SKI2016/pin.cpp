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
int nums[MAX];
int sumEven, sumOdd;
bool isOnEven[15], isOnOdd[15];
int main(){
	ios_base::sync_with_stdio(0);
	int T,n;
	cin>>T;
	string s;
	while(T--){
		sumEven=0;
		sumOdd=0;
		cin>>s;
		loop(i,0,13){
			isOnEven[i]=0;
			isOnOdd[i]=0;
		}
		loop(i,0,s.size()){
			nums[i]=s[i]-'0';
			if(i%2==0){
				sumEven+=nums[i];
				isOnEven[nums[i]]=1;
			}else{
				sumOdd+=nums[i];
				isOnOdd[nums[i]]=1;	
			}
		}
		if(abs(sumEven-sumOdd)%2==1){
			cout<<"NIE";
		}else if(abs(sumEven-sumOdd)>18)
			cout<<"NIE";
		else{
			int r=abs(sumEven-sumOdd)/2;
			bool pass=0;
			if(sumEven==sumOdd){
				pass=1;
			}else if(sumEven>sumOdd){
				for(int i=0;i+r<10;i++){
					if(isOnOdd[i]&&isOnEven[i+r]){
						pass=1;
					}
				}
			}else{
				for(int i=0;i+r<10;i++){
					if(isOnEven[i]&&isOnOdd[i+r]){
						pass=1;
					}
				}
			}
			if(pass) cout<<"TAK";
			else cout<<"NIE";
		}
		entr;	
	}
}
