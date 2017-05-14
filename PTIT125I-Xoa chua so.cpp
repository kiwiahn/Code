#include<bits/stdc++.h>

using namespace std;

#define  For(i, a, b)     for(int i = a; i <= b; i++)
#define  Ford(i, a, b)    for(int i = a; i >= b; i--)
#define  ll               long long
#define  here             cout<<"i am here"<<endl;
const long long base= 1e9 + 7;

int main(void){
	ios::sync_with_stdio(false);
	string s;
	int k,n;
	stack <char> check;
	stack <char> KQ;
	cin>>n;
	cin>>k;
	cin>>s;
	For(i, 0, s.length()-1){
		while(k > 0&& check.size() > 0&& check.top() < s[i]){
			check.pop();
			k--;
		}
		check.push(s[i]);
	}
	For(i, 1, k) check.pop();
	while(check.empty() == false){
		KQ.push(check.top());
		check.pop();
	}
	while(KQ.empty() == false){
		cout<<KQ.top();
		KQ.pop();
	}
	return 0;
}

