#include "Riddle.h"
void enigme_que_ans(char name[],char que[],char ans[])
{
    FILE *f=NULL;
    f=fopen(name,"r");
    if (f!=NULL)
    {
        int a;
        srand(time(NULL));
        a=(rand()%3)+1;
       int  i=0;
        while (i<=a)
            {
            fgets(que,99,f);
             i++;
            }
    while (i<=a+4)
            {
            fgets(ans,99,f);
             i++;
            }
        //printf("%d",a);
        fclose(f);

    }
    else printf("can't open the file \n");
}
