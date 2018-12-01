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
int b;
int i;
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
int b = methodFrame->mframe.Main$m1->b;
int i = methodFrame->mframe.Main$m1->i;
{
struct Frame * frame = stackFrame;
int t0 = stackFrame->mframe.Main$m1->a;
frame->mframe.Main$m1->b = t0;}
;
while0:
{
int t1 = stackFrame->mframe.Main$m1->b;
int t2 = 0;
int t0=t1>t2;
if (t0)
goto while1;
goto while2;
}
while1:
{
int t0 = stackFrame->mframe.Main$m1->b;
printf("%d",t0);}
;
{
struct Frame * frame = stackFrame;
int t1 = stackFrame->mframe.Main$m1->b;
int t2 = 1;
int t0=t1-t2;
frame->mframe.Main$m1->b = t0;}
;
goto while0;
while2:
;
{
struct Frame * frame = stackFrame;
int t0 = 4;
frame->mframe.Main$m1->b = t0;}
;
{
int t0 = 0;
if (stackFrame->mframe.Main$m1->b== t0)
goto switch1;
goto switch2;
}
switch1:
{
char* t0 = "aa 0";
printf("%s",t0);}
;
goto switch0;
switch2:
{
int t0 = 1;
if (stackFrame->mframe.Main$m1->b== t0)
goto switch3;
goto switch4;
}
switch3:
{
char* t0 = "aa 1";
printf("%s",t0);}
;
goto switch0;
switch4:
{
char* t0 = "DEFAULTAO";
printf("%s",t0);}
;
switch0:
;
{
int t0 = stackFrame->mframe.Main$m1->a;
printf("%d",t0);}
;
{
int t0 = 0;
stackFrame->mframe.Main$m1->i=t0;
}
int for0min;
int for0max;
for0min=stackFrame->mframe.Main$m1->i;
{
int t0 = 2;
for0max= t0;
}
int for0step = 1;
{
int t0 = 2;
for0step= t0;
}
if (for0min>for0max)goto for2;
for0:
if (for0min<=stackFrame->mframe.Main$m1->i && for0max>=stackFrame->mframe.Main$m1->i)goto for1;
goto for3;
for1:
{
int t0 = stackFrame->mframe.Main$m1->i;
printf("%d",t0);}
;
stackFrame->mframe.Main$m1->i+=for0step;goto for0;
for2:
;int for2swap;
for2swap=for0min;for0min=for0max;for0max=for2swap;goto for0;
for3:
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
int t3 = 3;
int t4 = 5;
int t2=t3*t4;
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

