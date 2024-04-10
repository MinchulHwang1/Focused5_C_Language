/*
* File : f5.cpp
* Project : Focused 5
* Progtammer : Minchul Hwang
* FirstVersion : 2022-10-05
* Description : This program is related f4.
                But this project involves function to get number and compare the numbers which one is the lowest from user
* The functions in this file are used to getNum(), modifyArraValue() and minArrayValue()
     - getNum() is the function can get the numbers from user
	 - modifyArrayValue() is the function that can save the numbers as array value from getNum() function.
	 - minArrayValue() is the function that compares the value of array which is the lowest.
*/
#include<stdio.h>
#pragma warning(disable: 4996)



/*Declare functions*/
int getNum(void);
void modifyArrayValue(int getAr[], int a = 10);
int minArrayValue(int getAr[], int a = 10);



int main() {
	int getAr[10] = { 0 };      
	int i = 10;                 
	int indexNum = 0;           //declare the index number to get index number from minArrayValue function(returning index number)

	printf("Input 10 numbers : \n");

	modifyArrayValue(getAr, i);             
	indexNum = minArrayValue(getAr, i);     //Put return value of minArrayValue into indexNum.
	
	printf("\n");
	printf("The lowest value is %d at index %d \n", getAr[indexNum], indexNum);   //Display the number which is lowest and the index number

	return 0;
}



/*
* Function : modifyArrayValue()
* Description : This function get array and number of element from main function.
                and if user inpur the number, this function save the number as value of array from 1 to 10.
* Parameters : getAr[] - the array which can save the number from user as value
			   int a - the number of element, in this function it is 10
* Return : void (As requirements)
*/
void modifyArrayValue(int getAr[], int a) {
	int i = 0;           
	int get = 0;         //get number from user - need to initialization

	for (i = 0; i < a; i++) {   //Save the number get from user as array value 1~10
		get = getNum();
		if (get == -42) {
			//printf("please input lager than 10\n");
			break;
		}
		else {
			getAr[i] = get;
		}
	}
}



/*
* Function : minArrayValue()
* Description : This function get array and number of element from main function.(Array is made in modifyArrayValue() function)
				and if user inpur the number, this function save the number as value of array from 1 to 10.
* Parameters : getAr[] - the array which can save the number from user as value
			   int a - the number of element, in this function it is 10
* Return : void (As requirements)
*/
int minArrayValue(int getAr[], int a ) {
	int i= 0;
	int min = 0;
	int indexNum = 0;
	
	for (i = 0; i < a; i++) {
		if (i == 0) {          
			//for the first time, there is no number to be compared with, so, it need to put first elements into min.
			min = getAr[i];
			indexNum = i;
		}
		else {
			//Initiate compare numbers
			if (getAr[i] <= min) {
				min = getAr[i];
				indexNum = i;
			}
			else {
				getAr[i] = min;
			}
		}
	}

	return indexNum;
}


/*
* Function : getNum()
* Description : This function can get number from user.
* Parameter : Void
* Retuen : Number which is gotten by user.
*/
int getNum(void)
{
	/* the array is 121 bytes in size; we'll see in a later lecture how we can improve this code */
	char record[121] = { 0 }; /* record stores the string */
	int number = 0;
	/* NOTE to student: brace this function consistent with your others */
	/* use fgets() to get a string from the keyboard */
	fgets(record, 121, stdin);
	/* extract the number from the string; sscanf() returns a number
	* corresponding with the number of items it found in the string */
	if (sscanf(record, "%d", &number) != 1)
	{
		/* if the user did not enter a number recognizable by
		* the system, set number to -1 */
		number = -1;
	}
	return number;
}

