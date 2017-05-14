#include<iostream>
#include<math.h>
using namespace std;

int cp(int p){
	int s = (int) sqrt(p);
	if(s * s != p){
		return 0;
	}
	return 1;
}

int main(void){
	int n,dem=0;
	int p;
	cin>>n;
	for(int i=2;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			p= i*i + j*j;
			if(cp(p) == 1 && sqrt(p) <= n){
				dem++;
			}	
		}
	}
	cout<<dem;
	return 0;
}

