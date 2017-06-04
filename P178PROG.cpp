#include<bits/stdc++.h>

using namespace std;

#define   For(i, a, b)            for(int i = a; i <= b; i++)
#define   Ford(i, a, b)           for(int i = a; i >= b; i--)
#define   ll                      long long
#define   here                    cout<<"I am Here"<<endl;

int const maxn = 1000000;
int const base = 1e9 + 7;

int main(void){
	while(1){
		int N;
		cin>>N;
		if(N == 0) return 0;
		string S1, S2;
		cin>>S1>>S2;
		string X1 = S1, X2 = S2;
		string M;
		cin>>M;
		string S = "";
		int res = 0;
		while(1){
			S = "";
			res++;
			For(i, 0, N - 1){
				S += X2[i];
				S += X1[i];
			}
			if(S == M){
				cout<<res<<endl;
				break;
			}
			X1 = "";
			X2 = "";
			For(i, 0, N - 1){
				X1 += S[i];
			}
			For(i, N, S.length() - 1){
				X2 += S[i];
			}
			if(X1 == S1 && X2 == S2){
				cout<<"-1"<<endl;
				break;
			}
		}
	}
	return 0;
}

