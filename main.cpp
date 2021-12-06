#include <iostream>
#include <algorithm>
#include <math.h>

using namespace std;

struct DataPoint // Struct for every point to store values for each point
{
	int group;
	double x, y;
	double distance;
};

bool compare(DataPoint a, DataPoint b) // Compare data points by distance from p
{
	return (a.distance < b.distance);
}

int sortDataPoint(DataPoint arr[], int n, int k, DataPoint p) // Sorts the data points and assigns p to a group
{
	// Set distance of all points from p
	for (int i = 0; i < n; i++)
	{
		// Euclidean Distance
		arr[i].distance = sqrt((arr[i].x - p.x) * (arr[i].x - p.x) + 
			               (arr[i].y - p.y) * (arr[i].y - p.y));
	}

	// Sort data points by distance from p
	sort(arr, arr+n, compare);

	// For the first k elements, count the frequency of each group and assign p the most frequent group
	int freq1 = 0;
	int freq2 = 0;
	
	for (int i = 0; i < k; i++)
	{
		if (arr[i].group == 0)
			freq1++;
		else if (arr[i].group == 1)
			freq2++;
	}

	return (freq1 < freq2 ? 0 : 1);
}

int main()
{
	// Variables
	int n = 17; // Number of data points
    	DataPoint arr[n]; // Array of data points

	// Assign values for each data point	
    	arr[0].x = 1;
    	arr[0].y = 12;
    	arr[0].group = 0;
 
    	arr[1].x = 2;
    	arr[1].y = 5;
    	arr[1].group = 0;
 
    	arr[2].x = 5;
    	arr[2].y = 3;
    	arr[2].group = 1;
 
    	arr[3].x = 3;
    	arr[3].y = 2;
    	arr[3].group = 1;
 
    	arr[4].x = 3;
    	arr[4].y = 6;
    	arr[4].group = 0;
 
    	arr[5].x = 1.5;
    	arr[5].y = 9;
    	arr[5].group = 1;
 
    	arr[6].x = 7;
    	arr[6].y = 2;
    	arr[6].group = 1;
 
    	arr[7].x = 6;
    	arr[7].y = 1;
    	arr[7].group = 1;
 
    	arr[8].x = 3.8;
    	arr[8].y = 3;
    	arr[8].group = 1;
 
    	arr[9].x = 3;
    	arr[9].y = 10;
    	arr[9].group = 0;
 
    	arr[10].x = 5.6;
    	arr[10].y = 4;
    	arr[10].group = 1;
 
    	arr[11].x = 4;
    	arr[11].y = 2;
    	arr[11].group = 1;
 
    	arr[12].x = 3.5;
    	arr[12].y = 8;
    	arr[12].group = 0;
 
    	arr[13].x = 2;
    	arr[13].y = 11;
    	arr[13].group = 0;
 
    	arr[14].x = 2;
    	arr[14].y = 5;
    	arr[14].group = 1;
 
    	arr[15].x = 2;
    	arr[15].y = 9;
    	arr[15].group = 0;
 
    	arr[16].x = 1;
    	arr[16].y = 7;
    	arr[16].group = 0;
 
    	//Testing Point
    	DataPoint p;
	cout << "\ninput:" << endl;
	cout << "x value for unknown point: ";
	cin >> p.x;
	cout << "y value for unknown point: ";
	cin >> p.y;
	cout << "\n";

	// Algorithm and Output
	int k = 5;
	cout << "unknown point:\n--> x = " << p.x <<"\n--> y = " << p.y << "\n--> group = " << sortDataPoint(arr,n, k, p) << "\n" << endl;

	return 0;
}
