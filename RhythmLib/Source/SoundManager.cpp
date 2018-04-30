#include "SoundManager.h"
#include <fmod_errors.h>

#include <iostream>

SoundManager::SoundManager()
{
	
}


SoundManager::~SoundManager()
{

}

bool SoundManager::startup()
{
	//create main system object
	FMOD_RESULT result = System_Create(&m_pfmodSystem);
	
	
	//failed to create the system object
	if (result != FMOD_OK)
	{
		std::cout << "FMOD error! \n" << result << FMOD_ErrorString(result) << "\n";
		return false;
	}

	//initialise FMOD with 512 channels
	result = m_pfmodSystem->init(512, FMOD_INIT_NORMAL, 0);
	//error case
	if (result != FMOD_OK)
	{
		std::cout << "FMOD error! \n" << result << FMOD_ErrorString(result) << "\n";
	}

	loadSong("audio/Dieseldotogg.wav");
	loadSound("audio/gunshot.ogg");

	return true;
}

bool SoundManager::loadSound(const char* soundfile)
{
	
	Sound* pSound = nullptr;
	
	FMOD_RESULT result = m_pfmodSystem->createSound(soundfile, FMOD_DEFAULT, 0, &pSound);

	if (result != FMOD_OK)
	{
		std::cout << "FMOD error! \n" << result << FMOD_ErrorString(result) << "\n";
	}

	m_FXfiles.push_back(pSound);
	return true;
}
//loads single sound file to play as a backing song
bool SoundManager::loadSong(const char * soundfile)
{

	Sound* pSound = nullptr;

	FMOD_RESULT result = m_pfmodSystem->createSound(soundfile, FMOD_DEFAULT, 0, &pSound);

	if (result != FMOD_OK)
	{
		std::cout << "FMOD error! \n" << result << FMOD_ErrorString(result) << "\n";
	}

	m_currSong= pSound;
	return true;
}

bool SoundManager::Playsound(FMOD::Sound *sound)
{
	
	Channel* pChannel;
	FMOD_RESULT result = m_pfmodSystem->playSound(sound, 0, false, &pChannel);

	return false;
}

System * SoundManager::Getsystem()
{
	return nullptr;
}

void SoundManager::soundUpdate()
{
	m_pfmodSystem->update();
}

//takes a sound to test if it is playing
bool SoundManager::soundPlaying(Sound * soundTest)
{
	bool* Isplaying = new bool;
	
	*Isplaying = false;

	for (int i = 0; i < 256; i++)
	{
		FMOD::Channel* channel;

		m_pfmodSystem->getChannel(i, &channel);

		Sound* currentSound;
		channel->getCurrentSound(&currentSound);

		if (currentSound == soundTest)
		{
			channel->isPlaying(Isplaying);
			if (*Isplaying == true)
			{
				delete Isplaying;
				std::cout << "song is playing \n";
				return true;
			}
		}
	}
	delete Isplaying;
	return false;
}
