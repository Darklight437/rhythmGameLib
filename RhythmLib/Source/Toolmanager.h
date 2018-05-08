#pragma once
#include <thread>
#include <string>
#include "SoundManager.h"
#include"GameClock.h"
#include "BeatMap.h"
#include "BeatEvent.h"

class Toolmanager
{
public:
	Toolmanager();
	~Toolmanager();

	void startThread() {};
	void endThread();
	
	void dootTest();
	void playCurrSong();
	
	//call this each frame to clean up fmod & other systems
	void update();

	//loads a song from the audio folder inside the bin folder of your application
	//there can only be one song loaded and loading another will overwrite the old one
	bool loadSong(const char* songName);
	bool loadSong(std::string songName);

	//same as song but will allow any number to be loaded
	bool loadSound(const char* soundName);
	bool loadSound(std::string soundName);


	//might not be able to delete TODO learn if this is possible
	//bool deleteSound(const char* soundName);
	//bool deleteSound(std::string soundName);

	void comparator() {}
	bool writeInput() {}
	bool readMusic() {}
	void debugClock();
	eventpoint recordEvent();

	//beat and timing functions
/////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////
	//returns the difference between the input and the closest correct beat
	float compareinput(eventpoint currNote, eventpoint input);
	//returns the most recent event created by the player
	eventpoint getLatestBeat();
	//evaluates player input and sets m_lastScore
	int handleBeat(eventpoint beat, bool recording);
	
	//takes input comparison float and rates it from 0-4 4 being highest accuracy
	int rateBeat(float differenceOfNote);
	//set ratings for difference from the note in milliseconds
	void setDifficulties(float perfect, float great, float good, float bad);
	
/////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////
	//threading tools / wrapper
	//TODO all of this
	//up in the air if this is nessecary
	void runthread();


/////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////

	//consigned to irrelevant because FMOD hates me
	bool songPlaying();

	


protected:
	//accuracy values in milliseconds
	float m_perfect = 25.0f;
	float m_great = 41.0f;
	float m_good = 81.0f;
	float m_bad = 121.0f;
	std::string getExePath();
	SoundManager m_SoundM;
	std::thread mythread;
	BeatMap m_currentSong;
};

