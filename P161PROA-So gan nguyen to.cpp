#include<iostream>
#include<math.h>
using namespace std;

int kt(long long x){
	if(x==1||x==0){
		return 0;
	}
	for(int i=2;i<=sqrt(x);i++){
		if(x%i==0){
			return 0;
		}
	}
	return 1;
}

int main(void){
	int n;
	long long a[100001],b[100001];
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[i]=(long long)sqrt(a[i]);
	}
	for(int i=1;i<=n;i++){
		if(b[i]*b[i]!=a[i]){
			cout<<"NO"<<endl;
		}
		else{
			if(kt(b[i])==1){
				cout<<"YES"<<endl;
			}
			else{
				cout<<"NO"<<endl;
			}
		}
	}
	return 0;
}

