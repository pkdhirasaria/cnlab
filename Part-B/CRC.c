#include<stdio.h>
#include<string.h>
#include<bits/stdc++.h>
int main()
{
	int r,m,j,i,t,k;
	char msg[30];
	char g[]="10001000000100001",dup[50];
	printf("Enter the binary data\n");
 	scanf("%s",msg);
  	r=strlen(g);
 	t=m=strlen(msg);
 	strcpy(dup,msg);
	for(i=0;i<(r-1);i++,m++)
  	 	dup[m]='0'; 				//To append 0's
	dup[m]='\0';
	printf("The msg before adding checksum:\n");
	printf("%s\n",dup);
							/*division*/
	for(i=0;i<t;i++)
  	if(dup[i]=='1')
  	{
    		for(j=0;j<r;j++)
      		{
        		if(dup[i+j]==g[j])
          		dup[i+j]='0';
       			else
          		dup[i+j]='1';
      		}
        }

	dup[i+j]='\0';
	printf("The checksum calculated:\n");
	for(i=t;dup[i]!='\0';i++)
  		printf("%c",dup[i]);
	for(k=t;dup[k]!='\0';k++)
  		msg[k]=dup[k];
	msg[k]='\0';
	printf("\nThe code word is:%s\n",msg);

//receiving side
	printf(" enter the transmitted code word \n");
scanf("%s",msg);

printf("Received msg:%s\n",msg);
						 //division
	for(i=0;i<t;i++)
  	if(msg[i]=='1')
  	{
    		for(j=0;j<r;j++)
    		{
      			if(msg[i+j]==g[j])
        			msg[i+j]='0';
      			else
        			msg[i+j]='1';
    		}
  	}
	msg[i+j]='\0';
	printf("\n The checksum is:");
	for(i=t;msg[i]!='\0';i++)
  		printf("%c",msg[i]);
	for(i=0;msg[i]!='\0';i++)
  		if(msg[i]!='0')
  		{
    			printf("\n Error in the msg\n");
    			exit(0);
  		}
	printf("\nNo error in the msg\n");
}
