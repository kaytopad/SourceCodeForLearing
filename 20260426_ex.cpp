#include <iostream>
using  namespace std;

int main()
{
	int num1;
	int num2;
	int num3;

	int max;

	cin >> num1;
	cin >> num2;
	cin >> num3;
	max = num1;

	if (max > num2 && max > num3)
	{
		cout << "Max = " << max << endl;
	}

	else
	{
		if (num2 > num3) 
		{
			max = num2;
		}
		else
		{
			max = num3;
		}

	}

	cout << "Max = " << max << endl;

	return 0;
}