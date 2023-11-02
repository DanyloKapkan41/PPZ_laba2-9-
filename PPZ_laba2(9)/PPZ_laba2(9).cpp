#include <iostream>
using namespace std;
void filling(int*& nums, int i, int n, bool mode)
{
	if (mode) {
		if (i < n) {
			nums[i] = rand() % 10000+1;
			i++;
			filling(nums, i, n, mode);
		}
	}
	else {
		if (i < n) {
			do { cin >> nums[i]; } while (nums[i] < 1 || nums[i]>100000);
			cout << " writed...\n";
			i++;
			filling(nums, i, n, mode);
		}
	}
}
void extract(int* nums, int i, int n)
{
	if (i < n) {
		cout << nums[i] << ' ';
		i++;
		extract(nums, i, n);
	}
}
void changing(int*& numb, int n)
{
	int max;
	for (int i = 0; i < n-1; i++)
	{
		max = numb[i+1];
		for (int j = i+1; j < n; j++)
		{
			if (max < numb[j])
				max = numb[j];
		}
		numb[i] = max;
	}
	numb[n - 1] = -1;
}
int main()
{
	int n, modeint;
	bool mode;
	do {
		cout << "Enter array size(1 - 10000): ";
		cin >> n;
	} while (n < 1 || n > 10000);
	int* nums = new int[n];
	srand(time(NULL));
	do {
		cout << "Choose mode (1 - autoentering, 0 - enterig by yourself): ";
		cin >> modeint;
	} while (modeint < 0 || modeint > 1);
	mode = modeint;
	filling(nums, 0, n, mode);
	extract(nums, 0, n);
	changing(nums, n);
	cout << endl;
	extract(nums, 0, n);
}