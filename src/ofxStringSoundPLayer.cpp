#include "ofxStringSoundPLayer.h"

#ifdef _WIN32
#include <Windows.h>
#include <mmsystem.h>

void playSound(const std::string& filePath) {
	std::wstring wFilePath(filePath.begin(), filePath.end());
	std::wstring command = L"open \"" + wFilePath + L"\" type mpegvideo alias " + wFilePath;
	mciSendString(command.c_str(), NULL, 0, NULL);
	command = L"play " + wFilePath + L" from 0";
	mciSendString(command.c_str(), NULL, 0, NULL);
}

// We are not using this function, but it is here for reference
void stopSound(const std::string& filePath) {
	std::wstring wFilePath(filePath.begin(), filePath.end());
	std::wstring command = L"stop " + wFilePath;
	mciSendString(command.c_str(), NULL, 0, NULL);
	command = L"close " + wFilePath;
	mciSendString(command.c_str(), NULL, 0, NULL);
}

#endif

ofxStringSoundPlayer::ofxStringSoundPlayer() : dataPath("")
{
	players.clear();
}

ofxStringSoundPlayer::~ofxStringSoundPlayer()
{
	for (auto& player : players) {
		delete player;
	}
	players.clear();
}

void ofxStringSoundPlayer::playFile(std::string filePath)
{
	players.push_back(new SsPlayer(dataPath+filePath));
	update();
}

void ofxStringSoundPlayer::update()
{
	for (auto& player : players) {
		if (!player->isPlaying()) {
			delete player;
			player = nullptr;
		}
	}
	players.erase(std::remove_if(players.begin(), players.end(), [](SsPlayer* player) {
		return player == nullptr; }), players.end());
}

void ofxStringSoundPlayer::setDataPath(std::string path /*= "data/audio/"*/)
{
	dataPath = path;
}

ofxStringSoundPlayer::SsPlayer::SsPlayer(std::string filePath) : filePath(filePath), playing(true)
{
	startThread();
};

bool ofxStringSoundPlayer::SsPlayer::isPlaying() { return playing; }

void ofxStringSoundPlayer::SsPlayer::threadedFunction()
{
#ifdef __linux__
	std::string cmd = "aplay " + filePath + " & exit;";
	ofSystem(cmd.c_str());
#elif defined _WIN32
	// PlaySoundA(filePath.c_str(), NULL, SND_FILENAME | SND_ASYNC | SND_NOSTOP);
	playSound(filePath);
#else // No Sound
	ofLog() << "Unsupported sound playback on this platform." << std::end;
#endif
	playing = false;
}
