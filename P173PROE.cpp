#include<bits/stdc++.h>

using namespace std;

#define   For(i, a, b)            for(int i = a; i <= b; i++)
#define   Ford(i, a, b)           for(int i = a; i >= b; i--)
#define   ll                      long long
#define   here                    cout<<"I am Here"<<endl;

int const maxn = 1000000;
int const base = 1e9 + 7;

int a[maxn], b[maxn], c[maxn];

bool cmp(int a, int b){
	return a > b;
}

int main(void){
	int N, K;
	int j = 1;
	cin>>N>>K;
	For(i, 1, N){
		cin>>a[i];
		b[j] = a[i];
		j++;
	}
	sort(b + 1, b + N + 1, cmp);
	cout<<b[K]<<endl;
	int res = 0;
	For(i, 1, N){
		if(a[i] > b[K]){
			res++;
			c[res] = i;
		}
	}
	For(i, 1, N){
		if(a[i] == b[K]){
			res++;
			c[res] = i;
			if(res == K) break;
		}
	}
	sort(c + 1, c + res + 1);
	For(i, 1, res) cout<<c[i]<<" ";
	return 0;
}

