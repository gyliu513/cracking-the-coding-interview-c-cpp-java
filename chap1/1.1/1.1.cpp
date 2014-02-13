#include <iostream>
using namespace std;

int iArr[] = {0, 1, 2, 2, 3, 4, 5, 5};

int findMax(int arr[], int n)
{
	int max = 0;
	for(int i=0; i<n; i++)
	{
		if(max < arr[i])
		{
			max = arr[i];
		}
	}
	return max;
}

void main()
{
	const int iSize = sizeof(iArr)/sizeof(*iArr);
	int iMax = findMax(iArr, iSize);

	int* iTempArr = new int[iMax+1];
	for(int i=0; i<iMax+1; i++)
	{
		iTempArr[i] = -1;
	}
	for(int i=0; i<iSize; i++)
	{
		int iTemp = iArr[i]%(iMax + 1);
		if(iTempArr[iTemp] == -1)
		{
			iTempArr[iTemp] = iArr[i];
		}
		else
		{
			cout << iArr[i] << " is the first duplicate number!" << endl;
			//break;
		}
	}
	delete []iTempArr;
	system("pause");
}
