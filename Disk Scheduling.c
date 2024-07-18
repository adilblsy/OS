#include<stdio.h>
#include<stdlib.h>

int n,values[10],initial,range[2],position=0;

void fcfs()
{
        int i,seakt=0,current=initial;

        for(i=0;i<n;i++)
        {
                seakt+=abs(current-values[i]);
                current=values[i];
        }
        printf("Seak Time: %d",seakt);
}

void scan()
{
        int i,j,seakt=0,temp;

        for(i=0;i<n-1;i++)
        {
                for(j=0;j<n-i-1;j++)
                {
                        if(values[j]>values[j+1])
                        {
                                temp=values[j];
                                values[j]=values[j+1];
                                values[j+1]=temp;
                        }
                }
        }

        for(i=0;i<n;i++)
        {
                if(initial<values[i])
                {
                        position=i;
                        break;
                }
        }
        seakt+=abs(initial-range[1]);
        seakt+=abs(values[0]-range[1]);
        printf("Seak Time: %d",seakt);
}

void cscan()
{
        int seakt=0;

        seakt+=abs(initial-range[1]);
        seakt+=abs(range[0]-range[1]);
        seakt+=abs(range[0]-values[position-1]);
        printf("Seak Time: %d",seakt);
}

void look()
{
        int seakt=0;

        seakt+=abs(initial-values[n-1]);
        seakt+=abs(values[0]-values[n-1]);
        printf("Seak Time: %d",seakt);
}

void clook()
{
        int seakt=0;

        seakt+=abs(initial-values[n-1]);
        seakt+=abs(values[0]-values[n-1]);
        seakt+=abs(values[0]-values[position-1]);
        printf("Seak Time: %d\n",seakt);
}

void main()
{
        int i;
        printf("Enter number of cylinders: ");
        scanf("%d",&n);
        printf("Enter the values of cylinders:\n");
        for(i=0;i<n;i++)
        {
                scanf("%d",&values[i]);
        }
        printf("Enter value of initial position: ");
        scanf("%d",&initial);
        printf("Enter range:\n");
        for(i=0;i<2;i++)
        {
                scanf("%d",&range[i]);
        }

        printf("\nFCFS DISK SCHEDULING\n");
        fcfs();
        printf("\nSCAN DISK SCHEDULING\n");
        scan();
        printf("\nC-SCAN DISK SCHEDULING\n");
        cscan();
        printf("\nLOOK DISK SCHEDULING\n");
        look();
        printf("\nC-LOOK DISK SCHEDULING\n");
        clook();
}