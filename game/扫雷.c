/*实现思路：
2.1程序实现思路 ??
??首先，我们要思考一下怎样才能实现的和计算机里的扫雷游戏一样呢？进入计算机里的扫雷游戏，首先映入眼帘的是9×9的棋盘上所有的格子都被掩盖了。然后随机去翻开一些格子，你肯定能发现会出现几种情况：

1.当翻开的是“地雷”时，你会被炸死游戏结束。
2.当翻开的格子周围一圈当中存在“地雷”时，翻开的格子下面会显示周围一圈格子内存在“地雷”的个数。
3.当翻开的格子周围没有“地雷”时，会一下子展开一大片区域。

??然后不断地翻开格子，直到把所有的非“地雷”的格子全部翻开后，游戏提示：扫雷成功！那我们该怎么实现这里双层结构的棋盘呢？你会发现双层结构的第一层是用来覆盖住第二层上显
示的内容，一个想法就油然而生了：我们是不是只要创建两个二维数组，其中一个隐藏在暗处用来存放这些地雷啊、数字的信息，用户是看不见的；另一个则是专门向用户展示的，是摆在明面
上的棋盘。（这期会实现：可以自己标注地雷位置的操作，还有炸金花式展开的功能）

??游戏菜单：选择是否开始玩儿游戏，1：开始游戏，0：退出游戏。
??游戏流程：创建两个格子棋盘（其中一个是隐与幕后存放地雷信息用的，另一个是向用户展示的）→ 初始化两个棋盘 → 随机放置地雷 → 实现打印棋盘 → 开始扫雷（用户输入要查找的
位置的坐标 → 判断是否有雷 → 有则游戏结束，若没有则显示其周围一圈中地雷的个数或者炸金花式展开一片）→ 直至扫完所有非雷区 → 游戏结束。
*/ 


#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define ROW 9
#define COL 9
#define ROWS ROW + 2
#define COLS COL + 2
#define COUNT 10

void init_board(char board[ROWS][COLS], int rows, int cols, char set);
void set_mine(char mine[ROWS][COLS], int row, int col);
void display_board(char board[ROWS][COLS], int row, int col);
void find_mind(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col);

/*相信看到这肯定有同学问：“不是说实现的是9×9的扫雷吗，为什么这里是用11×11的二维数组来存放哒？？？”这就得夸夸那些牛逼的大佬想出来的方法了。
现在假设我用9×9的二维数组来存放信息，当排查某个非雷的坐标时，我们知道这时是需要将该坐标周围一圈坐标逐个排查一遍的。但当你去排查最边界的那一圈
坐标时，你会发现你必须得以特殊的排查法来处理这些坐标，不然你就会越界访问。就如下图所示：

??所以要在排查的时候不越界访问你就必须给这最边缘一圈的坐标设计出专门的排查规则，这是一种解决的方法，但该方法的实现太过于麻烦了。所以一些大佬就
思考：能不能从另一个角度以更加简便的方法来解决这个问题呢？其中有些人就发现，似乎只要把9×9的棋盘扩张成11×11的棋盘，然后只拿该棋盘中间的9×9的
格子用作和以前一样的操作，问题不就迎刃而解了。这是为什么呢？因为我操作时只会去排查中间那9行9列的格子，且就算我去排查最边上的一圈坐标也不会出现
越界访问的情况，如下图所示。你看仅仅只需要把数组的大小改一改就能解决困扰你很久的问题，完全没有必要在那限制这限制那的。所以有些时候不能硬想啊，
一定要学会换一个角度来思考问题的解决之法！！！
*/

void menu()
{
	printf("*****************************************\n");
	printf("*********  1.play      0.exit   *********\n");
	printf("*****************************************\n");
}

void game()
{
	//存放地雷的棋盘
	char mine[ROWS][COLS] = { 0 };
	//展示给用户看的棋盘
	char show[ROWS][COLS] = { 0 };
	//初始化棋盘
	init_board(mine, ROWS, COLS, '0');
	init_board(show, ROWS, COLS, '*');
	//放置地雷
	set_mine(mine, ROW, COL);
	system("cls");//清空屏幕
	//打印棋盘
	//display_board(mine, ROW, COL);
	display_board(show, ROW, COL);
	//开始扫雷
	find_mind(mine, show, ROW, COL);
}

int main()
{
	//设置随机数的起点
	srand((unsigned int)time(NULL));
	int input = 0;
	do
	{
		menu();//菜单
		printf("请选择：");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("退出游戏\n");
			break;
		default:
			printf("输入错误，请重新输入\n");
			break;
		}
	} while (input);
	return 0;
}
/*3.1 棋盘初始化函数??
?? 该函数做到了可以任意对棋盘进行初始化，想初始化什么就传参传进来就行了。*/

//初始化棋盘
void init_board(char board[ROWS][COLS], int rows, int cols, char set)
{
	int i = 0;
	for (i = 0; i < rows; i++)
	{
		int j = 0;
		for (j = 0; j < cols; j++)
		{
			board[i][j] = set;
		}
	}
}
/*3.2 设置地雷函数??
??该函数是通过rand（）随机数函数来设置地雷的，如果我之前有一期是专门讲解了如何去创建随机数，如果这里感觉不是很明确，建议先了解一下随机数再来看下去。链接：如何创建随机数。*/

//设置地雷
void set_mine(char mine[ROWS][COLS], int row, int col)
{
	int count = COUNT;
	while (count)
	{
		int x = rand() % 9 + 1;
		int y = rand() % 9 + 1;
		if (mine[x][y] == '0')
		{
			mine[x][y] = '1';
			count--;
		}
	}
}
/*3.3 打印棋盘函数??
??该函数可以实时的打印出你想要的几行几列的棋盘，只需更改头文件中的常量ROW和COL就行。*/

//打印棋盘
void display_board(char board[ROWS][COLS], int row, int col)
{
	int i = 0;
	printf("---------------扫雷游戏----------------\n");
	//打印列号
	for (i = 0; i <= row; i++)
	{
		printf(" %d  ", i);
	}
	printf("\n");
	printf("\n");
	for (i = 1; i <= row; i++)
	{
		int j = 0;
		//打印行号
		printf(" %d  ", i);
		//打印棋子行
		for (j = 1; j <= col; j++)
		{
			printf(" %c ", board[i][j]);
			if (j <= col - 1)
			{
				printf("|");
			}
		}
		printf("\n");
		//打印分隔行
		if (i <= row - 1)
		{
			printf("    ");
			for (j = 1; j <= col; j++)
			{
				printf("---");
				if (j <= col - 1)
				{
					printf("|");
				}
			}
			printf("\n");
		}
	}
	printf("---------------扫雷游戏----------------\n");
}

//计算周围一圈范围内存在地雷的个数
int get_mine_count(char mine[ROWS][COLS], int x, int y)
{
	//把3×3方格内所有的字符（‘1’或‘0’）加起来，然后再统一减去9个字符‘0’，得到的结果就是地雷的个数
	int i = 0;
	int sum = 0;
	for (i = x - 1; i <= x + 1; i++)
	{
		int j = 0;
		for (j = y - 1; j <= y + 1; j++)
		{
			sum += mine[i][j];
		}
	}
	return (sum - 9 * '0');
}

//把所有mine中地雷全部显示到show上
void show_all_mine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col)
{
	int i = 0;
	for (i = 1; i <= row; i++)
	{
		int j = 0;
		for (j = 1; j <= col; j++)
		{
			if (mine[i][j] == '1')
			{
				show[i][j] = '@';//地雷用字符‘@’在用户界面表示
			}
		}
	}
}

//炸金花式展开函数
void explode_spread(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col, int x, int y)
{
	//限制非法坐标的展开
	if (x >= 1 && x <= row && y >= 1 && y <= col)
	{
		//计算该位置附近四周地雷的个数
		int count = get_mine_count(mine, x, y);
		//若四周没有一个地雷，则需要向该位置的四周展开，直到展开到某个位置附近存在地雷为止
		if (count == 0)
		{
			//把附近没有地雷的位置变成字符 “空格”
			show[x][y] = ' ';
			int i = 0;
			//向四周共8个位置递归调用
			for (i = x - 1; i <= x + 1; i++)
			{
				int j = 0;
				for (j = y - 1; j <= y + 1; j++)
				{
					//限制对点位置的重复展开调用，使得每一个位置只能向四周展开一次
					if (show[i][j] == '*')
					{
						explode_spread(mine, show, row, col, i, j);
					}
				}
			}
		}
		//若四周存在地雷则应该在这个位置上标注上地雷的个数
		else
		{
			show[x][y] = count + '0';
		}
	}
}

//标记地雷位置（方便排查游戏中的地雷）
void sign_mine(char show[ROWS][COLS], int row, int col)
{
	int x = 0;
	int y = 0;
	while (1)
	{
		printf("请输入要标记的坐标：");
		scanf("%d%d", &x, &y);
		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			if (show[x][y] == '*')
			{
				show[x][y] = '!';
				break;
			}
			else
			{
				printf("该位置不能被标记，请重新输入：\n");
			}
		}
		else
		{
			printf("输入坐标非法，请重新输入:\n");
		}
	}
	system("cls");
	display_board(show, row, col);
}

//开始扫雷
void find_mind(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col)
{
	int x = 0;
	int y = 0;
	int win = 0;//记录排查出不是地雷位置的个数
	char ch = 0;
	while (win < row * col - COUNT)
	{
		printf("请输入要排查的位置下标：");
		scanf("%d%d", &x, &y);
		if (x >= 1 && x <= row && y >= 1 && y <= col)//判断输入下标是否有效
		{
			if (mine[x][y] == '1')//排查到了地雷
			{
				break;
			}
			//此时没有排查到地雷
			else
			{
				//炸金花式展开
				explode_spread(mine, show, row, col, x, y);
				system("cls");
				//打印棋盘
				display_board(show, row, col);
				printf("需要标注地雷就输入：Y，不需要标注地雷则输入：N\n");
				//清空一下缓冲区
				while ((ch = getchar()) != '\n');
				scanf("%c", &ch);
				switch (ch)
				{
				case 'Y':
					//标记雷的位置
					sign_mine(show, row, col);
					break;
				default:
					break;
				}
			}
		}
		else
		{
			printf("输入下标非法，请重新输入：\n");
		}
	}
	//把所有mine中地雷全部显示到show上
	show_all_mine(mine, show, row, col);
	system("cls");
	//打印棋盘
	display_board(show, row, col);
	//判断是否排查成功
	if (win >= row * col - COUNT)
	{
		printf("恭喜你排查出所有的地雷！！！\n");
	}
	else
	{
		printf("扫雷失败，你被炸死了！！！\n");
	}
}

