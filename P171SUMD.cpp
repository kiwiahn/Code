#include<bits/stdc++.h>

using namespace std;

#define   For(i, a, b)            for(int i = a; i <= b; i++)
#define   Ford(i, a, b)           for(int i = a; i >= b; i--)
#define   ll                      long long
#define   here                    cout<<"I am Here"<<endl;

int const maxn = 1000000;
int const base = 1e9 + 7;

int check(int A[101][101], int B[101][101], int m, int n){
	For(i, 1, m){
		For(j, 1, n){
			if(A[i][j] != B[i][j]) return 0;
		}
	}
	return 1;
}

int main(void){
	int m, n;
	int Pass[101][101];
	int Start[101][101];
	int H[10001], T = 0, C[10001], K = 0;
	cin>>m>>n;
	For(i, 1, m){
		For(j, 1, n){
			cin>>Pass[i][j];
			Start[i][j] = 0;
		}
	}
	if(m < n){
			For(i, 1, m){
				int mins = maxn;
				For(j, 1, n){
					if(Pass[i][j] < mins) mins = Pass[i][j];
				}
				if(mins != 0){
					For(k, 1, mins) H[++T] = i;
					For(j, 1, n){
						Start[i][j] += mins;
					}
				}
			}
			For(j, 1, n){
				int mins = maxn;
				int t;
				For(i, 1, m){
					if(Pass[i][j] < mins){
						mins = Pass[i][j];
						t = Pass[i][j] - Start[i][j];
					}
				}
				if(t != 0){
					For(k, 1, t) C[++K] = j;
					For(i, 1, m){
						Start[i][j] += t;
					}
				}
			}
			if(check(Start, Pass, m, n) == 0) cout<<"-1";
			else{
				cout<<(T + K)<<endl;
				For(i, 1, T) cout<<"H "<<H[i]<<endl;
				For(i, 1, K) cout<<"C "<<C[i]<<endl;
			}
	}
	else{
		For(j, 1, n){
			int mins = maxn;
			For(i, 1, m){
				if(Pass[i][j] < mins) mins = Pass[i][j];
			}
			if(mins != 0){
				For(k, 1, mins) C[++K] = j;
				For(i, 1, m){
					Start[i][j] += mins;
				}
			}
		}
		For(i, 1, m){
			int mins = maxn;
			int t;
			For(j, 1, n){
				if(Pass[i][j] < mins){
					mins = Pass[i][j];
					t = Pass[i][j] - Start[i][j];
				}
			}
			if(t != 0){
				For(k, 1, t) H[++T] = i;
				For(j, 1, n){
					Start[i][j] += t;
				}
			}
		}
		if(check(Start, Pass, m, n) == 0) cout<<"-1";
		else{
			cout<<(T + K)<<endl;
			For(i, 1, T) cout<<"H "<<H[i]<<endl;
			For(i, 1, K) cout<<"C "<<C[i]<<endl;
		}
	}
	return 0;
}

