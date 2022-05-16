// Copyright (c) 2022 Yiyun Qin All rights reserved
//
// Created by Yiyun Qin
// Created in May 2022
// This is a math program, calculating the area of the triangle

#include <iostream>
#include <string>
#include <iomanip>

void Triangle(float base, float height) {
    // This function calculates the area of the triangle

    // process & output
    float area;
    area = 1.0 / 2 * base * height;
    std::cout << "The area of the triangle is "
    << std::fixed << std::setprecision(2)
    << std::setfill('0') <<area << " cm²." << std::endl;
    std::cout << "\nDone.";
}


int main() {
    // This function does try and catch
    std::string baseString;
    std::string heightString;
    float baseFloat;
    float heightFloat;

    // input
    std::cout << "Enter the base length of the triangle (cm): ";
    std::cin >> baseString;
    std::cout << "Enter the height of the triangle (cm): ";
    std::cin >> heightString;

    // process
    std::cout << "" << std::endl;
    try {
        baseFloat = std::stof(baseString);
        heightFloat = std::stof(heightString);
        Triangle(baseFloat, heightFloat);
    } catch (std::invalid_argument) {
        std::cout << "Invalid number!" << std::endl;
        std::cout << "\nDone." << std::endl;
    }
}
