/*
 *      insultgenerator_19srs12.h
 *      
 *      Name: Shams Sajid
 * 
 *      Author: Alan McLeod
 *      A testing program for CISC320 assignment 1.
 */

#pragma once
#include <string>
#include <vector>
using namespace std;


const int maxInsults (10000);


// Creating the Exception class FileException
// This is the exception that is thrown if the source file cannot be read or if it is not possible to create a saved file.
class FileException {

    public:
        FileException (const string&);
        string what() const;
    
    private: 
        string message;

};

// This is the exception file thta is thrown if the number of insults is not between 1 and 10,000
class NumInsultsOutOfBounds {

    public: 
        NumInsultsOutOfBounds (const string&);
        string what() const;

    private: 
        string message;
};

// This class generates random insults
class InsultGenerator{

    public:
    
        // Empty Constructor
        InsultGenerator();
        // The initialize() method should load all the source phrases from the InsultsSource.txt file into the attributes.     
        void initialize ();
        // talkToMe() returns a single insult, generated at random.
        string talkToMe () const;
    	// Check number to generate limits. Then returns the randomized collection of insults. 
        vector<string> generate(int) const;
        // Generates and saves the collection of randomized insults in alphabetical order
        void generateAndSave (string, int) const;

    private:
        // The number of lines in the source file
        int sourceFileSize;
        // The words/phrases in the three columns
        vector <string> word1;
        vector <string> word2;
        vector <string> word3;
        // Random integar generator method
        int randInt (int) const;
};