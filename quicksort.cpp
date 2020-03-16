/*
 filename: quicksort.cpp
 author: Sara Davis 
 date: 9/22/2019
 version: 1.0
 description: c++ implementation of quicksort
 note: To work as is, array must be provided a string in main
*/

#include <iostream>


void partition(char array[], int l, int r, int &i, int &j);
void quicksort(char array[], int l, int r);


/*
 Function Name: int main()
 Purpose: Create character array, print original to screen, and print sort
 inputs: None
*/
int main() 
{ 
	char array [] = "ABRACACABRABCDC";
	std::cout << "Initial array: ";
	for (int i = 0; i < 16; ++i) {

		std::cout << array[i];
	}
	std::cout<<std::endl;
	quicksort(array, 0, sizeof(array) / sizeof(array[0]) - 1); 
	std::cout << "Sorted array: ";
	for (int i = 0; i < 16; ++i) {

		std::cout << array[i];
	}
	std::cout<<std::endl;
	return 0; 
} 

/*
 Function Name: partition(char array[], int left, int right, int &indexLeft, int &indexRight)
 Purpose: Repeatedly partition until the smallest element in the array is found
 inputs: array(portion of array), left (left pivot index), right (right pivot index), &indexLeft, &indexRight
 returns: none
*/
void partition(char array[], int left, int right, int &indexLeft, int &indexRight)
{ 
	indexLeft = left-1, indexRight = right; 
	int pivot = left-1, rightOfPivot = right; 
	int equalPiv = array[right]; 

	while (true) 
	{ 

		int i = indexLeft;
		
		while (array[++indexLeft] < equalPiv)
		{
			
		} 
		
		while (equalPiv < array[--indexRight])
		{ 
			if (indexRight == left)
			{
				break;
			} 
			
				 
		}
		if (indexLeft >= indexRight)
		{
			break;
		} 

		int temp = array[indexLeft];
		array[indexLeft] = array[indexRight];
		array[indexRight] = temp;
		
		if (array[indexLeft] == equalPiv) 
		{ 
			pivot++;
			int temp = array[pivot];
			array[pivot] = array[indexLeft];
			array[indexLeft] = temp;
	
		} 
		
		if (array[indexRight] == equalPiv) 
		{ 
			rightOfPivot--; 
			int temp = array[indexRight];
			array[indexRight] =array[rightOfPivot];
			array[rightOfPivot] = temp;
		
			
		} 


	} 
	int temp = array[indexLeft];
	array[indexLeft] = array[right];
	array[right] = temp;


	
	indexRight = indexLeft-1; 
	for (int i = left; i < pivot; i++, indexRight--)
	{
		int temp = array[i];
		array[i] = array[indexRight];
		array[indexRight]=temp;
		
		
	} 
		
	indexLeft = indexLeft+1; 
	for (int i = right-1; i > rightOfPivot; i--, indexLeft++) 
	{
		int temp = array[indexLeft];
		array[indexLeft]= array[i];
		array[i] = temp;
		
	}
		
} 

/*
 Function Name: void quicksort(char array[], int left, int right)
 Purpose: Perorm quicksort on the left and the right portions of the array
 inputs: array(portion of array), left (left pivot index), right (right pivot index)
 returns: none
*/
void quicksort(char array[], int left, int right) 
{ 
	
	for (int i = 0; i < 16; i++)
	{
		std::cout << array[i];
	}
	std::cout<< std::endl;
	int i, j; 
	if (right <= left)
	{
		return; 
	} 

	partition(array, left, right, i, j); 

	quicksort(array, left, j); 

	quicksort(array, i, right); 

	
} 

