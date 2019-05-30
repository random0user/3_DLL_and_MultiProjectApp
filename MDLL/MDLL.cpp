#include "windows.h"

extern "C" _declspec(dllexport)
void quicksort(double* array, long int quantity)
{
	//quantity--;
	double temp, p;
	int i = 0, j = quantity - 1;
	p = array[(quantity - 1) / 2];
	do
	{
		while (array[i] < p)
			i++;
		while (array[j]>p)
			j--;
		if (i <= j)
		{
			temp = array[i];
			array[i] = array[j];
			array[j] = temp;
			i++;
			j--;
		}
	} while (i <= j);
	if (j>0) quicksort(array, j + 1);
	if (quantity>i) quicksort(array + i, quantity - i);
}
