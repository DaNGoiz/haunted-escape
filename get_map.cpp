#include <iostream>
#include <fstream>
#include <string>

#include "generate_map.h"
#include "set_map.h"

using namespace std;

const int mapX = 25;
const int mapY = 100;

// Read all data from map.log
void getMapDataAll(char map[25][100]) {
    ifstream infile("map.log");

    if (infile.is_open()) {
        string file_contents((istreambuf_iterator<char>(infile)),
            istreambuf_iterator<char>());

        int row = 0;
        int col = 0;
        for (char c : file_contents) {
            if (c == '\n') {
                map[row][col] = '\0';
                row++;
                col = 0;
            } else {
                map[row][col] = c;
                col++;
            }
        }
    }
}

// Read data at point (x, y) from map.log
char getMapDataAtPoint(int x, int y) {
    char c;

    ifstream infile("map.log");

    if (infile.is_open()) {
        string file_contents((istreambuf_iterator<char>(infile)),
            istreambuf_iterator<char>());

        int row = 0;
        int col = 0;
        for (char c : file_contents) {
            if (c == '\n') {
                row++;
                col = 0;
            } else {
                if (row == x && col == y) {
                    return c;
                }
                col++;
            }
        }
    }

    return c;
}

// Get position of player
void getPlayerPosition(int& x, int& y) {
    ifstream infile("map.log");

    if (infile.is_open()) {
        string file_contents((istreambuf_iterator<char>(infile)),
            istreambuf_iterator<char>());

        int row = 0;
        int col = 0;
        for (char c : file_contents) {
            if (c == '\n') {
                row++;
                col = 0;
            } else {
                if (c == '@') {
                    x = row;
                    y = col;
                }
                col++;
            }
        }
    }

}

// Set color and print map elements
void printMapElement(char element) {
    if (element == '@')
        cout << "\x1b[43;30m" << element << "\x1b[0m";
    else if (element == '$' || element == '=')
        cout << "\x1b[33m" << element << "\x1b[0m";
    else if (element == '\'' || element == '"' || element == '`')
        cout << "\x1b[32m" << element << "\x1b[0m";
    else if (element == '#' || element == '!')
        cout << "\x1b[46;30m" << element << "\x1b[0m";
    else if (element == 'X')
        cout << "\x1b[90m" << element << "\x1b[0m";
    else if (element == '+')
        cout << "\x1b[31m" << element << "\x1b[0m";
    else if (element == '^') // different color
        cout << "\x1b[31m" << element << "\x1b[0m";
    else
        cout << element;
}

// Print the map on the console
void printMap(char map[25][100]) {
    for (int i = 0; i < mapX; ++i) {
        for (int j = 0; j < mapY; ++j) {
            printMapElement(map[i][j]);
        }
        cout << endl;
    }
}