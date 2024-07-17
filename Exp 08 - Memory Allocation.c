#include<stdio.h>

int bsize[10], psize[10], bno, pno;

void ff()
{
        int bdup[10],flag,i,j;

        for(i=0;i<bno;i++)
        {
                bdup[i]=bsize[i];
        }

        for(i=0;i<pno;i++)
        {
                flag=0;
                for(j=0;j<bno;j++)
                {
                        if(bdup[j]>=psize[i])
                        {
                                flag=1;
                                bdup[j]-=psize[i];
                                break;
                        }
                }
                if(flag!=1)
                {
                        printf("Process %d is not allocated\n",i+1);
                }
                else
                {
                        printf("Process %d (%d) allocated in block %d\n",i+1,psize[i],j+1);
                }
        }
}

void bf()
{
        int bdup[10],lowest,i,j;

        for(i=0;i<bno;i++)
        {
                bdup[i]=bsize[i];
        }

        for(i=0;i<pno;i++)
        {
                lowest=9999;
                for(j=0;j<bno;j++)
                {
                        if(bdup[j]>=psize[i])
                        {
                                if(lowest==9999)
                                {
                                        lowest=j;
                                }
                                if(bdup[j]<bdup[lowest])
                                {
                                        lowest=j;
                                }
                        }
                }

                if(lowest==9999)
                {
                        printf("Process %d is not allocated\n",i+1);
                }
                else
                {
                        printf("Process %d (%d) allocated in block %d\n",i+1,psize[i],lowest+1);
                        bdup[lowest]-=psize[i];
                }
        }
}

void wf()
{
        int bdup[10],greatest,i,j;

        for(i=0;i<bno;i++)
        {
                bdup[i]=bsize[i];
        }

        for(i=0;i<pno;i++)
        {
                greatest=-1;
                for(j=0;j<bno;j++)
                {
                        if(bdup[j]>=psize[i])
                        {
                                if(greatest==-1)
                                {
                                        greatest=j;
                                }
                                if(bdup[j]>bdup[greatest])
                                {
                                        greatest=j;
                                }
                        }
                }

                if(greatest==-1)
                {
                        printf("Process %d is not allocated\n",i+1);
                }
                else
                {
                        printf("Process %d (%d) allocated in block %d\n",i+1,psize[i],greatest+1);
                        bdup[greatest]-=psize[i];
                }
        }
}

void main()
{
        int i;

        printf("Enter number of blocks: ");
        scanf("%d",&bno);
        printf("Enter sizes of blocks:\n");
        for(i=0;i<bno;i++)
        {
                scanf("%d",&bsize[i]);
        }

        printf("Enter number of processes: ");
        scanf("%d",&pno);
        printf("Enter sizes of processes:\n");
        for(i=0;i<pno;i++)
        {
                scanf("%d",&psize[i]);
        }

        printf("\nFirst Fit\n");
        ff();
        printf("\nBest Fit\n");
        bf();
        printf("\nWorst Fit\n");
        wf();
}