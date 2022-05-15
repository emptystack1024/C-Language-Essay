#include <stdio.h>

static char daytab[][13] = 
{
	{0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
	{0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},};

int day_of_year(int year, int month, int day);/*将某年某月某日转换为某年的第几天*/
int month_day(int year, int yearday, int *pmonth, int *pday);/*将某年的第几天转换为某月某日的表示形式*/

int main(){
	int x, y;
	
	int a = day_of_year(2021, 12, 31);
    int b=month_day(2020, 365, &x, &y);

	printf("%d %d %d",a,x,y);
}

int day_of_year(int year, int month, int day){/*将某年某月某日转换为某年的第几天*/
	int i = 0;
	int leap = 0;
	
	leap = ((((year % 4) == 0) && ((year % 100) != 0)) || ((year % 400) == 0));
	for ( i = 1; (i < month) && (i < 13); i++){
		day += daytab[leap][i];
	}
	return day;
}

int month_day(int year, int yearday, int *pmonth, int *pday){/*将某年的第几天转换为某月某日的表示形式*/
	int i = 0;
	int leap = 0;
	
	leap = ((((year % 4) == 0) && ((year % 100) != 0)) || ((year % 400) == 0));
	for (i = 1; (i < 13) && (yearday > daytab[leap][i]); i++){
		yearday -= daytab[leap][i];
	}
	if (NULL != pmonth){
		*pmonth = i;
	}
	if (NULL != pday){
		*pday = yearday;
	}
	return 0;
}
