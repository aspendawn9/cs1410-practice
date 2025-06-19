#include <iostream>
#include <iomanip>
#include <random>
#include <string>
#include <sstream>

using namespace std;

enum class Side{ //lists the sides of the die
    One, Two, Three, Four, Five, Six
};
 
// represents a bar in a histogram
struct HistBar{
    int count;
    Side label;
};

default_random_engine en;
uniform_int_distribution<> dist{1, 2, 3, 4, 5, 6};



// define a function prototype to simulate rolling the dice and store the values
void rollDice(HistBar h[], int n = 1);

// create a function that resets the count member of every bar in h to 0
void reset(HistBar h[]);



int main(){
    
    
    // create an array of HistBars with count 0 and each with the correct side
    HistBar hist[6] = {{0, Side::One},{0, Side::Two}, {0, Side::Three}, {0, Side::Four}, {0, Side::Five}, {0, Side::Six}};

    // define a function prototype to simulate rolling the dice and store the values
    void rollDice(HistBar h[], int n = 1){
        hist[r(en)]++;
    };

    // create a function that resets the count member of every bar in h to 0
    void reset(HistBar h[]){
        h.count = 0;
    }; 

    

    // define a function to build the histogram
    string histogram(HistBar h[], char c = '*'){
    stringstream sout;
    sout << "ONE: " << histogram(h[0],c) << hist.count[0] << endl;
    sout << "TWO: " << histogram(h[1],c) << hist.count[1] << endl;
    sout << "THREE: " << histogram(h[2],c) << hist.count[2] << endl;
    sout << "FOUR: " << histogram(h[3],c) << hist.count[3] << endl;
    sout << "FIVE: " << histogram(h[4],c) << hist.count[4] << endl;
    sout << "SIX: " << histogram(h[5],c) << hist.count[5] << endl;
    }


    // initialize an integer that will be used to take in options from the user
    int x;

    // create a do while loop that outputs the menu options 
    do{
        cout << "DICE ROLLING SIMULATION" << endl;
        cout << "=======================" << endl;
        cout << 1 << ". Roll Dice" << endl;
        cout << 2 << ". Display Histogram" << endl;
        cout << 3 << ". Reset Histogram" << endl;
        cout << 4 << ". Quit Program" << endl;

        //take in a choice from the user
        cin >> x;

        if(x == 1){
            rollDice(100)
        }else if(x == 2){
            cout << histogram << endl;
        } else if(x ==3){
            reset(h[])
        }else{
            break;
        }

    }while(x != 4);
    
    return 0;
}