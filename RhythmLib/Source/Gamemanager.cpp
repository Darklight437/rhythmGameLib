#include "Gamemanager.h"
#include <Windows.h>


Gamemanager::Gamemanager()
{
	SoundM.startup();
}


Gamemanager::~Gamemanager()
{
}

void Gamemanager::endThread()
{
	mythread.join();
}

void Gamemanager::dootTest()
{
	
}

std::string Gamemanager::getExePath()
{
	char buffer[MAX_PATH];
	GetModuleFileName(NULL, buffer, MAX_PATH);
	char *pos;

	if (pos = strrchr(buffer, '\\'))
	{
		*pos = 0;
	}

	return buffer;
}
