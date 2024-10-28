#pragma once

#include "ofThread.h"
#include <vector>
#include <string>

class ofxPlayString {
public:
    ofxPlayString();
    ~ofxPlayString();

    void play(const std::string filePath);
    void update(); // Not really necessary
    // Also optional, so you do not have to give a full path
    // you would call this once in setup
    void setDataPath(const std::string path = "data/");
    bool anyPlaying();

private:
    class strPlayer : public ofThread {
    public:
        strPlayer(const std::string& filePath);
#ifdef _WIN32
        void play(const std::string& filePath);
        void stop(const std::string& filePath);
#endif
        void threadedFunction();
        bool isPlaying();
    private:
        std::string m_sFilePath;
        bool m_bPlaying;
    };

    std::string m_sDataPath;
    std::vector<strPlayer*> m_vThreads;
};
