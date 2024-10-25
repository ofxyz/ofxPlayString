#include "ofApp.h"


//--------------------------------------------------------------
void ofApp::setup(){
	ofBackground(0, 0, 255);
	ssp.setDataPath("data/audio/");
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
	ofSetColor(255, 255, 255);
	ofDrawBitmapString("Press any key to play a sound.", 25, 25);
	ofDrawBitmapString("> or a number [0-9] to be more precise", 25, 50);

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	switch (key)
	{
	case '0':
		ssp.playFile("sample0.wav");
		break;
	case '1':
		ssp.playFile("sample1.wav");
		break;
	case '2':
		ssp.playFile("sample2.wav");
		break;
	case '3':
		ssp.playFile("sample3.wav");
		break;
	case '4':
		ssp.playFile("sample4.wav");
		break;
	case '5':
		ssp.playFile("sample5.wav");
		break;
	case '6':
		ssp.playFile("sample6.wav");
		break;
	case '7':
		ssp.playFile("sample7.wav");
		break;
	case '8':
		ssp.playFile("sample8.wav");
		break;
	case '9':
		ssp.playFile("sample9.wav");
		break;
	default:
		ssp.playFile("sample" + to_string((int)ofRandom(9)) + ".wav");
		break;
	};
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
