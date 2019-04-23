#include "list.h"

int main()
{
	setlocale(LC_ALL, "RUS");
	list<int> all;
	int n;
	do
	{
		cout << "Введите количество элементов:\n";
		cin >> n;
	} while (n < 1);
	cout << "Введите 2n элементов:\n";
	for (int i = 0; i < 2 * n; i++)
	{
		int x;
		cin >> x;
		all.add(x);
	}
	int sum = 0;
	for (int i = 0; i < n; i++)
	{
		sum += all.at(n - i - 1)*all.at(n + i);
	}
	cout << sum << endl;
	system("pause");
	return 0;
}