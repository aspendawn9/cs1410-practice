// CS1410 - Assignment 04
#include <iostream>
#include <iomanip>  
#include <random>
#include <string>
#include <sstream>

using namespace std;

//list the sides of a die
enum class Side{One = 1, Two, Three, Four, Five, Six};

struct HistBar{ //represents a bar in a histogram
    int count;
    Side label;
};

//create a function for the name of the side
string nameOf(HistBar hh){
    if (hh.label == Side::One){
        return "One";
    }else if(hh.label == Side::Two){
        return "Two";
        }else if (hh.label == Side::Three){
        return "Three";
    }else if(hh.label == Side::Four){
        return "Four";
    }else if(hh.label == Side::Five){
        return "Five";
    }else{
        return "Six";
    }
}

//create the function to roll the dice n times
void rollDice(HistBar h[], int n = 1){
    default_random_engine en;
    uniform_int_distribution<> dist{1,6};

    // initialize each dice side to 0
    for(int i = 0; i < 6; i++){
         h[i].count = 0;
    }

    //store the results of rolling the dice using the random generator in h[] 
    for(int i = 0; i < n; i++){
        h[dist(en)-1].count++;
    }
}

//define histogram function
string histogram(HistBar h[], char c = '*'){
    stringstream ss;
     for (int i = 0; i < 6; i++) {
        ss << nameOf(h[i]) << ": ";
        for (int j = 0; j < h[i].count; j++) {
            ss << c;
        }
        ss << " (" << h[i].count << ")" << endl;
    }
    return ss.str();
}


void reset(HistBar h[]){
    for(int i = 0; i < 6; i++){
        h[i].count = 0;
    }
}

//create menu
string menuT(){
    stringstream sout;
    sout << "DICE ROLLING SIMULATION" << endl;
    sout << "=======================" << endl;
    sout << 1 << ". Roll Dice" << endl;
    sout << 2 << ". Display Histogram" << endl;
    sout << 3 << ". Reset Histogram" << endl;
    sout << 4 << ". Quit Program" << endl;
    return sout.str();

}


int main(){
    HistBar hist[6] = {{0, Side::One},{0, Side::Two}, {0, Side::Three}, {0, Side::Four}, {0, Side::Five}, {0, Side::Six}};
    string menu = menuT();
    int select;

    do{
        cout << menu << endl;
        cin >> select;

        if(select == 1){
            rollDice(hist,100);
        }else if(select == 2){
            cout << histogram(hist) << endl;
        }else if(select == 3){
            reset(hist);
        }



    }while(select != 4);


    return 0;
}
