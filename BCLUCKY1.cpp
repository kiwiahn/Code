#include<bits/stdc++.h>

using namespace std;

#define For(i, a, b)    for(int i = a; i <= b; i++)
#define Ford(i, a, b)   for(int i = a; i >= b; i--)
#define ll              long long
#define here            cout<<"I am here"<<endl;
const int base = 1e9 + 7;
const int maxn = 1000000;

int KT(int n){
	if(n == 4 || n == 7) return 1;
	return 0;
}

int Lucky(long long n){
	int res = 0;
	while(n != 0){
		if(n % 10 == 4 || n % 10 == 7) res++;
		n /= 10;
	}
	if(KT(res) == 1) return 1;
	return 0;
}

int main(void){
	ios::sync_with_stdio(false);
	long long n;
	cin>>n;
	if(Lucky(n) == 1) cout<<"YES";
	else cout << "NO";
	
	return 0;
}

