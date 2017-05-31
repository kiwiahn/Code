#include<bits/stdc++.h>

using namespace std;

#define   For(i, a, b)            for(int i = a; i <= b; i++)
#define   Ford(i, a, b)           for(int i = a; i >= b; i--)
#define   ll                      long long
#define   here                    cout<<"I am Here"<<endl;

int const maxn = 1000000;
int const base = 1e9 + 7;

int main(void){
	int N;
	cin>>N;
	int res4 = 0, res7 = 0;
	while(1){
		if(N % 7 == 0){
			res7 += N/7;
			N = 0;
			break;
		}
		if(N >= 4){
			N -= 4;
			res4++;
		}
		if(N < 4) break;
	}
	if(N != 0) cout<<"-1";
	else{
		if(res4 != 0){
			For(i, 1, res4) cout<<"4";
		}
		if(res7 != 0){
			For(i, 1, res7) cout<<"7";
		}
	}
	return 0;
}

