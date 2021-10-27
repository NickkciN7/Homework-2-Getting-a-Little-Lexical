#include <iostream>
#include <ctime>
#include <stdlib.h>

#define ARRAY_SIZE 10000

std::clock_t t0, t1;

void arrayStatic();
void arrayStack();
void arrayDynamic();


int main()
{
	//call functions
	arrayStatic();
	arrayStack();
	arrayDynamic();

	return 0;
}

void arrayStatic() {
	t0 = std::clock(); //store value of clock() currently

	static int arr[ARRAY_SIZE];
	for (int i = 0; i < ARRAY_SIZE; i++) {
		int randNum = rand() % 100 + 1; //get random number from 1 to 100
		arr[i] = randNum; //assign the random number to the i-th index of arr
	}

	t1 = std::clock(); //store value of clock() after assigning values to arr
	float tDifInSeconds = (float)(t1-t0) / CLOCKS_PER_SEC; //get the difference in terms of seconds
	
	std::cout << "Static Array Results: \n" << "\tClock Ticks: " << t1-t0 << "\n\tIn seconds: " << tDifInSeconds << "\n\n"; //print information
}

void arrayStack() {
	t0 = std::clock();
	
	int arr[ARRAY_SIZE];
	for (int i = 0; i < ARRAY_SIZE; i++) {
		int randNum = rand() % 100 + 1;
		arr[i] = randNum;
	}
	
	t1 = std::clock();
	float tDifInSeconds = (float)(t1 - t0) / CLOCKS_PER_SEC;

	std::cout << "Stack Dynamic Array Results: \n" << "\tClock Ticks: " << t1 - t0 << "\n\tIn seconds: " << tDifInSeconds << "\n\n";
}

void arrayDynamic() {
	t0 = std::clock();

	int* arr = new int[ARRAY_SIZE];
	for (int i = 0; i < ARRAY_SIZE; i++) {
		int randNum = rand() % 100 + 1;
		arr[i] = randNum;
	}
	
	t1 = std::clock();
	float tDifInSeconds = (float)(t1 - t0) / CLOCKS_PER_SEC;

	std::cout << "Heap Dynamic Array Results: \n" << "\tClock Ticks: " << t1 - t0 << "\n\tIn seconds: " << tDifInSeconds << "\n\n";
}