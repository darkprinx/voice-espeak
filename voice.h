/*
    Header file for Voice Class

    @author: Lenin Hadsa
    @email: leninhasda@gmail.com
    @URL: http://leninhasda.net/

    @vresion: 1.0
    @last update: 13-04-2014
*/

/* include files */
#include<stdio.h>
#include<windows.h>
#include<string>
using namespace std;


/*
    voice class
*/
class Voice
{
private:
	/* full parametar for the espeak call */
	string param;

	/* the string to speak */
	string text_str;

	/* specify voice type male/female */
	string voice_type;

	/* specify voice speed */
	string voice_speed;

	/* specify word gap speed */
	string word_gap_speed;

	/* volume */
	string voice_volume;

	/* saving filename */
	string save_as;

	/* save as file */
	bool is_save_to;

	/* private method prototype */
	void call();

public:

	/* public methods prototype */
	Voice();

	void speak( char *text );
	void speak( string text );

	void isFemale( bool femaleVoice );
	void isMale( bool maleVoice );

	void voiceSpeed( int vSpeed );
	void wordGapSpeed( int wSpeed );
	void volume( int vol );

	void saveTo( char *filename );
	void saveTo( string filename );
};


/*
    constructor function
    initialize all the default values

	@param - void
	@return - void
*/
Voice::Voice()
{
    // default value of the param
    this->param = "espeak ";
    this->text_str = "Hello world!";
    this->voice_type = "";
    this->voice_speed = "";
    this->word_gap_speed = "";
    this->voice_volume = "";
    this->save_as = "";
    this->is_save_to = false;
}

/*
	set female voice +f2

	@param - bool
	@return - void
*/
void Voice::isFemale( bool femaleVoice )
{
    if( femaleVoice )
    {
    	this->voice_type = "-v+f2 ";
    }
}

/*
	set male voice +m5

	@param - bool
	@return - void
*/
void Voice::isMale( bool maleVoice )
{
    if( maleVoice )
    {
    	this->voice_type = "-v+m5 ";
    }
}


/*
	specify voice speed

	@range - 80 to 450
	@default - 175

	@param - int
	@return - void
*/
void Voice::voiceSpeed( int vSpeed )
{
	char buffer[10];
	sprintf( buffer, "-s%d ", vSpeed );
	this->voice_speed = buffer;

}

/*
	specify word gap(pause between words)

	in units of 10mS
	@default - 170 wpm

	@param - int
	@return - void
*/
void Voice::wordGapSpeed( int wSpeed )
{
	char buffer[10];
	sprintf( buffer, "-g%d ", wSpeed );
	this->word_gap_speed = buffer;
}

/*
	specify volume of the voice

	@rande - 0 to 200
	@default - 100

	@param - int
	@return - void
*/
void Voice::volume( int vol )
{
	char buffer[10];
	sprintf( buffer, "-a%d ", vol );
	this->voice_volume = buffer;
}

void Voice::saveTo( char *filename )
{
	string tmp = filename;
	this->save_as = " -w\""+tmp+"\" ";
	this->is_save_to = true;
}
void Voice::saveTo( string filename )
{
	this->save_as = " -w\""+filename+"\" ";
	this->is_save_to = true;
}

/*
	execute the voice
	override method 1

	@param - char array OR char pointer
	@return - void
*/
void Voice::speak( char *str )
{
	string tmp = str;
	this->text_str = " \""+tmp+"\" ";
	this->call();
}

/*
	execute the voice
	override method 2

	@param - string
	@return - void
*/
void Voice::speak( string str )
{
	this->text_str = " \""+str+"\" ";
	this->call();
}


/*
	system calls the program with generated parameters

	@param - void
	@return - void
*/
void Voice::call()
{
    // make the parameter
    this->param += 	this->voice_type +
    				this->voice_speed +
    				this->word_gap_speed +
    				this->voice_volume;

    // check if for output in a file
    if( this->is_save_to )
    {
    	this->is_save_to = false;
    	this->param += this->save_as;
    }

    // finally add the string and execute
    this->param += this->text_str;
	system(this->param.c_str());
}
