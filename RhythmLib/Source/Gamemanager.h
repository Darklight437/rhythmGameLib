#pragma once
#include <thread>
#include <string>
#include "SoundManager.h"
#include"GameClock.h"
#include "BeatMap.h"

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



	bool songPlaying();

protected:
	SoundManager m_SoundM;
	std::thread mythread;
	GameClock Clock;
	BeatMap currentSong;
};

