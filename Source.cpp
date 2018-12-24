#include <iostream>

void QuickSort(int array[], int left, int right);
void ShowArray(int array[], int array_size);

int main()
{
	int array[9] = { 5,4,7,6,8,3,1,2,9 };
	int left = 0, right = 8;

	std::cout << "ソート前" << std::endl;
	ShowArray(array, 9);

	QuickSort(array, left, right);

	std::cout << "ソート後" << std::endl;
	ShowArray(array, 9);

	return 0;
}

void QuickSort(int array[], int left, int right)
{
	int i = left, k = right;
	int tmp;
	int pivot = array[(left + right) / 2];

	while (i <= k)
	{
		while (array[i] < pivot)
			i++;
		while (array[k] > pivot)
			k--;
		if (i <= k)
		{
			tmp = array[i];
			array[i] = array[k];
			array[k] = tmp;
			i++;
			k--;
		}
	}

	if (left < k)
		QuickSort(array, left, k);

	if (i < right)
		QuickSort(array, i, right);
}

void ShowArray(int array[], int array_size)
{
	for (int i = 0; i < array_size; i++)
		std::cout << array[i] << " " ;
	std::cout << std::endl;
}
