// COMSC-210 | Jed Aficial | Lab 31
// github link: https://github.com/jaficial/210-lab-29-30-31.git

// IMPORTING ALPHA_RELEASE PROGRAM TO THIS FILE 
#include <iostream>
#include <fstream>
#include <algorithm>
#include <list>
#include <string>
#include <random>
#include <map>
#include <array>
#include <ctime>
#include <vector>
using namespace std;

const int MIN = 1, MAX = 100;
// map[key][list0] = movelist
// map[key][list1] = monetary_value
// map[key][list2] = rarity
void read_kreature(map<string, array<list<string>, 3>> &, ifstream &, vector<int> &);
string kreature_rarity();
void output_collection(map<string, array<list<string>, 3>>);
void colletion_value(vector<int>); // added function to add up the value of the collection after collecting 25 cards
int card_value(int, string);

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

int card_value(string rarity, int value){
    if (rarity == "Common"){
        return value;
    }
    else if(rarity == "Uncommon"){
        return value * 1.5;
    }
    else if (rarity == "Rare"){
        return value * 3;
    }
    else if (rarity == "Ultra-Rare"){
        return value * 5;
    }
    else{
        return value * 10;
    }
}

// read_kreature is reading data from the file as expected
void read_kreature(map<string, array<list<string>, 3>> &collection, ifstream &fin, vector<int> &collection_mvalues){
    string temp_name; // name of Krazy Kreature
    string temp_moves; // name of moves
    string temp_value; // monetary value of base card
    string temp_rarity; // rarity of card
    int temp_value_int; // temp variable to hold int of base card value
    int rarity_value; // monetary value of card, based on rarity

    string endl_container; // read endls into this variable 

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
    
    temp_value_int = stoi(temp_value);// CITED: https://www.geeksforgeeks.org/convert-string-to-int-in-cpp/ on figuring out how to use stoi in order to type cast a string into an int
    rarity_value = card_value(temp_rarity, temp_value_int);
    collection_mvalues.push_back(rarity_value);
    getline(fin, endl_container);
}

void output_collection(map<string, array<list<string>, 3>> collection, vector<int> collection_mvalues){
    auto collection_mvalues_iterator = collection_mvalues.begin();
    cout << "This is the contents of the current collection:" << endl;
    for (map<string, array<list<string>, 3>>::iterator it = collection.begin(); it != collection.end(); it++){ // CITED: cited output function from the "210-demo-std-map.cpp" example code
        cout << "Krazy Kreature: " << it->first << endl; // name (or key of map) of Krazy Kreature
        
        for (auto movelist : it->second[0]){ // outputs all moves from move list into one line, NOTE: need to fix the output for the last move
            cout << movelist << ", "; 
            
        }
        cout << endl;
        for (auto rarity: it->second[2]){
            cout << "Rarity: " << rarity;
        }
        cout << endl;
        for (auto m_value : it->second[1]){ // CITED: cited output method from the "210-demo-stl-list-with-objects" example program
            cout << "Base Monetary Value: $" << m_value << endl;
            cout << "Card Monetary Value: $" << *collection_mvalues_iterator; //
            collection_mvalues_iterator++;
        }
        cout << endl << endl;
    }
    
}

// NEED TO REWRITE THIS FUNCTION, COME BACK TO THIS
void collection_value(vector<int> &collection_mvalues){
    auto collection_value_iterator = collection_mvalues.begin();
    int collection_total_value;
    for (collection_value_iterator < collection_mvalues.end();  )
}

int main(){
    srand(time(0));
    ifstream fin("Krazy-Kreatures-Beta-Kreatures.txt");
    map<string, array<list<string>, 3>> collection;
    vector<int> collection_mvalues; // using vector as a container for all the card's values

    for (int i = 0; i < 2; i++){
        read_kreature(collection, fin, collection_mvalues); // error, can't pass ifstream value by value. Has to be passed by reference
        output_collection(collection, collection_mvalues);

        if (fin.eof()){
            cout << "End of file reached!" << endl;
            break;
        }
    }
    
    // collection_value(collection, collection_mvalues);
    // // testing if the vector is accepting the values from the "collection_value" function
    // // WORKING
    // for (int i : collection_mvalues){
    //     cout << i << endl;
    // }
    fin.close();
    return 0;
}