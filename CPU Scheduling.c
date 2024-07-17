#include<stdio.h>
#include<stdlib.h>

struct process
{
        int pid;
        int at;
        int bt;
        int ct;
        int tat;
        int wt;
        int prio;
}p[10],temp;

int n;

void fcfs()
{
        int i,j,time=0;
        float avg_wt=0, avg_tat=0;

        for(i=0;i<n-1;i++)
        {
                for(j=0;j<n-i-1;j++)
                {
                        if(p[j].at>p[j+1].at){
                                temp=p[j];
                                p[j]=p[j+1];
                                p[j+1]=temp;
                        }
                }
        }

        for(i=0;i<n;i++)
        {
                if (time < p[i].at)
                {
                        time = p[i].at;
                }

                p[i].ct=time+p[i].bt;
                time=p[i].ct;
                p[i].tat=p[i].ct-p[i].at;
                p[i].wt=p[i].tat-p[i].bt;

                avg_tat+=p[i].tat;
                avg_wt+=p[i].wt;
        }

        for(i=0;i<n;i++)
        {
                printf("%d  | %d  |  %d  |  %d  |  %d  |  %d\n\n",p[i].pid,p[i].at,p[i].bt,p[i].ct,p[i].tat,p[i].wt);
        }

        printf("Total TurnAround Time: %f\nAverage TurnAround Time: %.2f\nTotal Waiting Time: %f\nAverage Waiting Time: %.2f\n",avg_tat,avg_tat/n,avg_wt,avg_wt/n);
}

void sjf()
{
        int i,j,time=0;

        float avg_wt=0, avg_tat=0;

        for(i=0;i<n-1;i++)
        {
                for(j=0;j<n-i-1;j++)
                {
                        if(p[j].at > p[j+1].at || (p[j].at==p[j+1].at && p[j].bt>p[j+1].bt))
                        {
                                temp=p[j];
                                p[j]=p[j+1];
                                p[j+1]=temp;
                        }
                }
        }

        for(i=0;i<n;i++)
        {
                if (time < p[i].at)
                {
                        time = p[i].at;
                }

                for(j=i+1;j<n;j++)
                {
                        if(time>=p[j].at && p[j].bt<p[i].bt)
                        {
                                temp=p[i];
                                p[i]=p[j];
                                p[j]=temp;
                        }
                }

                p[i].ct=time+p[i].bt;
                time=p[i].ct;
                p[i].tat=p[i].ct-p[i].at;
                p[i].wt=p[i].tat-p[i].bt;

                avg_tat+=p[i].tat;
                avg_wt+=p[i].wt;
        }

        for(i=0;i<n;i++)
        {
                printf("%d  | %d  |  %d  |  %d  |  %d  |  %d\n\n",p[i].pid,p[i].at,p[i].bt,p[i].ct,p[i].tat,p[i].wt);
        }

        printf("Total TurnAround Time: %f\nAverage TurnAround Time: %.2f\nTotal Waiting Time: %f\nAverage Waiting Time: %.2f\n",avg_tat,avg_tat/n,avg_wt,avg_wt/n);
}

void priority()
{
        int i,j,time=0;

        float avg_wt=0, avg_tat=0;

        printf("Enter priority in order:\n");
        for(i = 0; i < n; i++)
        {
                scanf("%d",&p[i].prio);
        }

        for(i=0;i<n-1;i++)
        {
                for(j=0;j<n-i-1;j++)
                {
                        if(p[j].at > p[j+1].at || (p[j].at==p[j+1].at && p[j].prio>p[j+1].prio))
                        {
                                temp=p[j];
                                p[j]=p[j+1];
                                p[j+1]=temp;
                        }
                }
        }

        for(i=0;i<n;i++)
        {
                if (time < p[i].at)
                {
                        time = p[i].at;
                }

                for(j=i+1;j<n;j++)
                {
                        if(time>=p[j].at && p[j].prio<p[i].prio)
                        {
                                temp=p[i];
                                p[i]=p[j];
                                p[j]=temp;
                        }
                }

                p[i].ct=time+p[i].bt;
                time=p[i].ct;
                p[i].tat=p[i].ct-p[i].at;
                p[i].wt=p[i].tat-p[i].bt;

                avg_tat+=p[i].tat;
                avg_wt+=p[i].wt;
        }

        for(i=0;i<n;i++)
        {
                printf("%d  | %d  |  %d  |  %d  |  %d  |  %d  |  %d\n\n",p[i].pid,p[i].at,p[i].bt,p[i].prio,p[i].ct,p[i].tat,p[i].wt);
        }

        printf("Total TurnAround Time: %f\nAverage TurnAround Time: %.2f\nTotal Waiting Time: %f\nAverage Waiting Time: %.2f\n",avg_tat,avg_tat/n,avg_wt,avg_wt/n);
}

void rdrb()
{
	int i, time = 0, tq, remaining = n;
	int rem_bt[10];
	float avg_wt = 0, avg_tat = 0;

	printf("Enter time quantum: ");
	scanf("%d", &tq);

	for (i = 0; i < n; i++)
	{
        	rem_bt[i] = p[i].bt;
    	}

	while (remaining > 0) {
		for (i = 0; i < n; i++) {
            		if (rem_bt[i] > 0) {
                		if (rem_bt[i] > tq)
				{
                    			time += tq;
                    			rem_bt[i] -= tq;
                		}
				else
				{
                    			time += rem_bt[i];
                    			p[i].ct = time;
                    			rem_bt[i] = 0;
                    			remaining--;
                		}
            		}
        	}
    	}

	for (i = 0; i < n; i++)
	{
        	p[i].tat = p[i].ct - p[i].at;
        	p[i].wt = p[i].tat - p[i].bt;

        	avg_tat += p[i].tat;
        	avg_wt += p[i].wt;
    	}

        for(i=0;i<n;i++)
        {
                printf("%d  | %d  |  %d  |  %d  |  %d  |  %d\n\n",p[i].pid,p[i].at,p[i].bt,p[i].ct,p[i].tat,p[i].wt);
        }

        printf("Total TurnAround Time: %f\nAverage TurnAround Time: %.2f\nTotal Waiting Time: %f\nAverage Waiting Time: %.2f\n",avg_tat,avg_tat/n,avg_wt,avg_wt/n);
}

void main()
{
    int i;
    printf("Enter total number of processes: ");
    scanf("%d", &n);

    printf("Enter process id, arrival time and burst time in order:\n");
    for(i = 0; i < n; i++)
    {
        scanf("%d %d %d", &p[i].pid, &p[i].at, &p[i].bt);
    }

    printf("FCFS SCHEDULING\n");
    fcfs();
    printf("SJF SCHEDULING\n");
    sjf();
    printf("PRIORITY SCHEDULING\n");
    priority();
    printf("ROUNDR ROBIN SCHEDULING\n");
    rdrb();
}
