#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "NeuralNetwork.h"

int main()
{
	printf("Artificial Neural Network Testing Suite\nWritten in C, with No Dependencies other than STD Console\n|Kenneth Vorseth, 2018|\n\n");
	//Seed Random Number Generator
	srand(time(NULL));

	//Create New ANN with Learning Rate of 0.12f
	ANN aNN;
	ANN_Initialize(&aNN, 0.12f);
	//Input Data Set (100 Training Sets of Iris Flowers)
	Input1D trial[75] = 
	{ 
		{5.1f, 3.5f, 1.4f, 0.2f}, //0: Start of Iris Setosa
		{4.9f, 3.0f, 1.4f, 0.2f}, //1
		{4.7f, 3.2f, 1.3f, 0.2f}, //2
		{4.6f, 3.1f, 1.5f, 0.2f}, //3
		{5.0f, 3.6f, 1.4f, 0.3f}, //4
		{5.4f, 3.9f, 1.7f, 0.4f}, //5
		{4.6f, 3.4f, 1.5f, 0.1f}, //6
		{5.0f, 3.4f, 1.5f, 0.2f}, //7
		{4.4f, 2.9f, 1.4f, 0.2f}, //8
		{4.9f, 3.1f, 1.5f, 0.1f}, //9
		{5.4f, 3.7f, 1.5f, 0.2f}, //10
		{4.8f, 3.4f, 1.6f, 0.2f}, //11
		{4.3f, 3.0f, 1.1f, 0.1f}, //12
		{5.8f, 4.0f, 1.2f, 0.2f}, //13
		{5.7f, 4.4f, 1.5f, 0.4f}, //14
		{5.4f, 3.9f, 1.3f, 0.4f}, //15
		{5.1f, 3.5f, 1.4f, 0.3f}, //16
		{5.7f, 3.8f, 1.7f, 0.3f}, //17
		{5.1f, 3.8f, 1.5f, 0.3f}, //18
		{5.4f, 3.4f, 1.5f, 0.4f}, //19
		{5.1f, 3.7f, 1.5f, 0.4f}, //20
		{4.6f, 3.6f, 1.0f, 0.2f}, //21
		{5.1f, 3.3f, 1.7f, 0.5f}, //22
		{4.6f, 3.6f, 1.0f, 0.2f}, //23
		{4.8f, 3.4f, 1.9f, 0.2f}, //24: End of Iris Setosa
		{7.0f, 3.2f, 4.7f, 1.4f}, //25: Start of Iris Versicolor
		{6.4f, 3.2f, 4.5f, 1.5f}, //26
		{6.9f, 3.1f, 4.9f, 1.5f}, //27
		{5.5f, 2.3f, 4.0f, 1.3f}, //28
		{6.5f, 2.8f, 4.6f, 1.5f}, //29
		{5.7f, 2.8f, 4.5f, 1.3f}, //30
		{6.3f, 3.3f, 4.7f, 1.6f}, //31
		{4.9f, 2.4f, 3.3f, 1.0f}, //32
		{6.6f, 2.9f, 4.6f, 1.3f}, //33
		{5.2f, 2.7f, 3.9f, 1.4f}, //34
		{5.0f, 2.0f, 3.5f, 1.0f}, //35
		{5.9f, 3.0f, 4.2f, 1.5f}, //36
		{6.0f, 2.2f, 4.0f, 1.0f}, //37
		{6.1f, 2.9f, 4.7f, 1.4f}, //38
		{5.6f, 2.9f, 3.6f, 1.3f}, //39
		{5.8f, 2.7f, 4.1f, 1.0f}, //40
		{6.2f, 2.2f, 4.5f, 1.5f}, //41
		{5.6f, 2.5f, 3.9f, 1.1f}, //42
		{6.1f, 2.8f, 4.0f, 1.3f}, //43
		{6.3f, 2.5f, 4.9f, 1.5f}, //44
		{6.1f, 2.8f, 4.7f, 1.2f}, //45
		{6.4f, 2.9f, 4.3f, 1.3f}, //46
		{6.1f, 2.8f, 4.7f, 1.2f}, //47
		{6.4f, 2.9f, 4.3f, 1.3f}, //48
		{6.6f, 3.0f, 4.4f, 1.4f}, //49: End of Iris Versicolor
		{6.3f, 3.3f, 6.0f, 2.5f}, //50: Start of Iris Virginica
		{5.8f, 2.7f, 5.1f, 1.9f}, //51
		{7.1f, 3.0f, 5.9f, 2.1f}, //52
		{6.3f, 2.9f, 5.6f, 1.8f}, //53
		{6.5f, 3.0f, 5.8f, 2.2f}, //54
		{7.6f, 3.0f, 6.6f, 2.1f}, //55
		{4.9f, 2.5f, 5.8f, 1.8f}, //56
		{7.3f, 2.9f, 6.3f, 1.8f}, //57
		{6.7f, 2.5f, 6.3f, 1.8f}, //58
		{7.2f, 3.6f, 6.1f, 2.5f}, //59
		{6.5f, 3.2f, 5.1f, 2.0f}, //60
		{6.4f, 2.7f, 5.3f, 1.9f}, //61
		{6.8f, 3.0f, 5.5f, 2.1f}, //62
		{5.7f, 2.5f, 5.0f, 2.0f}, //63
		{5.8f, 2.8f, 5.1f, 2.4f}, //64
		{6.4f, 3.2f, 5.3f, 2.3f}, //65
		{6.5f, 3.0f, 5.5f, 1.8f}, //66
		{7.7f, 3.8f, 6.7f, 2.2f}, //67
		{7.7f, 2.6f, 6.9f, 2.3f}, //68
		{6.0f, 2.2f, 5.0f, 1.5f}, //69
		{6.9f, 3.2f, 5.7f, 2.3f}, //70
		{5.6f, 2.8f, 4.9f, 2.0f}, //71
		{7.7f, 2.8f, 6.7f, 2.0f}, //72
		{6.3f, 2.7f, 4.9f, 1.8f}, //73
		{6.7f, 3.3f, 5.7f, 2.1f}  //74 End of Iris Virginica
	};
	//Label Data Set
	Output1D target[75];
	for (int i = 0; i < 75; i++)
	{
		if (i < 25) //Label as Iris Setosa
		{
			target[i].val[0] = 1.0f;
			target[i].val[1] = -1.0f;
			target[i].val[2] = -1.0f;
		}
		else if (i >= 25 && i < 50) //Label as Iris Versicolor
		{
			target[i].val[0] = -1.0f;
			target[i].val[1] = 1.0f;
			target[i].val[2] = -1.0f;
		}
		else if (i >= 50)//Label as Iris Virginica
		{
			target[i].val[0] = -1.0f;
			target[i].val[1] = -1.0f;
			target[i].val[2] = 1.0f;
		}
	}


	//Attempt Making Predictions and Learning from Them
	for (int t = 0; t < 75; t++)
	{
		//Choose Random Selections to Learn From
		int randIndex = rand() % 75;
		printf("\n~~~~[TRIAL %d]~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n", t);
		ANN_Learn(&aNN, &trial[randIndex], &target[randIndex]);
		printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
		printf("Hit 'Enter' to Continue.");
		getchar();
	}

	//Training Complete; Make Four Flower Predictions
	//Setosa, Versicolor, Virginica, Setosa, Versicolor, Virginica
	Input1D flowerInput[6] = { {5.1f, 3.8f, 1.6f, 0.2f}, {5.7f, 2.9f, 4.2f, 1.3f}, {5.9f, 3.0f, 5.1f, 1.8f},
							   {4.4f, 3.2f, 1.3f, 0.2f}, {5.5f, 2.6f, 4.4f, 1.2f}, {6.2f, 3.4f, 5.4f, 2.3f} }; 
	for (int i = 0; i < 6; i++)
	{
		printf("\n~~~~[REAL PREDICTION %d]~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n", i);
		//Make a Prediction
		Output1D pred = ANN_MakePrediction(&aNN, &flowerInput[i]);
		pred = Output1D_Sigmoid(&pred);
		//Constrain to -1.0f to 1.0f Range, If Exceeded
		float confSetosa = (pred.val[0] < -1.0f) ? -1 : (pred.val[0] > 1.0f) ? 1.0f : pred.val[0];
		float confVersi = (pred.val[1] < -1.0f) ? -1 : (pred.val[1] > 1.0f) ? 1.0f : pred.val[1];
		float confVirgi = (pred.val[2] < -1.0f) ? -1 : (pred.val[2] > 1.0f) ? 1.0f : pred.val[2];
		//Display Confidence Levels
		printf("Confidence in Iris Setosa: %f\n", confSetosa);
		printf("Confidence in Iris Versicolor: %f\n", confVersi);
		printf("Confidence in Iris Virginica: %f\n", confVirgi);
		//Display Highest Confidence (Classified Item)
		if (pred.val[0] > pred.val[1] && pred.val[0] > pred.val[2]) { printf("Result: Iris Setosa!\n"); }
		else if (pred.val[1] > pred.val[0] && pred.val[1] > pred.val[2]) { printf("Result: Iris Versicolor!\n"); }
		else if (pred.val[2] > pred.val[0] && pred.val[2] > pred.val[1]) { printf("Result: Iris Virginica!\n"); }
		//Display True Values (For Human-Comparison)
		if (i == 0 || i == 3) { printf("Should be Iris Setosa!\n"); }
		else if (i == 1 || i == 4) { printf("Should be Iris Versicolor!\n"); }
		else if (i == 2 || i == 5) { printf("Should be Iris Virginica!\n"); }
		printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
		printf("Hit 'Enter' to Continue.");
		getchar();
	}

	printf("Program Complete.");
	getchar();
    return 0;
}

