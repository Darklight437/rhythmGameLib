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


protected:
	SoundManager SoundM;
	std::thread mythread;
	
};

