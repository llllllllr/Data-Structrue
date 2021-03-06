// 后缀表达式.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<stack>
#include<iostream>
using namespace std;

void show(char exp[])
{
	for (int i = 0; exp[i] != '#'; i++)
	{
		cout << exp[i] << " " << endl;
	}
}
void postFix(char exp[],char post[])
{

	int i = 0,k=0;
	char e;
	stack<char> stk;
	stk.push('#');
	while (exp[i] != '#')
	{
		switch (exp[i])
		{
		case'(':
			stk.push(exp[i++]); break;
		case')':
				while (!stk.empty()&&stk.top() != '(')
				{
					post[k++] = stk.top();
					stk.pop();
				}
			stk.pop();
			i++;
			break;
		case'*':
		case'/':
			while (!stk.empty())
			{
				if (stk.top() == '*' || stk.top() == '/')
				{
					post[k++] = stk.top();
					stk.pop();
				}
				else
					break;
			}
			stk.push(exp[i++]);
			break;
		case'+':
		case'-':
			if (stk.top() == '(')
			{
				stk.push(exp[i++]); break;
			}
			else
			{
				while (!stk.empty())
				{
					if (stk.top() == '+' || stk.top() == '-')
					{
						post[k++] = stk.top();
						stk.pop();
					}
					else
						break;
				}
					stk.push(exp[i++]);
					break;
				}
			
		default:
			if (exp[i] >= '0' || exp[i] <= '9')
				post[k++] = exp[i++];
			break;
		}
	
	}
	while (!stk.empty())
	{
		post[k++] = stk.top();
		stk.pop();
	}

 }
int main() 
{

	char exp[100];
	cin >> exp;
	char post[100];
	int n = 0;
	postFix(exp, post); 
	for (int i = 0; post[i]!='#'; i++)
		cout <<post[i] << " ";
	cout << endl;
    return 0;
}

//(8+9)*10#