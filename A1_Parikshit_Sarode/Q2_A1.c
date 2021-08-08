#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>

int arr1[10], arr2[10];

//thread function to compare selected elems of array1 to array2

void *threadfun(void *ptr){
	int k = 0;
	int n = (int *) ptr;
	for (int i = (0+n); i < (5+n); i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if (arr1[i]==arr2[j] && i > 5)
			{
				//res[k++] = arr1[i];
				printf("Common element computed by thread 1 is - %d\n",arr1[i]);
			}
			if (arr1[i]==arr2[j] && i < 6){
				printf("Common element computed by thread 2 is - %d\n",arr1[i]);
			}
		}
	}
	
}
int main()
{	
	//Taking input from user in 2 arrays
	int j = 0; 
	pthread_t thread1, thread2;
	printf("Enter 10 numbers for array 1\n");
	for (int i = 0; i < 9; i++)
	{
		scanf("%d",&arr1[i]);
	}
	printf("Enter 10 numbers for array 2\n");
	for (int i = 0; i < 9; i++)
	{
		scanf("%d",&arr2[i]);
	}

	//creating threads
	pthread_create(&thread1,NULL,(void*)&threadfun,0);	//start of array is 0
	//Thread1 finds common elems of half of array1 (arr[0] to arr[4])

	pthread_create(&thread2,NULL,(void*)&threadfun,5);	//mid of array is 5
	//Thread2 finds common elems of other half of arrys (arr[5] to arr[9])

	pthread_join(thread1,NULL);
	pthread_join(thread2,NULL);

	return 0;
}