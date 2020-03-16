
/*
 filename: dynamic.cpp
 author: Sara Davis 
 date: 11/13/2019
 version: 1.0
 description: c++ implementation a dynamic programming problem. Given a series of events and coordinates
 plan the maximum number of observable events that you can view at time (t) given that you cannot 
 observe 1 event at each time
 note: To work as is, events and coordinates must be provided in main
*/
using namespace std;
#include <iostream>

int maxVal(int a, int b, int c);
int maxInd(int tableEvents[10][12], int i, int j);
int maxObservable(int events[], int coordinates[]);




/*
 Function Name: int main()
 Purpose: declare events and coordinates, call maxObservable
 inputs: None
*/
int main()
{
	int events[10] = {0,1,2, 3, 4, 5, 6, 7, 8, 9};
	int coordinates[10] = {0,1, -4, -1, 4, 5, -4, 6, 7, -2};
	maxObservable(events, coordinates);
}
/*
 Function Name: int maxVal(int a, int b, int c)
 Purpose: Calculate the maximum of 3 events (you can go to the left, right, or stay where you are)
 inputs: int a (left), int b (current), int c(right)
 returns: maximum value
*/
int maxVal(int a, int b, int c)
{
	int maxVal = std::max(std::max(a, b),c);
	if (maxVal < 0){
		return 0;
	}
	else{
		return maxVal;
	}
}
/*
 Function Name: int maxInd(int tableEvents[10][12], int i, int j)
 Purpose: Given your current position (j), determine if you should move left (j-1), right (j+1) or stay where you are and view current event
 inputs: int a (left), int b (current), int c(right)
 returns: index that maximizes the number of events at current time
*/
int maxInd(int tableEvents[10][12], int i, int j)
{
	int a, b, c;


	if(j<=0){
				a = -1;
			}

			else{
				a = tableEvents[i-1][j-1];
			}

			if (j>=11)
			{
				c = -1;
			}

			else{
				c=tableEvents[i-1][j+1];
			}
	b = tableEvents[i-1][j];
	int maxVal = std::max(std::max(a, b), c);
	
	if(maxVal ==tableEvents[i-1][j-1])
	{
		return j-1;
	}
	else if(maxVal == tableEvents[i-1][j])
	{
		return j;
	}
	else
	{
		return j+1;
	}

	
}
/*
 Function Name: int maxObservable(int events[], int coordinates[])
 Purpose: Create a board of the table of coordinates, and where you're coming from- use them to repeatedly call maxVal and maxInd to determine
 the number of maximum observable events at any time. Print the table of events and the max number of events at that time, as well as possible paths
 inputs: int a (left), int b (current), int c(right)
 returns: nothing
*/
int maxObservable(int events[], int coordinates[])
{
	int tableEvents[10][12]= {{-1, -1, -1, -1, 0, -1, -1, -1, -1, -1, -1, -1}, {-1, -1, -1, 0, 0, 0, -1, -1, -1, -1, -1, -1}, {-1, -1, 0, 0, 0, 0, 0, -1, -1, -1, -1, -1}, {-1, 0, 0, 0, 0, 0, 0, 0, -1, -1, -1, -1}, {-1, 0, 0, 0, 0, 0, 0, 0, 0, -1, -1, -1}
	, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -1, -1}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -1}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}};
	
	int tableComingFrom[10][12] = {{-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1}, {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1}, {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1}, {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1}, {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1}
	, {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1}, {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1}, {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1}, {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1}, {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1}};
	
	int mappedCoords[10];
	
	for (int i = 0; i < 10; i ++)
	{
		mappedCoords[i] = coordinates[i] + 4;
		//cout << coordinates[i] << " " << mappedCoords[i] << endl;
	}

	
	for (int i = 1; i < 10; i++)
	{
		for(int j = 0; j < 12; j++)
		{
			int a, b, c;
			if(j<=0){
				a = -1;
			}
			else{
				a = tableEvents[i-1][j-1];
			}
			if (j>=11)
			{
				c = -1;
			}
			else{
				c=tableEvents[i-1][j+1];
			}
			b = tableEvents[i-1][j];
			
			tableEvents[i][j] += maxVal(a, b, c);

			if(j == mappedCoords[i])
			{
				//tableEvents[i][j] += maxVal(tableEvents[i-1][j-1], tableEvents[i-1][j], tableEvents[i-1][j+1]);

				tableEvents[i][j] ++;
			}
			tableComingFrom[i][j] =maxInd(tableEvents, i, j);


			
		}
	}
	




	cout << "====================Table of Events====================" << endl;
	for (int i = 0; i < 10; i ++)
	{
		for(int j = 0; j < 12; j++)
		{
			cout << " " << tableEvents[i][j];

		}
		cout << endl;
	}

	cout <<  "\n====================Optimal Values====================" << endl;
	for (int i = 0; i < 10; i ++)
	{
		for(int j = 0; j < 12; j++)
		{
			if (j == mappedCoords[i]){
				if (tableEvents[i][j] > 0){
					cout << "Event " << i << ": " << tableEvents[i][j]; 
				}
				else{
					cout<<  "Event " << i << ": 0"; 
				}
			}
		}
		cout << endl;
	}
	cout << endl;

	cout << "====================Table of Paths====================" << endl;
	for (int i = 0; i < 10; i ++)
	{
		for(int j = 0; j < 12; j++)
		{
			cout << " " << tableComingFrom[i][j];
			
		}
		cout << endl;
	}
	cout << endl;


	cout << "\n====================Optimal Path====================" << endl;
	int point = 2;

	for (int i = 9; i >0; i --)
	{
		//cout << point << " " << mappedCoords[i] << " ";
		
		

		if(mappedCoords[i] == point)
		{
			cout << "event: " << i << endl;
		}

		point = tableComingFrom[i][point];
	}

	cout << endl;






}


