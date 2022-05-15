/*本题要求编写程序，输出n行由大写字母A开始构成的三角形字符阵列。

输入格式：
输入在一行中给出一个正整数n（1≤n<7）。

输出格式：
输出n行由大写字母A开始构成的三角形字符阵列。格式见输出样例，其中每个字母后面都有一个空格。

输入样例：
4
输出样例：
A B C D 
E F G 
H I 
J 
*/
#include<stdio.h>
int main(void)
{
	int n;
	char ch = 'A';

	scanf("%d", &n);

	for (int i = n; i >=1 ; i--)	// 输出n行
	{
		for (int j = i; j > 0; j--, ch++)	// 每行输出i个，之后换行
		{
			printf("%c ", ch);
		}

		printf("\n");
	}

	return 0;
}
