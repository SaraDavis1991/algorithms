
/*
 filename: bubbleSort.cpp
 author: Sara Davis 
 date: 9/21/2019
 version: 1.0
 description: c++ implementation of bubblesort
 note: To work as is, array must be provided in main
*/

#include <iostream>
#include <algorithm>

void sortnum(int array[], int len);
void sortchar(char array[], int len);


/*
 Function Name: int main()
 Purpose: declare array, print contents, call sortnum, and print sorted contents
 inputs: None
 returns: None
*/
int main()
{
	int numarray[] = {6,5,2,8,3,1};
	sortnum(numarray,  sizeof(numarray) / sizeof(numarray[0]));
	for (int i = 0; i < sizeof(numarray) / sizeof(numarray[0]); i++)
	{
		std::cout << numarray[i] << " ";
	}
	std::cout << std::endl;


	char chararray[] = { 'E','A','S','Y','Q','U','E','S','T','I','O','N' };
	sortchar(chararray, sizeof(chararray) / sizeof(chararray[0]));
	std::cout << ("Sorted:\n");
	for (int i = 0; i < sizeof(chararray) / sizeof(chararray[0]); i++)
	{
		std::cout << chararray[i] << " ";
	}
	std::cout << std::endl;
	

}
/*
 Function Name: void sortnum(int array[], int len)
 Purpose: use bubblesort algrithm to sort left to right, then right to left, printing each
 inputs: int array[], int len
 returns: none
*/
void sortnum(int array[], int len)
{
	int first = 0;
	int last = len - 1;
	bool flip = true;
	

	while (flip == true) 
	{
		flip = false;
		std::cout << "Left to right: ";
		for (int i = first; i < last; ++i) 
		{
			if (array[i] > array[i + 1]) 
			{
				std::swap(array[i], array[i + 1]);
				flip = true;
			}

		std::cout << array[i]<<" ";

		}
		std::cout << std::endl;

	
		flip = false;

		last--;
		std::cout << "Right to left: ";
		for (int i = last - 1; i >= first; --i)
	 	{
			if (array[i] > array[i + 1])
		 	{
				std::swap(array[i], array[i + 1]);
				flip = true;
			}
			std::cout << array[i]<<" ";
	}
		std::cout << std::endl;
		first++;
}

}
/*
 Function Name: void sortchar(char array[], int len)
 Purpose: use bubblesort algrithm to sort left to right, then right to left, printing each
 inputs: int array[], int len
 returns: none
*/
void sortchar(char array[], int len)
{
	int first = 0;
	int last = len - 1;
	bool flip = true;
	int numcomp = 0;
	

	while (flip == true) 
	{
		flip = false;
		std::cout << "Left to right: ";
		for (int i = first; i < last; ++i) 
		{
			numcomp +=1;
			if (array[i] > array[i + 1]) 
			{
				std::swap(array[i], array[i + 1]);
				flip = true;
			}

		std::cout << array[i]<<" ";

		}
		std::cout << std::endl;

	
		flip = false;

		last--;
		std::cout << "Right to left: ";
		for (int i = last - 1; i >= first; --i)
	 	{
	 		numcomp+=1;
			if (array[i] > array[i + 1])
		 	{
				std::swap(array[i], array[i + 1]);
				flip = true;
			}
			std::cout << array[i]<<" ";
	}
		std::cout << std::endl;

		std::cout << "Num comparisons: " << numcomp << std::endl;
		first++;
}

}
