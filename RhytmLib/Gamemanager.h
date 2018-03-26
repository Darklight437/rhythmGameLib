#pragma once
#include <thread>
#include <iostream>
class Gamemanager
{
public:
	Gamemanager();
	~Gamemanager();

	void startThread();
	void endThread();
	bool threadUpdate();


protected:

	std::thread mythread;
	void 
};

