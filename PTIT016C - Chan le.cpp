#include<iostream>

using namespace std;

int length(char c[]){
	int i=0;
	int dem=0;
	while(c[i]!=NULL){
		dem++;
		i++;
	}
	return dem;
}

int main(void){
	char c[200];
	int t,i=1,dem;
	cin>>t;
	while(i<=t){
		cin>>c;
		dem=1;
		for(int j=0;j<length(c);j++){
			if(((j % 2==0)&&((c[j]-48)%2==0))||(j % 2 !=0)&&(c[j] - 48)%2!=0){
				dem=0;
				break;
			}
		}
		if(dem==1){
			cout<<"YES"<<endl;
		}
		else{
			cout<<"NO"<<endl;
		}
		i++;
	}
	return 0;
}

