//CT  modulo
#include<bits/stdc++.h>

using namespace std;

#define   For(i, a, b)            for(int i = a; i <= b; i++)
#define   Ford(i, a, b)           for(int i = a; i >= b; i--)
#define   ll                      long long
#define   here                    cout<<"I am Here"<<endl;

int const maxn = 1000000;
const ll mod = 1e9 + 7;

long long giaithua(ll n){
	ll s = 1;
	For(i, 1, n){
		s = (s * i) % mod;
	}
	return s;
}
long long pows(ll a, ll b){
	if(b == 0) return 1;
	if(b % 2 == 0){
		ll tmp = pows(a, b/2) % mod;
		return tmp * tmp % mod;
	}
	return pows(a, b - 1) * a % mod;
}

int main(void){
	long long n;
	cin>>n;
	ll a = giaithua(2 * n - 1);
	ll b = (giaithua(n) * giaithua(n - 1)) % mod;
	b = pows(b, mod - 2);
	ll x = (a * b) % mod;
	ll ans = (2 * x - n) % mod;
	cout<<ans;
	return 0;
}

