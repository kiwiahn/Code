#include<bits/stdc++.h>

using namespace std;

#define   For(i, a, b)            for(int i = a; i <= b; i++)
#define   Ford(i, a, b)           for(int i = a; i >= b; i--)
#define   ll                      long long
#define   here                    cout<<"I am Here"<<endl;

int const maxn = 1000000;
int const base = 1e9 + 7;

int solution(int n){
	int res = 1;
	if(n % 2 != 0) return 0;
	For(i, 2, sqrt(n)){
		if(i * i == n && n % i == 0){
			if(i % 2 == 0) res++;
		}
		if(n % i == 0 && i * i != n){
			if(i % 2 == 0) res++;
			if((n / i) % 2 == 0) res++;
		}
	}
	return res;
}

int main(void){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		cout<<solution(n)<<endl;
	}
	return 0;
}

