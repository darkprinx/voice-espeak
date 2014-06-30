#include<iostream>
#include<cstdlib>
#include "voice.h"

using namespace std;

int main()
{
	Voice *v = new Voice();
	char str[1000];
	char ch[9];
	while(gets(str)) {
        gets(ch);
		//cout<<endl;
		//cout<<"male(m) or female(f)? "; cin>>ch;
		//if(ch == 'f')
			//v->isFemale(true);
		//else
			//v->isMale(true);
		v->speak(str);
	}

	return 0;
}
