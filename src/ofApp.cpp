#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofSetBackgroundColor(0, 0, 0);

	// Camera at Z = 50, looking in the +Y direction.
	_cam.setPosition(0, 0, 50);
	_cam.lookAt(glm::vec3(0, 1000, 0), glm::vec3(0, 0, 1));
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
	_cam.begin();

	// Light-green grid on the X/Y plane (Z = 0), lines every 50 units.
	ofSetColor(144, 238, 144);
	const int extent = 500;
	for (int i = -extent; i <= extent; i += 50) {
		// Lines parallel to the Y axis.
		ofDrawLine(i, -extent, 0, i, extent, 0);
		// Lines parallel to the X axis.
		ofDrawLine(-extent, i, 0, extent, i, 0);
	}

	_pawn.drawTrail();
	_pawn.draw();

	_cam.end();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	if (key == OF_KEY_UP) {
		_pawn.moveForward(50);
	} else if (key == OF_KEY_LEFT) {
		_pawn.turnLeft();
		_pawn.moveForward(50);
	} else if (key == OF_KEY_RIGHT) {
		_pawn.turnRight();
		_pawn.moveForward(50);
	}
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

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
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

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
