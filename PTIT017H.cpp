#include<bits/stdc++.h>

using namespace std;

#define  For(i, a, b)     for(int i = a; i <= b; i++)
#define  Ford(i, a, b)    for(int i = a; i >= b; i--)
#define  ll               long long
#define  here             cout<<"i am here"<<endl;
const long long base= 1e9 + 7;
const int maxn = 1000000;
ll n;
int math(ll n){
	long long s = 0;
	For(i, 1, sqrt(n)){
		if(n % i == 0){
			if(i * i == n){
				s = s + i;
			}
			if(i * i != n){
				s = s + i + n/i;
			}
		}
	}
	return s;
}

int main(void){
	ios::sync_with_stdio(false);
	int t;
	cin>>t;
	while(t--){
		cin>>n;
		if(math(math(n)) == 2 * n) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
	return 0;
}

