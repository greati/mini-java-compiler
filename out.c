#include <stdio.h>
#include <stdlib.h>
#include <string.h>
enum FType {
class$A,
method$A$m1,
method$A$m2,
class$B,
method$B$m1,
class$Main,
method$Main$m1,
method$Main$main,
};
struct Frame {
enum FType ftype;
struct Frame* next;
struct Frame* prev;
union {
struct class$A *A;
struct method$A$m1 *A$m1;
struct method$A$m2 *A$m2;
struct class$B *B;
struct method$B$m1 *B$m1;
struct class$Main *Main;
struct method$Main$m1 *Main$m1;
struct method$Main$main *Main$main;
} mframe;
};
struct class$A
{
int a;
int z;
char * b;
};
struct method$A$m1{
char * retLabel;
struct Frame* classFrame;
int a;
int b;
int c;
int d;
};
struct method$A$m2{
char * retLabel;
struct Frame* classFrame;
int *b;
};
struct class$B
{
int a;
int x;
};
struct method$B$m1{
char * retLabel;
struct Frame* classFrame;
int a;
};
struct class$Main
{
};
struct method$Main$m1{
char * retLabel;
struct Frame* classFrame;
int a;
int b;
};
struct method$Main$main{
char * retLabel;
struct Frame* classFrame;
};
int main(void) {
struct Frame * stackFrame = malloc(sizeof(struct Frame));
char * currentReturn = "exit";
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
if (strcmp(currentReturn,"A$m1$c0$ret") == 0) {
goto A$m1$c0$ret;
}
if (strcmp(currentReturn,"Main$m1$c1$ret") == 0) {
goto Main$m1$c1$ret;
}
A$m1$body:
{
struct Frame* methodFrame = stackFrame;
struct Frame* classFrame = methodFrame->mframe.A$m1->classFrame;
int a = methodFrame->mframe.A$m1->a;
int b = methodFrame->mframe.A$m1->b;
int c = methodFrame->mframe.A$m1->c;
int d = methodFrame->mframe.A$m1->d;
int z = classFrame->mframe.A->z;
printf("%s","a");
methodFrame->prev->next = NULL;
stackFrame = methodFrame->prev;
free(methodFrame);
int n = strlen(methodFrame->mframe.A$m1->retLabel);
currentReturn = (char *) realloc(currentReturn, n+1);
strcpy(currentReturn, methodFrame->mframe.A$m1->retLabel);
}
goto retSwitch;
A$m2$body:
{
struct Frame* methodFrame = stackFrame;
struct Frame* classFrame = methodFrame->mframe.A$m2->classFrame;
int *b = methodFrame->mframe.A$m2->b;
int a = classFrame->mframe.A->a;
int z = classFrame->mframe.A->z;
printf("%s","b");
struct method$A$m1 *newMFrame= malloc(sizeof(struct method$A$m1));
struct Frame * newFrame = malloc(sizeof(struct Frame));
newFrame->mframe.A$m1 = newMFrame;
newFrame->ftype = method$A$m1;
newFrame->prev = stackFrame;
newFrame->next = NULL;
stackFrame->next = newFrame;
stackFrame = newFrame;
newFrame->mframe.A$m1->a=2;
newFrame->mframe.A$m1->b=3;
goto A$m1$body;
A$m1$c0$ret:
;
methodFrame->prev->next = NULL;
stackFrame = methodFrame->prev;
free(methodFrame);
int n = strlen(methodFrame->mframe.A$m2->retLabel);
currentReturn = (char *) realloc(currentReturn, n+1);
strcpy(currentReturn, methodFrame->mframe.A$m2->retLabel);
}
goto retSwitch;
;
B$m1$body:
{
struct Frame* methodFrame = stackFrame;
struct Frame* classFrame = methodFrame->mframe.B$m1->classFrame;
int a = methodFrame->mframe.B$m1->a;
int x = classFrame->mframe.B->x;
printf("%s","c");
methodFrame->prev->next = NULL;
stackFrame = methodFrame->prev;
free(methodFrame);
int n = strlen(methodFrame->mframe.B$m1->retLabel);
currentReturn = (char *) realloc(currentReturn, n+1);
strcpy(currentReturn, methodFrame->mframe.B$m1->retLabel);
}
goto retSwitch;
;
Main$m1$body:
{
struct Frame* methodFrame = stackFrame;
struct Frame* classFrame = methodFrame->mframe.Main$m1->classFrame;
int a = methodFrame->mframe.Main$m1->a;
int b = methodFrame->mframe.Main$m1->b;
printf("%d", a+b);
methodFrame->prev->next = NULL;
stackFrame = methodFrame->prev;
int n = strlen(methodFrame->mframe.Main$m1->retLabel);
currentReturn = (char *) realloc(currentReturn, n+1);
strcpy(currentReturn, methodFrame->mframe.Main$m1->retLabel);
free(methodFrame);
}
goto retSwitch;
Main$main$body:
{
struct Frame* methodFrame = stackFrame;
struct Frame* classFrame = methodFrame->mframe.Main$main->classFrame;
printf("%s","a");
struct method$Main$m1 *newMFrame= malloc(sizeof(struct method$Main$m1));
struct Frame * newFrame = malloc(sizeof(struct Frame));
newFrame->mframe.Main$m1 = newMFrame;
newFrame->ftype = method$Main$m1;
newFrame->prev = stackFrame;
newFrame->next = NULL;
stackFrame->next = newFrame;
stackFrame = newFrame;
newFrame->mframe.Main$m1->a=2;
newFrame->mframe.Main$m1->b=4;
goto Main$m1$body;
Main$m1$c1$ret:
;
methodFrame->prev->next = NULL;
stackFrame = methodFrame->prev;
free(methodFrame);
int n = strlen(methodFrame->mframe.Main$main->retLabel);
currentReturn = (char *) realloc(currentReturn, n+1);
strcpy(currentReturn, methodFrame->mframe.Main$main->retLabel);
}
goto retSwitch;
;
return 0;
}

