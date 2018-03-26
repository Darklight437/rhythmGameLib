#pragma once
#include "fmod.hpp"
#include <vector>
using namespace FMOD;

class SoundManager
{
public:
	SoundManager();
	~SoundManager();
	System* m_pfmodSystem = nullptr;
	
	
	bool startup();
	
	bool loadSound(const char* soundfile);
	bool Playsound(FMOD::Sound* sound);
	System* Getsystem();


	bool started = false;
	std::vector<Sound*> m_soundfiles;

};

