#pragma once

#include "ofMain.h"
// #include "auraDisplay.h"

#include "ofxCv.h"
#include "ofxGui.h"
#include "ofxAnimatableFloat.h"

#include "ConsoleListener.h"
#include "sceneManager.h"
#include "utils.h"
#include "auraDisplay.h"

#ifdef __arm__
    #include "ofxCvPiCam.h"
#endif

class ofApp : public ofBaseApp , public SSHKeyListener{
    
public:
    void setup();
    void update();
    void draw();
    
    void keyPressed(int key);
    void keyReleased(int key);
    void mouseMoved(int x, int y );
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void windowResized(int w, int h);
    void dragEvent(ofDragInfo dragInfo);
    void gotMessage(ofMessage msg);
    
    bool debug;
    
    // SSH Keystroke Capture
    ConsoleListener consoleListener;
    void onCharacterReceived(SSHKeyListenerEventData& e);
    
    // GUI & Settings
    void setupGui();
    ofxPanel gui;
    ofParameterGroup paramsGroup1;
    ofParameter<float> pColorR;
    ofParameter<float> pColorG;
    ofParameter<float> pColorB;
    ofParameter<int> pMultiplier;
    ofParameter<int> pDivider;
    
    ofParameter<int> pBrightnessMin;
    ofParameter<int> pBrightnessMax;
    ofParameter<int> pBrightness;
    void pBrightnessChanged(int &value);

    
    ofParameter<int> pPiCamBrightness;
    ofParameter<int> pPiCamContrast;
    
    ofParameter<int>  pPiCamExposureMeteringMode;
    ofParameter<int>  pPiCamExposureCompensation;
    ofParameter<int>  pPiCamExposureMode;
    
    ofParameter<int>  pPiCamISO;
    ofParameter<float> pPiCamRoiX;
    ofParameter<float> pPiCamRoiY;
    ofParameter<float> pPiCamRoiW;
    ofParameter<float> pPiCamRoiH;
    ofParameter<int> pPiCamImageFX;

    
    void pPiCamBrightnessChanged(int &value);
    void pPiCamContrastChanged(int &value);
    
    void pPiCamRoiXChanged(float &value);
    void pPiCamRoiYChanged(float &value);
    void pPiCamRoiWChanged(float &value);
    void pPiCamRoiHChanged(float &value);
    void pPiCamExposureMeteringModeChanged(int &value);
    void pPiCamExposureModeChanged(int &value);
    void pPiCamExposureCompensationChanged(int &value);
    void pPiCamISOChanged(int &value);
    void pPiCamImageFXChanged(int &value);

    
    ofRectangle ROI;
    string PiCamExposureModes[14];
    string PiCamExposureMeteringModes[5];
    string PiCamImageFXLabels[24];

    int activeSettingParam;
    
    // DISPLAY / LED MATRIX
    auraDisplay ledDisplay;
    
    // CAM
    #ifdef __arm__
        ofxCvPiCam cam;
    #else
        ofVideoGrabber cam;
    #endif
    
    // FACEDETECTION
    ofxCv::ObjectFinder finder;
    ofImage img;
    
    bool personPresent;
    bool personPresentLastFrame;
    bool personPresentChanged;
    
    float personBrightness;
    auraTimer presentTimer;
    auraTimer fpsOutTimer;
    
    // THE AURAL FACTOR
    float aFactor;
    float aFactorLast;
    
    // SCENES
    sceneManager SM;
    ofxAnimatableFloat sceneBlend;
    
    // HACKS
    bool sawSomeone;

};



