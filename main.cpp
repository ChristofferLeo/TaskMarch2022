//
// This is example code from Chapter 2.2 "The classic first program" of
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
//
// This program outputs the message "Hello, World!" to the monitor

#include "std_lib_facilities.h"
#include "LaserProjection.h"

//------------------------------------------------------------------------------'

// C++ programs start by executing the function main
int main() {


    // ------    Task A ---------

    //Calculating y-cordinates
    LaserProjection projection;
    projection.readLaserData("a.csv");
    projection.calculateBoardPosition();

    //Comparing to real value
    projection.printBoardResult();


    // -----  Task B -------
    LaserProjection projectionB;
    projectionB.readLaserData("b.csv");
    projectionB.calculateAngle();

    //Comparing to real value
    projectionB.printAngleResult();

    return 0;
}

//------------------------------------------------------------------------------
