#include <stdio.h>
#include<stdlib.h>
#define filen "attendance.txt"
void mrkatndc();
void fatndc();
int main()
{
    int choice;
    while(1)
    {
    printf("-----student attendance-----\n");
    printf("1.mark attandance\n"); 
    printf("2.view attendance\n");
    printf("3.exit\n");
    scanf("%d",&choice);

    switch(choice)
    {
        case 1:mrkatndc();break;
        case 2:fatndc();break;
        case 3:exit(0);break;
        default : printf("enter the valid choice");break;
    }
    }
    return 0;
}
void mrkatndc()
{
    FILE *file=fopen(filen,"a");
    if(file==NULL)
    {
        printf("Error:cant open the file");
        return;
    }
    char id[10],name[10],atndc[10];
    printf("enter the ID");
    scanf("%s",&id);
    printf("enter the name:");
    scanf("%s",&name);
    printf("enter absent/present");
    scanf("%s",&atndc);
    fprintf(file,"%s,%s,%s\n",id,name,atndc);
    fclose(file);
}
void fatndc()
{
    FILE *file=fopen(filen,"r");
    if(file==NULL)
    {
        printf("Error:cant open the file");
        return;
    }
    char id[10],name[10],atndc[10];
    while(fscanf(file,"%s,%s,%s\n",&id,&name,&atndc)!=EOF)
    {
        printf("%s,%s,%s \n",id,name,atndc);
        printf("\n");
    }
    fclose(file);
}