#include <stdio.h>
#include <graphics.h>

int main() 
{
      int arrival_time[10], burst_time[10], temp[10];
      int i, smallest, count = 0, time, limit;
      double wait_time = 0, turnaround_time = 0, end;
      float average_waiting_time, average_turnaround_time;
      float arr[100];
      int z =0;
    


      for(int x =0;x<2;x++){
      printf("\nEnter the Total Number of Processes:\t");
      scanf("%d", &limit); 
      printf("\nEnter Details of %d Processesn", limit);
      for(i = 0; i < limit; i++)
      {
            printf("\nEnter Arrival Time:\t");            
            scanf("%d", &arrival_time[i]);
            printf("Enter Burst Time:\t");
            scanf("%d", &burst_time[i]); 
            temp[i] = burst_time[i];
      }
      burst_time[9] = 9999;  
      for(time = 0; count != limit; time++)
      {
            smallest = 9;
            for(i = 0; i < limit; i++)
            {
                  if(arrival_time[i] <= time && burst_time[i] < burst_time[smallest] && burst_time[i] > 0)
                  {
                        smallest = i;
                  }
            }
            burst_time[smallest]--;
            if(burst_time[smallest] == 0)
            {
                  count++;
                  end = time + 1;
                  wait_time = wait_time + end - arrival_time[smallest] - temp[smallest];
                  turnaround_time = turnaround_time + end - arrival_time[smallest];
            }
      }
      average_waiting_time = wait_time / limit; 
      arr[z]= average_waiting_time;
      z++;
      average_turnaround_time = turnaround_time / limit;
      printf("\n\nAverage Waiting Time:\t%lf\n", average_waiting_time);
      printf("Average Turnaround Time:\t%lf\n", average_turnaround_time);
      count =0;
      wait_time=0;
      turnaround_time=0;
      }
      for(int i=0;i<z;i++){
          printf("%f ",arr[i]);
      }
          int gd = DETECT, gm;
   initgraph(&gd, &gm, "X:\\TC\\BGI");
 
   settextstyle(BOLD_FONT,HORIZ_DIR,2);
   outtextxy(275,0,"BAR GRAPH");
 
   setlinestyle(SOLID_LINE,0,2);
   /* Draw X and Y Axis */
   line(90,410,90,50);
   line(90,410,590,410);
   line(85,60,90,50);
   line(95,60,90,50);
   line(585,405,590,410);
   line(585,415,590,410);
 
   outtextxy(65,60,"Y");
   outtextxy(570,420,"X");
   outtextxy(70,415,"O");
   /* Draw bars on screen */
   setfillstyle(XHATCH_FILL, RED);
   bar(150,arr[0],200,410);
   bar(225,arr[1],275,410);
   bar(300,arr[2],350,410);
   bar(375,arr[3],425,410);
   bar(450,arr[4],500,410);
   int a=0;
   for(int i=0;i<z;i++){
       bar(150+a,arr[i],200+a;410);
       a+=75;
   }
 
   getch();
   closegraph();   
      return 0;
}