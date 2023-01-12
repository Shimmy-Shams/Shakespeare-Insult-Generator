/* 	
 * 	TestInsultGenerator.cpp
 *
 *      Name: Shams Sajid
 * 		Course: CMPE 320
 * 		Student Number: 20217791
 * 
 * 		Author: Alan McLeod
 *      A testing program for CISC320 assignment 1.
 */

#include <iostream>
#include <fstream>
#include <string>
#include <utility>
#include <vector>
#include <set>
#include <algorithm>
#include <time.h>
#include <stdlib.h>

#include "insultgenerator_19srs12.h"


using namespace std; 


// Throws an error if the file could not be read 
FileException::FileException(const string& message) : message(message) {}
string FileException::what() const { return message; }


// Throws error if the provide number of insults is out of the bounds limit
NumInsultsOutOfBounds::NumInsultsOutOfBounds (const string& message) : message(message) {}
string NumInsultsOutOfBounds:: what () const { return message; }


// Creating a constructor
InsultGenerator::InsultGenerator() : sourceFileSize(0) {
    srand(time(0));
}


// Creating an initializer that will read the source file and then split each line into 3 columns
void InsultGenerator::initialize() {

    string insultPhrase;
    ifstream fileIn;

    fileIn.open ("InsultsSource.txt");
    if (fileIn.fail()){
        throw FileException ("Error: Illegal File");
        return;
        } // End if


    while (!fileIn.eof()) {
        fileIn >> insultPhrase;
        word1.push_back(insultPhrase);
        fileIn >> insultPhrase;
        word2.push_back(insultPhrase);
        fileIn >> insultPhrase;
        word3.push_back(insultPhrase);
        sourceFileSize++;
    }

    fileIn.close();

}// End the read txt file method



// Creating a random number generator
int InsultGenerator::randInt(int upperLimit) const {
    int randInt = rand() % upperLimit;
    return randInt;
} // end randInt

// Returns 1 insult based on the random number
string InsultGenerator::talkToMe() const {
	string insult("Thou ");

	insult += word1.at(randInt(sourceFileSize));
	insult += " " + word2.at(randInt(sourceFileSize)) + " ";
	insult += word3.at(randInt(sourceFileSize)) + "!";

    return insult;
} // end talkToMe


/*  
    Generates the desired number of insults using the 3D bool array. 
    This algorithm does not require any sorting or searching. 
    It will automatically generate the desired number of insults in order 
    since the phrases are already in order.

*/
vector <string> InsultGenerator::generate(int numOfInsults) const{

    // Throws an error if the number of insults is not within the accepted range
    if (numOfInsults > maxInsults || numOfInsults < 1 )
        throw NumInsultsOutOfBounds ("Error: Illegal number of insults. The number of insults must be between 1 - 10,000");

    set <string> insultsSet;
    string insult;

    // Creating a set of insults that is automatically sorted in order
    while (numOfInsults > insultsSet.size()){
        insult = std::string(talkToMe());
        insultsSet.insert(insult);
    }
    vector<string> insults;
    copy (insultsSet.begin(), insultsSet.end(), back_inserter(insults));
	return insults;

}// end generate



// Generates the number of insults and outputs them into a txt file. 
void InsultGenerator::generateAndSave (string filename, int numOfInsults) const{

    int count = 0;
    ofstream fileOut (filename.c_str());
    vector<string> insultsSet (generate (numOfInsults));

    if (fileOut.fail()){
        throw FileException ("Error: Could not open file.");
    }// end if

    while (count < numOfInsults){
        fileOut << insultsSet [count] << endl;
        count++;
    }// end loop

    fileOut.close();

}// end generateAndSave