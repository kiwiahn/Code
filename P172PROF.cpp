#include<bits/stdc++.h>

using namespace std;

#define   For(i, a, b)            for(int i = a; i <= b; i++)
#define   Ford(i, a, b)           for(int i = a; i >= b; i--)
#define   ll                      long long
#define   here                    cout<<"I am Here"<<endl;

int const maxn = 1000000;
int const base = 1e9 + 7;

long long cmp(long long a, long long b, long long c){
	if(a < b && a < c) return a;
	if(b < c && b < a) return b;
	if(c < a && c < b) return c;
}

int main(void){
	long long X, Try, Bike, Foot, Fix;
	cin>>X>>Try>>Bike>>Foot>>Fix;
	long long res = 0;
	if(X <= Try){
		cout<<(X * Bike);
	}
	else{
		res += Bike * Try;
		X -= Try;
		long long ByBike = Fix + Try * Bike;
		long long ByFoot = Foot * Try;
		if(ByFoot < ByBike) res += X * Foot;
		else{
			long long M = X/Try;
			res += M*Fix + M * Try * Bike;
			if((X - M * Try) * Foot < (X - M * Try) * Bike + Fix) res += (X - M * Try) * Foot;
			else{
				res += (X - M * Try) * Bike + Fix;
			}
		}
		cout<<res;
	} 
	return 0;
}

