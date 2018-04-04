#pragma once
#include <thread>
#include <string>
#include "SoundManager.h"
#include"GameClock.h"
#include "BeatMap.h"
#include "BeatEvent.h"

class Gamemanager
{
public:
	Gamemanager();
	~Gamemanager();

	void startThread() {};
	void endThread();
	
	void dootTest();
	void playCurrSong();
	std::string getExePath();
	void update();
	void comparator() {}
	bool writeInput() {}
	bool readMusic() {}
	void debugClock();
	void recordEvent();


	bool songPlaying();

protected:
	SoundManager m_SoundM;
	std::thread mythread;
	GameClock Clock;
	BeatMap m_currentSong;
};

