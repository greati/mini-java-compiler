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
method$Main$m2,
method$Main$m1,
method$Main$m0,
method$Main$r0,
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
struct method$Main$m2 *Main$m2;
struct method$Main$m1 *Main$m1;
struct method$Main$m0 *Main$m0;
struct method$Main$r0 *Main$r0;
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
struct method$Main$m2{
char * retLabel;
struct Frame* classFrame;
int a;
};
struct method$Main$m1{
char * retLabel;
struct Frame* classFrame;
int a;
int b;
int c;
};
struct method$Main$m0{
char * retLabel;
struct Frame* classFrame;
int a;
};
struct method$Main$r0{
char * retLabel;
struct Frame* classFrame;
int* b;
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
if (strcmp(currentReturn,"A$m1$c0$ret") == 0) {
goto A$m1$c0$ret;
}
if (strcmp(currentReturn,"Main$m2$c1$ret") == 0) {
goto Main$m2$c1$ret;
}
if (strcmp(currentReturn,"Main$m0$c2$ret") == 0) {
goto Main$m0$c2$ret;
}
if (strcmp(currentReturn,"Main$m1$c3$ret") == 0) {
goto Main$m1$c3$ret;
}
if (strcmp(currentReturn,"Main$m0$c4$ret") == 0) {
goto Main$m0$c4$ret;
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
{
char* t0 = "a\n";
printf("%s",t0);}
;
int n = strlen(stackFrame->mframe.A$m1->retLabel);
currentReturn = (char *) realloc(currentReturn, n+1);
strcpy(currentReturn, stackFrame->mframe.A$m1->retLabel);
stackFrame->prev->next = NULL;
struct Frame * toDelete = stackFrame;
stackFrame = toDelete->prev;
free(toDelete);
}
goto retSwitch;
A$m2$body:
{
struct Frame* methodFrame = stackFrame;
struct Frame* classFrame = methodFrame->mframe.A$m2->classFrame;
int *b = methodFrame->mframe.A$m2->b;
int a = classFrame->mframe.A->a;
int z = classFrame->mframe.A->z;
{
char* t0 = "b\n";
printf("%s",t0);}
;
{
struct method$A$m1 *newMFrame= malloc(sizeof(struct method$A$m1));
struct Frame * newFrame = malloc(sizeof(struct Frame));
newFrame->mframe.A$m1 = newMFrame;
newFrame->ftype = method$A$m1;
newFrame->prev = stackFrame;
newFrame->next = NULL;
stackFrame->next = newFrame;
newMFrame->retLabel = "A$m1$c0$ret";
{
int t0 = 2;
newFrame->mframe.A$m1->a= t0;
}
{
int t0 = 3;
newFrame->mframe.A$m1->b= t0;
}
stackFrame = newFrame;
goto A$m1$body;
}
A$m1$c0$ret:
;
int n = strlen(stackFrame->mframe.A$m2->retLabel);
currentReturn = (char *) realloc(currentReturn, n+1);
strcpy(currentReturn, stackFrame->mframe.A$m2->retLabel);
stackFrame->prev->next = NULL;
struct Frame * toDelete = stackFrame;
stackFrame = toDelete->prev;
free(toDelete);
}
goto retSwitch;
;
B$m1$body:
{
struct Frame* methodFrame = stackFrame;
struct Frame* classFrame = methodFrame->mframe.B$m1->classFrame;
int a = methodFrame->mframe.B$m1->a;
int x = classFrame->mframe.B->x;
{
char* t0 = "c\n";
printf("%s",t0);}
;
int n = strlen(stackFrame->mframe.B$m1->retLabel);
currentReturn = (char *) realloc(currentReturn, n+1);
strcpy(currentReturn, stackFrame->mframe.B$m1->retLabel);
stackFrame->prev->next = NULL;
struct Frame * toDelete = stackFrame;
stackFrame = toDelete->prev;
free(toDelete);
}
goto retSwitch;
;
Main$m2$body:
{
struct Frame* methodFrame = stackFrame;
struct Frame* classFrame = methodFrame->mframe.Main$m2->classFrame;
int a = methodFrame->mframe.Main$m2->a;
{
int t0 = stackFrame->mframe.Main$m2->a;
printf("%d",t0);}
;
{
char* t0 = "\n";
printf("%s",t0);}
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
int b = methodFrame->mframe.Main$m1->b;
int c = methodFrame->mframe.Main$m1->c;
{
int t2 = stackFrame->mframe.Main$m1->a;
int t1 = stackFrame->mframe.Main$m1->b;
int t0=t2*t1;
printf("%d",t0);}
;
{
char* t0 = "\n";
printf("%s",t0);}
;
{
struct Frame * frame = stackFrame;
int t0 = 2;
stackFrame->mframe.Main$m1->c = t0;}
;
{
char* t0 = "olha o valor de c antes\n";
printf("%s",t0);}
;
{
int t0 = stackFrame->mframe.Main$m1->c;
printf("%d",t0);}
;
{
struct Frame * frame = stackFrame;
int t0 = 4;
stackFrame->mframe.Main$m1->c = t0;}
;
{
char* t0 = "olha o valor agora\n";
printf("%s",t0);}
;
{
int t0 = stackFrame->mframe.Main$m1->c;
printf("%d",t0);}
;
{
struct method$Main$m2 *newMFrame= malloc(sizeof(struct method$Main$m2));
struct Frame * newFrame = malloc(sizeof(struct Frame));
newFrame->mframe.Main$m2 = newMFrame;
newFrame->ftype = method$Main$m2;
newFrame->prev = stackFrame;
newFrame->next = NULL;
stackFrame->next = newFrame;
newMFrame->retLabel = "Main$m2$c1$ret";
{
int t2 = stackFrame->mframe.Main$m1->a;
int t1 = stackFrame->mframe.Main$m1->b;
int t0=t2+t1;
newFrame->mframe.Main$m2->a= t0;
}
stackFrame = newFrame;
goto Main$m2$body;
}
Main$m2$c1$ret:
;
{
char* t0 = "retornou de m2\n";
printf("%s",t0);}
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
Main$m0$body:
{
struct Frame* methodFrame = stackFrame;
struct Frame* classFrame = methodFrame->mframe.Main$m0->classFrame;
int a = methodFrame->mframe.Main$m0->a;
{
int t2 = stackFrame->mframe.Main$m0->a;
int t1 = 0;
int t0=t2==t1;
if (t0) 
goto if0;
goto if1;
}
if0:
{
char* t0 = "fim da recursão\n";
printf("%s",t0);}
;
goto if2;
if1:
{
int t0 = stackFrame->mframe.Main$m0->a;
printf("%d",t0);}
;
{
char* t0 = "\n";
printf("%s",t0);}
;
{
struct method$Main$m0 *newMFrame= malloc(sizeof(struct method$Main$m0));
struct Frame * newFrame = malloc(sizeof(struct Frame));
newFrame->mframe.Main$m0 = newMFrame;
newFrame->ftype = method$Main$m0;
newFrame->prev = stackFrame;
newFrame->next = NULL;
stackFrame->next = newFrame;
newMFrame->retLabel = "Main$m0$c2$ret";
{
int t2 = stackFrame->mframe.Main$m0->a;
int t1 = 1;
int t0=t2-t1;
newFrame->mframe.Main$m0->a= t0;
}
stackFrame = newFrame;
goto Main$m0$body;
}
Main$m0$c2$ret:
;
if2:
;
int n = strlen(stackFrame->mframe.Main$m0->retLabel);
currentReturn = (char *) realloc(currentReturn, n+1);
strcpy(currentReturn, stackFrame->mframe.Main$m0->retLabel);
stackFrame->prev->next = NULL;
struct Frame * toDelete = stackFrame;
stackFrame = toDelete->prev;
free(toDelete);
}
goto retSwitch;
Main$r0$body:
{
struct Frame* methodFrame = stackFrame;
struct Frame* classFrame = methodFrame->mframe.Main$r0->classFrame;
int* b = methodFrame->mframe.Main$r0->b;
{
char* t0 = "oi\n";
printf("%s",t0);}
;
int n = strlen(stackFrame->mframe.Main$r0->retLabel);
currentReturn = (char *) realloc(currentReturn, n+1);
strcpy(currentReturn, stackFrame->mframe.Main$r0->retLabel);
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
char* t0 = "a\n";
printf("%s",t0);}
;
{
struct method$Main$m1 *newMFrame= malloc(sizeof(struct method$Main$m1));
struct Frame * newFrame = malloc(sizeof(struct Frame));
newFrame->mframe.Main$m1 = newMFrame;
newFrame->ftype = method$Main$m1;
newFrame->prev = stackFrame;
newFrame->next = NULL;
stackFrame->next = newFrame;
newMFrame->retLabel = "Main$m1$c3$ret";
{
int t0 = 2;
newFrame->mframe.Main$m1->a= t0;
}
{
int t0 = 4;
newFrame->mframe.Main$m1->b= t0;
}
stackFrame = newFrame;
goto Main$m1$body;
}
Main$m1$c3$ret:
;
{
char* t0 = "retornou!!!\n";
printf("%s",t0);}
;
{
struct method$Main$m0 *newMFrame= malloc(sizeof(struct method$Main$m0));
struct Frame * newFrame = malloc(sizeof(struct Frame));
newFrame->mframe.Main$m0 = newMFrame;
newFrame->ftype = method$Main$m0;
newFrame->prev = stackFrame;
newFrame->next = NULL;
stackFrame->next = newFrame;
newMFrame->retLabel = "Main$m0$c4$ret";
{
int t0 = 10;
newFrame->mframe.Main$m0->a= t0;
}
stackFrame = newFrame;
goto Main$m0$body;
}
Main$m0$c4$ret:
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

