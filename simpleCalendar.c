#include<stdio.h>

int days_in_month[]={0,31,28,31,30,31,30,31,31,30,31,30,31};

char *months[]=
{
	" ",
	"\n\nJanuary",
	"\n\nFebruary",
	"\n\nMarch",
	"\n\nApril",
	"\n\nMay",
	"\n\nJune",
	"\n\nJuly",
	"\n\nAugust",
	"\n\nSeptember",
	"\n\nOctober",
	"\n\nNovember",
	"\n\nDecember"
};

int determinedaycode(int year)
{
	int daycode,d1, d2, d3;
	d1 = (year - 1)/ 4;
	d2 = (year - 1)/ 100;
	d3 = (year - 1)/ 400;
	daycode = (year + d1 - d2 + d3) %7;
	return daycode;
}

void determineleapyear(int year)
{
	if(year% 4 == 0 && year%100 != 0 || year%400 == 0)
	{
		days_in_month[2] = 29;
	}
	else
	{
		days_in_month[2] = 28;
	}
}

void calendar(int year, int daycode)
{
	for (int month = 1; month <= 12; month++ )
	{
		printf("%s", months[month]);
		printf("\n\nSun  Mon  Tue  Wed  Thu  Fri  Sat\n" );

		for (int space = 0; space < 1 + daycode * 5; space++ )
		{
			printf(" ");
		}

		for (int date = 1; date <= days_in_month[month]; date++ )
		{
			printf("%2d", date );

			if ( ( date + daycode ) % 7 > 0 )
				printf("   " );
			else
				printf("\n " );
		}

			daycode = ( daycode + days_in_month[month] ) % 7;
	}
}

void main()
{
	int year,daycode;
	printf("Please enter a year (example: 2000) : ");
	scanf("%d", &year);
	daycode = determinedaycode(year);
	determineleapyear(year);
	calendar(year, daycode);
}
