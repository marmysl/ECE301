/* Maria Mysliwiec
 * ECE 0301: Problem Solving with C++
 * In Class Assignment 1*/
 
 //Step 7

#include <iostream>
#include <string>
using namespace std;

int main(){
	
	// Print Introductory Statement, used \n to start a new line between phrases
	cout << "ECE 0301 DC Resistive Circuit Simulation\nModeled after www.falstad.com/circuit/\nCircuits -> Basics -> Ohm's Law\n";
	
	// Declare variables Vs, R1, R2 
	double Vs=7200, R1=8, R2=10;
	
	// Print voltage and resistor statements
	cout << "Vs = " << Vs << " Volts\n";
	cout << "R1 = " << R1 << " Ohms\n";
	cout << "R2 = " << R2 << " Ohms\n";
	
	
	// Ohm's Law Calculation: V=IR
	// Define variables in terms of V and R
	double I1=Vs/R1, I2=Vs/R2;
	
	// Power Dissipation Calculation: P = IV 
	double P1=I1*Vs, P2=I2*Vs, Ptotal; // define power variables for each resistor in terms of I and V

	// Print Current and Power Statements
	cout << "I1 = " << I1 << " Amperes\n";
	cout << "P1 = " << P1 << " Watts\n";
	cout << "I2 = " << I2 << " Amperes\n";	
	cout << "P2 = " << P2 << " Watts\n";
	
	// Energy Computation: E = P*time
	const int secondsday=3600*24, secondsyear=secondsday*365; // define constants for the number of seconds in a day and a year for energy computation
	
	// Assign value to Ptotal (Powers added because parallel circuit)
	Ptotal=P1+P2;
	
	// Define and calculate values for the energy variables
	double Esecond=Ptotal, Ehour=Ptotal*3600, Eday=Ptotal*secondsday, Eyear=Ptotal*secondsyear; // Energy= Ptotal*time, 1 hour = 3600 seconds
	
	//Display total energy statements to the screen for one second, one hour, one day, and one year
	cout << "Energy supplied in one second = " << Esecond << " Joules\n";
	cout << "Energy supplied in one hour = " << Ehour << " Joules\n"; 
	cout << "Energy supplied in one day = " << Eday << " Joules\n";
	cout << "Energy supplied in one year = " << Eyear << " Joules\n";
	
	// Energy Cost Computation
	string rate= "$0.10/kWh"; // define the string rate so that it can be displayed in the energy cost statements
	
	// Define cost of electricity variable in terms of watts per hour and watts per second
	double Watt_Seconds=0.10/(1000*3600);
	
	//Define and calculate cost variables
	double CostSecond = Watt_Seconds*Esecond, CostHour = CostSecond*3600;
	double CostDay = CostHour*24, CostYear = CostDay*365;
	
	// Print energy cost statements
	cout << "Cost of supplying energy for one second at " << rate << " = $" << CostSecond << endl;
	cout << "Cost of supplying energy for one hour at " << rate << " = $" << CostHour << endl;
	cout << "Cost of supplying energy for one day at " << rate << " = $" << CostDay << endl;
	cout << "Cost of supplying energy for one year at " << rate << " = $" << CostYear << endl;

	return 0;
}





