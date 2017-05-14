#include<iostream>

using namespace std;

int main(void){
	int a[1000],i=1,j=1,b=1;
	long long s=1;
	
	do{
		cin>>a[i];
		b=a[i];
		i++;
	}while(b!=0);
	while(a[j]!=0){
		for(i=1;i<=a[j];i++){
			s=(long long)s*i;
		}
		cout<<s<<endl;
		s=1;
		j++;
	}
	return 0;
}

