//This File Defines Basic Vector/Float Operations Needed for Neural Network
//By Kenneth Vorseth, 2/18/18
#ifndef NEURAL_NET_MATH_H
#define NEURAL_NET_MATH_H
#include <vector>
using namespace std;

//<General Mathematics Helper Functions>------------------------------------
//Absolute Value Function --> {|x|}
inline float absVal(float val) { return (val >= 0) ? val : -val; }
//Sign Function --> {-1 (Neg), 0 (Zero), 1 (Pos)}
inline float sign(float val)
{
	return (val == 0) ? 0 : (val > 0) ? 1 : -1;
}
//Square Function --> {x * x}
inline float sqr(float val) { return (val * val); }
//--------------------------------------------------------------------------

//<Vector/Float Mathematics Functions>--------------------------------------

//Vector Subtraction
vector<float> Vector_Subtraction(vector<float> sourceVector, vector<float> subVector)
{
	//Create Vector to Return as Output
	vector<float> outputVector;
	//Iterate Through Vector, Subtracting Values
	for (int v = 0; v < sourceVector.size(); v++)
	{
		outputVector.push_back(sourceVector[v] - subVector[v]);
	}
	//Return Difference Vector as Output
	return outputVector;
}
//Vector Addition
vector<float> Vector_Addition(vector<float> sourceVector, vector<float> addVector)
{
	//Create Vector to Return as Output
	vector<float> outputVector;
	//Iterate Through Vector, Adding Values
	for (int v = 0; v < sourceVector.size(); v++)
	{
		outputVector.push_back(sourceVector[v] + addVector[v]);
	}
	//Return Sum Vector as Output
	return outputVector;
}
//Vector Element Multiplication
vector<float> Vector_Multiply(vector<float> sourceVector, vector<float> mulVector)
{
	//Create Vector to Return as Output
	vector<float> outputVector;
	//Iterate Through Vector, Multiplying Values
	for (int v = 0; v < sourceVector.size(); v++)
	{
		outputVector.push_back(sourceVector[v] * mulVector[v]);
	}
	//Return Product Vector as Output
	return outputVector;
}
//Vector Scale
vector<float> Vector_Scale(vector<float> sourceVector, int scalar)
{
	//Create Vector to Return as Output
	vector<float> outputVector;
	//Iterate Through Vector, Scaling Values
	for (int v = 0; v < sourceVector.size(); v++)
	{
		outputVector.push_back(sourceVector[v] * scalar);
	}
	//Return Product Vector as Output
	return outputVector;
}

//Sigmoid: (X / 1 + abs(x)) + 1 --> {0.0f to 2.0f}
inline float Sigmoid(float val)
{
	return (val / (1 + absVal(val))) + 1;
}

//Sigmoid: (X / 1 + abs(x)) + 1 --> {0.0f to 2.0f}
vector<float> Vector_Sigmoid(vector<float>& inputMatrix)
{
	//Create a New Vector for Output
	vector<float> outputMatrix(inputMatrix.size());
	//Iterate Through Input Matrix and Take the Sigmoid for Each Iteration
	for (int i = 0; i < inputMatrix.size(); i++)
	{
		//Calculate Sigmoid for Each Iteration
		float val = inputMatrix[i];
		outputMatrix[i] = (val / (1 + absVal(val))) + 1;
	}
	return outputMatrix;
}

//Sigmoid Derivative --> (d/dx) Slope of Sigmoid Function
vector<float> Vector_Sigmoid_Derivative(vector<float> inputMatrix)
{
	//Create a New Vector for Output
	vector<float> outputMatrix(inputMatrix.size());
	//Iterate Through Input Matrix and Take 1st Derivative of Sigmoid Function
	for (int i = 0; i < inputMatrix.size(); i++)
	{
		//Calculate Sigmoid 1st Derivative for Each Iteration
		float val = inputMatrix[i];
		outputMatrix[i] = (1 / (1 + absVal(val))) - ((val * sign(val)) / sqr((absVal(val) + 1)));
	}
	return outputMatrix;
}
//--------------------------------------------------------------------------

#endif
