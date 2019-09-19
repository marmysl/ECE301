/* Maria Mysliwiec
 * ECE 0301: ICA 3*/
 
 #include <iostream>
 #include <iomanip>
 #include <cmath>
 #include <string>
 
 using namespace std;
 
 int main(){
	
	// STEP 1
	//Display introductory message and user prompt to enter 2 values
	cout << "ECE 0301 - Vectors in R2 and Complex Numbers\n";
	cout << "Please enter two numbers, separated by a space,\nthat will represent a vector or a complex number.\n\n";
 
	// STEP 2
	// Declare variables
	double number1, number2;
	string coordinate1;
	
	// Read user response from standard input 
	cin >> number1;
	cin >> number2;
	
	// Display user response to screen
	cout << "You entered " << setprecision(3) << fixed << number1 << " and " << number2 << ".\n\n";
	
	// STEP 3
	// Prompt user to enter character to indicate type of coordinates
	cout << "Are these numbers in Cartesian (C) or polar (p) coordinates?\nPlease enter a single character as your choice.\n";
	cin >> coordinate1;
	
	// Validate user response
	if (coordinate1 != "C" && coordinate1 != "c" && coordinate1 != "P" && coordinate1 != "p") {
		cout << "ERROR! Invalid selection, exiting.";
		return -1;
	}
	
	// Declare variables for polar/Cartesian coordinates
	double R1, theta1;
	double x1, y1;
	
	// STEP 4: Computing values in other polar coordinate representation if given Cartesian
	if (coordinate1 == "C" || coordinate1 == "c") {
		cout << "You entered Cartesian coordinates.\n";
		
		//Set user's chosen values to XY coordinate variables
		x1=number1;
		y1=number2;
		
		//Solve for R and theta
		R1 = sqrt(pow(x1, 2) + pow(y1,2));
		theta1 = acos(x1/R1);
		
		// Pritn equivalent coordinates to screen	
		cout << "The equivalent polar coordinates are:\nR = " << R1 << ", theta = " << theta1 << endl;
	}	
	
	// STEP 5: Computation if given polar coordinates
	if (coordinate1 == "P" || coordinate1 == "p") {
		
		// If the value of the given polar coordinates are not in the given bounds, program exits
		if (number1 < 0 || number2 < -atan(1)*4 || number2 > atan(1)*4) {
			cout << "ERROR! Invalid polar coordinates, exiting.";
			return -1;
		}		
	
		// Print to screen if values are in the appropriate bounds
		cout << "You entered polar coordinates.\n";
		
		// Set user chosen variables equal to polar coordinate variables
		R1=number1;
		theta1=number2;
		
		// Calculate Cartesian using formula
		x1= R1*cos(theta1);
		y1= R1*sin(theta1);
		
		//Send equivalent Cartesian coordinates to screen 
		cout << "The equivalent Cartesian coordinates are:\nx = " << x1 << ", y = " << y1 << endl;
		
		}
	
	// STEP 6: Repeating Process for second pair of data points
	
	// Declare variables for calculation
	double num3, num4, R2, theta2, x2, y2;
	string coordinate2;
	
	// ASk user to enter data points and use cin to take in data points
	cout << "Please enter another pair of numbers, separated by a\nspace, to represent a second vector or complex number.\n\n";
	cin >> num3;
	cin >> num4;
	
	// Prompt user to enter whether or not points are Cartesian or Polar
	cout << "Are these numbers in Cartesian (C) or polar (p) coordinates?\nPlease enter a single character as your choice.\n";
	cin >> coordinate2;
	
	// Validating that user chose "c" "C" "P" or "p" using a conditional
	if (coordinate2 != "C" && coordinate2 != "c" && coordinate2 != "P" && coordinate2 != "p") {
		cout << "ERROR! Invalid selection, exiting.";
		return -1;
	}
	
	// Computation of corresponding Polar & Cartesian values
	// If user chooses C or C, print to screen that they entered Cartesian coordinates
	if (coordinate2 == "C" || coordinate2 == "c") {
		cout << "You entered Cartesian coordinates.\n"; 
		
		//Set user variables to Cartesian coordinate variables
		x2=num3;
		y2=num4;
		
		// Calculate R and theta using conversions
		R2 = sqrt(pow(x2, 2) + pow(y2,2));
		theta2 = acos(x2/R2);
			
		// Send equivalent polar coordinates to screen
		cout << "The equivalent polar coordinates are:\nR = " << R2 << ", theta = " << theta2 << endl;
	}	
	
	// Computation if coordinates are in polar
	if (coordinate2 == "P" || coordinate2 == "p") {
		
		// Check that user's chosen R is greater than 0 and theta is within the bounds of [-pi, pi]
		if (num3 < 0 || num4 < -atan(1)*4 || num4 > atan(1)*4) {
			cout << "ERROR! Invalid polar coordinates, exiting."; // Exit program if values are outside bounds
			return -1;
		}		
		
		// If bounds are correct, print to screen the following message
		cout << "You entered polar coordinates.\n";
		
		// Set user's variables equal to polar coordinate variables
		R2=num3;
		theta2=num4;
		
		// Calculate Cartesian coordinates
		x2= R2*cos(theta2);
		y2= R2*sin(theta2);
		
		// Print equivalent Cartesian coordinates to screen
		cout << "The equivalent Cartesian coordinates are:\nx = " << x2 << ", y = " << y2 << endl;
		
		}
		
	// STEP 7
	
	// Declare vector or complex variable
	string VorC;
	
	//Ask user if the values represent vectors or complex numbers and accept response
	cout << "\nDo the values you entered represent vectors (v) or complex numbers (c)?" << endl << "Please enter a single character as your choice.\n";
	cin >> VorC;
	
	// Validate user choice; if user enters anything other than C or V, exit program
	if (VorC != "C" && VorC != "c" && VorC != "V" && VorC != "v") {
		cout << "ERROR! Invalid selection, exiting.";
		return -1;
	}
	
	// STEP 8 + STEP 9 FOR VECTORS
	if (VorC == "V" || VorC == "v") {
		
		// Print Cartesian and Polar values to screen for each of the two chosen data points
		cout << setprecision(3) << fixed << "Cartesian:\t\t v1 = (" << x1 << ", " << y1 << ")\n";
		cout << setprecision(3) << fixed << "Polar:\t\t\t v1 = (" << R1 << ", " << theta1 << ")\n\n";
		
		cout << setprecision(3) << fixed << "Cartesian:\t\t v2 = (" << x2 << ", " << y2 << ")\n";
		cout << setprecision(3) << fixed << "Polar:\t\t\t v2 = (" << R2 << ", " << theta2 << ")\n\n";
		
		// Display menu to user prompting choice from 1-4
		int menuchoice;
		cout << "Which of the following vector sums or differences\nwould you like to compute?\n";
		cout << "(1) v1 + v2" << endl << "(2) v1 - v2" << endl << "(3) v2 - v1" << endl << "(4) -v1 - v2\n" << endl;
		cin >> menuchoice;
		
		// Declare variables needed for new polar coordinate values
		// Equations: r = sqrt of x2 + y2 and theta = acos x /r
		double Rnew, thetanew;
		
		// Switch case for user menu choice
		switch(menuchoice) {
			case 1:
				// Print out Cartesian sum v1 + v2
				cout << "Sum, Cartesian:\tv_sum = (" << x1+x2 << ", " << y1+y2 << ")\n";
				
				// Calculate new Polar values that correspond to Cartesian sum
				Rnew= sqrt(pow(x1+x2,2)+pow(y1+y2,2));
				
				// Calculate new theta value using conditional
				if (x1+x2 >= 0) {
					thetanew= atan((y1+y2)/(x1+x2)); 
				} else if (x1+x2 < 0 && y1+y2 >=0) {
					thetanew= atan((y1+y2)/(x1+x2))+(atan(1)*4);
				} else 
					thetanew= atan((y1+y2)/(x1+x2))-(atan(1)*4);
				
				// Print polar sum to screen
				cout << "Sum, Polar:\tv_sum = (" << Rnew << ", " << thetanew << ")\n";
				break;
			
			case 2:
				// Print out Cartesian sum v1-v2
				cout << "Sum, Cartesian:\tv_sum = (" << x1-x2 << ", " << y1-y2 << ")\n";
				
				// Calculate new Polar values that correspond to Cartesian sum v1-v2
				Rnew= sqrt(pow(x1-x2,2)+pow(y1-y2,2));
				
				// Calculate new theta value 
				if (x1-x2 >= 0) {
					thetanew= atan((y1-y2)/(x1-x2)); 
				} else if (x1-x2 < 0 && y1-y2 >=0) {
					thetanew= atan((y1-y2)/(x1-x2))+(atan(1)*4);
				} else 
					thetanew= atan((y1-y2)/(x1-x2))-(atan(1)*4);
				
				//Print polar sum to screen
				cout << "Sum, Polar:\tv_sum = (" << Rnew << ", " << thetanew << ")\n";
				break;
			case 3:
				// Print out Cartesian sum v2-v1
				cout << "Sum, Cartesian:\tv_sum = (" << x2-x1 << ", " << y2-y1 << ")\n";			
				
				//Calculate new Polar values that correspond to Cartesian sum v1-v2
				Rnew= sqrt(pow(x2-x1,2)+pow(y2-y1,2));
				
				// Calculate theta new
				if (x2-x1 >= 0) {
					thetanew= atan((y2-y1)/(x2-x1)); 
				} else if (x2-x1 < 0 && y2-y1 >=0) {
					thetanew= atan((y2-y1)/(x2-x1))+(atan(1)*4);
				} else 
					thetanew= atan((y2-y1)/(x2-x1))-(atan(1)*4);
				
				//Print polar sum to screen
				cout << "Sum, Polar:\tv_sum = (" << Rnew << ", " << thetanew << ")\n";
				break;
			case 4:
				// Print out Cartesian sum -v1-v2
				cout << "Sum, Cartesian:\tv_sum = (" << -x1-x2 << ", " << -y1-y2 << ")\n";				
				
				// Calculate new corresponding R1 value
				Rnew= sqrt(pow(-x1-x2,2)+pow(-y1-y2,2));
				
				// Calculate theta new
				if (-x1-x2 >= 0) {
					thetanew= atan((-y1-y2)/(-x1-x2)); 
				} else if (-x1-x2 < 0 && -y1-y2 >=0) {
					thetanew= atan((-y1-y2)/(-x1-x2))+(atan(1)*4);
				} else 
					thetanew= atan((-y1-y2)/(-x1-x2))-(atan(1)*4);		

				// Print polar sum to screen
				cout << "Sum, Polar:\tv_sum = (" << Rnew << ", " << thetanew << ")\n";
				break;
			default:
				// If user chooses a value other than 1-4, program exits
				cout << "ERROR! Invalid selection, exiting.";
				return -1;
		}	
		
	// STEP 11: CALCULATING DOT PRODUCT AND CONFIRMNG RESULTS
	
	// declare dot product variables
	double dotprod1, dotprod2;
	
	//  Use equation to find dot product; product = r1*r2 * cos(theta1-theta2)	
	dotprod1 = R1*R2*cos(theta1-theta2);
	cout << "\nProduct, polar:\t\t" << dotprod1 << endl; // print response to screen
	
	//  product = x1*x2 + y1*y2
	dotprod2 = (x1*x2)+(y1*y2);
	cout << "Product, Cartesian:\t" << dotprod2 << endl; // print response
	cout << "The dot products are consistent!"; 		 // validate consistency!	
	}
	
	// STEP 8 + STEP 10 FOR COMPLEX NUMBERS
	
	// If user chooses C/c
	if (VorC == "C" || VorC == "c") {
		
		// Display both numbers as vector forms
			cout << setprecision(3) << fixed << "Cartesian:\t\t z1 = " << x1 << " + j " << y1 << "\n";
			cout << setprecision(3) << fixed << "Polar:\t\t\t z1 = " << R1 << " exp(j " << theta1 << ")\n\n";
			
			cout << setprecision(3) << fixed << "Cartesian:\t\t z2 = " << x2 << " + j " << y2 << "\n";
			cout << setprecision(3) << fixed << "Polar:\t\t\t z2 = " << R2 << " exp(j " << theta2 << ")\n\n";
		 
		// Display menu and prompt user for choice
		int menuchoice;
		cout << "Which of the following vector sums or differences\nwould you like to compute?\n";
		cout << "(1) z1 + z2" << endl << "(2) z1 - z2" << endl << "(3) z2 - z1" << endl << "(4) -z1 - z2\n" << endl;
		cin >> menuchoice;
		
		// declare new variables for theta and R calculation
		double Rnew, thetanew;
		
		// Switch case in regards to menuchoice variable
		switch(menuchoice){
			case 1:
				// Calculate new Polar values that correspond to Cartesian sum
				Rnew= sqrt(pow(x1+x2,2)+pow(y1+y2,2));
				
				// Calculate new theta value using conditional
				if (x1+x2 >= 0) {
					thetanew= atan((y1+y2)/(x1+x2)); 
				} else if (x1+x2 < 0 && y1+y2 >=0) {
					thetanew= atan((y1+y2)/(x1+x2))+(atan(1)*4);
				} else 
					thetanew= atan((y1+y2)/(x1+x2))-(atan(1)*4);
				
				// Conditionals for both Cartersian and Polar sums used to determine what the correct sign is for display to screen
				if (y1+y2 >= 0){
					cout << "Sum, Cartesian:\tz_sum = " << x1+x2 << " + j " << y1+y2 << endl;
				} else {
					cout << "Sum, Cartesian:\tz_sum = " << x1+x2 << " - j " << abs(y1+y2) << endl;}

				if (thetanew >= 0){
					cout <<"Sum, Polar:\tz_sum = " << Rnew << " exp(+j " << thetanew << ")\n";
				} else {	
					cout <<"Sum, Polar:\tz_sum = " << Rnew << " exp(-j " << abs(thetanew) << ")\n"; }
							
				break;
			case 2:
				// Calculate new Polar values that correspond to Cartesian sum v1-v2
				Rnew= sqrt(pow(x1-x2,2)+pow(y1-y2,2));
				
				// Calculate new theta value 
				if (x1-x2 >= 0) {
					thetanew= atan((y1-y2)/(x1-x2)); 
				} else if (x1-x2 < 0 && y1-y2 >=0) {
					thetanew= atan((y1-y2)/(x1-x2))+(atan(1)*4);
				} else 
					thetanew= atan((y1-y2)/(x1-x2))-(atan(1)*4);
					
				// Conditionals for correct signs to print to screen
				if (y1-y2 >= 0){
					cout << "Sum, Cartesian:\tz_sum = " << x1-x2 << " + j " << y1-y2 << endl;
				} else {
					cout << "Sum, Cartesian:\tz_sum = " << x1-x2 << " - j " << abs(y1-y2) << endl;}

				if (thetanew >= 0){
					cout <<"Sum, Polar:\tz_sum = " << Rnew << " exp(+j " << thetanew << ")\n";
				} else {	
					cout <<"Sum, Polar:\tz_sum = " << Rnew << " exp(-j " << abs(thetanew) << ")\n"; }
							
				break;
			case 3:
				//Calculate new Polar values that correspond to Cartesian sum v1-v2
				Rnew= sqrt(pow(x2-x1,2)+pow(y2-y1,2));
				
				// Calculate theta new
				if (x2-x1 >= 0) {
					thetanew= atan((y2-y1)/(x2-x1)); 
				} else if (x2-x1 < 0 && y2-y1 >=0) {
					thetanew= atan((y2-y1)/(x2-x1))+(atan(1)*4);
				} else 
					thetanew= atan((y2-y1)/(x2-x1))-(atan(1)*4);
					
				// Conditionals for correct signs to print to screen
				if (y2-y1 >= 0){
					cout << "Sum, Cartesian:\tz_sum = " << x2-x1 << " + j " << y2-y1 << endl;
				} else {
					cout << "Sum, Cartesian:\tz_sum = " << x2-x1 << " - j " << abs(y2-y1) << endl;}

				if (thetanew >= 0){
					cout <<"Sum, Polar:\tz_sum = " << Rnew << " exp(+j " << thetanew << ")\n";
				} else {	
					cout <<"Sum, Polar:\tz_sum = " << Rnew << " exp(-j " << abs(thetanew) << ")\n"; }
				break;
			case 4:
				// Calculate new corresponding R1 value
				Rnew= sqrt(pow(-x1-x2,2)+pow(-y1-y2,2));
				
				// Calculate theta new
				if (-x1-x2 >= 0) {
					thetanew= atan((-y1-y2)/(-x1-x2)); 
				} else if (-x1-x2 < 0 && -y1-y2 >=0) {
					thetanew= atan((-y1-y2)/(-x1-x2))+(atan(1)*4);
				} else 
					thetanew= atan((-y1-y2)/(-x1-x2))-(atan(1)*4);	
		
				// Conditional for correct signs to print to screen
				if (-y1-y2 >= 0){
					cout << "Sum, Cartesian:\tz_sum = " << -x1-x2 << " + j " << -y1-y2 << endl;
				} else {
					cout << "Sum, Cartesian:\tz_sum = " << -x1-x2 << " - j " << abs(-y1-y2) << endl;}

				if (thetanew >= 0){
					cout <<"Sum, Polar:\tz_sum = " << Rnew << " exp(+j " << thetanew << ")\n";
				} else {	
					cout <<"Sum, Polar:\tz_sum = " << Rnew << " exp(-j " << abs(thetanew) << ")\n"; }
				break;
			default:
			// IF user enters a value that is not between 1-4, the program is exited
				cout << "ERROR! Invalid selection, exiting.";
				return -1;
		}		
	
	// STEP 12
	
	// Calculate polar product z1z2= R1*R2 exp( j (theta1 + theta2) )
	
	//declare variables
	double Rprod=R1*R2, thetasum=theta1+theta2;
	
	// create conditional that chooses the correct sign for output depending on thetasum variable
	if (thetasum >=0) {
		cout << "\nProduct, polar:\t\tz1 * z2 = " << Rprod << " exp(j " << thetasum << ")\n";
	} else {
		cout << "\nProduct, polar:\t\tz1 * z2 = " << Rprod << " exp(-j " << abs(thetasum) << ")\n";}
	
	// Dot product with Cartesian: z1z2 = (x1x2 - y1y2) + j(x1y2 + y1x2)
	
	// Declare term variables
	double term1, term2;
	
	// Calculate x and y terms
	term1 = x1*x2 - y1*y2;
	term2 = x1*y2 + y1*x2;
	
	// If statement to determine correct sign for output
	if (term2 >= 0) {
		cout << "Product, Cartesian:\tz1 * z2 = " << term1 << " + j(" << term2 << ")\n";
	} else {
		cout << "Product, Cartesian:\tz1 * z2 = " << term1 << " - j(" << abs(term2) << ")\n";}
	
	// Convert polar product to cartesian
	double xprod, yprod;
	
	// Convert polar product to Cartesian using conversion formula
	xprod= Rprod*cos(thetasum);
	yprod= Rprod*sin(thetasum);
	
	// Conditional statement to determine what sign should be displayed in the formula
	if (yprod >=0) {
			cout << "Polar, converted to Cartesian:\t z1 * z2 = " << xprod << " + j " << yprod;	 
	} else
		cout << "Polar, converted to Cartesian:\t z1 * z2 = " << xprod << " - j " << abs(yprod);
	}
 
 return 0;
 }
 
 
 
