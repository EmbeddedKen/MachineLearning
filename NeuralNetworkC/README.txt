NeuralNetwork, written in C; by Kenneth Vorseth

*Only dependency is STDIO.h, for Win32 Console Verification
*This program does not utilize Dynamic Memory; Static, Compile-Time methodologies are used for maximum platform independence.

This is a single-layer, neural network.
To setup a Neural Network:
	-In NeuralNetwork.h, set #define INPUT_SIZE to number of inputs needed (# data inputs/fields)
	-In NeuralNetwork.h, set #define OUTPUT_SIZE to number of outputs needed (# of classifications)
	-Create an ANN struct, initialize using ANN_Initialize(ANN* aNN);
	-Create an Input1D struct, populate with input data, each Input1D represents one test run (maybe create an array?)
	-Create an Output1D struct, populate with input data's label, 0.0f or 1.0f; same goes for Input1D usage.
	-To Make a Prediction AND Train the Network, use ANN_Learn(ANN* aNN, Input1D* input, Output1D* target)
	-To Make a Prediction Alone with No Training, use ANN_MakePrediction(ANN* aNN, Input1D* input)
		-Then, take the output structure and run through Output1D_Sigmoid(Output1D* pred)
		-Returns result of {0.0f <-> 1.0f} for each Label/Classifier

As of now, the a pre-written test program runs through 50 samples of Iris flower dataset, and attempts classifying Iris Versicolor
and Iris Setosa.
