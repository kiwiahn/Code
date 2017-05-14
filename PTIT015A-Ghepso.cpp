#include<iostream>
#include<algorithm>
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
	char a[100],b[100],c[100];
	int s[1000];
	int j,x,y,z;
	int t,l;
	int i=1;
	cin>>t;
	while(i<=t){
		j=1;
		cin>>a>>b>>c;
		x=length(a);
		y=length(b);
		z=length(c);
		l=x+y+z;
		for(int k=0;k<x;k++){
			s[j]=a[k]-48;
			j++;
		}
		for(int k=0;k<y;k++){
			s[j]=b[k]-48;
			j++;
		}
		for(int k=0;k<z;k++){
			s[j]=c[k]-48;
			j++;
		}
		sort(s+1,s+l+1);
		
		for(int k=l;k>=1;k--){
			cout<<s[k];
		}
		cout<<endl;
		i++;
	}
	return 0;
}

