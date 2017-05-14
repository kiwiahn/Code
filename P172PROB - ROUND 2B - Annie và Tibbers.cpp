#include<iostream>

using namespace std;

int main(void){
	string s;
	int n,k,j;
	int dem=0,d=1;
	cin>>n>>k;
	cin>>s;
	
	for(int i=0;i<s.length();i++){
		if(s[i]=='G'){
			j=i;
			break;
		}
		if(s[i]=='T'){
			j=i;
			break;
		}
	}
	
	for(int i=j;i<s.length();i+=k){
		if(s[i]=='G'&&dem!=0){
			d=0;
			cout<<"YES";
			break;
		}
		if(s[i]=='T'&&dem!=0){
			d=0;
			cout<<"YES";
			break;
		}
		if(s[i]=='#'){
			d=0;
			cout<<"NO";
			break;
		}
		dem++;
	}
	if(d==1){
		cout<<"NO";
	}
	return 0;
}

