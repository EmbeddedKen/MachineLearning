#include <iostream>
#include <string>
#include "MatrixMath.h"

int main()
{
	//Testing of Sigmoid Function, and It's First Derivative
	vector<float> newVect;
	for (float i = -5.0f; i < 5.0f; i += 0.25f) //-5 to 5 via steps of 0.25f
	{
		cout << "Adding: " << i << "\n";
		newVect.push_back(i);
	}

	//Running Sigmoid Function
	vector<float> nextVect = Matrix_Sigmoid(newVect);

	//Displaying Sigmoid Function Results
	for (int i = 0; i < nextVect.size(); i++)
	{
		cout << nextVect[i] << "\n";
	}

	system("pause");
    return 0;
}

