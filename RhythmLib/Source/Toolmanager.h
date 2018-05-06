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
	void recordEvent();

	//beat and timing functions
/////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////
	//returns the difference between the input and the closest correct beat
	float compareinput(eventpoint currNote, eventpoint input);
	//returns the most recent event created by the player
	eventpoint getLatestBeat();
	//evaluates player input and sets m_lastScore
	void handleBeat(eventpoint beat);
	
	//takes input comparison float and rates it from 0-4 4 being highest accuracy
	int rateBeatEasy();
	//as above but harsher for difficulty
	int rateBeatMedium();
	//hardest accuracy standard
	int rateBeatHard();

/////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////
	//threading tools / wrapper
	//TODO all of this

/////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////

	//consigned to irrelevant because FMOD hates me
	bool songPlaying();

protected:
	std::string getExePath();
	SoundManager m_SoundM;
	std::thread mythread;
	BeatMap m_currentSong;
};

