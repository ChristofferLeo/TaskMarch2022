#include "LaserProjection.h"
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cmath>

LaserProjection::LaserProjection(/* args */){
    
}

LaserProjection::~LaserProjection(){
}

void LaserProjection::readLaserData(char* fileName){
    printf("Reading from file\n");
    
    std::ifstream file(fileName);

    //Handling file name error
    if (!file.is_open()) {
        std::cerr << "Failed to open file: " << fileName << std::endl;
        return;
    }

    std::string line;
    // Skipping header
    std::getline(file, line);

    while (std::getline(file, line)) {
        std::istringstream ss(line);
        LaserData reading;
        std::string value;

        // Extracting x-cordinate
        std::getline(ss, value, ',');
        reading.boardX = std::stof(value);

        // Extracting y-cordinate
        std::getline(ss, value, ',');
        reading.boardY = std::stof(value);

        // Extracting input angle
        std::getline(ss, value, ',');
        reading.angle = std::stof(value);

        laserData.push_back(reading);
    }

}

void LaserProjection::calculateBoardPosition(){
    float theta{0};
    float y_cordinate{0};

    for (LaserData reading : laserData){
        //Calculating the output angle
        theta = asin(sin(reading.angle) / n);

        //Calculating y-cordinate of the board
        y_cordinate = (reading.boardX - d_glass) * tan(theta);

        estimatedPosition.push_back(y_cordinate);
    }
}

void LaserProjection::calculateAngle(){
    float tempAngle;
    float estimatedAngle;

    for(auto reading : laserData){
        tempAngle = atan(reading.boardY / (reading.boardX-d_glass));

        estimatedAngle = asin(n * sin(tempAngle));

        estimatedPosition.push_back(estimatedAngle);
    }
}


void LaserProjection::printBoardResult(){
    // PRinting error
    for (int i = 0; i < laserData.size(); i++){
        printf("Error for reading %i was: %f \n", i, (laserData[i].boardY - estimatedPosition[i]));
        //printf("True value: %f \t Estimated Value: %f \n", laserData[i].boardY, estimatedPosition[i]);

    }
}

void LaserProjection::printAngleResult(){
    // PRinting error
    for (int i = 0; i < laserData.size(); i++){
        printf("Error for reading %i was: %f \n", i, (laserData[i].angle - estimatedPosition[i]));
        //printf("True value: %f \t Estimated Value: %f \n", laserData[i].boardY, estimatedPosition[i]);

    }
}