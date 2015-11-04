#include <iostream>
#include <fstream>


using namespace std;

int main (int argcount, char** argvector){


	// check if a filename is given
	if (argcount != 2) {
		cout << "usage: " << argvector[0] << " filename" << endl;
		return -1;
	}

	// basic variables
	double x0 = 0.5;
	double x_temp;

	int Nskip = 100; //Number of iterations to skip
	int Nend  = 200; //Number of total iterations

	// array to hold x values
	double x[Nend - Nskip]; 

	// open file
	ofstream out(argvector[1]);

	// iterate different weighting factorss
	for(double r=0; r <= 4; r += 0.001){

		// reinitialize x
		x_temp = x0;

		// iterate Nskip steps without writing out
		for(int i=0; i < Nskip; i++)
			x_temp = r*x_temp*(1-x_temp);

		// iterate the first step within the array
		x[0] = r*x_temp*(1-x_temp);
		
		// iterate the rest of the steps
		for(int i=1; i < Nend-Nskip; i++)
			x[i] = r*x[i-1]*(1-x[i-1]);

		// print results for current r to file
		for (int i=0; i < Nend-Nskip; i++) 
			out << r << "\t" << x[i] << endl;
	}

	// close outgoing file stream and return to caller
	out.close();
	return 0;
}
