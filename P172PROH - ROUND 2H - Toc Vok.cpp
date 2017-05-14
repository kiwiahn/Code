#include<iostream>

using namespace std;

int main(void){
	string s;
	cin>>s;
	
	int d=s.length();
	
	for(int i=0;i<s.length();i++){
		if(s[i]=='='){
			if(s[i-1]=='c'||s[i-1]=='s'||(s[i-1]=='z'&&s[i-2]!='d')){
				d--;
			}
			if(s[i-1]=='z'&&s[i-2]=='d'){
				d=d-2;
			}
		}
		if(s[i]=='-'){
			if(s[i-1]=='c'||s[i-1]=='d'){
				d--;
			}
		}
		if(s[i]=='j'){
			if(s[i-1]=='l'||s[i-1]=='n'){
				d--;
			}
		}
	}
	cout<<d;
	return 0;
}

