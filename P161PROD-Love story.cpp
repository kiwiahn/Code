#include<iostream>

using namespace std;

int main(void){
	string a;
	string b="qwertyuiopasdfghjkl;zxcvbnm,./";
	string s;
	string x;
	int  k,pos;
	cin>>a;
	cin>>s;
	
	if(a[0]=='L'){
		for(int i=0;i<s.length();i++){
			pos=0;
			if(s[i]=='p'){
				s[i]='q';
			}
			if(s[i]==';'){
				s[i]='a';
			}
			if(s[i]=='/'){
				s[i]='z';
			}
			else{
				k=b.find(s[i],pos);
				s[i]=b[k+1];
			}
		}
		cout<<s;
	}
	if(a[0]=='R'){
		for(int i=0;i<s.length();i++){
			pos=0;
			if(s[i]=='q'){
				s[i]='p';
			}
			if(s[i]=='a'){
				s[i]=';';
			}
			if(s[i]=='z'){
				s[i]='/';
			}
			else{
				k=b.find(s[i],pos);
				s[i]=b[k-1];
			}
		}
		cout<<s;
	}
	return 0;
}

