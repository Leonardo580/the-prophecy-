#include "Riddle.h"
void enigme_que_ans(char name[],char *que,char *ans)
{
    FILE *f=NULL;
    f=fopen(name,"r");
    if (f)
    {
        int a;
        srand(time(NULL));
        a=rand()%3;
        for (int i=0;i<a && fscanf(f,"%s,%s",que,ans);i++);
        fclose(f);

    }
    else printf("can't open the file \n");
}
