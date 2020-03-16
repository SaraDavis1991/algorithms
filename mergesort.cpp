/*
 filename: mergesort.cpp
 author: Sara Davis 
 date: 9/22/2019
 version: 1.0
 description: c++ implementation of mergesort
 note: To work as is, array must be provided a string in main
*/


#include <iostream>

void mergeSort(char array[], int l, int m, int r);

/*
 Function Name: int main()
 Purpose: Create character array, repeatedly call mergesort, print original to screen, and print sort
 inputs: None
*/

int main()

{

	char array[] = "ASORTINGEXAMPLE";


	for (int i=1; i<=(sizeof(array)/sizeof(array[0]))-1; i = 2*i)
	{
		for (int pointleft=0; pointleft<(sizeof(array)/sizeof(array[0]))-1; pointleft += 2*i)
		{
			int midval = pointleft + i - 1;
			if (pointleft + 2*i - 1  <(sizeof(array)/sizeof(array[0]))-1)
			{
				int pointleft2 = pointleft + 2*i - 1;
				mergeSort(array, pointleft, midval, pointleft2);
			}
			else
			{
				int pointleft2 = (sizeof(array)/sizeof(array[0]))-1;
				mergeSort(array, pointleft, midval, pointleft2);
			}
		
			

		}
	}
	std::cout << "Sorted: ";
	for (int i = 0; i < 16; i++){
		std::cout << array[i] << " ";
	}
	std::cout << std::endl;

	return 0;

}

/*
 Function Name: void mergeSort(char array[], int left, int mid, int right)
 Purpose: sort the left and right sides of the array, and merge them, printing at each stage
 inputs: array(portion of array), left (left pivot index), right (right pivot index), mid (mid index)
 returns: none
*/

void mergeSort(char array[], int left, int mid, int right)

{
	
	int leftHalf = mid - left + 1;
	int rightHalf = right - mid;
	int i = 0, j = 0;
	int k = left;
	char leftArray[leftHalf], rightArray[rightHalf];

	std::cout<<"Left:";
	for (int a = 0; a < leftHalf; a++)
	{
		leftArray[a] = array[left + a]; 
		std::cout<<leftArray[a] << " ";

	}
	std::cout<<std::endl;
	
	std::cout<<"Right:";

	for (int b = 0; b < rightHalf; b++)
	{
		rightArray[b] = array[mid + 1+ b]; 
		std::cout<<rightArray[b] << " ";
	}
	std::cout<<std::endl;


	std::cout<<"Merging:";
	while (i < leftHalf && j < rightHalf) 
	{
		if (leftArray[i] <= rightArray[j])
		{
			array[k] = leftArray[i];
			i++;
		}

		else
		{
			array[k] = rightArray[j];
			j++;
		}

		k++;
		std::cout<<" "<<array[k];
		}
		std::cout<<std::endl << std::endl;
	while (i < leftHalf)
	{
		array[k] = leftArray[i];
		i++;
		k++;
	}
	while (j < rightHalf)
	{
		array[k] = rightArray[j];
		j++;
		k++;

	}

}



