#pragma once
#include <vector>

struct LaserData
{
    float boardX;
    float boardY;
    float angle;
};



class LaserProjection
{
private:

    //Constand for laser system
    const float n = 1.33;
    const float d_glass = 0.04;


public:
    LaserProjection();
    ~LaserProjection();

    void readLaserData(char* filenName);

    void calculateBoardPosition();
    void calculateAngle();

    void printBoardResult();
    void printAngleResult();

    
    //-------   For simplicity theese are public for now  -------

    //Read data from file
    std::vector<LaserData> laserData;

    //Estimated position of the board
    std::vector<float> estimatedPosition;
};


