#include<bits/stdc++.h>

using namespace std;

#define For(i, a, b)    for(int i = a; i <= b; i++)
#define Ford(i, a, b)   for(int i = a; i >= b; i--)
#define ll              long long
#define here            cout<<"I am here"<<endl;
const int base = 1e9 + 7;
const int maxn = 1000000;

int Sum(int n){
	int s = 0;
	while(n != 0){
		s += n%10;
		n /= 10;
	}
	return s;
}

int Test(int n){
	if(n % 400 == 0 || (n % 4 == 0 && n % 100 != 0)) return 1;
	return 0;
}

int main(void){
	ios::sync_with_stdio(false);
	int n;
	cin>>n;
	if(Test(n) == 1){
		int S = Sum(n) * 366 + 868 + 630 + 58 + 1980 + 61;
		cout<<S;
	}
	else{
		int S = Sum(n) * 366 + 3597 - 13 - Sum(n);
		cout<<S;
	}
	return 0;
}
