/* Maria Mysliwiec
ECE 0301
In-Class Assignment 2 */

// Preprocessor directives
#include <iostream>
#include <string>
#include <iomanip>
#include <cmath>

using namespace std;

int main(void){
	
	//Display introductory message
	cout << "ECE 0301 Propositional Logic Example\n\n"; 
	
	//Declare string variables
	string P1 = "Pigs can fly.", P2 = "Earth is flat.", P3 = "The moon is cheese.";
	
	//Display propositions to output
	cout << "P1: " << P1  << endl;
	cout << "P2: " << P2 << endl;
	cout << "P3: " << P3 << endl;
	
	//Declare bool variables to store the user's true/false input
	bool P1_truth, P2_truth, P3_truth;
	
	//Ask user for input
	cout << "\nEnter P1 truth value: "; //0 for false, 1 for true
	cin >> P1_truth;					// accept and stores user input into variable
	
	cout << "Enter P2 truth value: ";
	cin >> P2_truth;
	
	cout << "Enter P3 truth value: ";
	cin >> P3_truth;
	
	//Display user input to screen
	cout << "\nYou entered: P1 = " << boolalpha << P1_truth << ", P2 = " << boolalpha << P2_truth << ", P3 = " << boolalpha << P3_truth << ".\n" << endl;
	
	//Declare P4 and P5 variables
	bool P4_truth, P5_truth;
	
	//Use AND operator to assign true value to P4
	P4_truth = (P1_truth == 1 && P2_truth == 0 && P3_truth == 1);
		
	//Use OR operator to assign true value to P5
	P5_truth = (P1_truth == 0 || P2_truth == 1 || P3_truth == 1);

	// Display truth table with all truth values (P1- P5)
	cout << "Truth Table:\nProposition\tTruth Value\n-----------\t-----------\n";
	cout << "P1\t\t" << P1_truth << endl;
	cout << "P2\t\t" << P2_truth << endl;
	cout << "P3\t\t" << P3_truth << endl;
	cout << "P4\t\t" << P4_truth << endl; 
	cout << "P5\t\t" << P5_truth << endl;
	
	// STEP 7
	// P6: one of the elementary propositions are true, others are false
	// Declare P6 boolean and int variable for boolean arithmetic
	bool P6_truth;
	int truthvalue = P1_truth + P2_truth + P3_truth; // set truthvalue to the sum of the three booleans

	// If statement: if only 1 of the propositions is true, truthvalue would equal 1 
	if (truthvalue == 1) 
		P6_truth = 1;
	else
		P6_truth =  0;
	
	cout << "P6\t\t" << P6_truth << endl; //display result in truth table
	
	// STEP 8 
	// P7: none of the  elementary propositions are true
	// declare P7 boolean and use AND operator to assign conditions for 'true'
	bool P7_truth;
	P7_truth = (P1_truth == 0 && P2_truth == 0 && P3_truth == 0);
	cout << "P7\t\t" << P7_truth << endl; //display result
	
	// STEP 9
	// P8: majority are true (at least 2/3)
	bool P8_truth;

	if (truthvalue >= 2)
		P8_truth = 1;
	else 
		P8_truth = 0;
	cout << "P8\t\t" << P8_truth << endl; //display result in table
	
	// STEP 10
	// P9: 1 is false AND 2 is true OR 3 is true, but not both
	bool P9_truth; 
	
	// use a while loop so if the conditions for P9 = false are met, the loop will break
	while (true)  {
		
		if (P1_truth == 1) {P9_truth = 0;  break;}
		else P9_truth = 1;
		
		if(P2_truth == 1 && P3_truth == 1) {P9_truth = 0; break;}		
		else if (P2_truth == 0 && P3_truth == 0) {P9_truth = 0; break;}
		else {break;}	
	}
	
	cout << "P9\t\t" << P9_truth << endl; //display result
	
	return 0;
}


