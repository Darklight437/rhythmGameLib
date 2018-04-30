#include "Toolmanager.h"
#include <iostream>
#include <Windows.h>


Toolmanager::Toolmanager()
{
	m_SoundM.startup();
	
}


Toolmanager::~Toolmanager()
{
	
}

void Toolmanager::endThread()
{
	mythread.join();
}

void Toolmanager::dootTest()
{
	m_SoundM.Playsound(m_SoundM.m_FXfiles[0]);
}

void Toolmanager::playCurrSong()
{
	m_SoundM.Playsound(m_SoundM.m_currSong);
}



std::string Toolmanager::getExePath()
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

void Toolmanager::update()
{
	m_SoundM.soundUpdate();
	
}

void Toolmanager::debugClock()
{
	

	std::cout << GameClock::getInstance().getTimeSeconds() << "\n";
}

void Toolmanager::recordEvent()
{
	//m_currentSong

}

bool Toolmanager::songPlaying()
{
	if (m_SoundM.soundPlaying(m_SoundM.m_currSong) == true)
	{
		return true;
	}
	else
	{
		return false;
	}
	
	return false;
	
	
}

