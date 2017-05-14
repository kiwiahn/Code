#include<bits/stdc++.h>

using namespace std;

#define  For(i, a, b)     for(int i = a; i <= b; i++)
#define  Ford(i, a, b)    for(int i = a; i >= b; i--)
#define  ll               long long
#define  here             cout<<"i am here"<<endl;
const long long base= 1e9 + 7;
const int maxn = 1000000;

int m,n,h[maxn],pos_min[maxn],pos_max[maxn];
stack <int> St;
ll Asw;

void solve(){
	St.push(0);
	For(i, 1, n){
		while(St.empty() == false && h[St.top()] >= h[i]) St.pop();
		if(h[i]) pos_min[i] = St.top() + 1;
		St.push(i);
	}
	St.pop();
	St.push(n+1);
	Ford(i, n, 1){
		while(St.empty() == false && h[St.top()] >= h[i]) St.pop();
		if(h[i]) pos_max[i] = St.top() - 1;
		St.push(i);
	}
	For(i, 1, n){
		if(h[i]){
			ll val = 1ll * h[i] * (pos_max[i] - pos_min[i] + 1);
			if(val > Asw) Asw = val;
		}
	}
	
}

int main(void){
	ios::sync_with_stdio(false);
	cin>>m>>n;
	For(i, 1, n){
		cin>>h[i];
	}
	solve();
	For(i, 1, n){
		h[i] = m - h[i];
	}
	solve();
	cout<<Asw;
	return 0;
}

