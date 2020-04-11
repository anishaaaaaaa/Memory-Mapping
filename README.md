## Memory Mapping of Cache in Computer Organization and Architecture

This is my lab implementation of Memory mapping in the following ways -
- Direct 
- Associative
- Set Associative

### Theory :

Cache Memory is a special very high-speed memory. It is used to speed up and synchronizing with high-speed CPU. Cache memory is costlier than main memory or disk memory but economical than CPU registers. Cache memory is an extremely fast memory type that acts as a buffer between RAM and the CPU. It holds frequently requested data and instructions so that they are immediately available to the CPU when needed.

Cache memory is used to reduce the average time to access data from the Main memory. The cache is a smaller and faster memory which stores copies of the data from frequently used main memory locations.

## Cache Mapping:
There are three different types of mapping used for the purpose of cache memory which are as follows: Direct mapping, Associative mapping, and Set-Associative mapping. These are explained below.

## Direct Mapping –
The simplest technique, known as direct mapping, maps each block of main memory into only one possible cache line. or
In Direct mapping, assigne each memory block to a specific line in the cache. If a line is previously taken up by a memory block when a new block needs to be loaded, the old block is trashed. An address space is split into two parts index field and a tag field. The cache is used to store the tag field whereas the rest is stored in the main memory. Direct mapping's performance is directly proportional to the Hit ratio.

i = j modulo m
where
i=cache line number
j= main memory block number
m=number of lines in the cache

For purposes of cache access, each main memory address can be viewed as consisting of three fields. The least significant w bits identify a unique word or byte within a block of main memory. In most contemporary machines, the address is at the byte level. The remaining s bits specify one of the 2s blocks of main memory. The cache logic interprets these s bits as a tag of s-r bits (most significant portion) and a line field of r bits. This latter field identifies one of the m=2r lines of the cache.

![Image](https://media.geeksforgeeks.org/wp-content/uploads/20190305171558/1232.png)
![Image](https://media.geeksforgeeks.org/wp-content/uploads/cache1.png)

## Associative Mapping –
In this type of mapping, the associative memory is used to store content and addresses of the memory word. Any block can go into any line of the cache. This means that the word id bits are used to identify which word in the block is needed, but the tag becomes all of the remaining bits. This enables the placement of any word at any place in the cache memory. It is considered to be the fastest and the most flexible mapping form.

![Image](https://media.geeksforgeeks.org/wp-content/uploads/cache2.png)

## Set-associative Mapping –
This form of mapping is an enhanced form of direct mapping where the drawbacks of direct mapping are removed. Set associative addresses the problem of possible thrashing in the direct mapping method. It does this by saying that instead of having exactly one line that a block can map to in the cache, we will group a few lines together creating a set. Then a block in memory can map to any one of the lines of a specific set..Set-associative mapping allows that each word that is present in the cache can have two or more words in the main memory for the same index address. Set associative cache mapping combines the best of direct and associative cache mapping techniques.
In this case, the cache consists of a number of sets, each of which consists of a number of lines. The relationships are

m = v * k
i= j mod v

where
i=cache set number
j=main memory block number
v=number of sets
m=number of lines in the cache number of sets 
k=number of lines in each set 

![Image](https://media.geeksforgeeks.org/wp-content/uploads/20190305171821/setassociative.png)
![Image](https://media.geeksforgeeks.org/wp-content/uploads/cache4.png)

# The below code is a C language implementation of Memory Mapping.

```markdown
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


##### Thank You
