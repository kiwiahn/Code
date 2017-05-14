// Back track
#include<bits/stdc++.h>

using namespace std;

#define  For(i, a, b)     for(int i = a; i <= b; i++)
#define  Ford(i, a, b)    for(int i = a; i >= b; i--)
#define  ll               long long
#define  here             cout<<"i am here"<<endl;
const long long base= 1e9 + 7;
const int maxn = 1000000;

string s;
int key[11], res1 = 0, a[103];
long long ans = 0;

int test(string s){
	int resx = 0, resy = 0, resz = 0;
	For(i, 0, s.length() - 1){
		if(s[i] == 'U' || s[i] == 'E' || s[i] == 'O' || s[i] == 'A' || s[i] == 'I'){
			resx++;
			resy = 0;
		}
		else{
			resy++;
			resx = 0;
		}
		if(s[i] == 'L') resz++;
		if(resx >= 3) return 0;
		if(resy >= 3) return 0;
	}
	if(resz == 0) return 0;
	return 1;
}

void space(){
	For(i, 0, s.length() - 1){
		if(s[i] == '_'){
			res1++;
			key[res1] = i;
		}
	}
}

void Bt(int i){
	For(j, 0, 2){
		string x = s;
		a[key[i]] = j;
		if(i == res1){
			long long t1 = 0, t2 = 0;
			For(k, 1, res1){
				if(a[key[k]] == 0){
					x[key[k]] = 'A';
					t1++;
				}
				if(a[key[k]] == 1){
					x[key[k]] = 'B'; 
					t2++;
				}
				if(a[key[k]] == 2){
					x[key[k]] = 'L'; 
				}
			}
			if(test(x) == 1){
				if(t1 == 0 && t2 == 0) ans += 1;
				if(t1 == 0 && t2 != 0) ans += pow(20, t2);
				if(t1 != 0 && t2 == 0) ans += pow(5, t1);
				if(t1 != 0 && t2 != 0) ans += pow(5, t1) * pow(20, t2);
			}
		}
		else Bt(i + 1);
	}
}

int main(void){
	ios::sync_with_stdio(false);
	cin>>s;
	space();
	Bt(1);
	cout<<ans;
	return 0;
}

