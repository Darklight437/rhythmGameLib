#pragma once
#include <thread>
#include <iostream>
class Gamemanager
{
public:
	Gamemanager();
	~Gamemanager();

	void createThread();
	void endThread();

	std::thread mythread;

	


};

