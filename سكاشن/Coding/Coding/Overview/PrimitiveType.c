
#include <stdio.h>
struct Session{
char NameTeacher[50];//50
int numStudents;//4
float bestGrade;//4
};
//58=={60}
struct Session2{
char NameTeacher[50];//50
int numStudents;//4
long long bestGrade; //8
};//62=={64}

struct Session3{
char NameTeacher;// 1
long long bestGrade; //8
//9--{16 {8}}{12{4}}
};
int main() {
    printf("Size of char: %d bytes\n", sizeof(char));
    printf("Size of short: %d bytes\n", sizeof(short));
    printf("Size of int: %d bytes\n", sizeof(int));
    printf("Size of long: %d bytes\n", sizeof(long));
    printf("Size of long long: %d bytes\n", sizeof(long long));
    printf("Size of float: %d bytes\n", sizeof(float));
    printf("Size of double: %d bytes\n", sizeof(double));
    printf("Size of long double: %d bytes\n", sizeof(long double));
    printf("Size of Session: %d bytes\n", sizeof(struct Session));
    printf("Size of Session: %d bytes\n", sizeof(struct Session2));
    printf("Size of Session: %d bytes\n", sizeof(struct Session3));

    return 0;
}
