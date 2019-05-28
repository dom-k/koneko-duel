#include <iostream>
#include <fstream>
#include "Menu.h"

Menu::Menu() {
    std::cout << "Menu constructed." << std::endl;
}

void printFile(const std::string &fileName) {
    std::ifstream fileStream;
    std::string line;

    fileStream.open(fileName);
    if (fileStream.is_open()) {
        while (std::getline(fileStream, line)) {
            std::cout << line << std::endl;
        }
    } else {
        std::cout << "Unable to open file " << fileName << std::endl;
    }

    fileStream.close();
}

void Menu::initMenu() {
    std::string headerFile = "../res/menu/Header.txt";
    char userInput;
    int err = 0;

    do {
        printFile(headerFile);

        std::cout << "\n";
        std::cout << "[S]: Start" << std::endl;
        std::cout << "[X]: Exit" << std::endl;

        std::cin >> userInput;

        if (userInput == 'S' || userInput == 's') {
            initStart();
        }

        if (userInput == 'X' || userInput == 'x') {
            err = 1;
        }

    } while (err == 0);
}

void Menu::initStart() {
    std::cout << "-- start --" << std::endl;
}