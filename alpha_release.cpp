// COMSC-210 | Jed Aficial | Lab 30
// github link: https://github.com/jaficial/210-lab-29-30-31.git

/* NOTE: This file will be dedicated to the alpha_release of the program
   - alpha_release.cpp will have a focused emphasis on making sure that the data is being read correctly
   - I will be making notes throughout the file if changes are made from the design I made in my pseudo/wirecode file
*/

// SLIGHT IDEA CHANGE: All cards have a different version/rarities of themselves
//  - rarity will not be featured in the data.txt file, but in the main file
//  - will use srand/rand() to create the rarity system within this file 

// SLIGHT CHANGE: Will need to change the way data is collected in order to have an array of lists, 
// OMITTING THE "Krazy_Kreature" class, 
#include <iostream>
#include <fstream>
#include <algorithm>
#include <list>
#include <string>
#include <random>
#include <map>

using namespace std;

// rewriting the main function/thought process, the monetary value of a card must be a string to have all elements of the array to be list of strings
void read_kreature(map<string, array<list<string>, 3>> &, ifstream);
void kreature_rarity(map<string, array<list<string>, 3>> &);
void output_collection(map<string, array<list<string>, 3>>);

void read_kreature(map<string, array<list<string>, 3>> &collection, ifstream fin){
    string temp_string;
    getline(fin, temp_string); // name of kreature
}

void kreature_rarity(map<string, array<list<string>, 3>> &collection){

}

int main(){
    srand(time(0));
    ifstream fin("Krazy-Kreatures-Alpha-Kreatures.txt");
    // need to fix rewriting the map 
    map<string, array<list<string>, 3>> collection;

    return 0;
}