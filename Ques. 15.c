#include <stdio.h>
int main() 
{
	// Declaring arrival time and burst time
      int at[10], bt[10]; 
	  int temp[10];
	  
      int i, smallest, count = 0, time, limit;
      double wait_time = 0, turnaround_time = 0, end;
      float average_waiting_time, average_turnaround_time;
      
	  printf("\nEnter the Total Number of Processes:\t");
      scanf("%d", &limit); 
      
	  printf("\nEnter Arrival Time & Burst Time For The %d Processes\n", limit);
      for(i = 0; i < limit; i++)
            
			 {
            
			printf("\nEnter Arrival Time:\t");
            scanf("%d", &at[i]);
            printf("Enter Burst Time:\t");
            scanf("%d", &bt[i]); 
            temp[i] = bt[i];
            
			 }  
      
      bt[9] = 9999; 
	   
      for(time = 0; count != limit; time++)
      {
            smallest = 9;
            for(i = 0; i < limit; i++)
            
            {
                  if(at[i] <= time && bt[i] < bt[smallest] && bt[i] > 0)
                  
                  {
                  	
                        smallest = i;
                        
                  }
            }
            
            bt[smallest]--;
            if(bt[smallest] == 0)
            
			{
                  count++;
                  end = time + 1;
                  wait_time = wait_time + end - at[smallest] - temp[smallest];
                  turnaround_time = turnaround_time + end - at[smallest];
            }
      }
      
      average_waiting_time = wait_time / limit; 
      average_turnaround_time = turnaround_time / limit;
      
	  printf("\n\nAverage Waiting Time:\t%lf\n", average_waiting_time);
      printf("Average Turnaround Time:\t%lf\n", average_turnaround_time);
      return 0;
    }
