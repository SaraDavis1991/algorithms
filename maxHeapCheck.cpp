
/*
 filename: maxHeapCheck.cpp
 author: Sara Davis 
 date: 10/06/2019
 version: 1.0
 description: c++ implementation of a check for maxHeap
 note: To work as is, array must be provided in main
*/
#include <iostream>

void heap(int array[], int len);
void print(int array[], int len);

/*
 Function Name: int main()
 Purpose: declare array, call print, call heap.
 inputs: None
 returns: None
*/
int main()
{
	int arrA [] = {16, 14, 10, 8, 7, 9, 3, 2, 4, 1};
	print(arrA, 10);
	heap(arrA, 10);
	int B []= {10, 3, 9, 7, 2, 11, 5, 1, 6};
	print(B, 9);
	heap(B, 9);
}
/*
 Function Name: void heap(int array[], int len)
 Purpose: iterate through heap and check if array element at 2*i+1 or +2 is greater than current element. If it is, it's not a heap and return
 inputs: int array[], int len
 returns: None
*/
void heap(int array[], int len)
{
	for (int i = 0; i <=(len-2)/2; i++)
	{
		if(array[2*i+1]>array[i])
		{
			std::cout << "Not a heap" << std::endl;
			return;
		}
		if(2*i+2 < len && array[2*i+2]>array[i])
		{
			std::cout << "Not a heap" << std::endl;
			return;
		}
	}
	std::cout << "YES, a heap" << std::endl;
	return;
}
/*
 Function Name: void print(int array[], int len)
 Purpose:print the contents of the array
 inputs: int array[], int len
 returns: None
*/
void print(int array[], int len)
{
	std::cout << "Checking Array: ";
	for (int i = 0; i < len; i++)
	{
		std::cout << array[i] << " " ;
	}
	std::cout <<  std::endl;
}