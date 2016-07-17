#include<stdio.h>
#include<stdlib.h>
void main()
{
	int k=0,output[10],d=0,t=0,ins[5],i,avail[5],allocated[10][5],need[10][5],max[10][5],pno,p[10],j,r,count=0,flag[100],noo;
	printf("\nEnter the number of resourses: ");
	scanf("%d",&r);
	printf("\nEnter the max instances of each resourses:\n");
	for(i=0;i<r;i++)
	{
		avail[i]=0;
		printf("%c= ",(i+97));
		scanf("%d",&ins[i]);
	}
	printf("enter the number of processes: ");
	scanf("%d",&pno);
	printf("\nEnter the allocation matrix:\n");
	for(i=0;i<r;i++)
		printf("%c",(i+97));
	printf("\n");
	for(i=0;i<pno;i++)
	{
		p[i]=i;
		printf("p[%d]",p[i]);
		flag[i]=0;
		for(j=0;j<r;j++)
		{
			scanf("%d",&allocated[i][j]);
			avail[j]+=allocated[i][j];
		}
	}
	printf("\nEnter the MAX matrix:\n");
	for(i=0;i<r;i++)
	{
		printf("%c",(i+97));
		avail[i]=ins[i]-avail[i];
	}
	printf("\n");
	for(i=0;i<pno;i++)
	{
		printf("p[%d]  ",i);
		for(j=0;j<r;j++)
			scanf("%d",&max[i][j]);
	}
	printf("\n");
	noo==pno;
	while(noo--)
	{
	    for(i=0;i<pno;i++)
	    {
		   if(flag[i]==0)
		   { count=0;
		    t=p[i];
		    for(j=0;j<r;j++)
		    {
			    need[t][j]=max[t][j]-allocated[t][j];
			    if(need[t][j]<=avail[j])
				    count++;
	    	}
	    	if(count==r)
	    	{
	    		output[k++]=p[i];
	    		flag[i]=1;
	    		for(j=0;j<r;j++)
	    		{
	    			avail[j]+=allocated[t][j];
	    		}
	    	}
	        }
	    }
	 }
	
	    if(k==pno)
	        printf("System is in safe condition.\n");
	    for(i=0;i<k;i++)
	    	printf("p[%d]>",output[i]);
	    if(k!=pno)
	        printf("System is in unsafe condition!!\n");
	}
