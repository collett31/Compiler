#include "stdafx.h"
#include<stack>
#include<iostream>
using namespace std;
#include<queue>

int pre(char p)
{
	char x = '*';
	char y = '/';
	char z = '+';
	char m = '-';
	//char n = '(';
	if (p == x || p == y)
	{
		return 2;
	}

	if (p == z || p == m)
	{
		return 1;
	}

}
void fun(istream& cin)
{
	stack <char> p;
	char par = '(';
	int num;
	char chars;
	queue<double> numbers;
	queue < char > symbols;
	char var;
	do
	{
		if (cin.peek() == par || cin.peek() == ')')
		{
			cin >> chars;

			//p.push(cin.peek());

			p.push(chars);
			//symbols.push(chars);
			//	numbers.push(-1);
			if (p.top() == ')')
			{
				p.pop();
				cout << p.top() << " ";
				symbols.push(p.top());
				p.pop();
			}
		}
		else if (isdigit(cin.peek()))
		{
			cin >> num;
			numbers.push(num);
			symbols.push('n');

			cout << num << " ";
		}

		else if (cin.peek() == '/' || cin.peek() == '*' || cin.peek() == '+' || cin.peek() == '-')
		{
			//cin >> x;
			//p.push(x);

			while (!p.empty() && p.top() != '(' && pre(p.top()) >= pre(cin.peek()))
			{
				if (p.top() == ')')
					p.pop();

				cout << p.top() << " ";
				symbols.push(p.top());
				numbers.push(-1);
				p.pop();
			}
			cin >> chars;
			//symbols.push(chars);
			//numbers.push(-1);
			p.push(chars);
		}
		else  //a ) is found
		{
			/*chars = cin.peek();
			cout << chars << " may be wrong" << endl << endl;
			system("pause");*/
			if (cin.peek() == ')')
			{
				cin >> chars;
				cin.ignore();
			}
			if (p.top() == par)
				p.pop();
			while (p.top() != par)// && !p.empty())
			{

				cout << p.top() << " ";
				var = p.top();
				symbols.push(var);
				numbers.push(-1);
				p.pop();
			}

			while (!p.empty())
			{
				if (p.top() == '(')
				{

					p.pop();
				}
				else
					cout << "An error as occured : Unbalanced parenthesis";
				cout << p.top() << " ";
				symbols.push(p.top());
				numbers.push(-1);
				p.pop();
			}


		}

	} while (cin &&cin.peek() != '\n');


	while (!p.empty())
	{
		if (p.top() == '(')
		{
			p.pop(); continue;
		}
		cout << p.top() << " ";
		symbols.push(p.top());
		numbers.push(-1);
		p.pop();
	}

	double n1, n2;
	stack<double> nums;
	double n;
	char c;

	//Started conversion here
	while (!symbols.empty() && !numbers.empty())
	{

		if (symbols.front() == 'n')
		{
			if (numbers.front() != -1)
				symbols.pop();
			if (numbers.front() != -1)
			{
				n = numbers.front();
				numbers.pop();
				nums.push(n);
			}
			else
				numbers.pop();
		}


		else
		{
			if (symbols.front() != 'n')
			{
				c = symbols.front();
				symbols.pop();
				n1 = nums.top();
				nums.pop();
				n2 = nums.top();
				nums.pop();
			}

			if (c == '*')
			{
				n1 = n2 * n1;
				nums.push(n1);
				continue;
			}

			if (c == '/')
			{
				n1 = n2 / +n1;
				nums.push(n1); continue;
			}

			if (c == '+')
			{
				n1 = n2 + n1;
				nums.push(n1);
				continue;
			}

			if (c = '-')
			{
				n1 = n2 - n1;
				nums.push(n1);
			}
		}

	}


	cout << endl << endl << "The result is " << nums.top() << endl;
	nums.pop();
	
	//cin >> num;
	
}

int main()
{
	char cont;
	cont = 'y';
	int x;

	while (cont == 'y')
	{
		cout << "Please enter a value" << endl;
		fun(cin);
		cout << endl << endl << "Would you like to continue? y for YES and n for NO" << endl;
		cin >> cont;
		//cout << "Please enter a value" << endl;
		//fun(cin);
		cout << cin.peek()<<" ";
	//	cin >> x;

		//cin.ignore(numeric_limits<streamsize>::max(), '\n');
		//cin.clear();
		//cin.read();
		cout << cin.peek();
	}
	system("pause");
	return 0;
}
