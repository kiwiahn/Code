#include<bits/stdc++.h>

using namespace std;

#define  For(i, a, b)     for(int i = a; i <= b; i++)
#define  Ford(i, a, b)    for(int i = a; i >= b; i--)
#define  ll               long long
#define  here             cout<<"i am here"<<endl;
const long long base= 1e9 + 7;
const int maxn = 1000000;

struct classmate{
	int dd;
	int mm;
	int yy;
};

int main(void){
	ios::sync_with_stdio(false);
	string s[103];
	classmate a[103];
	int n,max=0,min=maxn,key1,key2,k1 = 1, k2 = 1, b[103];
	int j = 1,c[103],x=1,d[103],e[103];
	cin>>n;
	For(i, 1, n){
		cin>>s[i];
		cin>>a[i].dd>>a[i].mm>>a[i].yy;
		if(a[i].yy > max) max = a[i].yy;
		if(a[i].yy < min) min = a[i].yy;
	}
	For(i, 1, n){
		if(a[i].yy == max){
			b[j] = i;
			j++;
		}
		if(a[i].yy == min){
			c[x] = i;
			x++;
		}
	} 
	if(j == 2) cout<<s[b[1]]<<endl;
	if(j != 2){
		max = 0;
		For(i, 1, j-1){
			if(a[b[i]].mm > max) max = a[b[i]].mm;
		}
		For(i, 1, j -1){
			if(a[b[i]].mm == max){
				d[k1] = b[i];
				k1++;
			}
		}
		if(k1 == 2) cout<<s[d[1]]<<endl;
		else{
			max = 0;
			For(i, 1, k1 - 1){
				if(a[b[i]].dd > max){
					max = a[d[i]].dd;
					key1 = d[i];
				}
			}
			cout<<s[key1]<<endl;
		}
	}
	if(x == 2) cout<<s[c[1]]<<endl;
	if(x != 2){
		min = maxn;
		For(i, 1, x-1){
			if(a[c[i]].mm < min) min = a[c[i]].mm;
		}
		For(i, 1, x -1){
			if(a[c[i]].mm == min){
				e[k2] = c[i];
				k2++;
			}
		}
		if(k2 == 2) cout<<s[e[1]]<<endl;
		else{
			min = maxn;
			For(i, 1, k2 - 1){
				if(a[c[i]].dd < min){
					min = a[e[i]].dd;
					key2 = e[i];
				}
			}
			cout<<s[key2]<<endl;
		}
	}	
	return 0;
}

