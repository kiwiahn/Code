#include<iostream>

using namespace std;

int main(void){
	int n;
	int a[3001];
	int b[3001]={0};
	cin>>n;
	
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[a[i]]=1;
	}
	int vt;
	for(int i=1;i<=n+1;i++) {
		if(b[i]==0) {
			vt=i;
			break;
		}
	}
	cout<<vt;
	return 0;
}
