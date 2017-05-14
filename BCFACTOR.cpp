#include<iostream>

using namespace std;

int kt(int n){
	if( n == 0 || n == 1){
		return 0;
	}
	for(int i = 2; i * i <= n; i++ ){
		if( n % i == 0){
			return 0;
		}
	}
	return 1;
}

int main(void){
	int n,dem = 0;
	int x = 2;
	cin>>n;
	int m = n;
	
	while( x * x <= n){
		if( m % x == 0){
			dem++;
			m= m / x;
		}
		if( m % x != 0 && dem == 0 ){
			x++;
		}
		if( m % x != 0 && dem != 0 ){
			cout<<x<<" "<<dem<<endl;
			x++;
			dem = 0;
		}
		if( m == 1 ){
			break;
		}
		if( kt(m) == 1 && m != x){
			cout<<m<<" 1";
			break;
		}
	}
	return 0;
}

