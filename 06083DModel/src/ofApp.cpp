#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    yourModel.loadModel("Hip.3ds");
    
    ofSetFrameRate(60);
    ofBackground(0);
    ofEnableDepthTest();
    //ライトを配置
    //light.enable();
    //light.setPosition(-100, 100, 500);
    //球からメッシュを生成
    mesh = yourModel.getMesh(0);
    //メッシュの色を設定
    for (int i = 0; i < mesh.getVertices().size(); i++) {
        mesh.addColor(ofFloatColor(1.0, 1.0, 1.0, 1.0));
    }
    
}

//--------------------------------------------------------------
void ofApp::update(){
    
    //頂点の数だけ繰り返し
    for (int i = 0; i < mesh.getVertices().size(); i++) {
        //頂点の位置を取得
        ofVec3f loc = mesh.getVertices()[i] / 300.0;
        //perlinノイズを生成
        float noise = ofMap(ofNoise(loc.x, loc.y, loc.z, ofGetElapsedTimef()), 0, 1, 80, 240);
        //ノイズの値で頂点位置を変更
        ofVec3f newLoc = loc.normalize()* noise;
        mesh.setVertex(i, newLoc);
        //頂点の色を設定
        float c = ofMap(ofNoise(loc.x, loc.y, loc.z, ofGetElapsedTimef()),0, 1, 0.5, 1.0);
        mesh.setColor(i, ofFloatColor(c, c, c, 1.0));
    }
   
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    cam.begin();
    ofPushMatrix();
    ofRotateY(ofGetElapsedTimef()*10.0);
    mesh.drawWireframe();
    ofPopMatrix();
    cam.end();

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    
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
