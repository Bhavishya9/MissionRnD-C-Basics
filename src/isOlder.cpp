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

int isOlder(char *dob1, char *dob2) {
	int arr1[3] = { 0 }, arr2[3] = { 0 }, index1 = 0;
	int flag = 0,temp=0;
	for (int index = 0; dob1[index] != '\0'; index++)
	{
		if (dob1[index] == '-')
		{
			index1++;
			continue;
		}
		else
		{
			arr1[index1] = arr1[index1] * 10 + (dob1[index] - '0');
		}
	}
	int daysInMonths[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	int i=0;
	int monthNo = arr1[1];
	if (arr1[1] == 2) //if the month is feburary
	{
		if (arr1[2] % 400 == 0 || (arr1[2] % 4 == 0 && arr1[2] % 100 != 0))//leap year condition
			daysInMonths[1] = 29;
		else
			daysInMonths[1] = 28;
	}
	if (arr1[0]>daysInMonths[monthNo - 1] || arr1[0]<1 || monthNo>12 || monthNo<1 || arr1[2]<1)//condition for date to be invalid
		flag=-1;
	else
		flag=1;
	if (flag == -1)
	{
		return -1;
	}
	else
	{
		for (int index = 0; dob2[index] != '\0'; index++)
		{
			if (dob2[index] == '-')
			{
				i++;
				continue;
			}
			else
			{
				arr2[i] = arr2[i] * 10 + (dob2[index] - '0');
			}
		}
		monthNo = arr2[1];
		if (arr2[1] == 2) //if the month is feburary
		{
			if (arr2[2] % 400 == 0 || (arr2[2] % 4 == 0 && arr2[2] % 100 != 0))//leap year condition
				daysInMonths[1] = 29;
			else
				daysInMonths[1] = 28;
		}
		if (arr2[0]>daysInMonths[monthNo - 1] || arr2[0]<1 || monthNo>12 || monthNo<1 || arr2[2]<1)//condition for date to be invalid
			temp = -1;
		else
			temp = 1;
		if (temp == -1)
		{
			return -1;
		}
		else
		{
			if (arr1[2] > arr2[2])
			{
				return 2;
			}
			else if (arr1[2] == arr2[2])
			{
				if (arr1[1] > arr2[1])
					return 2;
				else if (arr1[1] == arr2[1])
				{
					if (arr1[0] > arr2[0])
						return 2;
					else if (arr1[0] == arr2[0])
						return 0;
					else
						return 1;
				}
				else
					return 1;
			}
			else
				return 1;
		}
	}
}
