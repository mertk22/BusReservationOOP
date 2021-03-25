
#include <stdio.h>
#include <conio.h>
#include "BUS.h"
#include <iostream>
#include <string>
#include <cstdlib>
#include <fstream>

BUS::BUS() {
    for (int i = 0; i < 3; ++i) {
        busNo[i] = 0;
        drivers_name[i]  = "not-set";
        arrivalTime[i]   = "not-set";
        departureTime[i] = "not-set";
        from[i]          = "not-set";
        to[i]            = "not-set";
    }

}
void BUS::storeData() {
    outFile.open("BusData.txt");
    for (int i = 0; i < 3; ++i) {
        outFile << busNo[i] << " ";
        outFile << drivers_name[i] << " ";
        outFile << arrivalTime[i] << " ";
        outFile << departureTime[i] << " ";
        outFile << from[i] << " ";
        outFile << to[i] << " " << std::endl;
    }
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 8; ++j) {
            outFile << seat[i][j] << " ";
        }std::cout << std::endl;
    }
    outFile.close();
}
void BUS::writeData(){
    inFile.open("BusData.txt");
    for (int i = 0; i < 3; ++i) {
        inFile >> busNo[i];
        inFile >> drivers_name[i];
        inFile >> arrivalTime[i];
        inFile >> departureTime[i];
        inFile >> from[i];
        inFile >> to[i];
    }
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 8; ++j) {
            inFile >> seat[i][j];
        }
    }
    inFile.close();
}
void BUS::install() {
    for (int i = 0; i < 3; ++i) {
        std::cout << "Enter bus number :";
        std::cin >> busNo[i];
        std::cout << "Enter drivers name :";
        std::cin >> drivers_name[i];
        std::cout << "arrival time :";
        std::cin >> arrivalTime[i];
        std::cout << "departure time :";
        std::cin >> departureTime[i];
        std::cout << "from:";
        std::cin >> from[i];
        std::cout << "to :";
        std::cin >> to[i];
    }
}

void BUS::reservation() {
    int k = 0;
    int s;
    int b;
    std::cout <<"Enter a bus number :" ; std::cin >> b;
    std::cout << "showing results for bus " << busNo[b-1] << std::endl;
    std::cout << "enter a seat number of choice :" ; std::cin >> s;
    std::cout << "enter your name :" ; std::cin >> passengersName;
    for (int i = 0; i < 16; ++i) {
        std::cout << "#" ;
    }std::cout << std::endl;
    std::cout << "Driver :  " << drivers_name[b-1] << "   /  Arrival time  :  " << arrivalTime[b-1] << "  Departure time  :  " << departureTime[b-1] << std::endl;
    std::cout << std::endl;
    std::cout << "From       :" << from[b-1] << "    /To        :" << to[b-1] << std::endl;
    for (int i = 0; i < 16; ++i) {
        std::cout << "#" ;
    }std::cout << std::endl;
    seat[b-1][s-1] = passengersName;
    for (int j = 0; j < 4; ++j) {
        for (int l = 0; l < 2; ++l) {
            std::cout << k+1 << "." << seat[b-1][k] << " ";
            k++;
        }
        std::cout << std::endl;
    }
    for (int j = 0; j < 16; ++j) {
        std::cout << "#";
    }
    std::cout << std::endl;
}
void BUS::showReservationInformation() {
    int b;
    std::cout << "Enter a bus number :" ; std::cin >> b;
    std::cout << "showing results for bus " << busNo[b-1] << std::endl;
    for (int i = 0; i < 16; ++i) {
        std::cout << "#" ;
    }std::cout << std::endl;
    std::cout << "Driver :  " << drivers_name[b-1] << "   /  Arrival time  :  " << arrivalTime[b-1] << "  Departure time  :  " << departureTime[b-1] << std::endl;
    std::cout << std::endl;
    std::cout << "From       :" << from[b-1] << "    /To        :" << to[b-1] << std::endl;
    for (int i = 0; i < 16; ++i) {
        std::cout << "#" ;
    }std::cout << std::endl;
    int k = 0;
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 2; ++j) {
            std::cout << k+1 << "." << seat[b-1][k] << "  ";
            k++;
        }std::cout << std::endl;
    }
    for (int j = 0; j < 16; ++j) {
        std::cout << "#";
    }std::cout << std::endl;
    int emptySeats = 0;

    for (int i = 0; i < 8; ++i) {
        if (seat[b-1][i] == "empty"){
            emptySeats++;
        }
        else{
            std::cout << "seat no " << i+1 << " is reserved to " << seat[b-1][i] << std::endl;
        }
    }
    std::cout << "there are " << emptySeats << " empty seats" << std::endl;
    std::cout << std::endl;
}

