#include<bits/stdc++.h>

using namespace std;

#define   For(i, a, b)            for(int i = a; i <= b; i++)
#define   Ford(i, a, b)           for(int i = a; i >= b; i--)
#define   ll                      long long
#define   here                    cout<<"I am Here"<<endl;

int const maxn = 1000000;
int const base = 1e9 + 7;
int a[maxn];
int main(void){
	int T;
	cin>>T;
	while(T--){
		memset(a, 0, sizeof a);
		int N, k;
		cin>>N>>k;
		For(i, 1, N) a[i] = i;
		if(k == 0){
			For(i, 1, N) cout<<i<<" ";
			cout<<endl;
		}
		else{
			if(N % 2 != 0 || N % (2 * k) != 0){
				cout<<"-1"<<endl;
			}
			else{
				int x = 1, y = k + 1;
				while(y <= N){
					For(i, y, y + 2 * k - k - 1){
						cout<<a[i]<<" ";
					}
					For(i, x, x + k - 1) cout<<a[i]<<" ";
					x += 2 * k;
					y += 2 * k;
				}
				cout<<endl;
			}
		}
	}
	return 0;
}

