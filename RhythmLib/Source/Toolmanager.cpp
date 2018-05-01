#include "Toolmanager.h"
#include <iostream>
#include <Windows.h>


Toolmanager::Toolmanager()
{
	m_SoundM.startup();
	//generate folders for sounds & beatmaps if none exist

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
//compares a single time event to the saved list of time events for the current song 
//TODO make this mutex dependant OR make a threading wrapper
bool Toolmanager::compareinput(BeatMap map, eventpoint input)
{
	//get the time out of the object
	int64_t pressTime = input.timeEvent;
	if (pressTime <= map.getTimeEvents().front())//presstime is compared to the front of the list of time events
	{
		//refer to book
		
	}
	//search arange by identiftying a variance amount
	//check it against the time in the beatmap(beatmaps just store times not fancy structs
	//if within a threshold rate as a pass

	return false;//yep
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

