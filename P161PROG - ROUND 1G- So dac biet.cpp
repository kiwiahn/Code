#include<iostream>

using namespace std;

int main(void){
	long long n,i=1,s=1;
	long long x = 2 , a[1000];
	cin>>n;
	long long m = n;
	
	while( x * x <= n){
		if( m % x == 0 ){
			if( x != a[i-1]){
				s = s * x;
				a[i] = x;
				i++;
			}
			m= m / x;
		}
		if( m % x != 0 ){
			x++;
		}
		if( m == 1 ){
			break;
		}
	}
	if(m != 1 && m != a[i-1]){
		s = s * m;
	}
	cout<<s;
	return 0;
}

