/* ********************************************************
 *   This file contains control algerithms that may be used 
 * in robotic arm control.
 * @Author : Derek Lai
 * @Date   : 2018/6/11
 * @Version: v1.0
 * Copyright(c) All right reserved
 * ********************************************************/

#ifndef __CONTROL_HPP__
#define __CONTROL_HPP__

#include <vector>
#include <opencv2/opencv.hpp>
#include "UsbCAN.hpp"
#include "BpNetwork.hpp"

//  This function change the motor pwm values from old values
//to new values by a fixed step Δx, where Δx = 1 by default. 
//It will not return until the new values are reached.
//@CAUTION: step should be positive integer!
void fixStepMove(std::vector<int>& newVals,
                 UsbCAN& canDev,
                 int ID,
                 int step = 1);


// Make all motor reset to initial states
void reset2initPos(std::vector<int>& newVals,
                   UsbCAN& canDev,
                   int ID,
                   int step = 1);


// The motor values of desired position is calculated
//by the network given.
void move2desiredPos(double x,double y,
                     std::vector<int>& newVals,
                     TfNetwork& network,
                     UsbCAN& canDev,
                     int ID,
                     int step = 1);

//  This function detect the rectangle area from (150,180) to 
//targetPos to find whether an obstacle is presented and return
//its height in the img.
double obstacleHeight(cv::Mat depthRaw,
                      float depthScale,
                      cv::Point2f targetPos);


//  This function retrun the angle between the target and the 
//yOz plane. Motor 1 should turn pass this angle so as to make
//the arms and the target in the same plane.
double motor1moveAngle(cv::Vec3d targetPos);


#endif
