#include "Gamemanager.h"
#include <Windows.h>


Gamemanager::Gamemanager()
{
	m_SoundM.startup();
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
	m_SoundM.Playsound(m_SoundM.m_soundfiles[0]);
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

void Gamemanager::update()
{
	m_SoundM.soundUpdate();
}
