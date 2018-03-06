#include<bits/stdc++.h>
#define loop(i,j,s) for(int i=j;i<s;i++)
#define loopback(i,j,s) for(int i=j;i>=s;i--)
#define pln( x ) cout << x << "\n"
#define ps( x ) cout << x << " "
#define entr cout << "\n" 
#define pcnt(i) __builtin_popcount(i)
#define ll long long
#define pb push_back
using namespace std;
const int INFTY=20000000;
const int MAX=500100;
const int MOD=10000000;

void coutVec(vector<ll>* tab){
	loop(i,0,tab->size()){
		cout<<(*tab)[i]<<" ";
	}
	cout<<"\n";
}
//------------------------------------------
bool addAndCheck(vector<ll> nums, ll x){
	
	vector<ll> possibilities;
	loop(i,0,nums.size()){
		int tmpsz=possibilities.size();
		loop(j,0,tmpsz){
			possibilities.pb(possibilities[j]+nums[i]);
		}
		possibilities.pb(nums[i]);
	}
	bool founded=0;
	loop(i,0,possibilities.size()){
		//ps(possibilities[i]);
		if(possibilities[i]==x) founded=1;
	}
	//entr;
	if(founded)
		return 1;
	return 0;	
}
bool addAndCheck2(vector<ll> nums, ll x){
	
	ll sum=0;
	
	loop(i,0,nums.size()){
		sum=sum+nums[i];
	}
	//if(abs(x-sum)<20){
		//ps(sum);coutVec(&nums);
	
	if(sum==x){ 
		//cout<<"MAAAAAM";
		return 1;
	}
	return 0;
}
ll fctrl(int n){
	ll res=1;
	loop(i,1,n+1){
		res=res*i;
	}
	return res;
}
int sizeOf(ll a){
	int i=0;
	while(a>0){
		i++;
		a/=10;
	}
	return i;
}
ll combine(ll a, ll b, int x){
	if(sizeOf(a)+sizeOf(b)>sizeOf(x)) return -1;
	//ps(a*pow(10,sizeOf(b))+b);
	return a*pow(10,sizeOf(b))+b;
	
}
bool generateAllAndCheck(int n, vector<ll> nums, ll x){
	vector<ll> newNums;
	vector<ll> toCombinePre;
	vector<ll> toCombine;
	loop(mask,1,1<<n){
		toCombinePre.erase(toCombinePre.begin(),toCombinePre.end());
		loop(j,0,n){
			if(1<<j&mask){
				toCombinePre.pb(nums[j]);
			}
		}
		loop(mask3,0,1<<toCombinePre.size()){
			toCombine.erase(toCombine.begin(),toCombine.end());
			ll sum=0;
			loop(j,0,toCombinePre.size()){
				if(1<<j&mask3){
					sum=sum+toCombinePre[j];
				}else
					toCombine.pb(toCombinePre[j]);
			}
			if(sum>x) continue;
			toCombine.pb(sum);
			loop(i,0,fctrl(toCombine.size())){
				bool badsize=0;
				loop(mask2,0,(1<<(toCombine.size()-1))){
					badsize=0;
					newNums.erase(newNums.begin(),newNums.end());
					newNums.pb(toCombine[0]);
					loop(j,0,toCombine.size()-1){
						if(1<<j&mask2){
							newNums[newNums.size()-1]=combine(newNums[newNums.size()-1],toCombine[j+1],x);
							if(newNums[newNums.size()-1]==-1){ 
								badsize=1;
							}
						}else
							newNums.pb(toCombine[j+1]);	
					}
					if(!badsize){
						if(addAndCheck2(newNums,x)) return 1;
					}
				}
				next_permutation(toCombine.begin(),toCombine.end());
			}
		}
	}
	return 0;
}
int main(){
	ios_base::sync_with_stdio(0);
	int T,n;
	vector<ll> nums;
	cin>>T;
	while(T--){
		cin>>n;
		ll a,x;
		nums.erase(nums.begin(),nums.end());
		loop(i,0,n){
			cin>>a;
			nums.pb(a);
		}
		cin>>x;
		random_shuffle(nums.begin(),nums.end());
		if(addAndCheck(nums,x) xor generateAllAndCheck(n,nums,x)){
			cout<<"NIE";
		}else{
			cout<<"TAK";
		}
		entr;
	}
}
