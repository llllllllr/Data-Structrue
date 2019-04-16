![pta leaves list.png](https://github.com/llllllllr/im-ved/blob/master/pta%20leaves%20list.png?raw=true)

```c++
#include"stdafx.h"
#include<iostream>
using namespace std;

#define maxTree 10
#define null -1
typedef  int Tree;

struct TreeNode//树的结点，，每一个结点都有左右子数
{
	Tree left;
	Tree right;
};
TreeNode tree[10];
Tree BuildTree()
{
	int N;
	Tree root;
	char cl, cr;
	int check[10];//用来寻找根节点
	cin >> N;
	for (int i = 0; i<N; i++) check[i] = 0;
	for (int i = 0; i<N; i++)
	{
		cin >> cl >> cr;
		if (cl != '-')
		{
			tree[i].left = cl - '0';//将char变为数字放到数组中去
			check[tree[i].left] = 1;//左子树有根节点，标志为1
		}
		else {
			tree[i].left = null;
		}
		if (cr != '-')
		{
			tree[i].right = cr - '0';
			check[tree[i].right] = 1;
		}
		else {
			tree[i].right = null;
		}
	}
	for (int i = 0; i<N; i++)
	{
		if (check[i] == 0)//该结点无父母结点
		{
			root = i;
			break;
		}
	}
	return root;
}

void FindLeaves(Tree root)//树的层次遍历的应用
{
	int leaves = 0;
	Tree queue[10];
	int head = 0, rear = 0;
	queue[rear++] = root;//进队列
	while (rear - head)
	{
		Tree front = queue[head++];
		if ((tree[front].left == null )&& (tree[front].right == null))//如果是叶子结点
		{
			if (leaves)
				cout << " ";
			cout << front;
			leaves++;
		}
		else
		{
			if (tree[front].left != null)//如果不是叶子结点
				queue[rear++] = tree[front].left;
			if (tree[front].right!=null)
				queue[rear++] = tree[front].right;
		}
	}
}

int main() {
	FindLeaves(BuildTree());
	return 0;
}
```

