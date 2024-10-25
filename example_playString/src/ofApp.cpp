#include "ofApp.h"


//--------------------------------------------------------------
void ofApp::setup(){
	ofBackground(0, 0, 255);
	playString.setDataPath("data/audio/");
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
		playString.play("sample0.wav");
		break;
	case '1':
		playString.play("sample1.wav");
		break;
	case '2':
		playString.play("sample2.wav");
		break;
	case '3':
		playString.play("sample3.wav");
		break;
	case '4':
		playString.play("sample4.wav");
		break;
	case '5':
		playString.play("sample5.wav");
		break;
	case '6':
		playString.play("sample6.wav");
		break;
	case '7':
		playString.play("sample7.wav");
		break;
	case '8':
		playString.play("sample8.wav");
		break;
	case '9':
		playString.play("sample9.wav");
		break;
	default:
		playString.play("sample" + to_string((int)ofRandom(9)) + ".wav");
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
