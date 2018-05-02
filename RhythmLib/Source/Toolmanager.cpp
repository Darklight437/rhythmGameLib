#include "Toolmanager.h"
#include <iostream>
#include <Windows.h>


Toolmanager::Toolmanager()
{
	m_SoundM.startup();
	//TODO generate folders for sounds & beatmaps if none exist

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

bool Toolmanager::loadSong(const char * songName)
{
	if (m_SoundM.loadSong(songName))
	{
		return true;
	}
	return false;
}

bool Toolmanager::loadSong(std::string songName)
{
	const char * songNamechar = songName.c_str();
	if (m_SoundM.loadSong(songNamechar))
	{
		return true;
	}
	return false;
}

bool Toolmanager::loadSound(const char * soundName)
{
	if (m_SoundM.loadSound(soundName))
	{
		return true;
	}
	return false;
}

bool Toolmanager::loadSound(std::string soundName)
{
	const char * soundNamechar = soundName.c_str();
	if (m_SoundM.loadSound(soundNamechar))
	{
		return true;
	}
	return false;
}

void Toolmanager::debugClock()
{
	

	std::cout << GameClock::getInstance().getTimeSeconds() << "\n";
}

void Toolmanager::recordEvent()
{
	//m_currentSong

}
//returns the event if it was 
float Toolmanager::compareinput(BeatMap map, eventpoint input)
{
	return 0.0f;
}

eventpoint Toolmanager::getLatestBeat()
{
	m_currentSong.getTimeEvents().front();
	return eventpoint();
}

void Toolmanager::handleBeat()
{
	//take a beatevent as an argument
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

