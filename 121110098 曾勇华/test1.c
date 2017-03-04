# include<stdio.h>
# include<string.h>
typedef struct name
{
	int name;
	//char *name=(char *)malloc(10*sizeof(char));
}Name;
void main()
{
   Name  name;
   char str[10]="±³¾°",str1[10]="±³¾°";
   int i;
   name.name=3;
   printf("%d\t",name.name);
   if(strcmp(str,str1)>0)
   printf("%s>%s\n",str,str1);
   else
	   if(strcmp(str,str1)<0)
   //scanf("%s",str);
   printf("%s>%s\n",str1,str);
	   else
   printf("equal,length=%d\n",strlen(str));

  // for(i=0;i<10;i++)
	 //  printf("%c \t",str[i]);
}