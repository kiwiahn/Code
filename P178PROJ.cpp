#include<bits/stdc++.h>

using namespace std;

#define   For(i, a, b)            for(int i = a; i <= b; i++)
#define   Ford(i, a, b)           for(int i = a; i >= b; i--)
#define   ll                      long long
#define   here                    cout<<"I am Here"<<endl;

int const maxn = 1000000;
int const base = 1e9 + 7;

priority_queue < int, vector <int>, greater<int> > Qu;

int main(void){
	int N;
	int K;
	cin>>N;
	For(i, 1, N){
		cin>>K;
		Qu.push(K);
	}
	long long res = 0;
	while(Qu.empty() == false){
		int l, r;
		l = Qu.top();
		Qu.pop();
		r = Qu.top();
		Qu.pop();
		res = ( res + 1ll * (l + r)) % base;
		if(Qu.empty() == false){
			Qu.push((l+r) % base);
		}
	}
	cout<<res<<endl;
	
	return 0;
}

