#include <iostream>
#include "BUS.h"
#include <stdio.h>
#include <conio.h>
int main() {
    char input;
    BUS bus;
    while (true) {
        std::cout << "1.Install" << std::endl;
        std::cout << "2.reservation" << std::endl;
        std::cout << "3.show reservation information" << std::endl;
        std::cout << "4.Exit" << std::endl;
        std::cin >> input;
        if (input == '1') {
            bus.writeData();
            bus.install();
            bus.storeData();
        }
        else if (input == '2') {
            bus.writeData();
            bus.reservation();
            bus.storeData();
        }
        else if (input == '3') {
            bus.writeData();
            bus.showReservationInformation();
        }
        else{
            break;
        }
    }
    return 0;
}
