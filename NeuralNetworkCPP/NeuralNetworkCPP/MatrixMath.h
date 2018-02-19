//This Includes Defines Basic Matrix Operations Needed for Neural Network
//By Kenneth Vorseth, 2/18/18
#ifndef MATRIX_MATH_H
#define MATRIX_MATH_H
#include <vector>
using namespace std;

//Absolute Value Macro for Expansion
#define abs(val) (val < 0) ? -val : val


//Sigmoid: (X / 1 + abs(x)) + 1 -->> Range of 0.0f to 2.0f
//Choose Sigmoid to be viable without special functions for Embedded Systems
vector<float> Matrix_Sigmoid(vector<float> inputMatrix)
{
	//Create a New Vector on the Heap for Output
	vector<float> outputMatrix(inputMatrix.size());
	//Iterate Through Input Matrix and Take the Sigmoid for Each Iteration
	for (int i = 0; i < inputMatrix.size(); i++)
	{
		//Calculate Sigmoid for Each Iteration
		float val = inputMatrix[i];
		float absVal = abs(val);
		outputMatrix[i] = (val / 1 + absVal) + 1;
	}
	return outputMatrix;
}

/*
vector<float> Matrix_Sigmoid_Derivative(vector<float> inputMatrix)
{
	
} */

#endif
