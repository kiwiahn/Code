#include<bits/stdc++.h>

using namespace std;

#define For(i, a, b)    for(int i = a; i <= b; i++)
#define Ford(i, a, b)   for(int i = a; i >= b; i--)
#define ll              long long
#define here            cout<<"I am here"<<endl;
const int base = 1e9 + 7;
const int maxn = 1000000;

stack <int> Row, Col;

struct VT{
	string vt;
};

int main(void){
	ios::sync_with_stdio(false);
	VT s[100];
	int R, C, tmp = 0, res = 0;
	int maxs = 0;

	cin>>R>>C;
	For(i, 1, R){
		cin>>s[i].vt;
	}
	For(i, 1, R){
		For(j, 0, s[i].vt.length() - 1){
			if(s[i].vt[j] == '.'){
				Row.push(i);
				Col.push(j);
				tmp++;
			}
			if(s[i].vt[j] == 'o'){
				if(j < C-1){
					if(s[i].vt[j+1] == 'o') res++;
					if(i < R){
						if(s[i+1].vt[j] == 'o') res++;
						if(s[i+1].vt[j+1] == 'o') res++;
						if(j > 0){
							if(s[i+1].vt[j-1] == 'o') res++;
						}
					}
				}
				if(j == C-1){
					if(i < R){
						if(s[i+1].vt[j] == 'o') res++;
						if(s[i+1].vt[j-1] == 'o') res++;
					}
				}
			}
		}
	}
	if(tmp == 0) cout<<res;
	else{
		while(Row.empty() == false){
			int res = 0;
			s[Row.top()].vt[Col.top()] = 'o';
			For(i, 1, R){
				For(j, 0, s[i].vt.length() - 1){
					if(s[i].vt[j] == 'o'){
						if(j < C-1){
							if(s[i].vt[j+1] == 'o') res++;
							if(i < R){
								if(s[i+1].vt[j] == 'o') res++;
								if(s[i+1].vt[j+1] == 'o') res++;
								if(j > 0){
									if(s[i+1].vt[j-1] == 'o') res++;
								}
							}
						}
						if(j == C-1){
							if(i < R){
								if(s[i+1].vt[j] == 'o') res++;
								if(s[i+1].vt[j-1] == 'o') res++;
							}
						}
					}
				}
			}
			if(res > maxs) maxs = res;

			s[Row.top()].vt[Col.top()] = '.';
			Row.pop();
			Col.pop();
		}
		cout<<maxs;
	}
	return 0;
}
