#pragma once
#include <string>
#include "SoundManager.h"
#include"GameClock.h"
#include "BeatMap.h"
#include "BeatEvent.h"

class Toolmanager
{
public:
	Toolmanager();
	~Toolmanager();

	
	
	void beatSound();
	void playCurrSong();
	
	//call this each frame to clean up fmod & other systems
	void update();

	//Loading functions
/////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////
	


	//loads a song from the audio folder inside the bin folder of your application
	//there can only be one song loaded and loading another will overwrite the old one
	bool loadSong(const char* songName);
	bool loadSong(std::string songName);

	//same as song but will allow any number to be loaded
	bool loadSound(const char* soundName);
	bool loadSound(std::string soundName);

	bool loadMap(const char* mapName);
	bool saveMap();
	
	bool readMusic() {}
	void debugClock();


	//beat and timing functions
/////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////
	//returns the difference between the input and the closest correct beat
	float compareinput(eventpoint currNote, eventpoint input);

	//returns the most recent event created by the player
	eventpoint getLatestBeat();

	//evaluates player input and sets m_lastScore
	int handleBeat(eventpoint beat, bool recording);

	//makes an event at the time it was called
	eventpoint createEvent();

	//takes input comparison float and rates it from 0-4 4 being highest accuracy
	int rateBeat(float differenceOfNote);

	//set ratings for difference from the note in milliseconds
	void setDifficulties(float perfect, float great, float good, float bad);
	
/////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////
	



	//consigned to irrelevant because FMOD hates me
	bool songPlaying();

	//returns the absolute path to the EXE
	std::string getExePath();
	


protected:
	void writeEvent(eventpoint);
	//accuracy values in milliseconds
	float m_perfect = 25.0f;
	float m_great = 41.0f;
	float m_good = 81.0f;
	float m_bad = 121.0f;
	void serialiseBeatmap();

	SoundManager m_SoundM;
	BeatMap m_currentSong;
	BeatMap m_recording;
};