#include <iostream>
#include <stack>

int main()
{
	using namespace std;
	int n;
	cin >> n;
	stack<int> p;
	stack<int> help;
	while (n > 0)
	{
		int num;
		cin >> num;
		p.push(num);
		n--;
	}

	while (!p.empty())
	{
		if (help.empty())
		{
			help.push(p.top());
			p.pop();
		}
		int temp = p.top();
		p.pop();
		while (help.top()<temp)
		{
			p.push(help.top());
			help.pop();
			help.push(temp);
		}
		if (help.top() > temp)
			help.push(temp);
	}

	while (!help.empty())
	{
		p.push(help.top());
		help.pop();
	}

	while(!p.empty())
	{
		cout << p.top()<<" ";
		p.pop();
	}

	return 0;
}