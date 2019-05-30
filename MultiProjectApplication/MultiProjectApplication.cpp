// MultiProjectApplication.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "windows.h"
#include "iostream"
#include "ctime"

using namespace std;

int main()
{
	HMODULE hLib = LoadLibrary(L"MDLL.dll");
	void(*p_qsort) (double*, int);
	(FARPROC &)p_qsort = GetProcAddress(hLib, "quicksort");

	srand(time(0));
	double arr[100000];

	for (int i = 0; i< 100000; i++)
		arr[i] = rand() % 10000;

	int start = clock();
	p_qsort(arr, sizeof(arr) / 8);
	int ends = clock();
	cout << ends - start << endl;



    return 0;
}

