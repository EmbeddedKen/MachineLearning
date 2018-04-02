#ifndef NEURAL_NETWORK_H
#define NEURAL_NETWORK_H
#include <stdio.h> //REMOVE FOR DEPLOYMENT TO EMBEDDED PLATFORMS

//Defines and Macros
#define INPUT_SIZE 4
#define OUTPUT_SIZE 3
#define ABSOLUTE(val) ((val >= 0) ? val : -val)
#define SIGN(val) ((val == 0) ? 0 : (val > 0) ? 1 : -1)

//Artificial Neural Network Structures
typedef struct { float val[INPUT_SIZE];				 } Input1D;	
typedef struct { float val[OUTPUT_SIZE];			 } Output1D;
typedef struct { float val[OUTPUT_SIZE][INPUT_SIZE]; } Weights2D;
typedef struct { Weights2D weights; float iterations; float iterSum; float learningRate; } ANN;

//Win32 StdIO Dependencies (For Debug Only)
void DisplayInput1D(Input1D* input)
{
	printf("Input1D: {");
	for (int i = 0; i < INPUT_SIZE; i++)
	{
		printf("%f", input->val[i]);
		if (i != INPUT_SIZE - 1) { printf(","); }
	}
	printf("}\n");
}
void DisplayOutput1D(Output1D* output)
{
	printf("Output1D: {");
	for (int o = 0; o < OUTPUT_SIZE; o++)
	{
		printf("%f", output->val[o]);
		if (o != OUTPUT_SIZE - 1) { printf(","); }
	}
	printf("}\n");
}
void DisplayWeights2D(Weights2D* weights)
{
	printf("Weights2D:\n");
	for (int o = 0; o < OUTPUT_SIZE; o++)
	{
		printf("%d: {", o);
		for (int i = 0; i < INPUT_SIZE; i++)
		{
			printf("%f", weights->val[o][i]);
			if (i != INPUT_SIZE - 1) { printf(","); }
		}
		printf("}\n");
	}
}

//ANN Initialization Function (For new ANN's only!)
ANN_Initialize(ANN* aNN, float learnRate)
{
	//New Artificial Neural Network
	aNN->iterations = aNN->iterSum = 0;
	aNN->learningRate = learnRate;
	//Initialize Weights
	for (int o = 0; o < OUTPUT_SIZE; o++)
	{
		for (int i = 0; i < INPUT_SIZE; i++)
		{
			aNN->weights.val[o][i] = 0.25f;
		}
	}
}

//Determines the Cost Between the Prediction and the Target
Output1D Output1D_Cost(Output1D* prediction, Output1D* target)
{
	//Create Return Output Struct
	Output1D output;
	//Cost Function (Prediction - Target)^2
	for (int o = 0; o < OUTPUT_SIZE; o++)
	{
		output.val[o] = target->val[o] - prediction->val[o];
		output.val[o] = (output.val[o] * output.val[o]) * SIGN(output.val[o]);
	}
	return output;
}

//Sigmoid: (X / 1 + ABSOLUTE(x)) --> {-1.0f to 1.0f}
Output1D Output1D_Sigmoid(Output1D* prediction)
{
	//Create Return Output Struct
	Output1D output;
	//Iterate Through Prediction and Take the Sigmoid for Each Iteration
	for (int o = 0; o < OUTPUT_SIZE; o++)
	{
		//Calculate Sigmoid for Each Iteration
		float val = prediction->val[o];
		output.val[o] = (val / (1 + ABSOLUTE(val)));
	}
	return output;
}

//Sigmoid Derivative: (1 / ((1 + ABSOLUTE(val)) * (1 + ABSOLUTE(val))))
Output1D Output1D_SigmoidDeriv(Output1D* error)
{
	//Create Output Struct
	Output1D output;
	for (int o = 0; o < OUTPUT_SIZE; o++)
	{
		float val = error->val[o];
		float absVal = ABSOLUTE(val);
		output.val[o] = 1 / ((1 + ABSOLUTE(val)) * (1 + ABSOLUTE(val)));
	}
	//Return Output
	return output;
}

//Makes a New Prediction and Returns Results as an Output1D
Output1D ANN_MakePrediction(ANN* aNN, Input1D* input)
{
	//Create New Output 1 Dimensional Array
	Output1D output;
	//For Each Output, Sum all Products of Each Input with Weight
	for (int o = 0; o < OUTPUT_SIZE; o++)
	{
		output.val[o] = 0; //Initialize Output Sum
		for (int i = 0; i < INPUT_SIZE; i++)
		{
			output.val[o] += input->val[i] * aNN->weights.val[o][i];
		}
	}
	//Return Output Prediction (Pass by Value)
	return output;
}

//Makes a New Prediction and Updates Weights for "Learning"
Output1D ANN_Learn(ANN* aNN, Input1D* input, Output1D* target)
{
	//DEBUG: Display Input Data
	printf("[Artificial Neural Network Training/Learning]---------\n");
	printf("[Current Weights]-------------------------------------\n");
	DisplayWeights2D(&aNN->weights);
	printf("[Neuron Inputs]---------------------------------------\n");
	DisplayInput1D(input);


	//Make a Prediction Based on Input Data
	Output1D rawPrediction = ANN_MakePrediction(aNN, input);
	printf("[Prediction Prior to Sigmoid]-------------------------\n");
	DisplayOutput1D(&rawPrediction);
	Output1D prediction = Output1D_Sigmoid(&rawPrediction);
	printf("[Prediction Filtered with Sigmoid]--------------------\n");
	DisplayOutput1D(&prediction);
	printf("[Target for Output]-----------------------------------\n");
	DisplayOutput1D(target);  

	//Determine Error Between Output and Target (Cost Func)
	Output1D error = Output1D_Cost(&rawPrediction, target);
	Output1D sig_deriv = Output1D_SigmoidDeriv(&rawPrediction);
	printf("[Cost of Prediction]----------------------------------\n");
	DisplayOutput1D(&error);
	printf("[Sigmoid Deriviative of Weighted Input]---------------\n");
	DisplayOutput1D(&sig_deriv);

	//Calculate Delta Weight Changes
	Weights2D deltaWeights;
	for (int o = 0; o < OUTPUT_SIZE; o++)
	{
		for (int i = 0; i < INPUT_SIZE; i++)
		{
			deltaWeights.val[o][i] = aNN->learningRate * (target->val[o] - rawPrediction.val[o]) * sig_deriv.val[o] * input->val[i];
		}
	}
	printf("[Delta Weights, Weight Changes]-----------------------\n");
	DisplayWeights2D(&deltaWeights);

	//Apply Weight Changes to ANN
	for (int o = 0; o < OUTPUT_SIZE; o++)
	{
		for (int i = 0; i < INPUT_SIZE; i++)
		{
			aNN->weights.val[o][i] += deltaWeights.val[o][i];
		}
	}
	printf("[Recalculated Weights for ANN]------------------------\n");
	DisplayWeights2D(&aNN->weights);

	//Return Prediction
	return prediction;
}


#endif
