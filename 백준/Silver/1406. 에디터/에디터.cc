#include <iostream>
#include <list>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	string str;
	cin >> str;

	list<char> l;
	for (int i = 0; i < str.length(); i++)
		l.push_back(str[i]);

	list<char>::iterator it = l.end();

	int M;
	cin >> M;

	for (int i = 0; i < M; i++)
	{
		char order;

		cin >> order;
		if (order == 'P')
		{
			char c;
			cin >> c;
			l.insert(it, c);
		}
		else if (order == 'L')
		{
			if (it != l.begin())
				it--;
		}
		else if (order == 'D')
		{
			if (it != l.end())
				it++;
		}
		else if (order == 'B')
		{
			if (it != l.begin())
			{
				it--;
				it = l.erase(it);
			}
		}
	}
	for (auto i : l)
		cout << i;
}