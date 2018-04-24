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
	GameClock m_Clock;
	BeatMap m_currentSong;
};

