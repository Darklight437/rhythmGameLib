#pragma once
#include <thread>
#include <iostream>
class Gamemanager
{
public:
	Gamemanager();
	~Gamemanager();

	void startThread() {};
	void endThread() {};
	bool threadUpdate() { return false; };


protected:

	std::thread mythread;
	
};

