#include<stdio.h>
#include<math.h>
#define INT_SIZE sizeof(int)*8
int bin[INT_SIZE];
int power(int b,int e)
{
	int res=1,i=1;
	while(i<=e)
	{
		res=res*b;
		i++;
	}
	return res;
}
int expo(int a)
{
	int n;
	float x;
	x=log(a)/log(2);
	n=x;
	return n;
}
void binary(int num,int len)
{
	int i,index;
	index=INT_SIZE - 1;
	while(index>=0)
    	{
        	bin[index]=num&1;
        	index--;
        	num>>=1;
    	}
	printf("\nThe binary representation of %d is: ",num);
	for(i=(31-len)+ 1;i<INT_SIZE;i++)
    	{
        	printf("%d",bin[i]);
    	}
    	printf("\n");
}
void Direct(int tot,int lno,int blsize)
{
	int tag,line,word,n,i,j,total,a[100];
	total=tot;
	line=expo(lno);
	word=expo(blsize);
	tag=tot-(line+word);
	printf("\nDirect Mapping:");
	printf("\nTag address: %d",tag);
	printf("\nLine address: %d",line);
	printf("\nWord offset: %d",word);
	printf("\n\nEnter the address of main memory to map to a Direct mapped cache:\n");
	scanf("%d",&n);
	binary(n,total);
	printf("\nTag of %d: ",n);
	for(i=(31 - total)+ 1;i<(((31- total)+ 1)+(tag));i++)
    	{
        	printf("%d",bin[i]);
    	}
    	printf("\nLine of %d: ",n);
	for(i=INT_SIZE-word;i>=INT_SIZE - ((word+line) - 1);i--)
	{
        	printf("%d",bin[i]);
    	}
	printf("\nWord of %d: ",n);
	for(i=INT_SIZE;i>=(INT_SIZE-(word- 1));i--)
	{
        	printf("%d",bin[i]);
    	}	
}
void Associative(int total,int blosize)
{
	int tag,word,i,n;
	word=expo(blosize);
	tag=total-word;
	printf("\nAssociative Mapping:");
	printf("\nTag address: %d",tag);
	printf("\nWord offset: %d",word);
	printf("\n\nEnter the address of main memory to map to a Associative mapped cache:\n");
	scanf("%d",&n);
	binary(n,total);
	printf("\nTag of %d: ",n);
	for(i=(31 - total)+ 1;i<(((31- total)+ 1)+(tag));i++)
    	{
        	printf("%d",bin[i]);
    	}
    	printf("\nWord of %d: ",n);
	for(i=INT_SIZE;i>=(INT_SIZE-(word- 1));i--)
    	{
        	printf("%d",bin[i]);
    	}	
}
void SetAssociative(int k,int totall,int lineno,int blocksize)
{
	int tag,set,word,i,n,total;
	total=totall;
	word=expo(blocksize);
	set=expo(lineno/k);
	tag=totall-(set+word);
	printf("\nSet Associative Mapping:");
	printf("\nTag address: %d",tag);
	printf("\nSet address: %d",set);
	printf("\nWord offset: %d",word);
	printf("\n\nEnter the address of main memory to map to a Set Associative mapped cache:\n");
	scanf("%d",&n);
	binary(n,total);
	printf("\nTag of %d: ",n);
	for(i=(31 - total)+ 1;i<(((31- total)+ 1)+(tag));i++)
    	{
        	printf("%d",bin[i]);
    	}
    	printf("\nSet of %d: ",n);
	for(i=INT_SIZE-word;i>=INT_SIZE - ((word+set) - 1);i--)
    	{
        	printf("%d",bin[i]);
    	}
    	printf("\nWord of %d: ",n);
	for(i=INT_SIZE;i>=(INT_SIZE-(word- 1));i--)
    	{
        	printf("%d",bin[i]);
    	}	
}
void main()
{
	int csize,msize,ws,bs,cs,ms,lines_no,tag,line,word,tot_addr,choice,k;
	printf("Enter the cache size in KB:\n");
	scanf("%d",&csize);
	cs=csize*power(2,10);
	printf("Cache size in bytes: %d",cs);
	printf("\nEnter the physical memory size in MB:\n");
	scanf("%d",&msize);
	ms=msize*power(2,20);
	tot_addr=expo(ms);
	printf("Physical memory size in bytes: %d",ms);
	printf("\nEnter the word size in B:\n");
	scanf("%d",&ws);
	printf("Enter the block size in B:\n");
	scanf("%d",&bs);
	lines_no=cs/bs;
	printf("\nEnter your choice:\n");
	printf("1. Direct Mapping\t2. Associative Mapping\t3. Set Associative Mapping\n");
	scanf("%d",&choice);
	switch(choice)
	{
		case 1: Direct(tot_addr,lines_no,bs);
			break;
		case 2:	Associative(tot_addr,bs);
			break;
		case 3:	printf("\nEnter the k-way Set Associative\nie. Enter the number of lines in one set:\n");
			scanf("%d",&k);
			SetAssociative(k,tot_addr,lines_no,bs);
			break;
		default: printf("\nYou have entered a wrong choice!");
			 break;
	}
}
