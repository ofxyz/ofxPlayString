ofxStringSoundPlayer
====================

![thumb](ofxaddons_thumbnail.png)

This 'player' was made because I had over 500 sound files on a raspberry and couldn't load them all in memory.

This addon is using `aplay` on Linux and `PlaySoundA` on Windows.

### The Good
  - Lightweight  
  - No sound loaded in memory  
  - Threaded Non-blocking playback  
  - Works on Windows and Linux  
  - Tested on Raspberry Pi  

### The Bad
  - No playback controls  
  - Unknown latency (Not bad, for normal usage)  
  - .aiff files are not supported on Linux  
  - No MacOs support (Should be easy to add, send me a pull request!)  
  - Probably more, let me know.

## How to Use

Play a sound by passing a string:

    playFile("pathTo/Sound.wav"); 

See example.

## Version History:

**v1.0.0**: Finally an addon, need again.
