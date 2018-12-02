#include <stdio.h>
#include <stdlib.h>
#include <string.h>
enum FType {
class$Main,
method$Main$m3,
method$Main$m2,
method$Main$m1,
method$Main$main,
};
struct Frame {
enum FType ftype;
struct Frame* next;
struct Frame* prev;
union {
struct class$Main *Main;
struct method$Main$m3 *Main$m3;
struct method$Main$m2 *Main$m2;
struct method$Main$m1 *Main$m1;
struct method$Main$main *Main$main;
} mframe;
};
struct class$Main
{
};
struct method$Main$m3{
char * retLabel;
struct Frame* classFrame;
int *b;
};
struct method$Main$m2{
char * retLabel;
struct Frame* classFrame;
int*** arr;
};
struct method$Main$m1{
char * retLabel;
struct Frame* classFrame;
int a;
int*** v;
int* v2;
};
struct method$Main$main{
char * retLabel;
struct Frame* classFrame;
};
int main(void) {
void * returnPointer = NULL;
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
if (strcmp(currentReturn,"Main$m2$c0$ret") == 0) {
goto Main$m2$c0$ret;
}
if (strcmp(currentReturn,"Main$m3$c1$ret") == 0) {
goto Main$m3$c1$ret;
}
if (strcmp(currentReturn,"Main$m1$c2$ret") == 0) {
goto Main$m1$c2$ret;
}
Main$m3$body:
{
struct Frame* methodFrame = stackFrame;
struct Frame* classFrame = methodFrame->mframe.Main$m3->classFrame;
int *b = methodFrame->mframe.Main$m3->b;
{
int t0 = 4;
*stackFrame->mframe.Main$m3->b= t0;}
;
int n = strlen(stackFrame->mframe.Main$m3->retLabel);
currentReturn = (char *) realloc(currentReturn, n+1);
strcpy(currentReturn, stackFrame->mframe.Main$m3->retLabel);
stackFrame->prev->next = NULL;
struct Frame * toDelete = stackFrame;
stackFrame = toDelete->prev;
free(toDelete);
}
goto retSwitch;
Main$m2$body:
{
struct Frame* methodFrame = stackFrame;
struct Frame* classFrame = methodFrame->mframe.Main$m2->classFrame;
int*** arr = methodFrame->mframe.Main$m2->arr;
{
int t0 = 15;
int i0;
{
int t0 = 2;
i0 = t0;
}
int i1;
{
int t0 = 4;
i1 = t0;
}
int i2;
{
int t0 = 4;
i2 = t0;
}
stackFrame->mframe.Main$m2->arr[i0][i1][i2]= t0;}
;
int n = strlen(stackFrame->mframe.Main$m2->retLabel);
currentReturn = (char *) realloc(currentReturn, n+1);
strcpy(currentReturn, stackFrame->mframe.Main$m2->retLabel);
stackFrame->prev->next = NULL;
struct Frame * toDelete = stackFrame;
stackFrame = toDelete->prev;
free(toDelete);
}
goto retSwitch;
Main$m1$body:
{
struct Frame* methodFrame = stackFrame;
struct Frame* classFrame = methodFrame->mframe.Main$m1->classFrame;
int a = methodFrame->mframe.Main$m1->a;
{
int t2 = 2;
int t1 = 3;
int t0=t2*t1;
methodFrame->mframe.Main$m1->a=t0;
}
int*** v = methodFrame->mframe.Main$m1->v;
{
int k0;
{
int t0 = 10;
k0 = t0;
}
int k1;
{
int t0 = 20;
k1 = t0;
}
int k2;
{
int t0 = 2;
k2 = t0;
}
int*** t0 = (int***) malloc(sizeof(int**) * k0);
for (int i0=0; i0< k0; ++i0)
t0[i0] = (int**) malloc(sizeof(int*) * k1);
for (int i0=0; i0< k0; ++i0)
for (int i1=0; i1< k1; ++i1)
t0[i0][i1] = (int*) malloc(sizeof(int) * k2);
methodFrame->mframe.Main$m1->v=t0;
}
int* v2 = methodFrame->mframe.Main$m1->v2;
{
int t0 = 10;
int i0;
{
int t0 = 2;
i0 = t0;
}
int i1;
{
int t0 = 4;
i1 = t0;
}
int i2;
{
int t0 = 4;
i2 = t0;
}
stackFrame->mframe.Main$m1->v[i0][i1][i2]= t0;}
;
{
struct method$Main$m2 *newMFrame= malloc(sizeof(struct method$Main$m2));
struct Frame * newFrame = malloc(sizeof(struct Frame));
newFrame->mframe.Main$m2 = newMFrame;
newFrame->ftype = method$Main$m2;
newFrame->prev = stackFrame;
newFrame->next = NULL;
stackFrame->next = newFrame;
newMFrame->retLabel = "Main$m2$c0$ret";
{
int*** t0 = stackFrame->mframe.Main$m1->v;
newFrame->mframe.Main$m2->arr= t0;
}
stackFrame = newFrame;
goto Main$m2$body;
}
Main$m2$c0$ret:
;
{
int i0;
{
int t0 = 2;
i0 = t0;
}
int i1;
{
int t0 = 4;
i1 = t0;
}
int* t0 = stackFrame->mframe.Main$m1->v[i0][i1];
stackFrame->mframe.Main$m1->v2= t0;}
;
{
int i0;
{
int t0 = 4;
i0 = t0;
}
int t0 = stackFrame->mframe.Main$m1->v2[i0];
printf("%d",t0);}
;
{
int i0;
{
int t0 = 2;
i0 = t0;
}
int i1;
{
int t0 = 4;
i1 = t0;
}
int i2;
{
int t0 = 4;
i2 = t0;
}
int t0 = stackFrame->mframe.Main$m1->v[i0][i1][i2];
printf("%d",t0);}
;
{
char* t0 = "ANTES: \n";
printf("%s",t0);}
;
{
int t0 = stackFrame->mframe.Main$m1->a;
printf("%d",t0);}
;
{
char* t0 = "\n";
printf("%s",t0);}
;
{
struct method$Main$m3 *newMFrame= malloc(sizeof(struct method$Main$m3));
struct Frame * newFrame = malloc(sizeof(struct Frame));
newFrame->mframe.Main$m3 = newMFrame;
newFrame->ftype = method$Main$m3;
newFrame->prev = stackFrame;
newFrame->next = NULL;
stackFrame->next = newFrame;
newMFrame->retLabel = "Main$m3$c1$ret";
{
newFrame->mframe.Main$m3->b= &stackFrame->mframe.Main$m1->a;
}
stackFrame = newFrame;
goto Main$m3$body;
}
Main$m3$c1$ret:
;
{
char* t0 = "DEPOIS: \n";
printf("%s",t0);}
;
{
int t0 = stackFrame->mframe.Main$m1->a;
printf("%d",t0);}
;
{
char* t0 = "\n";
printf("%s",t0);}
;
{
int t0 = 0;
int * $returnPointerValue = (int *) malloc(sizeof(int));
*$returnPointerValue = (int) t0;
returnPointer = $returnPointerValue;
int n = strlen(stackFrame->mframe.Main$m1->retLabel);
currentReturn = (char *) realloc(currentReturn, n+1);
strcpy(currentReturn, stackFrame->mframe.Main$m1->retLabel);
stackFrame->prev->next = NULL;
struct Frame * toDelete = stackFrame;
stackFrame = toDelete->prev;
free(toDelete);
goto retSwitch;
}
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
struct method$Main$m1 *newMFrame= malloc(sizeof(struct method$Main$m1));
struct Frame * newFrame = malloc(sizeof(struct Frame));
newFrame->mframe.Main$m1 = newMFrame;
newFrame->ftype = method$Main$m1;
newFrame->prev = stackFrame;
newFrame->next = NULL;
stackFrame->next = newFrame;
newMFrame->retLabel = "Main$m1$c2$ret";
stackFrame = newFrame;
goto Main$m1$body;
}
Main$m1$c2$ret:
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

