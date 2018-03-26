#pragma once
#include <thread>
#include <iostream>
#include "SoundManager.h"


class Gamemanager
{
public:
	Gamemanager();
	~Gamemanager();

	void startThread() {};
	void endThread() {};
	bool threadUpdate() { return false; };


protected:
	SoundManager SoundM;
	std::thread mythread;
	
};

