#include<iostream>

using namespace std;

int main(void){
	int n,a[1000],b[1000];
	int s=0;
	cin>>n;
	
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[i]=a[i];
	}
	for(int i=1;i<=n;i++){
		while(a[i]!=0){
			s=s*10;
			s=s+a[i]%10;
			a[i]=a[i]/10;
		}
		if(s==b[i]){
			cout<<"YES"<<endl;
		}
		else{
			cout<<"NO"<<endl;
		}
		s=0;
	}
	return 0;
}

