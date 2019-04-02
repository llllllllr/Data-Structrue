#include<iostream>
#include <stack>
using namespace std;

 typedef struct Box
{
	int row, col;   //当前方块的行号和列号
	int direction; // 当前方块走的方向
	Box(int r, int c,int dir):row(r),col(c),direction(dir){}
	Box(){}
 };

bool mgPath(int beginr,int beginc, int endr,int endc,int mg[10][10])
{
	stack<Box> path;
	Box res[100];
	int row, col, tempr, tempc, tempdi,k=0;
	bool find;
	Box e(beginr, beginc, -1);
	mg[beginr][beginc] = -1;
	path.push(e);
	while (!path.empty())
	{
		Box top = path.top();
		tempdi = top.direction;
		row = top.row, col = top.col;
		if (top.col == endc && top.row == endr)
		{

			while (!path.empty())
			{
				res[k++] = top;
				top = path.top();
				path.pop();
				
			}
			for (int i = k - 1; i > 0; i--)
				cout << "(" << res[i].row << "," << res[i].col << ") " << endl;
			return true;
		}
		else 
		{
			find = false;
			while (!find && tempdi<3)
			{
				
				tempdi++;
				switch (tempdi)
				{
				case 0: tempr = row, tempc = col - 1; break;  //上
				case 1: tempr = row + 1, tempc = col;  break;   //右
				case 2: tempr = row, tempc = col + 1;   break;  //下
				case 3: tempr = row - 1, tempc = col ;    break; //左
				}
				if (mg[tempr][tempc] ==0)   find = true;
			}
			if (find)
			{
				mg[tempr][tempc] = -1;
				path.top().direction = tempdi;
				Box e(tempr, tempc, -1);
				path.push(e);
			}
			else
			{
				path.pop();
				mg[e.row][e.col] = 0;
			}
		}
	}
}
int main()
{
	int mg[10][10] = {
	{ 1,1,1,1,1,1,1,1,1,1 },{ 1,0,0,1,0,0,0,1,0,1 },
	{ 1,0,0,1,0,0,0,1,0,1 },{ 1,0,0,0,0,1,1,0,0,1 },
	{ 1,0,1,1,1,0,0,0,0,1 },{ 1,0,0,0,1,0,0,0,0,1 },
	{ 1,0,1,0,0,0,1,0,0,1 },{ 1,0,1,1,1,0,1,1,0,1 },
	{ 1,1,0,0,0,0,0,0,0,1 },{ 1,1,1,1,1,1,1,1,1,1 }
	};
	mgPath(1, 1, 8, 8, mg);
	return 0;
}

