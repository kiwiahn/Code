#include<iostream>
#include<math.h>
using namespace std;

const int MAX=1000;
int p[MAX]={0};
int i,j=2,x;

int main(void){
	int n,k;
	int dem=0;
	cin>>n>>k;
	
	p[0]=p[1]=1;
	
	for(i=2;i<=n;i++){
		if(p[i]==0){
			dem++;
			if(dem==k){
				cout<<i;
				break;
			}
			for(j=i*j;j<=n;j+=i){
				if(p[j]==0){
					p[j]=1;
					dem++;
				}
				if(dem==k){
					x=dem;
					cout<<j;
					break;
				}
			}
			if(x==k){
				break;
			}
		}
		j=2;
	}
	return 0;
}

