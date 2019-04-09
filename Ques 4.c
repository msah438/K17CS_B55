#include<stdio.h>
#include<conio.h>
struct Process
{
	int process_id;
	int burst_time;
};

int compare(void *p, void *q)  
{ 
    int a = ((struct Process *)p)->burst_time; 
    int b = ((struct Process *)q)->burst_time;  
    return (a - b); 
} 

void processWaitTime( struct Process arr[] , int n , int wt[])
{
	int i;
	wt[0] = 0; // initializing the 'process 1' waiting time as 0. 
	for(i = 1 ; i< n ; i++)
	{
		
		wt[i] = arr[i-1].burst_time + wt[i-1];
	
	}
	
	
}
void turnAroundTime(struct Process arr[] , int n , int wt[] , int tat[])
{

	int i;
	for(i = 0 ; i < n ; i++)
	{

		tat[i] = wt[i] + arr[i].burst_time; 

	}
}
void computePriority(int priority[] , int n , int wt[] , struct Process arr[])
{
	
	int i;
	for(i = 0; i< n ; i++)
	{

		priority[i] = 1 + (wt[i]/arr[i].burst_time);

	}

	
}

void averageTime(struct Process arr[] , int n)
{
	int wt[n] , tat[n], priority[n],i ;
	int totaltime = 0 , turntime = 0;
	
	processWaitTime(arr , n , wt); //function call 
	
	turnAroundTime(arr , n , wt , tat) ; //function call
	
	computePriority(priority, n , wt , arr);	
	
	printf(" Process\t Burst Time\t Waiting Time\t Turn Around Time\t Priority\n");
	
	for(i = 0 ; i< n ; i++)
	{
	printf("\n");
	printf("   %d \t\t   %d \t\t   %d \t\t   %d \t\t    \t   %d\n" , arr[i].process_id,arr[i].burst_time,wt[i] , tat[i],priority[i]);}
	
	for(i = 0; i<n ;i++)
	{
		totaltime += wt[i];
	}
	for(i = 0; i<n ;i++)
	{
		turntime += tat[i];
	}
	printf("\n");
	printf("   Average Waiting Time : ");
	int avg1 = totaltime/n;
	printf("%d\n",avg1);
	printf("\n");
	printf("   Average Turn Around Time : ");
	int avg2 = turntime/n;
	printf("%d", avg2);
}



int main()
{
	int i,k;
	printf("Enter the number of processes: ");
	scanf("%d" , &k);
	struct Process arr[k];
	for(i=0 ; i<k;i++)
	{
		printf("\nProcess %d\n" , i+1);
		printf("Enter The Process ID : ");
		scanf("%d" , &arr[i].process_id);
		printf("Enter The Burst Time : ");
		scanf("%d",&arr[i].burst_time);
		
	}
	
	int n = sizeof(arr) / 	sizeof(arr[0]);
	qsort((void*)arr, n, sizeof(arr[0]), compare);
	averageTime(arr , n) ; // function call
	return 0;	
}
