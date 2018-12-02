#include <stdio.h>
#include <stdlib.h>
#include <string.h>
enum FType {
class$Main,
method$Main$binarySearch,
method$Main$perform,
method$Main$main,
};
struct Frame {
enum FType ftype;
struct Frame* next;
struct Frame* prev;
union {
struct class$Main *Main;
struct method$Main$binarySearch *Main$binarySearch;
struct method$Main$perform *Main$perform;
struct method$Main$main *Main$main;
} mframe;
};
struct class$Main
{
};
struct method$Main$binarySearch{
char * retLabel;
struct Frame* classFrame;
int* arr;
int l;
int r;
int x;
int mid;
};
struct method$Main$perform{
char * retLabel;
struct Frame* classFrame;
int* v;
int l;
int r;
int x;
int i;
int ret;
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
if (strcmp(currentReturn,"Main$binarySearch$c0$ret") == 0) {
goto Main$binarySearch$c0$ret;
}
if (strcmp(currentReturn,"Main$binarySearch$c1$ret") == 0) {
goto Main$binarySearch$c1$ret;
}
if (strcmp(currentReturn,"Main$binarySearch$c2$ret") == 0) {
goto Main$binarySearch$c2$ret;
}
if (strcmp(currentReturn,"Main$binarySearch$c3$ret") == 0) {
goto Main$binarySearch$c3$ret;
}
if (strcmp(currentReturn,"Main$perform$c4$ret") == 0) {
goto Main$perform$c4$ret;
}
Main$binarySearch$body:
{
struct Frame* methodFrame = stackFrame;
struct Frame* classFrame = methodFrame->mframe.Main$binarySearch->classFrame;
int* arr = methodFrame->mframe.Main$binarySearch->arr;
int l = methodFrame->mframe.Main$binarySearch->l;
int r = methodFrame->mframe.Main$binarySearch->r;
int x = methodFrame->mframe.Main$binarySearch->x;
int mid = methodFrame->mframe.Main$binarySearch->mid;
{
int t2 = stackFrame->mframe.Main$binarySearch->r;
int t1 = stackFrame->mframe.Main$binarySearch->l;
int t0=t2>=t1;
if (t0) 
goto if0;
goto if1;
}
if0:
{
int t2 = stackFrame->mframe.Main$binarySearch->l;
int t6 = stackFrame->mframe.Main$binarySearch->r;
int t5 = stackFrame->mframe.Main$binarySearch->l;
int t4=t6-t5;
int t3 = 2;
int t1=t4/t3;
int t0=t2+t1;
stackFrame->mframe.Main$binarySearch->mid= t0;}
;
{
int i0;
{
int t0 = stackFrame->mframe.Main$binarySearch->mid;
i0 = t0;
}
int t2 = stackFrame->mframe.Main$binarySearch->arr[i0];
int t1 = stackFrame->mframe.Main$binarySearch->x;
int t0=t2==t1;
if (t0) 
goto if3;
goto if4;
}
if3:
{
int t0 = stackFrame->mframe.Main$binarySearch->mid;
int * $returnPointerValue = (int *) malloc(sizeof(int));
*$returnPointerValue = (int) t0;
returnPointer = $returnPointerValue;
int n = strlen(stackFrame->mframe.Main$binarySearch->retLabel);
currentReturn = (char *) realloc(currentReturn, n+1);
strcpy(currentReturn, stackFrame->mframe.Main$binarySearch->retLabel);
stackFrame->prev->next = NULL;
struct Frame * toDelete = stackFrame;
stackFrame = toDelete->prev;
free(toDelete);
goto retSwitch;
}
;
goto if5;
if4:
if5:
;
{
int i1;
{
int t0 = stackFrame->mframe.Main$binarySearch->mid;
i1 = t0;
}
int t2 = stackFrame->mframe.Main$binarySearch->arr[i1];
int t1 = stackFrame->mframe.Main$binarySearch->x;
int t0=t2>t1;
if (t0) 
goto if6;
goto if7;
}
if6:
{
{
struct method$Main$binarySearch *newMFrame= malloc(sizeof(struct method$Main$binarySearch));
struct Frame * newFrame = malloc(sizeof(struct Frame));
newFrame->mframe.Main$binarySearch = newMFrame;
newFrame->ftype = method$Main$binarySearch;
newFrame->prev = stackFrame;
newFrame->next = NULL;
stackFrame->next = newFrame;
newMFrame->retLabel = "Main$binarySearch$c0$ret";
{
newFrame->mframe.Main$binarySearch->arr=stackFrame->mframe.Main$binarySearch->arr;
;
}
{
int t0 = stackFrame->mframe.Main$binarySearch->l;
newFrame->mframe.Main$binarySearch->l= t0;
;
}
{
int t2 = stackFrame->mframe.Main$binarySearch->mid;
int t1 = 1;
int t0=t2-t1;
newFrame->mframe.Main$binarySearch->r= t0;
;
}
{
int t0 = stackFrame->mframe.Main$binarySearch->x;
newFrame->mframe.Main$binarySearch->x= t0;
;
}
stackFrame = newFrame;
goto Main$binarySearch$body;
}
Main$binarySearch$c0$ret:;
int t0 = *((int*) returnPointer);
if (returnPointer != NULL) free(returnPointer);
returnPointer = NULL;
int * $returnPointerValue = (int *) malloc(sizeof(int));
*$returnPointerValue = (int) t0;
returnPointer = $returnPointerValue;
int n = strlen(stackFrame->mframe.Main$binarySearch->retLabel);
currentReturn = (char *) realloc(currentReturn, n+1);
strcpy(currentReturn, stackFrame->mframe.Main$binarySearch->retLabel);
stackFrame->prev->next = NULL;
struct Frame * toDelete = stackFrame;
stackFrame = toDelete->prev;
free(toDelete);
goto retSwitch;
}
;
goto if8;
if7:
if8:
;
{
{
struct method$Main$binarySearch *newMFrame= malloc(sizeof(struct method$Main$binarySearch));
struct Frame * newFrame = malloc(sizeof(struct Frame));
newFrame->mframe.Main$binarySearch = newMFrame;
newFrame->ftype = method$Main$binarySearch;
newFrame->prev = stackFrame;
newFrame->next = NULL;
stackFrame->next = newFrame;
newMFrame->retLabel = "Main$binarySearch$c1$ret";
{
newFrame->mframe.Main$binarySearch->arr=stackFrame->mframe.Main$binarySearch->arr;
;
}
{
int t2 = stackFrame->mframe.Main$binarySearch->mid;
int t1 = 1;
int t0=t2+t1;
newFrame->mframe.Main$binarySearch->l= t0;
;
}
{
int t0 = stackFrame->mframe.Main$binarySearch->r;
newFrame->mframe.Main$binarySearch->r= t0;
;
}
{
int t0 = stackFrame->mframe.Main$binarySearch->x;
newFrame->mframe.Main$binarySearch->x= t0;
;
}
stackFrame = newFrame;
goto Main$binarySearch$body;
}
Main$binarySearch$c1$ret:;
int t0 = *((int*) returnPointer);
if (returnPointer != NULL) free(returnPointer);
returnPointer = NULL;
int * $returnPointerValue = (int *) malloc(sizeof(int));
*$returnPointerValue = (int) t0;
returnPointer = $returnPointerValue;
int n = strlen(stackFrame->mframe.Main$binarySearch->retLabel);
currentReturn = (char *) realloc(currentReturn, n+1);
strcpy(currentReturn, stackFrame->mframe.Main$binarySearch->retLabel);
stackFrame->prev->next = NULL;
struct Frame * toDelete = stackFrame;
stackFrame = toDelete->prev;
free(toDelete);
goto retSwitch;
}
;
goto if2;
if1:
if2:
;
{
int t1 = 1;
int t0=-(t1);
int * $returnPointerValue = (int *) malloc(sizeof(int));
*$returnPointerValue = (int) t0;
returnPointer = $returnPointerValue;
int n = strlen(stackFrame->mframe.Main$binarySearch->retLabel);
currentReturn = (char *) realloc(currentReturn, n+1);
strcpy(currentReturn, stackFrame->mframe.Main$binarySearch->retLabel);
stackFrame->prev->next = NULL;
struct Frame * toDelete = stackFrame;
stackFrame = toDelete->prev;
free(toDelete);
goto retSwitch;
}
;
int n = strlen(stackFrame->mframe.Main$binarySearch->retLabel);
currentReturn = (char *) realloc(currentReturn, n+1);
strcpy(currentReturn, stackFrame->mframe.Main$binarySearch->retLabel);
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
int l = methodFrame->mframe.Main$perform->l;
{
int t0 = 0;
methodFrame->mframe.Main$perform->l=t0;
}
int r = methodFrame->mframe.Main$perform->r;
{
int t0 = 9;
methodFrame->mframe.Main$perform->r=t0;
}
int x = methodFrame->mframe.Main$perform->x;
int i = methodFrame->mframe.Main$perform->i;
int ret = methodFrame->mframe.Main$perform->ret;
{
int t0 = 0;
stackFrame->mframe.Main$perform->i=t0;
}
int for0min;
int for0max;
for0min=stackFrame->mframe.Main$perform->i;
{
int t0 = stackFrame->mframe.Main$perform->r;
for0max= t0;
}
int for0step = 1;
{
int t0 = 1;
for0step= t0;
}
if (for0min>for0max)goto for2;
for0:
if (for0min<=stackFrame->mframe.Main$perform->i && for0max>=stackFrame->mframe.Main$perform->i)goto for1;
goto for3;
for1:
{
int t0 = stackFrame->mframe.Main$perform->i;
int i2;
{
int t0 = stackFrame->mframe.Main$perform->i;
i2 = t0;
}
stackFrame->mframe.Main$perform->v[i2]= t0;}
;
stackFrame->mframe.Main$perform->i+=for0step;goto for0;
for2:
;int for2swap;
for2swap=for0min;for0min=for0max;for0max=for2swap;goto for0;
for3:
;
{
int t0 = 3;
stackFrame->mframe.Main$perform->x= t0;}
;
{
{
struct method$Main$binarySearch *newMFrame= malloc(sizeof(struct method$Main$binarySearch));
struct Frame * newFrame = malloc(sizeof(struct Frame));
newFrame->mframe.Main$binarySearch = newMFrame;
newFrame->ftype = method$Main$binarySearch;
newFrame->prev = stackFrame;
newFrame->next = NULL;
stackFrame->next = newFrame;
newMFrame->retLabel = "Main$binarySearch$c2$ret";
{
newFrame->mframe.Main$binarySearch->arr=stackFrame->mframe.Main$perform->v;
;
}
{
int t0 = stackFrame->mframe.Main$perform->l;
newFrame->mframe.Main$binarySearch->l= t0;
;
}
{
int t0 = stackFrame->mframe.Main$perform->r;
newFrame->mframe.Main$binarySearch->r= t0;
;
}
{
int t0 = stackFrame->mframe.Main$perform->x;
newFrame->mframe.Main$binarySearch->x= t0;
;
}
stackFrame = newFrame;
goto Main$binarySearch$body;
}
Main$binarySearch$c2$ret:;
int t0 = *((int*) returnPointer);
if (returnPointer != NULL) free(returnPointer);
returnPointer = NULL;
stackFrame->mframe.Main$perform->ret= t0;}
;
{
char* t0 = "Element found at position ";
printf("%s",t0);}
;
{
int t0 = stackFrame->mframe.Main$perform->ret;
printf("%d",t0);}
;
{
char* t0 = "\n";
printf("%s",t0);}
;
{
int t0 = 11;
stackFrame->mframe.Main$perform->x= t0;}
;
{
{
struct method$Main$binarySearch *newMFrame= malloc(sizeof(struct method$Main$binarySearch));
struct Frame * newFrame = malloc(sizeof(struct Frame));
newFrame->mframe.Main$binarySearch = newMFrame;
newFrame->ftype = method$Main$binarySearch;
newFrame->prev = stackFrame;
newFrame->next = NULL;
stackFrame->next = newFrame;
newMFrame->retLabel = "Main$binarySearch$c3$ret";
{
newFrame->mframe.Main$binarySearch->arr=stackFrame->mframe.Main$perform->v;
;
}
{
int t0 = stackFrame->mframe.Main$perform->l;
newFrame->mframe.Main$binarySearch->l= t0;
;
}
{
int t0 = stackFrame->mframe.Main$perform->r;
newFrame->mframe.Main$binarySearch->r= t0;
;
}
{
int t0 = stackFrame->mframe.Main$perform->x;
newFrame->mframe.Main$binarySearch->x= t0;
;
}
stackFrame = newFrame;
goto Main$binarySearch$body;
}
Main$binarySearch$c3$ret:;
int t0 = *((int*) returnPointer);
if (returnPointer != NULL) free(returnPointer);
returnPointer = NULL;
stackFrame->mframe.Main$perform->ret= t0;}
;
{
char* t0 = "Element not found, returned ";
printf("%s",t0);}
;
{
int t0 = stackFrame->mframe.Main$perform->ret;
printf("%d",t0);}
;
{
char* t0 = "\n";
printf("%s",t0);}
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

