#include "Gamemanager.h"
#include <iostream>
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
	m_SoundM.Playsound(m_SoundM.m_FXfiles[0]);
}

void Gamemanager::playCurrSong()
{
	m_SoundM.Playsound(m_SoundM.m_currSong);
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

void Gamemanager::debugClock()
{
	

	std::cout << Clock.getTimeSeconds() << "\n";
}

bool Gamemanager::songPlaying()
{
	if (m_SoundM.soundPlaying(m_SoundM.m_currSong))
	{
		return true;
	}
	

	return false;
	
}

