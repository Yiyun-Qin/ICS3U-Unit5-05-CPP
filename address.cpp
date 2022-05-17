// Copyright (c) 2022 Yiyun Qin All rights reserved
//
// Created by Yiyun Qin
// Created in May 2022
// This is a math program, formatting the address

#include <iostream>
#include <string>
#include <algorithm>

std::string Mail_Address(
    std::string name, std::string streetNumber, std::string streetName,
    std::string city, std::string province,
    std::string postalCode, std::string apartmentNumber = ""
) {
    // This function returns the string in mail format

    // process
    std::string mail;
    if (apartmentNumber != "") {
        mail = (
            name
            + "\n"
            + apartmentNumber
            + "-"
            + streetNumber
            + " "
            + streetName
            + "\n"
            + city
            + " "
            + province
            + "  "
            + postalCode);
    } else {
        mail = (
            name
            + "\n"
            + streetNumber
            + " "
            + streetName
            + "\n"
            + city
            + " "
            + province
            + "  "
            + postalCode);
    }
    std::for_each(mail.begin(), mail.end(), [](char & c) { c = ::toupper(c);});
    return mail;
}


main() {
    // This function does try and catch
    std::string fullName;
    std::string question;
    std::string apartmentNumberString = "";
    std::string streetNumberString;
    std::string streetName;
    std::string city;
    std::string province;
    std::string postalCode;
    std::string mail;
    std::string streetNumber;
    std::string apartmentNumber;
    int apartmentNumberInteger;
    int streetNumberInteger;

    // input
    std::cout << "This program formats your "
    << "address to a mailing address." << std::endl;
    std::cout << "Enter your full name: ";
    std::getline(std::cin, fullName);
    std::cout << "Do you live in an apartment? (y/n): ";
    std::cin >> question;
    if (question == "y" || question == "yes") {
        std::cout << "Enter your apartment number: ";
        std::cin >> apartmentNumberString;
    }
    std::cout << "Enter your street number: ";
    std::cin >> streetNumberString;
    std::cout << "Enter your street name "
    << "and type (Main St, Express Pkwy...): ";
    std::getline(std::cin, streetName);
    std::cout << "Enter your city: ";
    std::cin >> city;
    std::cout << "Enter your province "
    << "(as an abbreviation, ex: ON, BC...): ";
    std::cin >> province;
    std::cout << "Enter your postal code: ";
    std::getline(std::cin, postalCode);

    // process
    std::cout << "" << std::endl;
    try {
        streetNumberInteger = std::stoi(streetNumberString);
        if (apartmentNumberString != "") {
            apartmentNumberInteger = std::stoi(apartmentNumberString);
            apartmentNumber = std::to_string(apartmentNumberInteger);
            streetNumber = std::to_string(streetNumberInteger);
            mail = Mail_Address(
                fullName,
                streetNumber,
                streetName,
                city,
                province,
                postalCode,
                apartmentNumber);
        } else {
            streetNumber = std::to_string(streetNumberInteger);
            mail = Mail_Address(
                fullName,
                streetNumber,
                streetName,
                city,
                province,
                postalCode);
        }
        std::cout << mail << std::endl;
    } catch (std::invalid_argument) {
        std::cout << "Invalid number!" << std::endl;
    }
    std::cout << "\nDone." << std::endl;
}
