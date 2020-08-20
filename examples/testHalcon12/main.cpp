#include <iostream>

#include "halconcpp/HalconCpp.h"

int main()
{
    HalconCpp::HImage Mandrill("monkey");//read from file.
    Hlong width,height;
    Mandrill.GetImageSize(&width,&height);
    HalconCpp::HWindow w(0,0,width,height);// window with size equal to image
    Mandrill.DispImage(w);//display image in window
    w.Click();  // wait for mouse click
    w.ClearWindow();

    HalconCpp::HRegion Bright = Mandrill >= 128;         // select all bright pixels
    HalconCpp::HRegion Conn = Bright.Connection();       // get connected components

    // select regions with a size of at least 500 pixels
    HalconCpp::HRegion Large = Conn.SelectShape("area","and",500,90000);

    // select the eyes out of the instance variable Large by using
    // the anisometry as region feature:
    HalconCpp::HRegion Eyes = Large.SelectShape("anisometry","and",1,1.7);

    Eyes.DispRegion(w);// display result image in window
    w.Click();// wait for mouse click

    return 0;
}
