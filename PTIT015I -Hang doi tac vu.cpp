#include<iostream>

using namespace std;

int main(void){
	int t,a[51],j=1;
	int N,T,s=0,dem;
	cin>>t;
	while(j<=t){
		dem=0;
		s=0;
		cin>>N>>T;
		for(int i=1;i<=N;i++){
			cin>>a[i];
		}
		if(a[1]>T){
			cout<<"0"<<endl;
		}
		else{
			for(int i=1;i<=N;i++){
				s+=a[i];
				dem++;
				if(s+a[i+1]>T){
					break;
				}
			}
			cout<<dem<<endl;
		}
		j++;
		
	}
	return 0;
}

