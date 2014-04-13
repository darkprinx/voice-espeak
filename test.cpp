#include<iostream>
#include "voice.h"

using namespace std;

int main()
{
	Voice *v = new Voice();
	v->speak("শুভ নববর্ষ");

	return 0;
}
