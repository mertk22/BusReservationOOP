
#include <fstream>
#ifndef BUSRESERVATIONSYSTEMOOP_BUS_H
#define BUSRESERVATIONSYSTEMOOP_BUS_H
#include <iostream>
#include <string>
class BUS {
protected:
    std::ofstream outFile;
    std::ifstream inFile;
        int busNo[3];
        std::string drivers_name[3],passengersName;
        std::string arrivalTime[3];
        std::string departureTime[3];
        std::string from[3],to[3];
        std::string seat[3][8] = {{"empty","empty","empty","empty","empty","empty","empty","empty"},
                                  {"empty","empty","empty","empty","empty","empty","empty","empty"},
                                  {"empty","empty","empty","empty","empty","empty","empty","empty"}};
public:

        BUS();
        void storeData();
        void writeData();
        void install();
        void reservation();
        void showReservationInformation();

};


#endif //BUSRESERVATIONSYSTEMOOP_BUS_H
