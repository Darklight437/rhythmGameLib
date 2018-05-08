#include "Toolmanager.h"
#include <iostream>
#include <Windows.h>
#include <mutex>

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
	

	std::cout << GameClock::getInstance().getTimeMilliseconds() << "\n";
}

void Toolmanager::recordEvent()
{
	//m_currentSong

}
//returns how close the player input was to the beat
float Toolmanager::compareinput(eventpoint currNote, eventpoint input)
{
	//working in miliseconds
	//if it's within 500MS count it
	int64_t d1 = 200;
	int64_t difference = input.timeEvent - currNote.timeEvent;
	if (difference <=  d1)
	{
		return difference;
	}

	return 300.0f;
}

eventpoint Toolmanager::getLatestBeat()
{
	m_currentSong.getTimeEvents().front();
	return eventpoint();
}

int Toolmanager::handleBeat(eventpoint beat)
{
	//take a beatevent as an argument
	float difference;
	difference = compareinput(getLatestBeat(), beat);

	int beatscore = rateBeat(difference);
	return beatscore;

}

int Toolmanager::rateBeat(float differenceOfNote)
{
	if (differenceOfNote = 300.0f)
	{
		return 0;
	}
	if (differenceOfNote <= m_bad  && differenceOfNote > m_good)
	{
		return 1;
	}

	if (differenceOfNote <= m_good && differenceOfNote > m_great)
	{
		return 2;
	}

	if (differenceOfNote <= m_great && differenceOfNote > m_perfect)
	{
		return 3;
	}
	if (differenceOfNote <= m_perfect)
	{
		return 4;
	}
}

void Toolmanager::setDifficulties(float perfect, float great, float good, float bad)
{
	m_perfect = perfect;
	m_great = great;
	m_good = good;
	m_bad = bad;
}

void Toolmanager::runthread()
{
	static int lastScore;
	static std::mutex mutex;
	


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

