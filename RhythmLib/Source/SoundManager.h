#pragma once
#include <fmod.hpp>
#include <string>
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
	bool loadSong(const char* soundfile);
	bool Playsound(FMOD::Sound* sound);
	System* Getsystem();
	void soundUpdate();
	std::string getExePath();
	bool soundPlaying(Sound* soundTest);


	bool started = false;
	Sound* m_currSong;
	std::vector<Sound*> m_FXfiles;

};

