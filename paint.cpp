// Author:			Logan Hammond; hamm32637@email.ccbcmd.edu; Febuary 22, 2018
// Source file:		paint.cpp
// Description:		Calculates cost to paint a room given length and width.
// IDE used:		Microsoft Visual Studio 2017

#include <iostream> // I/O
#include <String>	// cout string vars.
#include <iomanip>	// setw().
using namespace std;

// Global Vars
const double PAINT_PRICE = 12.99;		// Price of one can of paint. Specified by project details.
const int ROOM_HEIGHT = 8,				// Height of room.
		  CAN_COVERAGE = 250;			// Amount of square feet one can of paint covers.

// Function Declarations
void displayTitle();												// Displays title for window.
void getData(int &length, int &width);								// Requests value for length and width from user.
int calcSqFt(int length, int width);								// Returns square footage of walls and ceiling.
int calcTotalCans(int feetToCover);									// Returns number of cans needed.
double calcCost(int cansNeeded);									// Returns total cost of cans needed.
void displayResults(int squareFootage, int numCans, double cost);	// Displays results of purchase.
void displayMsg(int numCans);										// Displays free gift customer receives.

// Funtion Definitions
/**
	Displays title of remodeling company.
	@return void.
*/
void displayTitle() {
	cout << "\n\n\t\tChesapeake Remodeling Company";
	cout << "\n\t\t\tPaint Costing";
	cout << "\n\t\t-----------------------------";
}

/*
Requests value from user for room length/width.
@param &length Reference of int roomLength from main().
@param &width Reference for int roomWidth from main().
@return void
*/
void getData(int &length, int &width) {
	do {
		cout << "\n\n\tEnter length in ft (0 to stop): ";
		while (!(cin >> length) || length < 0) {
			cout << "\tInvalid input. Try again.";
			cin.clear();
			cin.ignore(INT_MAX, '\n');
			cout << "\n\tEnter length in ft (0 to stop): ";
		}
	}while (length < 0);
	if (length != 0) {
		do {
			cout << "\tEnter width in ft             : ";
			while (!(cin >> width) || width < 1) {
				cout << "\tInvalid input. Try again.";
				cin.clear();
				cin.ignore(INT_MAX, '\n');
				cout << "\n\tEnter width in ft             : ";
			}
		} while (width < 1);
	}
}

/*
	Calculates and returns square footage of room including ceiling.
	@param width Width of room.
	@param length Length of room.
	@return total Square footage of room including ceiling.
*/
int calcSqFt(int length, int width) {
	int totalFeet = 0;
	totalFeet = (2 * (length * ROOM_HEIGHT)) + (2 * (width * ROOM_HEIGHT)) + (length * width);		// Total includes four walls and ceiling. 
	return totalFeet;
}

/*
Calculates and returns number of cans needed to paint required footage.
@param feetToCover Total footage that must be covered.
@return numCans Number of cans that must be bought.
*/
int calcTotalCans(int feetToCover) {
	double numCans = 0.00;
	numCans = ceil((feetToCover * 1.0) / CAN_COVERAGE);		// Rounds double up regardless of decimal.
	return static_cast<int>(numCans);						// Returns numCans cast as int.
}

/*
	Calculates and returns total cost of paint can.
	@param cansNeeded Number of cans to buy.
	@return totalCost Total cost of cans to buy.
*/
double calcCost(int cansNeeded) {
	double totalCost = 0;
	totalCost = (cansNeeded * PAINT_PRICE);
	return totalCost;
}

/*
	Displays details of purchase
	@param squareFootage Total footage of room that must be painted.
	@param numCans Number of cans that must be purcahsed to cover footage.
	@param cost	Total cost of can(s) purchase.
	@return void.
*/
void displayResults(int squareFootage, int numCans, double cost) {

	cout.setf(ios::fixed);
	cout.setf(ios::showpoint);
	cout.precision(2);

	cout << "\n\n\t    Square Footage:" << setw(16) << squareFootage;
	cout << "\n\t    Cans          :" << setw(16) << numCans;
	cout << "\n\t    Cost          :" << setw(19) << cost;
}

/*
	Displays free gift customer recieves based on number of paint cans bought.
	@param numCans Number of paint cans bought
	@return void.
*/
void displayMsg(int numCans) {
	string giftString;
	cout << "\n\n\tThank you for your purchase.";
	
	if (numCans <= 3) {
		giftString = "Free paint brush.";
	}
	else if (numCans <= 7) {
		giftString = "Free paint tray.";
	}
	else {
		giftString = "$10 gift card.";
	}
	cout << "\n\tGift = " << giftString;
}

int main() {
	int roomLength = 0, roomWidth = 0,								// Length set to -1. Pre-test does not loop when length = 0.
		squareFootage = 0,
		numPaintCans = 0;
	double totalCost = 0.00;

	displayTitle();
	getData(roomLength, roomWidth);									// Pre-test loop start.
	while (roomLength != 0) {
		squareFootage = calcSqFt(roomLength, roomWidth);
		numPaintCans = calcTotalCans(squareFootage);
		totalCost = calcCost(numPaintCans);
		displayResults(squareFootage, numPaintCans, totalCost);
		displayMsg(numPaintCans);
		getData(roomLength, roomWidth);
	}																// Pre-test loop end.

	cout << "\n\n\t";
	system("pause");
	return 0;
}