ofxPlayString
=============

![thumb](ofxaddons_thumbnail.png)

This addon was created because I had over 500 sound files on a raspberry and couldn't load them all in memory.

This addon is using `aplay` on Linux and `mciSendString` on Windows.

### The Good
  - Lightweight  
  - No sound loaded in memory  
  - Threaded Non-blocking playback  
  - Works on Windows and Linux  
  - Tested on Raspberry Pi  
  - NEW! Added delay parameter for forward scheduling  

### The Bad
  - No playback controls  
  - Unknown latency (Actually not bad)  
  - Not all sound formats supported.  
  - No MacOs support (Should be easy to add, send me a pull request!)  
  - Probably more, let me know.

### The Simple

    stringPlayer.play("myFile.wav"); 

See example.
