#pragma once
#include <thread>
#include <iostream>
#include <string>
#include "SoundManager.h"


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
	bool writeInput();
	bool readMusic();


protected:
	SoundManager m_SoundM;
	std::thread mythread;
	
};

