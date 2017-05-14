#include<iostream>

using namespace std;

string change(int n){
	string a="";
	string b="";
	
	while(n>0){
		a+=(n%10 + '0');
		n=n/10;
	}
	for(int i=a.length()-1;i>=0;i--){
		b=b+a[i];
	}
	return b;
	
}

string deleteeven(string a){
	string b="";
	
	for(int i=0;i<a.length();i++){
		if(i%2==0){
			b=b+a[i];
		}
	}
	return b;
}

string deleteodd(string a){
	string b="";
	for(int i=0;i<a.length();i++){
		if(i%2!=0){
			b=b+a[i];
		}
	}
	return b;
}

string Work(string a){
	while(a.length()>1){
		a=deleteeven(a);
		if(a.length()>1){
			a=deleteodd(a);
		}
	}
	return a;
}
int main(void){
	int m;
	long n;
	cin>>m;
	while(m>0){
		cin>>n;
		string a="";
		for(int i=1;i<=n;i++){
			a=a+change(i);
		}
		cout<<Work(a)<<endl;
		m--;
	}
	return 0;
}

