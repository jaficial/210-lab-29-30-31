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
#include <array>
using namespace std;

const int MIN = 1, MAX = 100;
// rewriting the main function/thought process, the monetary value of a card must be a string to have all elements of the array to be list of strings
// map[key][list0] = movelist
// map[key][list1] = monetary_value
// map[key][list2] = rarity
void read_kreature(map<string, array<list<string>, 3>> &, ifstream);
string kreature_rarity();
void output_collection(map<string, array<list<string>, 3>>);

string kreature_rarity(){
    int temp_rarity;
    temp_rarity = (rand() % MAX) + MIN;

    if ((1 <= temp_rarity) && (temp_rarity <= 50)){ // Common rarity 50% chance rate
        return "Common";
    }
    else if ((51 <= temp_rarity) && (temp_rarity <= 70)){ // Uncommon rarity 20% chance rate
        return "Uncommon";
    }
    else if ((71 <= temp_rarity) && (temp_rarity <= 85)){ // Rare rarity 15% chance rate
        return "Rare";
    }
    else if ((86 <= temp_rarity) && (temp_rarity <= 95)){ // Ultra-Rare rarity 10% chance rate
        return "Ultra-Rare";
    }
    else if ((96 <= temp_rarity) && (temp_rarity <= 100)){ // Exotic rarity 5% chance rate
        return "Exotic";
    }
    else {
        return "Placeholder for bypassing no return on non-void function";
    }
}

void read_kreature(map<string, array<list<string>, 3>> &collection, ifstream fin){
    string temp_name;
    string temp_moves;
    string temp_value;
    string temp_rarity;
    getline(fin, temp_name); // name of kreature
    for (int i = 0; i < 3; i++){ // moves of the kreature
        getline(fin, temp_moves); // first move
        // need to fix pushing a value to a list of the map, cannot use iterators to access the different lists
        // possibly fixed the problem by including the "array" header 
        collection[temp_name][0].push_back(temp_moves); // should push back every read move list (3 moves per kreature)
    }

    getline(fin, temp_value); // monetary value of the kreature
    collection[temp_name][1].push_back(temp_value); // m_value gets pushed into list[1]
    temp_rarity = kreature_rarity();
    collection[temp_name][2].push_back(temp_rarity); // rarity of card gets pushed into list[2]
}

void output_collection(map<string, array<list<string>, 3>> collection){
    cout << "This is the contents of the current collection:" << endl;
    for (map<string, array<list<string>, 3>>::iterator it = collection.begin(); it != collection.end(); it++){ // CITED: cited output function from the "210-demo-std-map.cpp" example code
        cout << "Krazy Kreature: " << it->first << endl;
        
    }

}

int main(){
    srand(time(0));
    ifstream fin("Krazy-Kreatures-Alpha-Kreatures.txt");
    // need to fix rewriting the map 
    map<string, array<list<string>, 3>> collection;

    return 0;
}