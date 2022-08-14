#include<stdio.h>
#include <graphics.h>
 int main()
{
    int bt[20],p[20],wt[20],tat[20],i,j,n,total=0,pos,temp;
    float arr[100];
    int z=0;
    float avg_wt,avg_tat;
    for(int q=0; q<2; q++){
        q != 0 ? printf("\n\nEnter number of process: ") : printf("\nEnter number of process: ");
        scanf("%d",&n);
        printf("\nEnter Burst Time: \n");
        for(i=0;i<n;i++)
        {
            printf("p%d: ",i+1);
            scanf("%d",&bt[i]);
            p[i]=i+1;         
        }
       //sorting of burst times
        for(i=0;i<n;i++)
        {
            pos=i;
            for(j=i+1;j<n;j++)
            {
                if(bt[j]<bt[pos])
                    pos=j;
            }
            temp=bt[i];
            bt[i]=bt[pos];
            bt[pos]=temp;
            temp=p[i];
            p[i]=p[pos];
            p[pos]=temp;
        }
        wt[0]=0;            
        for(i=1;i<n;i++)
        {
            wt[i]=0;
            for(j=0;j<i;j++)
                wt[i]+=bt[j];
            total+=wt[i];
        }
        avg_wt=(float)total/n;
        arr[z] = avg_wt;
        z++;
        total=0;
        printf("\nProcess\t    Burst Time    \tWaiting Time\tTurnaround Time");
        for(i=0;i<n;i++)
        {
            tat[i]=bt[i]+wt[i];   
            total+=tat[i];
            printf("\np%d\t\t  %d\t\t    %d\t\t\t%d",p[i],bt[i],wt[i],tat[i]);
        }
        avg_tat=(float)total/n;    
        printf("\n\nAverage Waiting Time = %f",avg_wt);
        printf("\nAverage Turnaround Time = %f \n",avg_tat);
        total=0;
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
}