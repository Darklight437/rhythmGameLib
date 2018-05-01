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
	bool compareinput(BeatMap map, eventpoint input);

	bool songPlaying();

protected:
	std::string getExePath();
	SoundManager m_SoundM;
	std::thread mythread;
	BeatMap m_currentSong;
};

