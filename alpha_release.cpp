// COMSC-210 | Jed Aficial | Lab 30
// github link: https://github.com/jaficial/210-lab-29-30-31.git

/* NOTE: This file will be dedicated to the alpha_release of the program
   - alpha_release.cpp will have a focused emphasis on making sure that the data is being read correctly
   - I will be making notes throughout the file if changes are made from the design I made in my pseudo/wirecode file
*/

// SLIGHT IDEA CHANGE: All cards have a different version/rarities of themselves
//  - rarity will not be featured in the data.txt file, but in the main file
//  - will use srand/rand() to create the rarity system within this file 

#include <iostream>
#include <fstream>
#include <algorithm>
#include <list>
#include <string>
#include <random>
#include <map>

using namespace std;

class Krazy_Kreature{
private:
    int monetary_value;
    string movelist[3];

public:
    // default constructor
    Krazy_Kreature(){}

    // parameter constructor
    Krazy_Kreature(int m_value, string moves[3]) {
        m_value = monetary_value;
        // copies the string array from movelist to moves
        for (int i = 0; i < 3; i++){
            moves[i] = movelist[i];
        }
    }
    // getters and setters
    void set_value(int m_value) {monetary_value = m_value;}
    int get_value() {return monetary_value;}
    
    void set_movelist(string moves[3]) {
        for (int i = 0; i < 3; i++){
            moves[i] = movelist[i];
        };
    }
    void get_movelist()

};