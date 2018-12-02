#include <stdio.h>
#include <stdlib.h>
#include <string.h>
enum FType {
class$Main,
method$Main$quickSort,
method$Main$perform,
method$Main$main,
};
struct Frame {
enum FType ftype;
struct Frame* next;
struct Frame* prev;
union {
struct class$Main *Main;
struct method$Main$quickSort *Main$quickSort;
struct method$Main$perform *Main$perform;
struct method$Main$main *Main$main;
} mframe;
};
struct class$Main
{
};
struct method$Main$quickSort{
char * retLabel;
struct Frame* classFrame;
int* v;
int begin;
int end;
int i;
int j;
int pivot;
int aux;
};
struct method$Main$perform{
char * retLabel;
struct Frame* classFrame;
int* v;
int begin;
int end;
int i;
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
if (strcmp(currentReturn,"Main$quickSort$c0$ret") == 0) {
goto Main$quickSort$c0$ret;
}
if (strcmp(currentReturn,"Main$quickSort$c1$ret") == 0) {
goto Main$quickSort$c1$ret;
}
if (strcmp(currentReturn,"Main$quickSort$c2$ret") == 0) {
goto Main$quickSort$c2$ret;
}
if (strcmp(currentReturn,"Main$perform$c3$ret") == 0) {
goto Main$perform$c3$ret;
}
Main$quickSort$body:
{
struct Frame* methodFrame = stackFrame;
struct Frame* classFrame = methodFrame->mframe.Main$quickSort->classFrame;
int* v = methodFrame->mframe.Main$quickSort->v;
int begin = methodFrame->mframe.Main$quickSort->begin;
int end = methodFrame->mframe.Main$quickSort->end;
int i = methodFrame->mframe.Main$quickSort->i;
{
int t0 = stackFrame->mframe.Main$quickSort->begin;
methodFrame->mframe.Main$quickSort->i=t0;
}
int j = methodFrame->mframe.Main$quickSort->j;
{
int t2 = stackFrame->mframe.Main$quickSort->end;
int t1 = 1;
int t0=t2-t1;
methodFrame->mframe.Main$quickSort->j=t0;
}
int pivot = methodFrame->mframe.Main$quickSort->pivot;
{
int i0;
{
int t4 = stackFrame->mframe.Main$quickSort->begin;
int t3 = stackFrame->mframe.Main$quickSort->end;
int t2=t4+t3;
int t1 = 2;
int t0=t2/t1;
i0 = t0;
}
int t0 = stackFrame->mframe.Main$quickSort->v[i0];
methodFrame->mframe.Main$quickSort->pivot=t0;
}
int aux = methodFrame->mframe.Main$quickSort->aux;
while0:
{
int t2 = stackFrame->mframe.Main$quickSort->i;
int t1 = stackFrame->mframe.Main$quickSort->j;
int t0=t2<=t1;
if (t0)
goto while1;
goto while2;
}
while1:
while3:
{
int i1;
{
int t0 = stackFrame->mframe.Main$quickSort->i;
i1 = t0;
}
int t4 = stackFrame->mframe.Main$quickSort->v[i1];
int t3 = stackFrame->mframe.Main$quickSort->pivot;
int t2=t4<t3;
int t6 = stackFrame->mframe.Main$quickSort->i;
int t5 = stackFrame->mframe.Main$quickSort->end;
int t1=t6<t5;
int t0=t2&&t1;
if (t0)
goto while4;
goto while5;
}
while4:
{
int t2 = stackFrame->mframe.Main$quickSort->i;
int t1 = 1;
int t0=t2+t1;
stackFrame->mframe.Main$quickSort->i= t0;}
;
goto while3;
while5:
;
while6:
{
int i2;
{
int t0 = stackFrame->mframe.Main$quickSort->j;
i2 = t0;
}
int t4 = stackFrame->mframe.Main$quickSort->v[i2];
int t3 = stackFrame->mframe.Main$quickSort->pivot;
int t2=t4>t3;
int t6 = stackFrame->mframe.Main$quickSort->j;
int t5 = stackFrame->mframe.Main$quickSort->begin;
int t1=t6>t5;
int t0=t2&&t1;
if (t0)
goto while7;
goto while8;
}
while7:
{
int t2 = stackFrame->mframe.Main$quickSort->j;
int t1 = 1;
int t0=t2-t1;
stackFrame->mframe.Main$quickSort->j= t0;}
;
goto while6;
while8:
;
{
int t2 = stackFrame->mframe.Main$quickSort->i;
int t1 = stackFrame->mframe.Main$quickSort->j;
int t0=t2<=t1;
if (t0) 
goto if0;
goto if1;
}
if0:
{
int i3;
{
int t0 = stackFrame->mframe.Main$quickSort->i;
i3 = t0;
}
int t0 = stackFrame->mframe.Main$quickSort->v[i3];
stackFrame->mframe.Main$quickSort->aux= t0;}
;
{
int i4;
{
int t0 = stackFrame->mframe.Main$quickSort->j;
i4 = t0;
}
int t0 = stackFrame->mframe.Main$quickSort->v[i4];
int i5;
{
int t0 = stackFrame->mframe.Main$quickSort->i;
i5 = t0;
}
stackFrame->mframe.Main$quickSort->v[i5]= t0;}
;
{
int t0 = stackFrame->mframe.Main$quickSort->aux;
int i6;
{
int t0 = stackFrame->mframe.Main$quickSort->j;
i6 = t0;
}
stackFrame->mframe.Main$quickSort->v[i6]= t0;}
;
{
int t2 = stackFrame->mframe.Main$quickSort->i;
int t1 = 1;
int t0=t2+t1;
stackFrame->mframe.Main$quickSort->i= t0;}
;
{
int t2 = stackFrame->mframe.Main$quickSort->j;
int t1 = 1;
int t0=t2-t1;
stackFrame->mframe.Main$quickSort->j= t0;}
;
goto if2;
if1:
if2:
;
goto while0;
while2:
;
{
int t2 = stackFrame->mframe.Main$quickSort->j;
int t1 = stackFrame->mframe.Main$quickSort->begin;
int t0=t2>t1;
if (t0) 
goto if3;
goto if4;
}
if3:
{
struct method$Main$quickSort *newMFrame= malloc(sizeof(struct method$Main$quickSort));
struct Frame * newFrame = malloc(sizeof(struct Frame));
newFrame->mframe.Main$quickSort = newMFrame;
newFrame->ftype = method$Main$quickSort;
newFrame->prev = stackFrame;
newFrame->next = NULL;
stackFrame->next = newFrame;
newMFrame->retLabel = "Main$quickSort$c0$ret";
{
newFrame->mframe.Main$quickSort->v=stackFrame->mframe.Main$quickSort->v;
;
}
{
int t0 = stackFrame->mframe.Main$quickSort->begin;
newFrame->mframe.Main$quickSort->begin= t0;
;
}
{
int t2 = stackFrame->mframe.Main$quickSort->j;
int t1 = 1;
int t0=t2+t1;
newFrame->mframe.Main$quickSort->end= t0;
;
}
stackFrame = newFrame;
goto Main$quickSort$body;
}
Main$quickSort$c0$ret:
;
goto if5;
if4:
if5:
;
{
int t2 = stackFrame->mframe.Main$quickSort->i;
int t1 = stackFrame->mframe.Main$quickSort->end;
int t0=t2<t1;
if (t0) 
goto if6;
goto if7;
}
if6:
{
struct method$Main$quickSort *newMFrame= malloc(sizeof(struct method$Main$quickSort));
struct Frame * newFrame = malloc(sizeof(struct Frame));
newFrame->mframe.Main$quickSort = newMFrame;
newFrame->ftype = method$Main$quickSort;
newFrame->prev = stackFrame;
newFrame->next = NULL;
stackFrame->next = newFrame;
newMFrame->retLabel = "Main$quickSort$c1$ret";
{
newFrame->mframe.Main$quickSort->v=stackFrame->mframe.Main$quickSort->v;
;
}
{
int t0 = stackFrame->mframe.Main$quickSort->i;
newFrame->mframe.Main$quickSort->begin= t0;
;
}
{
int t0 = stackFrame->mframe.Main$quickSort->end;
newFrame->mframe.Main$quickSort->end= t0;
;
}
stackFrame = newFrame;
goto Main$quickSort$body;
}
Main$quickSort$c1$ret:
;
goto if8;
if7:
if8:
;
int n = strlen(stackFrame->mframe.Main$quickSort->retLabel);
currentReturn = (char *) realloc(currentReturn, n+1);
strcpy(currentReturn, stackFrame->mframe.Main$quickSort->retLabel);
stackFrame->prev->next = NULL;
struct Frame * toDelete = stackFrame;
stackFrame = toDelete->prev;
free(toDelete);
}
goto retSwitch;
Main$perform$body:
{
struct Frame* methodFrame = stackFrame;
struct Frame* classFrame = methodFrame->mframe.Main$perform->classFrame;
int* v = methodFrame->mframe.Main$perform->v;
{
int k0;
{
int t0 = 10;
k0 = t0;
}
int* t0 = (int*) malloc(sizeof(int) * k0);
methodFrame->mframe.Main$perform->v=t0;
}
int begin = methodFrame->mframe.Main$perform->begin;
{
int t0 = 0;
methodFrame->mframe.Main$perform->begin=t0;
}
int end = methodFrame->mframe.Main$perform->end;
{
int t0 = 9;
methodFrame->mframe.Main$perform->end=t0;
}
int i = methodFrame->mframe.Main$perform->i;
{
char* t0 = "Initial: \n";
printf("%s",t0);}
;
{
int t0 = stackFrame->mframe.Main$perform->end;
stackFrame->mframe.Main$perform->i=t0;
}
int for0min;
int for0max;
for0min=stackFrame->mframe.Main$perform->i;
{
int t0 = stackFrame->mframe.Main$perform->begin;
for0max= t0;
}
int for0step = 1;
{
int t1 = 1;
int t0=-(t1);
for0step= t0;
}
if (for0min>for0max)goto for2;
for0:
if (for0min<=stackFrame->mframe.Main$perform->i && for0max>=stackFrame->mframe.Main$perform->i)goto for1;
goto for3;
for1:
{
int t0 = stackFrame->mframe.Main$perform->i;
int i7;
{
int t0 = stackFrame->mframe.Main$perform->i;
i7 = t0;
}
stackFrame->mframe.Main$perform->v[i7]= t0;}
;
{
int i8;
{
int t0 = stackFrame->mframe.Main$perform->i;
i8 = t0;
}
int t0 = stackFrame->mframe.Main$perform->v[i8];
printf("%d",t0);}
;
{
char* t0 = "\n";
printf("%s",t0);}
;
stackFrame->mframe.Main$perform->i+=for0step;goto for0;
for2:
;int for2swap;
for2swap=for0min;for0min=for0max;for0max=for2swap;goto for0;
for3:
;
{
struct method$Main$quickSort *newMFrame= malloc(sizeof(struct method$Main$quickSort));
struct Frame * newFrame = malloc(sizeof(struct Frame));
newFrame->mframe.Main$quickSort = newMFrame;
newFrame->ftype = method$Main$quickSort;
newFrame->prev = stackFrame;
newFrame->next = NULL;
stackFrame->next = newFrame;
newMFrame->retLabel = "Main$quickSort$c2$ret";
{
newFrame->mframe.Main$quickSort->v=stackFrame->mframe.Main$perform->v;
;
}
{
int t0 = stackFrame->mframe.Main$perform->begin;
newFrame->mframe.Main$quickSort->begin= t0;
;
}
{
int t0 = stackFrame->mframe.Main$perform->end;
newFrame->mframe.Main$quickSort->end= t0;
;
}
stackFrame = newFrame;
goto Main$quickSort$body;
}
Main$quickSort$c2$ret:
;
{
char* t0 = "Sorted: \n";
printf("%s",t0);}
;
{
int t0 = stackFrame->mframe.Main$perform->begin;
stackFrame->mframe.Main$perform->i=t0;
}
int for4min;
int for4max;
for4min=stackFrame->mframe.Main$perform->i;
{
int t0 = stackFrame->mframe.Main$perform->end;
for4max= t0;
}
int for4step = 1;
if (for4min>for4max)goto for6;
for4:
if (for4min<=stackFrame->mframe.Main$perform->i && for4max>=stackFrame->mframe.Main$perform->i)goto for5;
goto for7;
for5:
{
int i9;
{
int t0 = stackFrame->mframe.Main$perform->i;
i9 = t0;
}
int t0 = stackFrame->mframe.Main$perform->v[i9];
printf("%d",t0);}
;
{
char* t0 = "\n";
printf("%s",t0);}
;
stackFrame->mframe.Main$perform->i+=for4step;goto for4;
for6:
;int for6swap;
for6swap=for4min;for4min=for4max;for4max=for6swap;goto for4;
for7:
;
int n = strlen(stackFrame->mframe.Main$perform->retLabel);
currentReturn = (char *) realloc(currentReturn, n+1);
strcpy(currentReturn, stackFrame->mframe.Main$perform->retLabel);
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
struct method$Main$perform *newMFrame= malloc(sizeof(struct method$Main$perform));
struct Frame * newFrame = malloc(sizeof(struct Frame));
newFrame->mframe.Main$perform = newMFrame;
newFrame->ftype = method$Main$perform;
newFrame->prev = stackFrame;
newFrame->next = NULL;
stackFrame->next = newFrame;
newMFrame->retLabel = "Main$perform$c3$ret";
stackFrame = newFrame;
goto Main$perform$body;
}
Main$perform$c3$ret:
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

