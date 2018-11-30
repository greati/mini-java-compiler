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
struct Frame* classFrame;
int *a;
int b;
int c;
int d;
};
struct method$A$m2{
struct Frame* classFrame;
int *b;
};
struct class$B
{
int a;
int x;
};
struct method$B$m1{
struct Frame* classFrame;
int a;
};
struct class$Main
{
};
struct method$Main$main{
struct Frame* classFrame;
};
#include <stdio.h>
int main(void) {
method0$body:
{
struct Frame* methodFrame = stackFrame;
struct Frame* classFrame = methodFrame->mframe.A$m1->classFrame;
int *a = methodFrame->mframe.A$m1->a;
int b = methodFrame->mframe.A$m1->b;
int c = methodFrame->mframe.A$m1->c;
int d = methodFrame->mframe.A$m1->d;
int z = classFrame->mframe.A->z;
printf("%s","a");
}
method1$body:
{
struct Frame* methodFrame = stackFrame;
struct Frame* classFrame = methodFrame->mframe.A$m2->classFrame;
int *b = methodFrame->mframe.A$m2->b;
int a = classFrame->mframe.A->a;
int z = classFrame->mframe.A->z;
printf("%s","b");
}
;
method2$body:
{
struct Frame* methodFrame = stackFrame;
struct Frame* classFrame = methodFrame->mframe.B$m1->classFrame;
int a = methodFrame->mframe.B$m1->a;
int x = classFrame->mframe.B->x;
printf("%s","c");
}
;
method3$body:
{
struct Frame* methodFrame = stackFrame;
struct Frame* classFrame = methodFrame->mframe.Main$main->classFrame;
printf("%s","a");
}
;
return 0;
}

