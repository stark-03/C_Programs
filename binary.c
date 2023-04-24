#include<stdio.h>
#include<stdlib.h>
//#include<time.h>

int binary(int item, int a[1000], int low, int high)
{
	int mid;
	mid = (low + high) / 2;
	if(low > high)
		return 0;
	if(a[mid] == item)
		return mid + 1;
	else if(a[mid] > item)
		return binary(item, a, low, mid - 1);
	else
		return binary(item, a, mid + 1, high);
}

int linear(int item, int n, int a[1000])
{
	int i;
	for(i = 0; i < n; i++)
	{
		if(a[i] == item)
			return i + 1;
	}
	return 0;
}

void sort(int a[1000], int n)
{
	int i, j, temp;
	for(i = 0; i < n -1; i++)
	for(j = i + 1; j < n; j++)
	if(a[i] > a[j])
	{
		temp = a[i];
		a[i] = a[j];
		a[j] = temp;
	}
}

void main()
{
	int a[1000], n, pos, item, i, opt;
	//clock_t start, end;
	//double time;
	printf("Enter the array size:");
	scanf("%d",&n);
	printf("\nElements are:\n");
	for(i = 0; i < n; i++)
	{
		a[i] = (int)rand() % 1000;
		printf("%d\t",a[i]);
	}
	for(;;)
	{
		printf("\n1.Binary\n2.linear search\n3.exit");
		printf("\nEnter your option:");
		scanf("%d",&opt);
		switch(opt)
		{
			case 1 : sort(a, n);
				 printf("\nsorted list:\n");
				 for(i = 0; i < n; i++)
				 printf("%d\t",a[i]);
				 printf("enter the key element:");
				 scanf("%d",&item);
				 //start = clock();
				 pos = binary(item, a, 0, n - 1);
				 //end = clock();
				 break;
			case 2 : printf("Enter the element to be searched:\n");
				 scanf("%d",&item);
				 //start = clock();
				 pos = linear(item, n, a);
				 //end = clock();
				 break;
				 default : exit(0);
		}
	if(pos == 0)
		printf("Item not found\n");
	else
		printf("Item found at the position %d",pos);
		//time = (end- start) / CLOCKS_PER_SEC;
		//printf("\nTime taken:%f",time);
	}
}
