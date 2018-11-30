#include <stdio.h>
#include <stdlib.h>
// switch for return points
retSwitch:
char * currentReturn;
if (strcomp(currentReturn,"A$m1$c0$ret") == 0) {
goto A$m1$c0$ret;
}
enum FType {
class$A,
method$A$m1,
method$A$m2,
class$B,
method$B$m1,
class$Main,
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
struct method$Main$main *Main$main;
} mframe;
} frame;
struct Frame * stackFrame = &frame;
struct class$A
{
int a;
int z;
char * b;
};
struct method$A$m1{
char * retLabel;
struct Frame* classFrame;
int *a;
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
struct method$Main$main{
char * retLabel;
struct Frame* classFrame;
};
int main(void) {
A$m1$body:
{
struct Frame* methodFrame = stackFrame;
struct Frame* classFrame = methodFrame->mframe.A$m1->classFrame;
int *a = methodFrame->mframe.A$m1->a;
int b = methodFrame->mframe.A$m1->b;
int c = methodFrame->mframe.A$m1->c;
int d = methodFrame->mframe.A$m1->d;
int z = classFrame->mframe.A->z;
printf("%s","a");
currentReturn = methodFrame->mframe.A$m1->retLabel;
}
goto returnSwitch;A$m2$body:
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
newFrame->mframe.A$m1->a=2;
newFrame->mframe.A$m1->b=3;
goto A$m1$body;
;
currentReturn = methodFrame->mframe.A$m2->retLabel;
}
goto returnSwitch;;
B$m1$body:
{
struct Frame* methodFrame = stackFrame;
struct Frame* classFrame = methodFrame->mframe.B$m1->classFrame;
int a = methodFrame->mframe.B$m1->a;
int x = classFrame->mframe.B->x;
printf("%s","c");
currentReturn = methodFrame->mframe.B$m1->retLabel;
}
goto returnSwitch;;
Main$main$body:
{
struct Frame* methodFrame = stackFrame;
struct Frame* classFrame = methodFrame->mframe.Main$main->classFrame;
printf("%s","a");
currentReturn = methodFrame->mframe.Main$main->retLabel;
}
goto returnSwitch;;
return 0;
}

