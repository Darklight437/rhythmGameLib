#pragma once
#include <thread>
#include <string>
#include "SoundManager.h"
#include"GameClock.h"


class Gamemanager
{
public:
	Gamemanager();
	~Gamemanager();

	void startThread() {};
	void endThread();
	bool threadUpdate() { return false; };
	void dootTest();
	std::string getExePath();
	void update();
	void comparator() {}
	bool writeInput() {}
	bool readMusic() {}
	void testClock();


protected:
	SoundManager m_SoundM;
	std::thread mythread;
	GameClock Clock;
};

