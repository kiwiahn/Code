// Back track
#include<bits/stdc++.h>

using namespace std;

#define  For(i, a, b)     for(int i = a; i <= b; i++)
#define  Ford(i, a, b)    for(int i = a; i >= b; i--)
#define  ll               long long
#define  here             cout<<"i am here"<<endl;
const long long base= 1e9 + 7;
const int maxn = 1000000;
ll n, s, a[100], res, res1, ans = 21;
void Bt(int i){
	For(j, 0, 1){
		res += a[i] * j;
		res1 += j;
		if(i == n){
			if(res == s){
				if(res1 < ans) ans = res1;
			}
		}
		else Bt(i + 1);
		res -= a[i] * j;
		res1 -= j;
	}
}

int main(void){
	ios::sync_with_stdio(false);
	res1 = res = 0;
	cin>>n>>s;
	For(i, 1, n) cin>>a[i];
	Bt(1);
	if(ans == 21) cout<<"-1";
	else cout<<ans;
	return 0;
}


