#include<bits/stdc++.h>

using namespace std;

#define   For(i, a, b)            for(int i = a; i <= b; i++)
#define   Ford(i, a, b)           for(int i = a; i >= b; i--)
#define   ll                      long long
#define   here                    cout<<"I am Here"<<endl;

int const maxn = 1000000;
int const base = 1e9 + 7;

char Ar[maxn], S[maxn];

int main(void){
	cin>>Ar>>S;
	int N = strlen(S), M = strlen(Ar);
	sort(S, S + N);
	int j = N - 1;
	For(i, 0, M - 1){
		if(Ar[i] < S[j]){
			Ar[i] = S[j];
			j--;
		}
	}
	cout<<Ar;
	return 0;
}

