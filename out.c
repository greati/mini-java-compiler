#include <stdio.h>
#include <stdlib.h>
#include <string.h>
enum FType {
class$Main,
method$Main$merge,
method$Main$mergeSort,
method$Main$perform,
method$Main$main,
};
struct Frame {
enum FType ftype;
struct Frame* next;
struct Frame* prev;
union {
struct class$Main *Main;
struct method$Main$merge *Main$merge;
struct method$Main$mergeSort *Main$mergeSort;
struct method$Main$perform *Main$perform;
struct method$Main$main *Main$main;
} mframe;
};
struct class$Main
{
};
struct method$Main$merge{
char * retLabel;
struct Frame* classFrame;
int* v;
int *begin;
int *middle;
int *end;
int i;
int j;
int k;
int length;
int* aux;
};
struct method$Main$mergeSort{
char * retLabel;
struct Frame* classFrame;
int* v;
int *begin;
int *end;
int middle;
int middlePlusOne;
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
if (strcmp(currentReturn,"Main$mergeSort$c0$ret") == 0) {
goto Main$mergeSort$c0$ret;
}
if (strcmp(currentReturn,"Main$mergeSort$c1$ret") == 0) {
goto Main$mergeSort$c1$ret;
}
if (strcmp(currentReturn,"Main$merge$c2$ret") == 0) {
goto Main$merge$c2$ret;
}
if (strcmp(currentReturn,"Main$mergeSort$c3$ret") == 0) {
goto Main$mergeSort$c3$ret;
}
if (strcmp(currentReturn,"Main$perform$c4$ret") == 0) {
goto Main$perform$c4$ret;
}
Main$merge$body:
{
struct Frame* methodFrame = stackFrame;
struct Frame* classFrame = methodFrame->mframe.Main$merge->classFrame;
int* v = methodFrame->mframe.Main$merge->v;
int *begin = methodFrame->mframe.Main$merge->begin;
int *middle = methodFrame->mframe.Main$merge->middle;
int *end = methodFrame->mframe.Main$merge->end;
int i = methodFrame->mframe.Main$merge->i;
{
int t0 = *stackFrame->mframe.Main$merge->begin;
methodFrame->mframe.Main$merge->i=t0;
}
int j = methodFrame->mframe.Main$merge->j;
{
int t2 = *stackFrame->mframe.Main$merge->middle;
int t1 = 1;
int t0=t2+t1;
methodFrame->mframe.Main$merge->j=t0;
}
int k = methodFrame->mframe.Main$merge->k;
{
int t0 = 0;
methodFrame->mframe.Main$merge->k=t0;
}
int length = methodFrame->mframe.Main$merge->length;
{
int t4 = *stackFrame->mframe.Main$merge->end;
int t3 = *stackFrame->mframe.Main$merge->begin;
int t2=t4-t3;
int t1 = 1;
int t0=t2+t1;
methodFrame->mframe.Main$merge->length=t0;
}
int* aux = methodFrame->mframe.Main$merge->aux;
{
int k0;
{
int t0 = stackFrame->mframe.Main$merge->length;
k0 = t0;
}
int* t0 = (int*) malloc(sizeof(int) * k0);
methodFrame->mframe.Main$merge->aux=t0;
}
while0:
{
int t4 = stackFrame->mframe.Main$merge->i;
int t3 = *stackFrame->mframe.Main$merge->middle;
int t2=t4<=t3;
int t6 = stackFrame->mframe.Main$merge->j;
int t5 = *stackFrame->mframe.Main$merge->end;
int t1=t6<=t5;
int t0=t2&&t1;
if (t0)
goto while1;
goto while2;
}
while1:
{
int i0;
{
int t0 = stackFrame->mframe.Main$merge->i;
i0 = t0;
}
int t2 = stackFrame->mframe.Main$merge->v[i0];
int i1;
{
int t0 = stackFrame->mframe.Main$merge->j;
i1 = t0;
}
int t1 = stackFrame->mframe.Main$merge->v[i1];
int t0=t2<t1;
if (t0) 
goto if0;
goto if1;
}
if0:
{
int i2;
{
int t0 = stackFrame->mframe.Main$merge->i;
i2 = t0;
}
int t0 = stackFrame->mframe.Main$merge->v[i2];
int i3;
{
int t0 = stackFrame->mframe.Main$merge->k;
i3 = t0;
}
stackFrame->mframe.Main$merge->aux[i3]= t0;}
;
{
int t2 = stackFrame->mframe.Main$merge->i;
int t1 = 1;
int t0=t2+t1;
stackFrame->mframe.Main$merge->i= t0;}
;
goto if2;
if1:
{
int i4;
{
int t0 = stackFrame->mframe.Main$merge->j;
i4 = t0;
}
int t0 = stackFrame->mframe.Main$merge->v[i4];
int i5;
{
int t0 = stackFrame->mframe.Main$merge->k;
i5 = t0;
}
stackFrame->mframe.Main$merge->aux[i5]= t0;}
;
{
int t2 = stackFrame->mframe.Main$merge->j;
int t1 = 1;
int t0=t2+t1;
stackFrame->mframe.Main$merge->j= t0;}
;
if2:
;
{
int t2 = stackFrame->mframe.Main$merge->k;
int t1 = 1;
int t0=t2+t1;
stackFrame->mframe.Main$merge->k= t0;}
;
goto while0;
while2:
;
while3:
{
int t2 = stackFrame->mframe.Main$merge->i;
int t1 = *stackFrame->mframe.Main$merge->middle;
int t0=t2<=t1;
if (t0)
goto while4;
goto while5;
}
while4:
{
int i6;
{
int t0 = stackFrame->mframe.Main$merge->i;
i6 = t0;
}
int t0 = stackFrame->mframe.Main$merge->v[i6];
int i7;
{
int t0 = stackFrame->mframe.Main$merge->k;
i7 = t0;
}
stackFrame->mframe.Main$merge->aux[i7]= t0;}
;
{
int t2 = stackFrame->mframe.Main$merge->i;
int t1 = 1;
int t0=t2+t1;
stackFrame->mframe.Main$merge->i= t0;}
;
{
int t2 = stackFrame->mframe.Main$merge->k;
int t1 = 1;
int t0=t2+t1;
stackFrame->mframe.Main$merge->k= t0;}
;
goto while3;
while5:
;
while6:
{
int t2 = stackFrame->mframe.Main$merge->j;
int t1 = *stackFrame->mframe.Main$merge->end;
int t0=t2<=t1;
if (t0)
goto while7;
goto while8;
}
while7:
{
int i8;
{
int t0 = stackFrame->mframe.Main$merge->j;
i8 = t0;
}
int t0 = stackFrame->mframe.Main$merge->v[i8];
int i9;
{
int t0 = stackFrame->mframe.Main$merge->k;
i9 = t0;
}
stackFrame->mframe.Main$merge->aux[i9]= t0;}
;
{
int t2 = stackFrame->mframe.Main$merge->j;
int t1 = 1;
int t0=t2+t1;
stackFrame->mframe.Main$merge->j= t0;}
;
{
int t2 = stackFrame->mframe.Main$merge->k;
int t1 = 1;
int t0=t2+t1;
stackFrame->mframe.Main$merge->k= t0;}
;
goto while6;
while8:
;
{
int t0 = *stackFrame->mframe.Main$merge->begin;
stackFrame->mframe.Main$merge->k=t0;
}
int for0min;
int for0max;
for0min=stackFrame->mframe.Main$merge->k;
{
int t0 = *stackFrame->mframe.Main$merge->end;
for0max= t0;
}
int for0step = 1;
{
int t0 = 1;
for0step= t0;
}
if (for0min>for0max)goto for2;
for0:
if (for0min<=stackFrame->mframe.Main$merge->k && for0max>=stackFrame->mframe.Main$merge->k)goto for1;
goto for3;
for1:
{
int i10;
{
int t2 = stackFrame->mframe.Main$merge->k;
int t1 = *stackFrame->mframe.Main$merge->begin;
int t0=t2-t1;
i10 = t0;
}
int t0 = stackFrame->mframe.Main$merge->aux[i10];
int i11;
{
int t0 = stackFrame->mframe.Main$merge->k;
i11 = t0;
}
stackFrame->mframe.Main$merge->v[i11]= t0;}
;
stackFrame->mframe.Main$merge->k+=for0step;goto for0;
for2:
;int for2swap;
for2swap=for0min;for0min=for0max;for0max=for2swap;goto for0;
for3:
;
int n = strlen(stackFrame->mframe.Main$merge->retLabel);
currentReturn = (char *) realloc(currentReturn, n+1);
strcpy(currentReturn, stackFrame->mframe.Main$merge->retLabel);
stackFrame->prev->next = NULL;
struct Frame * toDelete = stackFrame;
stackFrame = toDelete->prev;
free(toDelete);
}
goto retSwitch;
Main$mergeSort$body:
{
struct Frame* methodFrame = stackFrame;
struct Frame* classFrame = methodFrame->mframe.Main$mergeSort->classFrame;
int* v = methodFrame->mframe.Main$mergeSort->v;
int *begin = methodFrame->mframe.Main$mergeSort->begin;
int *end = methodFrame->mframe.Main$mergeSort->end;
int middle = methodFrame->mframe.Main$mergeSort->middle;
int middlePlusOne = methodFrame->mframe.Main$mergeSort->middlePlusOne;
{
int t2 = *stackFrame->mframe.Main$mergeSort->begin;
int t1 = *stackFrame->mframe.Main$mergeSort->end;
int t0=t2<t1;
if (t0) 
goto if3;
goto if4;
}
if3:
{
int t4 = *stackFrame->mframe.Main$mergeSort->end;
int t3 = *stackFrame->mframe.Main$mergeSort->begin;
int t2=t4+t3;
int t1 = 2;
int t0=t2/t1;
stackFrame->mframe.Main$mergeSort->middle= t0;}
;
{
int t2 = stackFrame->mframe.Main$mergeSort->middle;
int t1 = 1;
int t0=t2+t1;
stackFrame->mframe.Main$mergeSort->middlePlusOne= t0;}
;
{
struct method$Main$mergeSort *newMFrame= malloc(sizeof(struct method$Main$mergeSort));
struct Frame * newFrame = malloc(sizeof(struct Frame));
newFrame->mframe.Main$mergeSort = newMFrame;
newFrame->ftype = method$Main$mergeSort;
newFrame->prev = stackFrame;
newFrame->next = NULL;
stackFrame->next = newFrame;
newMFrame->retLabel = "Main$mergeSort$c0$ret";
{
newFrame->mframe.Main$mergeSort->v=stackFrame->mframe.Main$mergeSort->v;
;
}
{
newFrame->mframe.Main$mergeSort->begin=stackFrame->mframe.Main$mergeSort->begin;
;
}
{
newFrame->mframe.Main$mergeSort->end= &stackFrame->mframe.Main$mergeSort->middle;
;
}
stackFrame = newFrame;
goto Main$mergeSort$body;
}
Main$mergeSort$c0$ret:
;
{
struct method$Main$mergeSort *newMFrame= malloc(sizeof(struct method$Main$mergeSort));
struct Frame * newFrame = malloc(sizeof(struct Frame));
newFrame->mframe.Main$mergeSort = newMFrame;
newFrame->ftype = method$Main$mergeSort;
newFrame->prev = stackFrame;
newFrame->next = NULL;
stackFrame->next = newFrame;
newMFrame->retLabel = "Main$mergeSort$c1$ret";
{
newFrame->mframe.Main$mergeSort->v=stackFrame->mframe.Main$mergeSort->v;
;
}
{
newFrame->mframe.Main$mergeSort->begin= &stackFrame->mframe.Main$mergeSort->middlePlusOne;
;
}
{
newFrame->mframe.Main$mergeSort->end=stackFrame->mframe.Main$mergeSort->end;
;
}
stackFrame = newFrame;
goto Main$mergeSort$body;
}
Main$mergeSort$c1$ret:
;
{
struct method$Main$merge *newMFrame= malloc(sizeof(struct method$Main$merge));
struct Frame * newFrame = malloc(sizeof(struct Frame));
newFrame->mframe.Main$merge = newMFrame;
newFrame->ftype = method$Main$merge;
newFrame->prev = stackFrame;
newFrame->next = NULL;
stackFrame->next = newFrame;
newMFrame->retLabel = "Main$merge$c2$ret";
{
newFrame->mframe.Main$merge->v=stackFrame->mframe.Main$mergeSort->v;
;
}
{
newFrame->mframe.Main$merge->begin=stackFrame->mframe.Main$mergeSort->begin;
;
}
{
newFrame->mframe.Main$merge->middle= &stackFrame->mframe.Main$mergeSort->middle;
;
}
{
newFrame->mframe.Main$merge->end=stackFrame->mframe.Main$mergeSort->end;
;
}
stackFrame = newFrame;
goto Main$merge$body;
}
Main$merge$c2$ret:
;
goto if5;
if4:
if5:
;
int n = strlen(stackFrame->mframe.Main$mergeSort->retLabel);
currentReturn = (char *) realloc(currentReturn, n+1);
strcpy(currentReturn, stackFrame->mframe.Main$mergeSort->retLabel);
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
int t0 = 10;
int i12;
{
int t0 = 0;
i12 = t0;
}
stackFrame->mframe.Main$perform->v[i12]= t0;}
;
{
int t0 = 9;
int i13;
{
int t0 = 1;
i13 = t0;
}
stackFrame->mframe.Main$perform->v[i13]= t0;}
;
{
int t0 = 8;
int i14;
{
int t0 = 2;
i14 = t0;
}
stackFrame->mframe.Main$perform->v[i14]= t0;}
;
{
int t0 = 7;
int i15;
{
int t0 = 3;
i15 = t0;
}
stackFrame->mframe.Main$perform->v[i15]= t0;}
;
{
int t0 = 6;
int i16;
{
int t0 = 4;
i16 = t0;
}
stackFrame->mframe.Main$perform->v[i16]= t0;}
;
{
int t0 = 5;
int i17;
{
int t0 = 5;
i17 = t0;
}
stackFrame->mframe.Main$perform->v[i17]= t0;}
;
{
int t0 = 4;
int i18;
{
int t0 = 6;
i18 = t0;
}
stackFrame->mframe.Main$perform->v[i18]= t0;}
;
{
int t0 = 3;
int i19;
{
int t0 = 7;
i19 = t0;
}
stackFrame->mframe.Main$perform->v[i19]= t0;}
;
{
int t0 = 2;
int i20;
{
int t0 = 8;
i20 = t0;
}
stackFrame->mframe.Main$perform->v[i20]= t0;}
;
{
int t0 = 1;
int i21;
{
int t0 = 9;
i21 = t0;
}
stackFrame->mframe.Main$perform->v[i21]= t0;}
;
{
struct method$Main$mergeSort *newMFrame= malloc(sizeof(struct method$Main$mergeSort));
struct Frame * newFrame = malloc(sizeof(struct Frame));
newFrame->mframe.Main$mergeSort = newMFrame;
newFrame->ftype = method$Main$mergeSort;
newFrame->prev = stackFrame;
newFrame->next = NULL;
stackFrame->next = newFrame;
newMFrame->retLabel = "Main$mergeSort$c3$ret";
{
newFrame->mframe.Main$mergeSort->v=stackFrame->mframe.Main$perform->v;
;
}
{
newFrame->mframe.Main$mergeSort->begin= &stackFrame->mframe.Main$perform->begin;
;
}
{
newFrame->mframe.Main$mergeSort->end= &stackFrame->mframe.Main$perform->end;
;
}
stackFrame = newFrame;
goto Main$mergeSort$body;
}
Main$mergeSort$c3$ret:
;
{
int t0 = 0;
stackFrame->mframe.Main$perform->i=t0;
}
int for4min;
int for4max;
for4min=stackFrame->mframe.Main$perform->i;
{
int t0 = 9;
for4max= t0;
}
int for4step = 1;
{
int t0 = 1;
for4step= t0;
}
if (for4min>for4max)goto for6;
for4:
if (for4min<=stackFrame->mframe.Main$perform->i && for4max>=stackFrame->mframe.Main$perform->i)goto for5;
goto for7;
for5:
{
int i22;
{
int t0 = stackFrame->mframe.Main$perform->i;
i22 = t0;
}
int t0 = stackFrame->mframe.Main$perform->v[i22];
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
newMFrame->retLabel = "Main$perform$c4$ret";
stackFrame = newFrame;
goto Main$perform$body;
}
Main$perform$c4$ret:
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

