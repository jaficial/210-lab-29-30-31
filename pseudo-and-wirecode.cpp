// COMSC-210 | Jed Aficial | Lab 29
// github link: https://github.com/jaficial/210-lab-29-30-31.git

// PSEUDO CODE FOR Krazy Kreatures Collectible Cards
// NOTE: Changes are to be made, and some features from pseudocode and wirecode may be altered, deleted, or added for the final program

/*
    // class for Krazy Kreature object

    // void DEFINE PACK_OPENER function to simulate the user opening a card pack of Krazy Kreatures
    // pack_opener function will draw four random sets of data from an external file
        - each random set of data will contain the a string: name of the Krazy Kreature, array of strings: move lists, int: monetary value of the card, int (or possibly custom struct): representing rarity
        - each set of UNIQUE data will be stored into the map
        - pack_opener function will utilize temporary variables to store the data of each card 
    
    // monetary_calculator function:
        - monetary_calculator will take in the map as a parameter, and will use a static int to constantly add the monetary value of each card
        - will return the int amount of money the collection is worth

    // void output_collection: 
        // output_collection will output all the collected cards that have been stored into the map, (user's collection), in order based on rarity 
        // first set of cards that will be outputted will be common cards, then uncommon, rare, ultra-rare, and finally exotic cards
    
    // MAIN FUNCTION:
        // uses srand(time(0)) to simulate unique randomization for each time the program is ran
        // open file to read the data of all possible available cards within the Krazy Kreatures universe
        // initialize map (user's Krazy Kreatures card collection)
        // for 25 time iterations
            // user "opens" a pack of cards, (uses the pack_opener function)
            // after a user opens a pack, the current collection will be displayed
            // monetary value of the collection will also be outputted, (and possibly the amount of each card rarity?)
        
        // By the end of the 25 time interations, the user's collection will be outputted one last time, showcasing the monetary value, rarity, and set of moves for each Krazy Kreature in their collection
        // The monetary value of the whole collection will also be outputted (along with possibly the amount of cards for each rarity that the user has?)            

*/

// WIRECODE FOR Krazy Kreatures Collectible Cards (1 simulation)
#include <iostream>
#include <fstream>
#include <algorithm>
#include <list>
#include <string>
#include <random>
#include <map>

using namespace std;

// NEED TO COME BACK TO PASSING AN ARRAY OF STRINGS AS A PARAMTER FOR THE CONSTRUCTOR (movelist)
class Krazy_Kreature {
private:
    // string movelist[3];
    int monetary_value;
    string rarity;

public:
    //default constructor
    Krazy_Kreature(){}

    Krazy_Kreature(int m_value, string rare) {
        // string m_list = *movelist;
        m_value = monetary_value;
        rare = rarity;
    }
    // getters and setters
    void set_value(int m_value) {monetary_value = m_value;}
    int get_value() {return monetary_value;}

    void set_rarity(string rare) {rarity = rare;}
    string get_rarity() {return rarity;}
    
};

// pack_opener takes in the map, and the input file stream as parameters
void pack_opener(map<string, list<string, Krazy_Kreature>> &collection, ifstream& fin){ // pack_opener should read from file, and insert the read data into the map 
    string temp_name;
    string temp_move1;
    int temp_value;
    string temp_rarity;

    getline(cin, temp_name);
    getline(cin, temp_move1);
    cin >> temp_value;
    cin.ignore();
    getline(cin, temp_rarity);

    Krazy_Kreature temp_object(temp_value, temp_rarity);
    pair<string, Krazy_Kreature> temp_pair; // CITED: https://www.geeksforgeeks.org/forward-list-and-list-of-pairs-in-c-with-examples/ on declaring pairs/inserting pairs into a list; may be having interference with Krazy_Kreatures class object
    temp_pair = make_pair(temp_move1, temp_object);
    list<pair<string, Krazy_Kreature>> temp_list;
    
    collection.insert(temp_name, temp_list); // ERROR: with Krazy_Kreature object, NEED TO FIX
}

int main(){
    map<string, list<string, Krazy_Kreature>> collection;
    ifstream fin("Krazy-Kreatures-1-Kreature.txt");
    for (int i = 0; i < 1; i++){
        pack_opener(collection, fin);
    }
    //output_collection function call
    fin.close();
    return 0;
}
