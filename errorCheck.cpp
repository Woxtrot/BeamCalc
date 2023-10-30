// Made by Wessel Eikelboom (S2565196) for the C++ assignment in the PiE course.
// Mechanical Engineering, Faculty of Engineering Technology, University of Twente
#include <iostream>
#include <cmath>
#include "errorCheck.h"
using std::cout;
using std::cin;
using std::endl;
using std::cerr;
using std::string;
using std::numeric_limits;
using std::streamsize;


// Function to get an integer input with error checking
int getInputInt(const string& prompt, int min, int max) {
    int input;
    while (true) {
        cout << prompt << endl; // Display the prompt message
        if (!(cin >> input) || input < min || input > max) { // If the input is not an integer or is outside the specified range, display an error message
            cerr << "Invalid input. Please enter a valid integer between " << min << " and " << max << ".\n";
            cin.clear(); // Clear any error flags on the input stream and ignore any remaining characters in the input buffer.
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore all characters unit newline character \n is found adapted from https://stackoverflow.com/questions/28533483/checking-cin-input-clearing-input-buffer
        } else {
            return input;
        }
    }
}
// Function to get a double input with error checking
double getInputDouble(double min, double max, bool allowPositive, bool allowNegative) {
    double input;
    while (true) {
        if (!(cin >> input) || (input < min) || (input > max) ||
            (!allowPositive && input > 0) || (!allowNegative && input < 0)) { // If the input is not a valid double or doesn't meet the specified conditions, display an error message
            cerr << "Invalid input. Please enter a valid double";
            if (min != numeric_limits<double>::lowest()) { // use numeric_limits::lowest() as value can be negative! for positive only ::min() would suffice.
                cerr << " greater than or equal to " << min;
            }
            if (max != numeric_limits<double>::max()) {
                cerr << " less than or equal to " << max;
            }
            if (allowPositive && !allowNegative) {
                cerr << " and positive";
            }
            if (allowNegative && !allowPositive) {
                cerr << " and negative";
            }
            cerr << ".\n";
            cin.clear(); // Clear any error flags on the input stream and ignore any remaining characters in the input buffer.
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore all characters unit newline character \n is found adapted from https://stackoverflow.com/questions/28533483/checking-cin-input-clearing-input-buffer
        } else {
            return input;
        }
    }
}
