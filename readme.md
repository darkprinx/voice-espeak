Voice - helper header file for eSpeak in C++
=============================================

'Voice' is a simple helper class (in a header file) for C++ programmers, enabling program to speak up the output/or any other string instead of printing it out.

the class uses text-to-speach software [eSpeak](http://espeak.sourceforge.net/) for the purpose. so you have to keep the espeak.exe file in the same directory as your main .cpp file.

thats all. have fun!!! =)

Installation
-------------
you actually have to have the software installed in you pc.
1. go to this [url](http://espeak.sourceforge.net/download.html) (http://espeak.sourceforge.net/download.html)
2. download and install the software

Usage
------
simple include the header file `voice.h` in your program the call the voice class. example:

```
#include <iostream>
#include "voice.h" // voice header file included

using namespace std;

int main()
{
    Voice *v = new Voice(); // initiate a voice handler
	v->speak("শুভ নববর্ষ"); // calls the speak method

	return 0;
}
```

### Other Options
there are few optional methods, which trigger(s) some extra functionalities of eSpeak.
> *you have to call this option method(s) before calling `speak` method*

- **female voice:** simply call the following method with parameter `true` before calling the `speak` medhod
```
v->isFemale(true);
```
- **male voice:** by default male voice is triggered. however if you have already switched to female voice, you can switch back to male voie by call following method with parameter `true`
```
v->isMale(true);
```
- **voice speed:** you can specify voice speed as follow. default is 175. range is 80 to 450
```
v->voiceSpeed(200);
```
- **gap between words:** specify gap betweet two words as follow. in units of 10mS
```
v->wordGapSpeed(15);
```
- **volume:** adjust your volume as follow. default is 100. range is 0 to 200
```
v->volume(200);
```
- **save as:** you can also save the string as audio file too. note that program won't speak anything, instead only saves the speech in audio format
```
v->saveTo("filename.mp3"); // file format is must and can be any audio format
v->speak("i want to save this speech"); 
```

### Change log
version: 1.0