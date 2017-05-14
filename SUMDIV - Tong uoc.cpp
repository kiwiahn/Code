#include<iostream>

using namespace std;

int main(void){
	int t;
	cin>>t;
	long long n;
	long long s;
	
	while(t>0){
		cin>>n;
		s=0;
		for(long long i = 1; i * i <= n; i++){
			if( n % i == 0 ){
				if( i * i != n){
					s = s + i + n/i;
				}
				else{
					s = s + i;
				}
			}
		}
		cout<<s<<endl;
		t--;
	}
	return 0;
}

