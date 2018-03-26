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
	//Input Data Set (50 Training Sets of Iris Flowers)
	Input1D trial[50] = 
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
		{6.6f, 3.0f, 4.4f, 1.4f} //49: End of Iris Versicolor
	};
	//Label Data Set
	Output1D target[50];
	for (int i = 0; i < 50; i++)
	{
		if (i < 25) //Label as Iris Setosa
		{
			target[i].val[0] = 1.0f;
			target[i].val[1] = -1.0f;
		}
		else //Label as Iris Versicolor
		{
			target[i].val[0] = -1.0f;
			target[i].val[1] = 1.0f;
		}
	}


	//Attempt Making Predictions and Learning from Them
	for (int t = 0; t < 50; t++)
	{
		//Choose Random Selections to Learn From
		int randIndex = rand() % 50;
		printf("\n~~~~[TRIAL %d]~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n", t);
		ANN_Learn(&aNN, &trial[randIndex], &target[randIndex]);
		printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
		printf("Hit 'Enter' to Continue.");
		getchar();
	}

	//Training Complete; Make Four Flower Predictions
	Input1D flowerInput[4] = { { 4.6f, 3.4f, 1.5f, 0.1f },{ 5.6f, 2.9f, 3.6f, 1.3f },{ 4.9f, 3.1f, 1.5f, 0.1f },{ 6.4f, 2.9f, 4.3f, 1.3f } };
	for (int i = 0; i < 4; i++)
	{
		printf("\n~~~~[REAL PREDICTION %d]~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n", i);
		Output1D pred = ANN_MakePrediction(&aNN, &flowerInput[i]);
		pred = Output1D_Sigmoid(&pred);
		float confSetosa = (pred.val[0] < -1.0f) ? -1 : (pred.val[0] > 1.0f) ? 1.0f : pred.val[0];
		float confVersi = (pred.val[1] < -1.0f) ? -1 : (pred.val[1] > 1.0f) ? 1.0f : pred.val[1];
		printf("Confident Iris is Setosa: %f\n", confSetosa);
		printf("Confident Iris is Versicolor: %f\n", confVersi);
		if (i % 2 == 0) { printf("Should be Iris Setosa!\n\n"); }
		else { printf("Should be Iris Versicolor!\n"); }
		printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
		printf("Hit 'Enter' to Continue.");
		getchar();
	}

	printf("Program Complete.");
	getchar();
    return 0;
}

