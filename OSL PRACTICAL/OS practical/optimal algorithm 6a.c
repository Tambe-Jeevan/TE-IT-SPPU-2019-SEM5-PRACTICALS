#include <stdio.h>
int main()
{int fs, count, page_array[10], i, j, frame[10], flag, pf=0, top=-1;
printf("Enter the frame size:\n");
scanf("%d",&fs);
printf("Enter number of pages:\n");
scanf("%d",&count);
for(i=0;i<count;i++)
{printf("\nEnter page[%d]:",i+1);
scanf("%d",&page_array[i]);}
for(i=0;i<fs;i++)
frame[i]=0;
printf("\n page \t frame");
for(j=0;j<count;j++){
flag=0;
for(i=0;i<fs;i++){
if(frame[i]==page_array[j]){
flag=1;
break;}}if(flag==0){
if(top==fs-1){
top=-1;}
pf++;
top++;
frame[top]=page_array[j];}
printf("\n%d",page_array[j]);
for(i=0;i<fs;i++)
printf("\t %d",frame[i]);}
return(0);
}
