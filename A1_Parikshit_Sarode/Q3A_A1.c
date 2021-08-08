#include<stdio.h>
#include<stdlib.h>
#include<sys/wait.h>
#include<unistd.h>

struct node
{
	int num;
	struct node* next;	
}typedef node;

int main()
{	
	//Taking input from user in a linked list
	int ip,evensum,count,oddsum=0;
	node* head = NULL;
	node* temp = NULL;
	printf("Enter some numbers, press 9999 to quit\n");
	scanf("%d",&ip);
	while(ip!=9999){
		
		temp = (node*)malloc(sizeof(node));
		temp->num = ip;
		temp->next = NULL;
		if (head == NULL)
		{
			head = temp;
		}else{
			node* point = head;
			while(point->next!=NULL){
				point=point->next;
			}
			point->next = temp;
		}
		scanf("%d",&ip);
	}
	node* cur = head;
	
	//process and logic 
	
	int pid1 = fork();
	if (pid1==0)
	{
		//Child process 1 to calaclate sum of even nos
		evensum = 0;
		while(cur!=NULL){
			//printf("%d\n",cur->num);
			if (cur->num % 2 == 0)
			{
				evensum = evensum + cur->num;
			}
			cur = cur->next;
		}
		printf("Sum of even numbers id %d\n",evensum);
		exit(0);
	}
	else{
		//parent process
		wait(NULL);
		count = 0;
		while(cur!=NULL){
			//printf("%d\n",cur->num);
			count++;
			cur = cur->next;
		}
		printf("count is %d\n",count );
	}

	int pid2 = fork();
	if (pid2==0)
	{	sleep(3);
		//child 2 for odd sum;
		//oddsum = 0;
		cur = head;
		while(cur!=NULL){
			//printf("%d\n",cur->num);
			if ((cur->num % 2) != 0)
			{
				oddsum = oddsum + cur->num;
			}
			cur = cur->next;
		}
		printf("Sum of odd numbers id %d\n",oddsum);

	}
	else{
		wait(NULL);
	}

	
	return 0;
}
