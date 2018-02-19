#ifndef NEURAL_NETWORK_H
#define NEURAL_NETWORK_H
#include "NeuralNetMath.h"
using namespace std;

//Each Layer Represents a Two-Dimensional Array of Weights
//Connecting Itself to the Next Layer
struct Layer
{
public:
	vector<vector<float>> weights; // [output][input]
	int outputSize;
	int inputSize;
	
};

//Artificial Neural Network Class Itself
//Capable of 0,1,2 Hidden Layers via Constructor Overloads
class NeuralNetwork
{
public:
	NeuralNetwork(const int features, const int signatures) //0-Hidden Layer ANN
	{
		//Setup Input Layer
		Layer& featureLayer = *(new Layer());
		featureLayer.inputSize = features;
		featureLayer.outputSize = signatures;
		ResetLayer(featureLayer);
		//Set ANN to Single Layer Mode (0-Hidden Layers)
		numberOfLayers = 1;
		layers.push_back(featureLayer);
	}
	NeuralNetwork(const int features, const int layerSize, const int signatures) //1-Hidden Layer ANN
	{
		//Setup Input Layer
		Layer& featureLayer = *(new Layer());
		featureLayer.inputSize = features;
		featureLayer.outputSize = layerSize;
		ResetLayer(featureLayer);
		//Setup Hidden Layer
		Layer& hiddenLayer = *(new Layer());
		hiddenLayer.inputSize = layerSize;
		hiddenLayer.outputSize = signatures;
		ResetLayer(featureLayer);
		//Setup ANN to Two Layer Mode (1-Hidden Layer)
		numberOfLayers = 2;
		layers.push_back(featureLayer);
		layers.push_back(hiddenLayer);
	}
	NeuralNetwork(const int features, const int layerSizeA, const int layerSizeB, const int signatures) //2-Hidden Layer ANN
	{
		//Setup Input Layer
		Layer& featureLayer = *(new Layer());
		featureLayer.inputSize = features;
		featureLayer.outputSize = layerSizeA;
		ResetLayer(featureLayer);
		//Setup Hidden LayerA
		Layer& hiddenLayerA = *(new Layer());
		hiddenLayerA.inputSize = layerSizeA;
		hiddenLayerA.outputSize = layerSizeB;
		ResetLayer(hiddenLayerA);
		//Setup Hidden LayerB
		Layer& hiddenLayerB = *(new Layer());
		hiddenLayerB.inputSize = layerSizeB;
		hiddenLayerB.outputSize = signatures;
		ResetLayer(hiddenLayerB);
		//Setup ANN to Three Layer Mode (2-Hidden Layers)
		numberOfLayers = 3;
		layers.push_back(featureLayer);
		layers.push_back(hiddenLayerA);
		layers.push_back(hiddenLayerB);
	}
	vector<float> MakePrediction(vector<float> featureData)
	{
		//Iterate Through Each Layer, Starting from Features, through Hidden Layers
		vector<float> layerStage = featureData;
		for (int layer = 0; layer < numberOfLayers; layer++)
		{
			layerStage = ExecuteLayerPrediction(layerStage, layer);
		}
		//Layer Stage Vector Now Holds Result to Predictions
		return layerStage;
	}
	vector<float> TrainModel(vector<float> featureData, vector<float> correctOutput)
	{
		//Generate Prediction on Current Model using Correct FeatureData
		vector<float> prediction = MakePrediction(featureData);
		//Calculate Error Between Prediction and Actual Value
		vector<float> error = Vector_Subtraction(correctOutput, prediction);
		//Calculate Delta Error using Derivative Sigmoid Function
		vector<float> deltaError = Vector_Multiply(error, Vector_Sigmoid_Derivative(prediction));
		//Calculate Weight Delta by Taking Dot Product of FeatureData with DeltaError
		
		//Apply Backpropagation and Apply Weight Changes

		//...

		//Return Prediction to Show Improvement
		return prediction;
	}
private:
	vector<float> ExecuteLayerPrediction(vector<float> inputData, int layerIndex)
	{
		//Create Output Vector for Sums
		vector<float> outputVector;
		//For Each Output Layer, Sum the Product of All Input Data with Weights
		for (int oW = 0; oW < layers[layerIndex].outputSize; oW++)
		{
			float sum = 0.0f; //Compute Dot Product Sum of InputData and Respective Weights
			for (int iW = 0; iW < layers[layerIndex].inputSize; iW++)
			{
				sum += layers[layerIndex].weights[oW][iW] * inputData[iW];
			}
			//Compute Sigmoid of Dot Product Sum, Push to Output Vector
			outputVector.push_back(Sigmoid(sum));
		}
		//Return Output Vector, Contains Sums
		return outputVector;
	}
	void ResetLayer(Layer& layer)
	{
		//Iterate Through Each Output Layer Weight
		for (int oW = 0; oW < layer.outputSize; oW++)
		{
			//Iterate Through Each Input Layer Weight
			for (int iW = 0; iW < layer.inputSize; iW++)
			{
				layer.weights[oW][iW] =  0.5f; //Default Value of Weights
			}
		}
	}

	vector<Layer&> layers;		//Includes All Layers EXCEPT Signature Layer
	int numberOfLayers;			//Number of Layers (Not Counting Signature Layer)
};

#endif
