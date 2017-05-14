#include<bits/stdc++.h>

using namespace std;

#define  For(i, a, b)     for(int i = a; i <= b; i++)
#define  Ford(i, a, b)    for(int i = a; i >= b; i--)
#define  ll               long long
#define  here             cout<<"i am here"<<endl;
const long long base= 1e9 + 7;
const int maxn = 1000000;

int change6(string a){
	int s = 0;
	For(i, 0, a.length() - 1){
		if(a[i] == '5') a[i] = '6';
		s = s*10 + (a[i] - 48);
	}
	return s;
}

int change5(string a){
	int s = 0;
	For(i, 0, a.length() - 1){
		if(a[i] == '6') a[i] = '5';
		s = s*10 + (a[i] - 48);
	}
	return s;
}

int main(void){
	ios::sync_with_stdio(false);
	string a,b;
	cin>>a>>b;
	cout<<(change5(a) + change5(b))<<" "<<(change6(a) + change6(b));
	return 0;
}

