#include "SoundManager.h"
#include "fmod_errors.h"
#include <iostream>

SoundManager::SoundManager()
{
}


SoundManager::~SoundManager()
{
}

bool SoundManager::startup()
{
	FMOD_RESULT result = System_Create(&m_pfmodSystem);
	//create main system object
	
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



	return true;
}

bool SoundManager::loadSound(const char* soundfile)
{
	FMOD_RESULT result = System_Create(&m_pfmodSystem);
	Sound* pSound;
	
	result = m_pfmodSystem->createSound(soundfile, FMOD_DEFAULT, 0, &pSound);


	m_soundfiles.push_back(pSound);
	return true;
}

bool SoundManager::Playsound(FMOD::Sound *sound)
{
	FMOD_RESULT result = System_Create(&m_pfmodSystem);

	result = m_pfmodSystem->playSound(sound, 0, false, &pChannel);

	return false;
}

System * SoundManager::Getsystem()
{
	return nullptr;
}
