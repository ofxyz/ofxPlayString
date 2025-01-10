#include "ofxPlayString.h"
#include "ofLog.h"
#include <filesystem>

ofxPlayString::ofxPlayString() : m_sDataPath("")
{
    m_vThreads.clear();
}

ofxPlayString::~ofxPlayString()
{
    for (auto& thread : m_vThreads) {
        delete thread;
    }
    m_vThreads.clear();
}

void ofxPlayString::play(const std::string filePath, int delayMs /*= 0*/)
{
    m_vThreads.push_back(new strPlayer(m_sDataPath + filePath, delayMs));
    update(); // Clears old threads
}

void ofxPlayString::update()
{
    for (auto& player : m_vThreads) {
        if (!player->isPlaying()) {
            delete player;
            player = nullptr;
        }
    }
    m_vThreads.erase(std::remove_if(m_vThreads.begin(), m_vThreads.end(), [](strPlayer* player) {
        return player == nullptr; }), m_vThreads.end());
}

void ofxPlayString::setDataPath(std::string dataPath /*= "data/"*/)
{
    m_sDataPath = dataPath;
}

bool ofxPlayString::anyPlaying()
{
    for (auto& player : m_vThreads) {
        if (player->isPlaying()) {
            return true;
        }
    }
    return false;
}

ofxPlayString::strPlayer::strPlayer(std::string filePath, int delayMs /*= 0*/)
    : m_sFilePath(filePath),
      m_dDelayMs(delayMs),
      m_bPlaying(true)
{
    startThread();
};

#ifdef _WIN32
#include <Windows.h>
#include <mmsystem.h>

void ofxPlayString::strPlayer::play(std::string filePath) {
    std::wstring wFilePath(filePath.begin(), filePath.end());
    std::wstring command = L"open \"" + wFilePath + L"\"";
    mciSendString(command.c_str(), NULL, 0, NULL);
    command = L"play " + wFilePath + L" from 0";
    mciSendString(command.c_str(), NULL, 0, NULL);
}

void ofxPlayString::strPlayer::stop(std::string filePath) {
    std::wstring wFilePath(filePath.begin(), filePath.end());
    std::wstring command = L"stop " + wFilePath;
    mciSendString(command.c_str(), NULL, 0, NULL);
    command = L"close " + wFilePath;
    mciSendString(command.c_str(), NULL, 0, NULL);
}
#endif

void ofxPlayString::strPlayer::threadedFunction()
{
    if (m_dDelayMs > 0) {
        std::this_thread::sleep_for(std::chrono::milliseconds(m_dDelayMs));
    }

// We are in a threaded function so prefer to exit when sound has completed playback
#ifdef __linux__
    std::string cmd = "aplay " + m_sFilePath;
    ofSystem(cmd.c_str());
#elif defined _WIN32
    play(m_sFilePath);
#else // No Sound
    ofLog() << "Unsupported sound playback on this platform." << std::end;
#endif
    m_bPlaying = false;
}

bool ofxPlayString::strPlayer::isPlaying() { return m_bPlaying; }
