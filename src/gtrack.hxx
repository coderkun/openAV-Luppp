
#ifndef LUPPP_G_TRACK_H
#define LUPPP_G_TRACK_H

#include <iostream>

#include <FL/Fl.H>
#include <FL/Fl_Group.H>
#include <FL/Fl_Slider.H>
#include <FL/Fl_Progress.H>
#include <FL/Fl_Native_File_Chooser.H>

#include "avtk/avtk_box.h"
#include "avtk/avtk_dial.h"
#include "avtk/avtk_button.h"
#include "avtk/avtk_background.h"
#include "avtk/avtk_light_button.h"
#include "avtk/avtk_radial_status.h"

#include "avtk/volume.hxx"
#include "avtk/clipselector.hxx"

#include "config.hxx"
#include "audiobuffer.hxx"
#include "eventhandler.hxx"

using namespace std;

class GTrack : public Fl_Group
{
  public:
    
    Avtk::Volume*       getVolume(){return &volume;}
    Avtk::RadialStatus* getRadialStatus(){return &radial;}
    Avtk::ClipSelector* getClipSelector(){return &clipSel;}
    
    GTrack(int x, int y, int w, int h, const char* l = 0 );
    
    
    // getters
    float getSend();
    float getXSide();
    
    bool getSendActive();
    bool getKeyActive();
    bool getRecordActive();
    
    // setters
    void setSend(float s);
    void setXSide(float s);
    
    void setSendActive(bool a);
    void setKeyActive(bool a);
    void setRecordActive(bool a);
    
  
    int ID;
    
    Avtk::Background bg;
    
    Avtk::RadialStatus radial;
    
    Avtk::ClipSelector clipSel;
    
    Avtk::Box    volBox;
    
    Avtk::Volume volume;
    
  private:
    Avtk::Dial        sendDial;
    Avtk::LightButton sendActive;
    
    Avtk::Dial        xsideDial;
    Avtk::LightButton keyActive;
    
    Avtk::LightButton recordActive;
    
    
    static int privateID;
};

#endif // LUPPP_G_TRACK_H

