#include "Riddle.h"
int main ()
{
    char ch[]="enigme.txt",*que,*ans;
    que=(char*)malloc(sizeof(char)*100);
    ans=(char*)malloc(sizeof(char)*100);
    enigme_que_ans(ch,que,ans);
    printf("%s || %s",que,ans);
    return EXIT_SUCCESS;

}
