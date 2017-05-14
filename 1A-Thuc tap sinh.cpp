#include<iostream>

using namespace std;

int main(void){
	long long l,r;
	long long x,s=1;
	int dem=0;
	cin>>l>>r>>x;
	
	if(l==1){
		cout<<"1"<<" ";
		dem++;
	}
	while(r/s>=x){
		s=s*x;
		if(s>=l&&s<=r){
			cout<<s<<" ";
			dem++;
		}
	}
	if(dem==0){
		cout<<"-1";
	}
	return 0;
}

