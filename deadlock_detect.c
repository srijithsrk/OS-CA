#include<conio.h> 
#include<stdio.h> 
main() 
{ 
 int n;   
 int A;       
 int i,j,k,cnt,cntt; 
 int avail[10],p[10]; 
 int need[10][10],alloc[10][10],max[10][10]; 
 printf("\nEnter number of process :"); 
 scanf("%d",&n); 
 printf("\n Enter  resources available : "); 
 scanf("%d",&A); 
 printf("\nEnter instances for resources :\n"); 
  for(i=0;i<A;i++) 
 {  printf("A%d ",i+1); 
  scanf("%d",&avail[i]); 
  } 
 printf("\n Enter allocation matrix  \n"); 
 for(i=0;i<n;i++) 
 { 
 printf("p%d",i+1); p[i]=0; 
 for(j=0;j<A;j++) 
 { 
  scanf("%d",&alloc[i][j]); 
 } 
} 
  printf("\n Enter MAX matrix  \n");
   for(i=0;i<n;i++) 
 { 
 printf("p%d",i+1); 
 for(j=0;j<A;j++) 
 { 
  scanf("%d",&max[i][j]); 
 } 
 } 
 
 for(i=0;i<n;i++) 
 { 
 printf("\np%d\t",i+1) ; 
 for(j=0;j<A;j++) 
 { 
  need[i][j]=max[i][j]-alloc[i][j]; 
   printf("\t%d",need[i][j]); 
  } 
 } 
 k=0;     cntt=0; 
 printf("\n\n"); 
 while(k<15) 
 { 
 for(i=0;i<n;i++) 
 {  cnt=0; 
 for(j=0;j<A;j++) 
 { 
  if(p[i]==1) break; 
  if(need[i][j]<=avail[j]) 
  {
    cnt++; 
  } 
  if(cnt==A) 
  { 
  for(j=0;j<A;j++) 
  { 
  avail[j]+=alloc[i][j]; 
  } 
  printf("p%d\t",i+1);  p[i]=1;     cntt++; 
  } 
 } 
 } k++; 
 } 
 if(cntt<n-1) 
 { 
 printf("\n deadlock ");
  } 
      getch();
  }-           /////////////////////////////////////////////////////
#include <stdio.h>
 
int current[5][5], maximum_claim[5][5], available[5];
int allocation[5] = {0, 0, 0, 0, 0};
int maxres[5], running[5], safe = 0;
int counter = 0, i, j, exec, resources, processes, k = 1;
 
int main()
{
    printf("\nEnter number of processes: ");
        scanf("%d", &processes);
 
        for (i = 0; i < processes; i++) 
    {
            running[i] = 1;
            counter++;
        }
 
        printf("\nEnter number of resources: ");
        scanf("%d", &resources);
 
        printf("\nEnter Claim Vector:");
        for (i = 0; i < resources; i++) 
    { 
            scanf("%d", &maxres[i]);
        }
 
       printf("\nEnter Allocated Resource Table:\n");
        for (i = 0; i < processes; i++) 
    {
            for(j = 0; j < resources; j++) 
        {
              scanf("%d", &current[i][j]);
            }
        }
 
        printf("\nEnter Maximum Claim Table:\n");
        for (i = 0; i < processes; i++) 
    {
            for(j = 0; j < resources; j++) 
        {
                    scanf("%d", &maximum_claim[i][j]);
            }
        }
 
    printf("\nThe Claim Vector is: ");
        for (i = 0; i < resources; i++) 
    {
            printf("\t%d", maxres[i]);
    }
 
        printf("\nThe Allocated Resource Table:\n");
        for (i = 0; i < processes; i++) 
    {
            for (j = 0; j < resources; j++) 
        {
                    printf("\t%d", current[i][j]);
            }
        printf("\n");
        }
 
        printf("\nThe Maximum Claim Table:\n");
        for (i = 0; i < processes; i++) 
    {
            for (j = 0; j < resources; j++) 
        {
                printf("\t%d", maximum_claim[i][j]);
            }
            printf("\n");
        }
 
        for (i = 0; i < processes; i++) 
    {
            for (j = 0; j < resources; j++) 
        {
                    allocation[j] += current[i][j];
            }
        }
 
        printf("\nAllocated resources:");
        for (i = 0; i < resources; i++) 
    {
            printf("\t%d", allocation[i]);
        }
 
        for (i = 0; i < resources; i++) 
    {
            available[i] = maxres[i] - allocation[i];
    }
 
        printf("\nAvailable resources:");
        for (i = 0; i < resources; i++) 
    {
            printf("\t%d", available[i]);
        }
        printf("\n");
 
        while (counter != 0) 
    {
            safe = 0;
            for (i = 0; i < processes; i++) 
        {
                    if (running[i]) 
            {
                        exec = 1;
                        for (j = 0; j < resources; j++) 
                {
                                if (maximum_claim[i][j] - current[i][j] > available[j]) 
                    {
                                    exec = 0;
                                    break;
                                }
                        }
                        if (exec) 
                {
                                printf("\nProcess%d is executing\n", i + 1);
                                running[i] = 0;
                                counter--;
                                safe = 1;
 
                                for (j = 0; j < resources; j++) 
                    {
                                    available[j] += current[i][j];
                                }
                            break;
                        }
                    }
            }
            if (!safe) 
        {
                    printf("\nThe processes are in unsafe state.\n");
                    break;
            } 
        else 
        {
                    printf("\nThe process is in safe state");
                    printf("\nAvailable vector:");
 
                    for (i = 0; i < resources; i++) 
            {
                        printf("\t%d", available[i]);
                    }
 
                printf("\n");
            }
        }
        return 0;
}
