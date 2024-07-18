#include<stdio.h>

int pno,fno,p[10];

void fifo()
{
        int i,j,found,f[10],k=0,pfault=0;

        for(i=0;i<fno;i++)
        {
                f[i]=-1;
        }

        for(i=0;i<pno;i++)
        {
                found=0;
                for(j=0;j<fno;j++)
                {
                        if(f[j]==p[i])
                        {
                                printf("no page fault\n");
                                found=1;
                                break;
                        }
                }
                if(found==0)
                {
                        f[k]=p[i];
                        k=(k+1)%fno;
                        pfault++;

                        for(j=0;j<fno;j++)
                        {
                                if(f[j]!=-1)
                                {
                                        printf("%d\t",f[j]);
                                }
                        }
                        printf("\n");
                }
        }
        printf("Number of page faults: %d\nNumber of hits: %d\n",pfault,pno-pfault);
}

void lru()
{
        int i,j,found,k=0,pfault=0,cnt=1,ind=0;

        struct frame
        {
                int content,count;
        }f[10];

        for(i=0;i<fno;i++)
        {
                f[i].content=-1;
                f[i].count=0;
        }

        for(i=0;i<pno;i++)
        {
                found=0;
                for(j=0;j<fno;j++)
                {
                        if(f[j].content==p[i])
                        {
                                found=1;
                                printf("no page fault\n");
                                f[j].count=cnt++;
                        }
                }
                if(found==0)
                {
                        if(ind<fno)
                        {
                                f[ind].content=p[i];
                                f[ind].count=cnt++;
                                ind++;
                        }
                        else
                        {
                                int min=0;
                                for(j=0;j<fno;j++)
                                {
                                        if(f[j].count<f[min].count)
                                        {
                                                min=j;
                                        }
                                }
                                f[min].content=p[i];
                                f[min].count=cnt++;
                        }
                        pfault++;

                        for(j=0;j<fno;j++)
                        {
                                if(f[j].content!=-1)
                                {
                                        printf("%d\t",f[j].content);
                                }
                        }
                        printf("\n");
                }
        }
        printf("Number of page faults: %d\nNumber of hits: %d\n",pfault,pno-pfault);
}

void lfu()
{
        int i,j,found,k=0,pfault=0,cnt=1,ind=0;

        struct frame
        {
                int content,count,freq;
        }f[10];

        for(i=0;i<fno;i++)
        {
                f[i].content=-1;
                f[i].count=0;
                f[i].freq=0;
        }

        for(i=0;i<pno;i++)
        {
                found=0;
                for(j=0;j<fno;j++)
                {
                        if(f[j].content==p[i])
                        {
                                found=1;
                                printf("no page fault\n");
                                f[j].freq++;
                                break;
                        }
                }
                if(found==0)
                {
                        if(ind<fno)
                        {
                                f[ind].content=p[i];
                                f[ind].freq=1;
                                f[i].count=cnt++;
                                ind++;
                        }
                        else
                        {
                                int min=0;
                                for(j=0;j<fno;j++)
                                {
                                        if(f[j].freq<f[min].freq || f[j].freq==f[min].freq && f[j].count<f[min].count)
                                        {
                                                min=j;
                                        }
                                }
                                f[min].content=p[i];
                                f[min].freq=1;
                                f[min].count=cnt++;
                        }
                        pfault++;

                        for(j=0;j<fno;j++)
                        {
                                if(f[j].content!=-1)
                                {
                                        printf("%d\t",f[j].content);
                                }
                        }
                        printf("\n");
                }
        }
        if(pfault==0)
        {
                printf("No page fault");
        }
        printf("Number of page faults: %d\nNumber of hits: %d\n",pfault,pno-pfault);
}

void main()
{
        int i;

        printf("Enter number of pages: ");
        scanf("%d",&pno);
        printf("Enter page sequence:\n");
        for(i=0;i<pno;i++)
        {
                scanf("%d",&p[i]);
        }
        printf("Enter number of frames: ");
        scanf("%d",&fno);

        printf("\nFIFO\n");
        fifo();
        printf("\nLRU\n");
        lru();
        printf("\nLFU\n");
        lfu();
}