#include <stdio.h>
#include <stdlib.h>
#include <string.h>
enum FType {
class$Main,
method$Main$m1,
method$Main$main,
};
struct Frame {
enum FType ftype;
struct Frame* next;
struct Frame* prev;
union {
struct class$Main *Main;
struct method$Main$m1 *Main$m1;
struct method$Main$main *Main$main;
} mframe;
};
struct class$Main
{
};
struct method$Main$m1{
char * retLabel;
struct Frame* classFrame;
int a;
};
struct method$Main$main{
char * retLabel;
struct Frame* classFrame;
};
int main(void) {
struct Frame * stackFrame = malloc(sizeof(struct Frame));
char * currentReturn = (char*) malloc(5*sizeof(char));
strcpy(currentReturn, "exit");
{struct method$Main$main *newMFrame= malloc(sizeof(struct method$Main$main));
struct Frame * newFrame = malloc(sizeof(struct Frame));
newMFrame->retLabel = "exit";
newFrame->mframe.Main$main = newMFrame;
newFrame->ftype = method$Main$main;
newFrame->prev = stackFrame;
newFrame->next = NULL;
stackFrame->next = newFrame;
stackFrame = newFrame;
goto Main$main$body;
}
// switch for return points
retSwitch:
if (strcmp(currentReturn,"exit") == 0) {
free(stackFrame);
return 0;
}
if (strcmp(currentReturn,"Main$m1$c0$ret") == 0) {
goto Main$m1$c0$ret;
}
Main$m1$body:
{
struct Frame* methodFrame = stackFrame;
struct Frame* classFrame = methodFrame->mframe.Main$m1->classFrame;
int a = methodFrame->mframe.Main$m1->a;
{
int t0 = stackFrame->mframe.Main$m1->a;
printf("%d",t0);}
;
int n = strlen(stackFrame->mframe.Main$m1->retLabel);
currentReturn = (char *) realloc(currentReturn, n+1);
strcpy(currentReturn, stackFrame->mframe.Main$m1->retLabel);
stackFrame->prev->next = NULL;
struct Frame * toDelete = stackFrame;
stackFrame = toDelete->prev;
free(toDelete);
}
goto retSwitch;
Main$main$body:
{
struct Frame* methodFrame = stackFrame;
struct Frame* classFrame = methodFrame->mframe.Main$main->classFrame;
{
char* t0 = "abc";
printf("%s",t0);}
;
{
int t1 = 2;
int t2 = 3;
int t0=t1+t2;
printf("%d",t0);}
;
{
struct method$Main$m1 *newMFrame= malloc(sizeof(struct method$Main$m1));
struct Frame * newFrame = malloc(sizeof(struct Frame));
newFrame->mframe.Main$m1 = newMFrame;
newFrame->ftype = method$Main$m1;
newFrame->prev = stackFrame;
newFrame->next = NULL;
stackFrame->next = newFrame;
stackFrame = newFrame;
newMFrame->retLabel = "Main$m1$c0$ret";
{
int t0 = 3;
newFrame->mframe.Main$m1->a= t0;
}
goto Main$m1$body;
}
Main$m1$c0$ret:
;
int n = strlen(stackFrame->mframe.Main$main->retLabel);
currentReturn = (char *) realloc(currentReturn, n+1);
strcpy(currentReturn, stackFrame->mframe.Main$main->retLabel);
stackFrame->prev->next = NULL;
struct Frame * toDelete = stackFrame;
stackFrame = toDelete->prev;
free(toDelete);
}
goto retSwitch;
;
return 0;
}

