#include<bits/stdc++.h>

using namespace std;

#define For(i, a, b)    for(int i = a; i <= b; i++)
#define Ford(i, a, b)   for(int i = a; i >= b; i--)
#define ll              long long
#define here            cout<<"I am here"<<endl;
const int base = 1e9 + 7;
const int maxn = 1000000;

int main(void){
	ios::sync_with_stdio(false);
	int t;
	cin>>t;
	string F[31];
	F[0] = "{}";
	For(i, 1, 30){
		F[i] += '{';
		For(j, 0, i){
			if(j < i) F[i] += F[j] + ',';
			if(j == i) F[i] += F[j];
		}
		F[i] += '}';
	}	
	cout<<F[1];
	while(t--){
		
	}	
	return 0;
}

