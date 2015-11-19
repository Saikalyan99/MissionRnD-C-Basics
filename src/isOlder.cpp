/*
OVERVIEW: 	Given date of births of two persons as inputs, return 1 if person one is elder,
2 if person two is elder, 0 if both are of same age.
Example: isOlder("24-07-2000", "25-07-2000") should return 1 as person one
is elder than person two.

INPUTS: 	DOBs of two persons as parameters in the format "DD-MM-YYYY".

OUTPUT: 	1 if person one is elder, 2 if person two is elder, 0 if both are of same age.

ERROR CASES: Return -1 if any DOB is invalid.

NOTES: 		Don't use any built-in C functions for comparisions. You are free to write any helper functions.
*/
int convert(int strlen1, char *dob1, int arr[]);
int check(int arr[]);
int isOlder(char *dob1, char *dob2) 
{
	int strlen1 = 0, strlen2 = 0, index1 = 0, index2 = 0, index3 = 0, arr1[3] = { 0 }, arr2[3] = { 0 }, a = 0, b = 0;
	while (dob1[strlen1] != '\0')
	{
		strlen1++;
		if (dob1[strlen1] == '-')
			index1++;
	}
	while (dob2[strlen2] != '\0')
	{
		strlen2++;
		if (dob2[strlen2] == '-')
			index2++;
		if (dob2[strlen2] == dob2[strlen1])
			index3++;
	}
	if (index3 == strlen1)
		return 0;
	else if (index1 == index2)
	{
		a = convert(strlen1, dob1, arr1);
		b = convert(strlen2, dob2, arr2);
		if (a != 0 || b != 0)
			return -1;
		a = check(arr1);
		b = check(arr2);
		if (a != 0 || b != 0)
			return -1;
		if (arr1[2] > arr2[2])
			return 2;
		else if (arr1[2] < arr2[2])
			return 1;
		else
		{
			if (arr1[1] > arr2[1])
				return 2;
			else if (arr1[1] < arr2[1])
				return 1;
			else
			{
				if (arr1[0] > arr2[0])
					return 2;
				else if (arr1[0] < arr2[0])
					return 1;
				else
					return 0;
			}
		}
	}
	else
		return -1;
}
int convert(int strlen1, char *dob1, int arr[])
{
	int i, j, flag = 0, position = 0;
	for (i = 0; i<strlen1; i++)
	{
		if (dob1[i] > 47 && dob1[i] < 58)
		{
			for (j = 0; j < 10; j++)
			{
				if (dob1[i] == (j + 48))
				{
					arr[position] = arr[position] + j;
					if (dob1[i + 1] == '-' || dob1[i + 1] == '\0')
						break;
					else
						arr[position] = arr[position] * 10;
					break;
				}
			}
		}
		else if (dob1[i] == '-')
			position++;
		else
			flag++;
	}
	if (flag > 0)
		return 1;
	return 0;
}
int check(int arr[])
{
	int leap = 0, flag = 0;
	if (arr[2] % 400 == 0 || (arr[2] % 100 != 0 && arr[2] % 4 == 0))
		leap = 1;
	if (arr[1]<13)
	{
		if (arr[1] == 1 || arr[1] == 3 || arr[1] == 5 || arr[1] == 7 || arr[1] == 8 || arr[1] == 10 || arr[1] == 12)
		{
			if (arr[0] > 1 || arr[0] < 32)
				flag = 1;
		}
		else if (arr[1] == 4 || arr[1] == 6 || arr[1] == 9 || arr[1] == 11)
		{
			if (arr[0] < 31)
				flag = 1;
		}
		else
		{
			if (leap == 1)
				if (arr[0] <= 29)
					flag = 1;
			if (leap == 0)
				if (arr[0] <= 28)
					flag = 1;
		}
	}
	if (flag == 1)
		return 0;
	else
		return 1;
}