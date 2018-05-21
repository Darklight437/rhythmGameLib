#include "Toolmanager.h"
#include <iostream>
#include <fstream>
#include <iterator>
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


//plays the specified sound in the list of sfx in load order
void Toolmanager::beatSound(int soundnum)
{
	m_SoundM.Playsound(m_SoundM.m_FXfiles[soundnum]);
}

void Toolmanager::playCurrSong()
{
	m_SoundM.Playsound(m_SoundM.m_currSong);
}



void Toolmanager::serialiseBeatmap(std::string mapname)
{
	std::ofstream song1;
	
	std::vector<eventpoint> beats = m_recording.getTimeEvents();
	std::vector<eventpoint>::iterator it = beats.begin();
	song1.open(getExePath() + "\\beatmaps\\" + mapname);

	for (int i = 0; i < beats.size(); i++)
	{
		song1 << it->timeEvent << "\n";
		it++;
	}

	song1.close();

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



bool Toolmanager::loadSong(std::string songName, std::string path)
{
	std::string fullName = path + songName;
	const char * songNamechar = fullName.c_str();
	if (m_SoundM.loadSong(songNamechar))
	{
		return true;
	}
	return false;
}



bool Toolmanager::loadSound(std::string soundName, std::string path)
{
	std::string fullName = path + soundName;
	const char * soundNamechar = fullName.c_str();
	if (m_SoundM.loadSound(soundNamechar))
	{
		return true;
	}
	return false;
}

bool Toolmanager::loadMap(std::string mapName, std::string path)
{
	//Fstream read in the text file
	std::string::size_type size; //alias of size_t
	std::vector<eventpoint> newBeats;
	std::string line;
	std::ifstream mySong(path + "\\beatmaps\\" + mapName);
	if (mySong.is_open())
	{
		while (std::getline(mySong,line))
		{
			eventpoint beat;
			int64_t time = std::stoi(line, &size);
			beat.timeEvent = time;
			m_currentSong.addEvent(beat);
		}
		return true;
	}

	return false;
}

bool Toolmanager::saveMap(std::string mapname)
{
	serialiseBeatmap(mapname);
	return false;
}

void Toolmanager::writeEvent(eventpoint e)
{
	//save the eventpoint to a new beatmap
	m_recording.addEvent(e);


}

void Toolmanager::debugClock()
{
	

	std::cout << GameClock::getInstance().getTimeMilliseconds() << "\n";
}
//creates am eventpoint at the current time and using a keycode
eventpoint Toolmanager::createEvent()
{
	eventpoint beat;
	beat.timeEvent = GameClock::getInstance().getTimeMilliseconds();
	return beat;

}
//returns how close the player input was to the beat
float Toolmanager::compareinput(eventpoint currNote, eventpoint input)
{
	//working in miliseconds
	//if it's within 500MS count it
	int64_t d1 = 300;
	float difference = (float)input.timeEvent - (float) currNote.timeEvent;
	if (difference <=  d1)
	{
		
		return difference;
	}

	return d1;
}
//gets nearest beat to current time that is greater than current time
eventpoint Toolmanager::getNextBeat()
{
	std::vector<eventpoint> song = m_currentSong.getTimeEvents(); 
	if (GameClock::getInstance().getTimeMilliseconds >= song.back().timeEvent)
	{
		return song.back();
	}
	for (auto iter = song.begin(); iter != song.end(); iter++)
	{
		if (iter->timeEvent > GameClock::getInstance().getTimeMilliseconds())
		{
			return *iter;
		}
	}
	
	return eventpoint();
}

eventpoint Toolmanager::getLastBeat()
{
	std::vector<eventpoint> song = m_currentSong.getTimeEvents();
	if (GameClock::getInstance().getTimeMilliseconds >= song.back().timeEvent)
	{
		return song.back();
	}
	for (auto iter = song.end(); iter != song.begin(); iter++)
	{
		if (iter->timeEvent > GameClock::getInstance().getTimeMilliseconds())
		{
			return *iter;
		}
	}

	return eventpoint();
}
//gets closest beat to time regardless of wether it is before or after
eventpoint Toolmanager::getNearestBeat()
{
	std::vector<eventpoint> song = m_currentSong.getTimeEvents();

	for (auto iter = song.begin(); iter != song.end(); iter++)
	{
		if (iter->timeEvent - GameClock::getInstance().getTimeMilliseconds() < 300 && iter->timeEvent - GameClock::getInstance().getTimeMilliseconds() > -300)
		{
			return *iter;
		}
	}



	return eventpoint();
}


//takes a beat event & a bool to determine wether to record
int Toolmanager::handleBeat(eventpoint beat, bool recording)
{
	//take a beatevent as an argument
	if (recording)
	{
		writeEvent(beat);
		return 4;
	}
	else
	{
		//expose this differance value

		float difference;
		
		difference = compareinput(getNextBeat(), beat);

		int beatscore = rateBeat(difference);
		return beatscore;
	}

	

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

	return 0;
}

void Toolmanager::setDifficulties(float perfect, float great, float good, float bad)
{
	m_perfect = perfect;
	m_great = great;
	m_good = good;
	m_bad = bad;
}





float Toolmanager::getDecimalToBeat()
{
	return decimalToBeat;
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

