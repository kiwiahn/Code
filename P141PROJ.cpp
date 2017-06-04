#include<bits/stdc++.h>

using namespace std;

#define For(i, a, b)    for(int i = a; i <= b; i++)
#define Ford(i, a, b)   for(int i = a; i >= b; i--)
#define ll              long long
#define here            cout<<"I am here"<<endl;
const int base = 1e9 + 7;
const int maxn = 1000000;

struct Row{
	string row;
};

int main(void){
	ios::sync_with_stdio(false);
	Row s[5];
	For(i, 1, 4) cin >> s[i].row;
	For(i, 1, 3){
		For(j, 0, s[i].row.length() - 2){
			int res1 = 0, res2 = 0;
			if(s[i].row[j] == '#') res1++;
			if(s[i].row[j+1] == '#'){
					res1++;
			}
			if(s[i+1].row[j] == '#') res1++;
			if(s[i+1].row[j+1] == '#') res1++;
			if(res1 >= 3){
				cout<<"YES";
				return 0;	
			}
			if(s[i].row[j] == '.') res2++;
			if(s[i].row[j+1] == '.'){
					res2++;
			}
			if(s[i+1].row[j] == '.') res2++;
			if(s[i+1].row[j+1] == '.') res2++;
			if(res2 >= 3){
				cout<<"YES";
				return 0;	
			}
			
		}
	}
	cout<<"NO";
	return 0;
}

