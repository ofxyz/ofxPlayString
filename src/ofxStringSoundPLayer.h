#pragma once

#include "ofThread.h"
#include <vector>
#include <string>

class ofxStringSoundPlayer {
public:
    ofxStringSoundPlayer();
    ~ofxStringSoundPlayer();

    void playFile(std::string filePath);
    void update(); // Not really necessary
    // Also optional, so you do not have to give a full path
    // you would call this once in setup
    void setDataPath(std::string path = "data/");

private:
    class SsPlayer : public ofThread {
    public:
        SsPlayer(std::string filePath);
        bool isPlaying();
        void threadedFunction();
    private:
        std::string filePath;
        bool playing;
    };

    std::string dataPath;
    std::vector<SsPlayer*> players;
};
